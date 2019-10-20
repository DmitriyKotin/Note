import QtQuick 2.12
//import QtQuick.Controls 2.13
import QtQuick.Layouts 1.0
//import Rendall.Component 1.0
import "./Rendall/Component" as Rendall
import rendall 1.0


BasePage {
  id: page

  //  property Contact contact: Presenter.node

  title: isCreate ? qsTr("Новый контакт") : node.name
  //  icon: contact.bigIcon


  Column {

    anchors.top: parent.top
    anchors.topMargin: 24
    spacing: 24

    anchors.horizontalCenter: parent.horizontalCenter


    Rendall.InputField {
      id: nameField

      labelText:  qsTr("Название")
      //      text: contact.name
      inputMethodHints: Qt.ImhPreferUppercase

      //      KeyNavigation.up: commentField
      //      KeyNavigation.down: firstNameField
      //      KeyNavigation.right: firstNameField
      //      KeyNavigation.left: commentField

      //      Keys.onReturnPressed: firstNameField.forceActiveFocus()
    }


    Row {
      width: nameField.width
      spacing: 16

      Rendall.InputField {
        id: firstNameField

        labelText: qsTr("Имя")
        //        text: contact.firstName
        inputMethodHints: Qt.ImhPreferUppercase
        width: parent.width / 2 - parent.spacing / 2

        //        KeyNavigation.up: nameField
        //        KeyNavigation.down: secondNameField
        //        KeyNavigation.right: secondNameField
        //        KeyNavigation.left: nameField

        //        Keys.onReturnPressed: secondNameField.forceActiveFocus()
      }


      Rendall.InputField {
        id: secondNameField

        labelText: qsTr("Фамилия")
        //        text: contact.secondName
        inputMethodHints: Qt.ImhPreferUppercase
        width: parent.width / 2 - parent.spacing / 2

        //        KeyNavigation.up: firstNameField
        //        KeyNavigation.down: companyField
        //        KeyNavigation.right: companyField
        //        KeyNavigation.left: firstNameField

        //        Keys.onReturnPressed: companyField.forceActiveFocus()
      }
    }


    Rendall.InputField {
      id: companyField

      labelText: qsTr("Компания")
      //      text: contact.companyName
      inputMethodHints: Qt.ImhPreferUppercase

      //      KeyNavigation.up: secondNameField
      //      KeyNavigation.down: phoneField
      //      KeyNavigation.right: phoneField
      //      KeyNavigation.left: secondNameField

      //      Keys.onReturnPressed: phoneField.forceActiveFocus()
    }


    Rendall.InputField {
      id: phoneField

      labelText: qsTr("Телефон")
      //      text: contact.phoneNumber
      inputMethodHints: Qt.ImhDialableCharactersOnly

      //      KeyNavigation.up: companyField
      //      KeyNavigation.down: emailField
      //      KeyNavigation.right: emailField
      //      KeyNavigation.left: companyField

      //      Keys.onReturnPressed: emailField.forceActiveFocus()
    }


    Rendall.InputField {
      id: emailField

      labelText: qsTr("Email")
      //      text: contact.email
      inputMethodHints: Qt.ImhEmailCharactersOnly

      //      KeyNavigation.up: phoneField
      //      KeyNavigation.down: addressField
      //      KeyNavigation.right: addressField
      //      KeyNavigation.left: phoneField

      //      Keys.onReturnPressed: addressField.forceActiveFocus()
    }


    Rendall.InputField {
      id: addressField

      labelText: qsTr("Адрес")
      //      text: contact.address

      //      KeyNavigation.up: emailField
      //      KeyNavigation.down: commentField
      //      KeyNavigation.right: commentField
      //      KeyNavigation.left: emailField

      //      Keys.onReturnPressed: commentField.forceActiveFocus()
    }


    Rendall.InputArea {
      id: commentField

      labelText: qsTr("Коментарий")
      //      text: contact.comment
    }
  }


  function view2data(node)
  {
    node.name = nameField.text
    node.firstName = firstNameField.text
    node.secondName = secondNameField.text
    node.companyName = companyField.text
    node.phoneNumber = phoneField.text
    node.email = emailField.text
    node.address = addressField.text
    node.comment = commentField.text
  }


  function data2view()
  {
    nameField.text = node.name
    firstNameField.text = node.firstName
    secondNameField.text = node.secondName
    companyField.text = node.companyName
    phoneField.text = node.phoneNumber
    emailField.text = node.email
    addressField.text = node.address
    commentField.text = node.comment

    nameField.ensureVisible(0)
    firstNameField.ensureVisible(0)
    secondNameField.ensureVisible(0)
    companyField.ensureVisible(0)
    phoneField.ensureVisible(0)
    emailField.ensureVisible(0)
    addressField.ensureVisible(0)
  }


  function createNode()
  {
    return contact
  }


  Contact {
    id: contact
  }

  function isEmpty()
  {
    return nameField.text === ""
  }

}
