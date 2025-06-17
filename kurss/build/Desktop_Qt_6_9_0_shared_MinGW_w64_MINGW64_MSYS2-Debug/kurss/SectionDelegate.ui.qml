import QtQuick
import QtQuick.Controls

ToolBar {
    id: background

    required property string section

    Label {
        id: label
        text: background.section
        anchors.fill: parent
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
    }
}
