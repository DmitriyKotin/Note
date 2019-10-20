import Felgo 3.0
import QtQuick 2.12
//import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
import "./Rendall/Component" as Rendall
import rendall 1.0


BasePage {
  id: page


//  //  property Account account: Presenter.node
  title: isCreate ? qsTr("Новый аккаунт") : node.name
//  //  icon: account.bigIcon

//  focus: true
//  content: Column {

//    spacing: 8

  Column {

    anchors.top: parent.top
    anchors.topMargin: 24
    spacing: 24

    anchors.horizontalCenter: parent.horizontalCenter

    Rendall.InputField {
      id: nameField

      labelText: qsTr("Название")
      //      text: account.name

      inputMethodHints: Qt.ImhPreferUppercase

//      KeyNavigation.up: commentField
//      KeyNavigation.down: loginField
//      KeyNavigation.right: loginField
//      KeyNavigation.left: commentField

//      Keys.onReturnPressed: loginField.forceActiveFocus()
    }


    Rendall.InputField {
      id: loginField


      labelText: qsTr("Логин")
//      //      text: account.login
      inputMethodHints: Qt.ImhNoAutoUppercase

//      KeyNavigation.up: nameField
//      KeyNavigation.down: passwordField
//      KeyNavigation.right: passwordField
//      KeyNavigation.left: nameField

//      Keys.onReturnPressed: passwordField.forceActiveFocus()
    }


    Rendall.InputField {
      id: passwordField

      labelText: qsTr("Пароль")
//      //      text: account.password
      echoMode: TextInput.Password
      inputMethodHints: Qt.ImhSensitiveData

//      KeyNavigation.up: loginField
//      KeyNavigation.down: emailField
//      KeyNavigation.right: emailField
//      KeyNavigation.left: loginField

//      Keys.onReturnPressed: emailField.forceActiveFocus()
    }


    Rendall.InputField {
      id: emailField

      labelText: qsTr("Email")
//      //      text: account.email
//      inputMethodHints: Qt.ImhEmailCharactersOnly

//      KeyNavigation.up: passwordField
//      KeyNavigation.down: uriField
//      KeyNavigation.right: uriField
//      KeyNavigation.left: passwordField

//      Keys.onReturnPressed: uriField.forceActiveFocus()
    }


    Rendall.InputField {
      id: uriField

      labelText: qsTr("Ресурс")
//      //      text: account.uri
//      inputMethodHints: Qt.ImhUrlCharactersOnly

//      KeyNavigation.up: emailField
//      KeyNavigation.down: commentField
//      KeyNavigation.right: commentField
//      KeyNavigation.left: emailField

//      Keys.onReturnPressed: commentField.forceActiveFocus()
    }


    Rendall.InputArea {
      id: commentField

      labelText: qsTr("Коментарий")
//      //      text: account.comment
    }
  }


  function getNode()
  {
    return node;
  }


  function view2data(node)
  {
    node.name = nameField.text
    node.login = loginField.text
    node.password = passwordField.text
    node.email = emailField.text
    node.uri = uriField.text
    node.comment = commentField.text
  }


  function data2view()
  {
    nameField.text = node.name
    loginField.text = node.login
    passwordField.text = node.password
    emailField.text = node.email
    uriField.text = node.uri
    commentField.text = node.comment

    nameField.ensureVisible(0)
    loginField.ensureVisible(0)
    passwordField.ensureVisible(0)
    emailField.ensureVisible(0)
    uriField.ensureVisible(0)
  }


  function createNode()
  {
    return account
  }


  Account {
    id: account
  }


  function isEmpty()
  {
    return nameField.text === ""
  }

}
