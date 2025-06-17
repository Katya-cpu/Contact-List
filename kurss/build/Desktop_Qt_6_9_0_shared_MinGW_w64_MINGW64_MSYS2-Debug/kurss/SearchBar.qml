import QtQuick
import QtQuick.Controls

TextField {
    id: searchField
    placeholderText: qsTr("Поиск контактов...")
    font.pixelSize: 14
    padding: 10

    background: Rectangle {
        color: "#f5f5f5"
        radius: 8
        border.color: searchField.activeFocus ? "#4a90e2" : "#cccccc"
        border.width: 1
    }
}
