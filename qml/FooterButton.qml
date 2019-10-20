import Felgo 3.0
import QtQuick 2.12
import QtQuick.Controls 2.12 as QtQuick
import QtQuick.Layouts 1.0
//import Rendall.Component 1.0
import rendall 1.0


Item {


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
      onClicked: Presenter.closeNode()
    }
  }


}
