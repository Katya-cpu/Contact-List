import QtQuick
import QtQuick.Controls

Dialog {
    id: dialog

    signal finished(string fullName, string address, string city, string number,
                   string workPhone, string homePhone, string email, string birthDate, string photo)




    function createContact() {
        form.fullName.clear();
        form.address.clear();
        form.city.clear();
        form.number.clear();
        form.workPhone.clear();
        form.homePhone.clear();
        form.email.clear();
        form.birthDate.clear();
        form.photo = ""

        dialog.title = qsTr("Добавить новый контакт");
        dialog.open();

    }

    function editContact(contact) {
        form.fullName.text = contact.fullName;
        form.address.text = contact.address;
        form.city.text = contact.city;
        form.number.text = contact.number;
        form.workPhone.text = contact.workPhone;
        form.homePhone.text = contact.homePhone;
        form.email.text = contact.email;
        form.birthDate.text = contact.birthDate;
        form.photo = contact.photo


        dialog.title = qsTr("Edit Contact");
        dialog.open();
    }

    x: parent.width / 2 - width / 2
    y: parent.height / 2 - height / 2

    focus: true
    modal: true
    title: qsTr("Добавить новый контакт")
    footer: Row {
        spacing: 10
        padding: 10
        Button {
            text: qsTr("Отмена")
            onClicked: dialog.close()
        }
        Button {
            text: qsTr("Сохранить")
            onClicked: {
                if (form.validate()) {
                    dialog.finished(
                        form.fullName.text, form.address.text, form.city.text, form.number.text,
                        form.workPhone.text, form.homePhone.text, form.email.text, form.birthDate.text, form.photo
                    );
                    dialog.close();
                }
            }
        }
    }

    contentItem: ContactForm {
        id: form
    }

}
