#pragma once

#include <QAbstractListModel>
#include "logic/nodelist.h"
#include "logic/node.h"
#include "logic/folder.h"


namespace presenter {

  class Model : public QAbstractListModel
  {
    Q_OBJECT

  public:
    enum Roles {
      NameRole = Qt::UserRole + 1,
      SmallIconRole,
      BigIconRole,
      PageRole,
      NodeRole,
    };

  public:
    explicit Model(logic::Folder* folder, QObject* parent = nullptr);
    virtual ~Model() override = default;

  public:
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

  public:
    void select(logic::Folder* folder);
    void change(logic::Node* node);

  public slots:
    void beginReset();
    void endReset();

    void beginAppend(logic::Node* node);
    void endAppend(logic::Node* node);

    void beginRemove(logic::Node* node);
    void endRemove(logic::Node* node);

    void beginChange();
    void endChange();

    void beginMove();
    void endMove();

  private:
    logic::Folder* m_folder;
  };

} // namespace presenter
