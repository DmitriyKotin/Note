﻿import QtQuick 2.12
import QtQuick.Controls 2.12


Rectangle {

  color: "red"
  property alias text: label.text

  Label {
    id: label

    text: "Поиск"
    anchors.centerIn: parent
  }
}
