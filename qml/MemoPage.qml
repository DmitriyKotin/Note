import Felgo 3.0
import QtQuick 2.12
//import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
import "./Rendall/Component" as Rendall

//import Rendall.Component 1.0
import rendall 1.0


BasePage {
  id: page

//  property Memo memo: Presenter.node

  title: isCreate ? qsTr("Новая заметка") : node.name
//  icon: memo.bigIcon


  Column {

    anchors.top: parent.top
    anchors.topMargin: 24
    spacing: 24

    anchors.horizontalCenter: parent.horizontalCenter

    Rendall.InputField {
      id: nameField

      labelText: qsTr("Название")
//      text: memo.name
      inputMethodHints: Qt.ImhPreferUppercase

//      KeyNavigation.up: commentField
//      KeyNavigation.down: commentField
//      KeyNavigation.right: commentField
//      KeyNavigation.left: commentField

//      Keys.onReturnPressed: commentField.forceActiveFocus()
    }


    Rendall.InputArea {
      id: commentField

      labelText: qsTr("Текст")
//      text: memo.comment
    }
  }


  function view2data(node)
   {
    node.name = nameField.text
    node.comment = commentField.text
  }


  function data2view()
  {
    nameField.text = node.name
    commentField.text = node.comment

    nameField.ensureVisible(0)
  }


  function createNode()
  {
    return memo
  }

  Memo {
    id: memo
  }

  function isEmpty()
  {
    return nameField.text === ""
  }

}
