import QtQuick 2.12


Item {
  id: item

  property color primaryColor
  property color backgroundColor

  anchors.left: parent.left
  anchors.right: parent.right

  Rectangle {
    id: background

    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom

    height: 1
    color: backgroundColor
  }

  Rectangle {
    id: indicator

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    height: 2
    color: primaryColor

    Behavior on width {
      NumberAnimation {duration: 75}
    }
  }

  states: [
    State {name: "Open"
      PropertyChanges {target: background; visible: true}
      PropertyChanges {target: indicator; width: item.width}
    },
    State {name: "Close"
      PropertyChanges {target: background; visible: true}
      PropertyChanges {target: indicator; width: 0}
    },
    State {name: "Disable"
      PropertyChanges {target: background; visible: false}
      PropertyChanges {target: indicator; width: 0}
    }
  ]

}
