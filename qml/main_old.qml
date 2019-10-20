import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import rendall 1.0


Rectangle {

}


//ApplicationWindow {
//  visible: true
//  width: 1280
//  height: 720
//  title: qsTr("Rendall note")

//  SplitView {
//    anchors.fill: parent
//    orientation: Qt.Horizontal

//    ListPage {
//      id: listPage

//      implicitWidth: 320
//      SplitView.maximumWidth: 400
//      SplitView.minimumWidth: 200

//      contextMenu.onCreateAccount: nodePage.setSource("AccountPage.qml", {isCreate: true})
//      contextMenu.onCreateBankCard: nodePage.setSource("BankCardPage.qml", {isCreate: true})
//      contextMenu.onCreateContact: nodePage.setSource("ContactPage.qml", {isCreate: true})
//      contextMenu.onCreateMemo: nodePage.setSource("MemoPage.qml", {isCreate: true})

//      listView.onSelected:
//      {
//        if (!node.isFolder()) {
//          Presenter.setNode(node)
//          nodePage.setSource(node.qmlPage,
//                             {isCreate: false,
//                              node: node,
//                              icon: node.bigIcon})
//        }
//        else {
//          Presenter.selectFolder(node)
//        }
//      }
//    }


//    Loader {
//      id: nodePage

//      source: "EmptyPage.qml"

//      SplitView.minimumWidth: 50
//      SplitView.fillWidth: true
//    }


//    Connections {
//      target: Presenter
//      onClosedNode: nodePage.setSource("EmptyPage.qml")
//    }

//  }
//}
