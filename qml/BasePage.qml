import Felgo 3.0
import QtQuick 2.12
import QtQuick.Controls 2.12 as QtQuick
import QtQuick.Layouts 1.0
//import Rendall.Component 1.0
import rendall 1.0


Page {
  id: page

  property Node node
  property bool isCreate: true
//  property alias icon: icon.source
  property alias content: content.contentItem



//  Image {
//    id: icon
//    x: 16

//    width: 72
//    height: 72
//  }


  Flickable {
    id: flickable

    anchors.left: parent.left
    anchors.leftMargin: 16
    anchors.right: parent.right
    anchors.rightMargin: 16
    anchors.top: parent.top
    anchors.bottom: footer.top

    clip: true

    contentWidth: width
    contentHeight: content.height

    boundsBehavior: Flickable.StopAtBounds
    flickableDirection: Flickable.VerticalFlick
    QtQuick.ScrollBar.vertical: QtQuick.ScrollBar {}

    QtQuick.Control {
      id: content
      implicitWidth: flickable.contentWidth
    }
  }


  Item {
    id: footer

    anchors.bottom: parent.bottom

    width: parent.width
    height: row.implicitHeight + 32

    RowLayout {
      id: row

      anchors.centerIn: parent
      width: parent.width - 32

      AppButton {
        visible: true
        text: qsTr("Отменить")
        onClicked: {
          data2view()
          nameField.forceActiveFocus()
        }
      }

      AppButton {
        visible: !isEmpty()
        enabled: !isEmpty()

        text: isCreate ? qsTr("Создать") : qsTr("Изменить")

        onClicked: accept()
      }

      Item { Layout.fillWidth: true }

      AppButton {
        Layout.alignment: Qt.AlignRight

        visible: true
        text: qsTr("Закрыть")
        onClicked: {
          Presenter.closeNode()
          page.navigationStack.pop()
        }
      }
    }
  }


////  RendallComponent.BasePopup {
////    id: warningDialog

////    width: parent.width - 32
////    height: 160
////    buttonMargin: 8

////    title: qsTr("Проблема")

////    Text {
////      anchors.top: parent.top
////      renderType: Text.NativeRendering
////      clip: true

////      text: qsTr("Невозможно создать объект")
////    }

////    acceptButtonName: qsTr("Ok")
////    rejectButtonName: qsTr("Отмена")
////  }


  function accept()
  {
    if (isCreate) {
      var node = createNode()
      view2data(node)
      Director.addNote(node, Presenter.folder)
      Presenter.closeNode()
    }
    else {
      view2data(getNode())
      Director.saveNote(getNode())
    }
  }


  Component.onCompleted: {
    nameField.forceActiveFocus()

    if (!isCreate)
      data2view()
  }

}
