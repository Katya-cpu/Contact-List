import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: window

    property int currentContact: -1

    ContactDialog {
        id: contactDialog
        onFinished: function(fullName, address, city, number, workPhone, homePhone, email, birthDate, photo) {
            if (window.currentContact === -1)
                contactView.model.append(fullName, address, city, number, workPhone, homePhone, email, birthDate, photo)
            else
                contactView.model.set(window.currentContact, fullName, address, city, number, workPhone, homePhone, email, birthDate, photo)
        }
    }

    Menu {
        id: contactMenu
        x: parent.width / 2 - width / 2
        y: parent.height / 2 - height / 2
        modal: true

        Label {
            padding: 10
            font.bold: true
            width: parent.width
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            text: window.currentContact >= 0 ? contactView.model.get(window.currentContact).fullName : ""
        }
        MenuItem {
            text: qsTr("Изменить контакт")
            onTriggered: contactDialog.editContact(contactView.model.get(window.currentContact))
        }
        MenuItem {
            text: qsTr("Удалить контакт")
            onTriggered: contactView.model.remove(window.currentContact)
        }
    }

    ContactView {
        id: contactView
        anchors.fill: parent
        onPressAndHold: function(index) {
            window.currentContact = index
            contactMenu.open()
        }
    }

    RoundButton {
        text: qsTr("+")
        highlighted: true
        anchors.margins: 10
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: {
            window.currentContact = -1
            contactDialog.createContact()
        }
    }
}
