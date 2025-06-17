import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Shapes 1.15

ItemDelegate {
    id: delegate
    checkable: true

    property bool expanded: checked
    property color colorText: "#5e5e5e"

    required property string fullName
    required property string address
    required property string city
    required property string number
    required property string workPhone
    required property string homePhone
    required property string email
    required property string birthDate
    required property string photo

    background: Rectangle {
        color: delegate.down ? Qt.lighter("#f2e9e4", 1.1) :
               delegate.hovered ? "#f2e9e4" : "transparent"
        radius: 12
        Behavior on color { ColorAnimation { duration: 200 } }
    }

    contentItem: Column {
        spacing: 10

        Row {
                    spacing: 10
                    width: parent.width

                    Rectangle {
                        width: 40
                        height: 40
                        radius: 20
                        border.color: "#cccccc"
                        border.width: 1

                        Image {
                            anchors.fill: parent
                            source: photo.length > 0 ? photo : "qrc:/kurss/default-avatar.png"
                            fillMode: Image.PreserveAspectCrop
                            clip: true
                        }
                    }

            Text {
                text: fullName
                font {
                    family: "Montserrat"
                    weight: Font.Medium
                    pixelSize: 18
                    letterSpacing: 0.5
                }
                color: colorText
                verticalAlignment: Text.AlignVCenter
                height: 40
            }
        }

        Column {
            id: details
            width: parent.width
            spacing: 8
            opacity: expanded ? 1 : 0
            visible: opacity > 0
            height: expanded ? implicitHeight : 0

            Behavior on opacity { NumberAnimation { duration: 200 } }
            Behavior on height { NumberAnimation { duration: 200 } }

            Repeater {
                model: [
                    { icon: "📍", value: address },
                    { icon: "🏙️", value: city },
                    { icon: "📞", value: number },
                    { icon: "🏢", value: workPhone },
                    { icon: "🏠", value: homePhone },
                    { icon: "✉️", value: email },
                    { icon: "🎂", value: birthDate }
                ]

                Row {
                    spacing: 12
                    visible: modelData.value && modelData.value.length > 0
                    Text {
                        text: modelData.icon
                        font.pixelSize: 16
                    }
                    Text {
                        text: modelData.value
                        font.pixelSize: 14
                        color: colorText
                    }
                }
            }
        }
    }

}
