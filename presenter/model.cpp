#include "model.h"


namespace presenter {

  Model::Model(logic::Folder* folder, QObject* parent)
    : QAbstractListModel(parent)
    , m_folder(folder)
  {
  }


  QHash<int, QByteArray> Model::roleNames() const
  {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[SmallIconRole] = "smallIcon";
    roles[BigIconRole] = "bigIcon";
    roles[PageRole] = "page";
    roles[NodeRole] = "node";
    return roles;
  }


  int Model::rowCount(const QModelIndex& parent) const
  {
    Q_UNUSED(parent);

    if (m_folder == nullptr)
      return 0;
    return m_folder->count();
  }


  QVariant Model::data(const QModelIndex& index, int role) const
  {
    Q_UNUSED(role)

    if (!index.isValid()) {
      return QVariant();
    }

    logic::Node* node = m_folder->value(index.row());
    if (node == nullptr) {
      qDebug() << Q_FUNC_INFO << " node of index " << index.row() << " is null";
      return QVariant();
    }

    switch (role) {
    case NameRole:
      return node->name();
    case SmallIconRole:
      return node->smallIcon();
    case BigIconRole:
      return node->bigIcon();
    case PageRole:
      return node->qmlPage();
    case NodeRole:
      return QVariant::fromValue(node);
    }
    return QVariant();
  }


  void Model::select(logic::Folder* folder)
  {
    beginResetModel();
    m_folder = folder;
    endResetModel();
  }


  void Model::change(logic::Node* node)
  {
    const int row = m_folder->children().indexOf(node);
    QModelIndex index = this->index(row);
    emit dataChanged(index, index);
  }


  void Model::beginReset()
  {
    beginResetModel();
  }

  void Model::endReset()
  {
    endResetModel();
  }


  void Model::beginAppend(logic::Node* node)
  {
    Q_UNUSED(node)
    const int count = m_folder->count();
    beginInsertRows(QModelIndex(), count, count);
  }

  void Model::endAppend(logic::Node* node)
  {
    Q_UNUSED(node)
    endInsertRows();
  }


  void Model::beginRemove(logic::Node* node)
  {
    const int index = m_folder->indexOf(node);
    beginRemoveRows(QModelIndex(), index, index);
  }

  void Model::endRemove(logic::Node* node)
  {
    Q_UNUSED(node)
    endRemoveRows();
  }


  void Model::beginChange()
  {

  }

  void Model::endChange()
  {

  }


  void Model::beginMove()
  {

  }

  void Model::endMove()
  {

  }


  //  bool NodeModel::isRoot() const
  //  {
  //    return m_folder->id() == 0;
  //  }

} // namespace presenter
