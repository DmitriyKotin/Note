import QtQuick 2.12
import QtQuick.Controls 2.12


Menu {
  margins: 4

  signal createMemo()
  signal createAccount()
  signal createContact()
  signal createBankCard()
  signal openFolderDialog()

  MenuItem {
    text: qsTr("Аккаунт")
    font.pixelSize: 32
    icon.source: "qrc:/qml/image/account_small.png"
    onClicked: createAccount()
  }

  MenuItem {
    text: qsTr("Заметка")
    font.pixelSize: 32
    icon.source: "qrc:/qml/image/memo_small.png"
    onClicked: createMemo()
  }

  MenuItem {
    text: qsTr("Контакт")
    font.pixelSize: 32
    icon.source: "qrc:/qml/image/contact_small.png"
    onClicked: createContact()
  }

  MenuItem {
    text: qsTr("Банковская карта")
    font.pixelSize: 32
    icon.source: "qrc:/qml/image/bankcard_small.png"
    onClicked: createBankCard()
  }

  MenuSeparator {}

  MenuItem {
    text: qsTr("Новая папка")
    font.pixelSize: 32
    icon.source: "qrc:/qml/image/folder_small.png"
    onClicked: openFolderDialog()
  }

}
