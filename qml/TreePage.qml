import Felgo 3.0
import QtQuick 2.12
import rendall 1.0


ListPage {
  id: listpage

  //  signal selected(Node node)
  //    signal deleted(Node node)
  //    signal renamed(Node node, string name)



  title: qsTr("Заметки")

  property alias contextMenu: menu
  //  property alias view: view



  //    delegate: SimpleRow {}

  //    signal selected(Node node)
  //    signal deleted(Node node)
  //    signal renamed(Node node, string name)

  model: Presenter.model()
  //    clip: true
  //    snapMode: ListView.SnapToItem
  //    currentIndex: -1


  listView.header: SimpleRow {
    text: ".."
    //      imageSource: "qrc:/qml/image/home_folder.png"

    enabled: !Presenter.isRoot
    visible: !Presenter.isRoot
    //      height: !Presenter.isRoot ? implicitHeight : 0

    //      width: view.width
    onSelected: Presenter.selectBackFolder()
  }


  delegate: SimpleRow {
    text: model.name
    imageSource: model.smallIcon

    //      width: view.width

    onSelected: listpage.itemSelected(index, model.node)

    //      onClicked: {
    //        currentIndex = index
    //        view.selected(model.node)
    //      }

    //      onDeleted: {
    //        view.deleted(model.node)
  }

  //      onRenamed: {
  //        view.renamed(model.node, text)
  //      }
  //    }


  //    footerPositioning: ListView.OverlayFooter
  //    footer: RoundButton {

  //      anchors.right: parent.right
  //      height: 64
  //      width: 64

  //      text: "+"

  //      onClicked: menu.open()
  //    }

  //    Connections {
  //      target: Presenter
  //      onFolderChanged: view.currentIndex = -1
  //    }


  //    AddNodeMenu {
  //      id: menu

  //    }

  FloatingActionButton {
    id: fab

    icon: IconType.plus
    visible: true
    onClicked: menu.open()
  }



  CreateNodeMenu {
    id: menu

    anchors.centerIn: parent
  }

}


