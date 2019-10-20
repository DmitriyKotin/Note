import QtQuick 2.12


Text {
  font.family: regularFont.name
  renderType: Text.NativeRendering

  elide: Text.ElideRight

  FontLoader {
    id: regularFont
    source: "qrc:/font/OpenSans-Regular.ttf"
  }
}
