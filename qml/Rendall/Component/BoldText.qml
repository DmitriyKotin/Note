import QtQuick 2.12


Text {
  font.family: boldFont.name
  renderType: Text.NativeRendering

  elide: Text.ElideRight

  FontLoader {
    id: boldFont
    source: "qrc:/font/OpenSans-SemiBold.ttf"
  }
}
