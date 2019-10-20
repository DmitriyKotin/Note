import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12


TextArea {
  id: control

  width: 280
  height: 72

  state: "Inactive"

  onTextChanged: {
    var line = text.split('\n').length
    height = 72 + fontMetric.lineSpacing * (line - 1)
  }

  property string labelText : "label"
  property string helpText : "help"
  property string errorText : "error"
  property string emptyText

  property bool emptyValidate: false
  property var emptyValidateFunction: function(text) {
    if (!emptyValidate)
      return false
    return text.length === 0
  }

  property var validateFunction: function(text) {return true}

  property int fontMainSize: 16
  property int fontHelpSize: 12

  property color primaryColor: Material.accent
  property color fontColor: Material.foreground
  property color errorColor: Material.color(Material.Red, Material.Shade500)

  background: Item {
    Rectangle {
      id: background

      anchors.left: parent.left
      anchors.right: parent.right
      anchors.top: parent.top
      height: parent.height - 16

      color: control.primaryColor
      opacity: 0.12
    }

    Indicator {
      id: indicator

      anchors.bottom: parent.bottom
      anchors.bottomMargin: 16

      primaryColor: control.primaryColor
      backgroundColor: control.fontColor
    }
  }


  Text {
    id: label

    anchors.left: parent.left
    anchors.leftMargin: parent.leftPadding
    anchors.baseline: parent.top
    renderType: Text.NativeRendering

    Behavior on anchors.baselineOffset {
      NumberAnimation {duration: 125}
    }

    Behavior on font.pixelSize {
      NumberAnimation {duration: 125}
    }
  }


  Text {
    id: help

    anchors.left: parent.left
    anchors.leftMargin: parent.leftPadding
    anchors.baseline: parent.bottom
    renderType: Text.NativeRendering
    font.pixelSize: fontHelpSize
    opacity: 0.5
  }


  function isEmpty()
  {
    return text.length === 0
  }


  leftPadding: 12
  rightPadding: 12
  topPadding: 24
  selectByMouse: true
  mouseSelectionMode: TextInput.SelectWords
  renderType: Text.NativeRendering
  font.pixelSize: fontMainSize


  onActiveFocusChanged: {
    if (activeFocus) {
      state = "Focused"
    }
    else {
      if (emptyValidateFunction(text)) {
        state = "EmptyError"
        return
      }
      else if (!validateFunction(text)) {
        state = "ValidateError"
        return
      }
      else {
        state = "Inactive"
      }
    }
  }


  states: [
    State {name: "Inactive"
      PropertyChanges {target: indicator; state: "Close"}
      PropertyChanges {target: label; anchors.baselineOffset: isEmpty() ? control.height / 2 : 21}
      PropertyChanges {target: label; font.pixelSize: isEmpty() ? fontMainSize : fontHelpSize}
      PropertyChanges {target: label; opacity: 0.5}
      PropertyChanges {target: label; color: fontColor}
      PropertyChanges {target: label; text: labelText}
      PropertyChanges {target: control; opacity: 1.0}
      PropertyChanges {target: help; text: helpText}
      PropertyChanges {target: help; color: fontColor}
      PropertyChanges {target: background; color: primaryColor}
    },
    State {name: "Focused"
      PropertyChanges {target: indicator; state: "Open"}
      PropertyChanges {target: label; anchors.baselineOffset: 21}
      PropertyChanges {target: label; font.pixelSize: fontHelpSize}
      PropertyChanges {target: label; opacity: 1.0}
      PropertyChanges {target: label; color: primaryColor}
      PropertyChanges {target: label; text: labelText}
      PropertyChanges {target: control; opacity: 1.0}
      PropertyChanges {target: help; text: helpText}
      PropertyChanges {target: help; color: fontColor}
      PropertyChanges {target: background; color: primaryColor}
    },
    State {name: "EmptyError"
      PropertyChanges {target: indicator; state: "Close"}
      PropertyChanges {target: label; anchors.baselineOffset: 21}
      PropertyChanges {target: label; font.pixelSize: fontHelpSize}
      PropertyChanges {target: label; opacity: 1.0}
      PropertyChanges {target: label; color: errorColor}
      PropertyChanges {target: label; text: labelText + "*"}
      PropertyChanges {target: control; opacity: 1.0}
      PropertyChanges {target: help; text: emptyText}
      PropertyChanges {target: help; color: errorColor}
      PropertyChanges {target: background; color: errorColor}
    },
    State {name: "ValidateError"
      PropertyChanges {target: indicator; state: "Close"}
      PropertyChanges {target: label; anchors.baselineOffset: 21}
      PropertyChanges {target: label; font.pixelSize: fontHelpSize}
      PropertyChanges {target: label; opacity: 1.0}
      PropertyChanges {target: label; color: errorColor}
      PropertyChanges {target: label; text: labelText + "*"}
      PropertyChanges {target: control; opacity: 1.0}
      PropertyChanges {target: help; text: errorText}
      PropertyChanges {target: help; color: errorColor}
      PropertyChanges {target: background; color: errorColor}
    },
    State {name: "Disabled"
      PropertyChanges {target: indicator; state: "Disable"}
      PropertyChanges {target: label; anchors.baselineOffset: 21}
      PropertyChanges {target: label; font.pixelSize: fontHelpSize}
      PropertyChanges {target: label; opacity: 0.7}
      PropertyChanges {target: label; color: fontColor}
      PropertyChanges {target: label; text: labelText}
      PropertyChanges {target: control; opacity: 0.32}
      PropertyChanges {target: help; text: helpText}
      PropertyChanges {target: help; color: fontColor}
      PropertyChanges {target: background; color: primaryColor}
    }
  ]


  FontMetrics {
    id: fontMetric

    font: control.font
  }

}
