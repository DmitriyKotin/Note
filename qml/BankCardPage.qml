import Felgo 3.0
import QtQuick 2.12
//import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
import "./Rendall/Component" as Rendall
import rendall 1.0


BasePage {
  id: page

//  property BankCard card: Presenter.node

  title: isCreate ? qsTr("Новая карта") : node.name
//  icon: card.bigIcon


  Column {
    anchors.top: parent.top
    anchors.topMargin: 24
    spacing: 24

    anchors.horizontalCenter: parent.horizontalCenter


    Rendall.InputField {
      id: nameField

      labelText: qsTr("Название")
//      text: card.name
      inputMethodHints: Qt.ImhPreferUppercase

//      KeyNavigation.up: commentField
//      KeyNavigation.down: numberField
//      KeyNavigation.right: numberField
//      KeyNavigation.left: commentField

//      Keys.onReturnPressed: numberField.forceActiveFocus()
    }


    Rendall.InputField {
      id: numberField

      labelText: qsTr("Номер карты")
//      text: card.number
      maximumLength: 19
      inputMethodHints: Qt.ImhDigitsOnly

//      KeyNavigation.up: nameField
//      KeyNavigation.down: holderField
//      KeyNavigation.right: holderField
//      KeyNavigation.left: nameField

//      Keys.onReturnPressed: holderField.forceActiveFocus()
    }


    Rendall.InputField {
      id: holderField

      labelText: qsTr("Имя держателя")
//      text: card.holderName
      maximumLength: 128
      inputMethodHints: Qt.ImhUppercaseOnly

//      KeyNavigation.up: numberField
//      KeyNavigation.down: validThruField
//      KeyNavigation.right: validThruField
//      KeyNavigation.left: numberField

//      Keys.onReturnPressed: validThruField.forceActiveFocus()
    }


    Row {
      width: nameField.width
      spacing: 16

      Rendall.InputField {
        id: validThruField

        labelText: qsTr("Срок действия")
//        text: card.validThru
        inputMask: "DD.DDDD;_"
        inputMethodHints: Qt.ImhDate
        width: parent.width / 2 - parent.spacing / 2

//        KeyNavigation.up: holderField
//        KeyNavigation.down: cvcField
//        KeyNavigation.right: cvcField
//        KeyNavigation.left: holderField

//        Keys.onReturnPressed: cvcField.forceActiveFocus()
      }


      Rendall.InputField {
        id: cvcField

        labelText: qsTr("CVV/CVC")
//        text: card.cvc
        maximumLength: 3
        echoMode: passwordMouseArea.pressed ? TextInput.Normal : TextInput.Password
        inputMethodHints: Qt.ImhDigitsOnly
        width: parent.width / 2 - parent.spacing / 2

//        KeyNavigation.up: validThruField
//        KeyNavigation.down: commentField
//        KeyNavigation.right: commentField
//        KeyNavigation.left: validThruField

        Keys.onReturnPressed: commentField.forceActiveFocus()

        Image {
          anchors.right: parent.right
          anchors.verticalCenter: parent.verticalCenter

//          source: "qrc:/style/newStyle/pics/administration/invis.png"

          MouseArea {
            id: passwordMouseArea

            anchors.fill: parent
          }
        }
      }
    }


    Rendall.InputArea {
      id: commentField

      labelText: qsTr("Коментарий")
//      text: card.comment
    }
  }


  function view2data(node)
  {
    node.name = nameField.text
    node.number = numberField.text
    node.holderName = holderField.text
    node.validThru = validThruField.text
    node.cvc = cvcField.text
    node.comment = commentField.text
  }


  function data2view()
  {
    nameField.text = node.name
    numberField.text = node.number
    holderField.text = node.holderName
    validThruField.text = node.validThru
    cvcField.text = node.cvc
    commentField.text = node.comment

    nameField.ensureVisible(0)
    numberField.ensureVisible(0)
    holderField.ensureVisible(0)
    validThruField.ensureVisible(0)
    cvcField.ensureVisible(0)
  }


  function createNode()
  {
    return bankCard
  }


  BankCard {
    id: bankCard
  }


  function isEmpty()
  {
    return nameField.text === ""
  }

}
