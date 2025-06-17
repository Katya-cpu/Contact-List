import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

GridLayout {
    id: grid
    property alias fullName: fullName
    property alias address: address
    property alias city: city
    property alias number: number
    property alias workPhone: workPhone
    property alias homePhone: homePhone
    property alias email: email
    property alias birthDate: birthDate
    property alias photo: photoPath.text
    property int minimumInputSize: 180
    property string placeholderText: qsTr("Введите данные...")

    function reset() {
            fullName.text = ""
            address.text = ""
            city.text = ""
            number.text = ""
            workPhone.text = ""
            homePhone.text = ""
            email.text = ""
            birthDate.text = ""
            photo = ""
            resetValidation()
        }

        function resetValidation() {
            fullName.error = false
            number.error = false
            fullName.placeholderText = placeholderText
            number.placeholderText = placeholderText
        }

    rows: 8
    columns: 2
    columnSpacing: 15
    rowSpacing: 12

    Label {
        id: labelStyle
        font.pixelSize: 14
        color: "#555555"
        visible: false
    }

    TextField {
        id: fieldStyle
        font.pixelSize: 14
        padding: 8
        background: Rectangle {
            color: "#f5f5f5"
            border.color: "#cccccc"
            border.width: 1
            radius: 4
        }
        visible: false
    }

    FileDialog {
            id: photoDialog
            title: qsTr("Выберите фото")
            nameFilters: ["Images (*.png *.jpg *.jpeg *.bmp)"]
            onAccepted: {
                photoPath.text = selectedFile
            }
        }

    Label {
        text: qsTr("Фотография:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

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
        Button {
            text: qsTr("Выбрать фото")
            onClicked: photoDialog.open()
        }

        TextField {
            id: photoPath
            visible: false
        }
    }

    Label {
        text: qsTr("Полное имя (обязательно):")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: fullName
        property bool error: false

        focus: true
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: fullName.error ? "red" : (fullName.activeFocus ? "#4a90e2" : fieldStyle.background.border.color)
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        validator: RegularExpressionValidator {
                regularExpression: /^[а-яА-ЯёЁa-zA-Z\s]+$/ // Только буквы и пробелы
            }
    }

    Label {
        text: qsTr("Адрес:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: address
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: address.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
    }

    Label {
        text: qsTr("Город:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: city
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: city.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
    }

    Label {
        text: qsTr("Номер телефона (обязательно):")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: number
        property bool error: false
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: number.error ? "red" : (number.activeFocus ? "#4a90e2" : fieldStyle.background.border.color)
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        inputMethodHints: Qt.ImhDialableCharactersOnly  // Подсказка для клавиатуры
        validator: RegularExpressionValidator {
                regularExpression: /^[\d\s\(\)\-+]*$/ // Только цифры и символы телефона
            }
            onTextChanged: {
                // Форматирование телефона
                var digits = text.replace(/\D/g, '');
                var formatted = '';

                if (digits.length > 0) {
                    // Если первая цифра не 8, добавляем 8
                    if (digits.charAt(0) !== '8' && digits.charAt(0) !== '7') {
                        digits = '8' + digits;
                    }

                    // Ограничиваем длину 11 цифрами
                    digits = digits.substring(0, 11);

                    // Форматируем по маске 8 (XXX) XXX-XX-XX
                    formatted = digits.charAt(0) + ' (';

                    if (digits.length > 1) {
                        formatted += digits.substring(1, 4);
                    }
                    if (digits.length > 4) {
                        formatted += ') ' + digits.substring(4, 7);
                    }
                    if (digits.length > 7) {
                        formatted += '-' + digits.substring(7, 9);
                    }
                    if (digits.length > 9) {
                        formatted += '-' + digits.substring(9, 11);
                    }
                }

                if (formatted !== text) {
                    text = formatted;
                }
            }

    }

    Label {
        text: qsTr("Рабочий телефон:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: workPhone
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: workPhone.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        inputMethodHints: Qt.ImhDialableCharactersOnly
        validator: RegularExpressionValidator {
                regularExpression: /^[\d\s\(\)\-+]*$/ // Только цифры и символы телефона
            }
            onTextChanged: {
                // Аналогичное форматирование как для number
                var digits = text.replace(/\D/g, '');
                var formatted = '';

                if (digits.length > 0) {
                    if (digits.charAt(0) !== '8' && digits.charAt(0) !== '7') {
                        digits = '8' + digits;
                    }

                    digits = digits.substring(0, 11);
                    formatted = digits.charAt(0) + ' (';

                    if (digits.length > 1) {
                        formatted += digits.substring(1, 4);
                    }
                    if (digits.length > 4) {
                        formatted += ') ' + digits.substring(4, 7);
                    }
                    if (digits.length > 7) {
                        formatted += '-' + digits.substring(7, 9);
                    }
                    if (digits.length > 9) {
                        formatted += '-' + digits.substring(9, 11);
                    }
                }

                if (formatted !== text) {
                    text = formatted;
                }
            }
    }

    Label {
        text: qsTr("Домашний телефон:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: homePhone
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: homePhone.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        inputMethodHints: Qt.ImhDialableCharactersOnly
        validator: RegularExpressionValidator {
                regularExpression: /^[\d\s\(\)\-+]*$/ // Только цифры и символы телефона
            }
            onTextChanged: {
                // Аналогичное форматирование как для number
                var digits = text.replace(/\D/g, '');
                var formatted = '';

                if (digits.length > 0) {
                    if (digits.charAt(0) !== '8' && digits.charAt(0) !== '7') {
                        digits = '8' + digits;
                    }

                    digits = digits.substring(0, 11);
                    formatted = digits.charAt(0) + ' (';

                    if (digits.length > 1) {
                        formatted += digits.substring(1, 4);
                    }
                    if (digits.length > 4) {
                        formatted += ') ' + digits.substring(4, 7);
                    }
                    if (digits.length > 7) {
                        formatted += '-' + digits.substring(7, 9);
                    }
                    if (digits.length > 9) {
                        formatted += '-' + digits.substring(9, 11);
                    }
                }

                if (formatted !== text) {
                    text = formatted;
                }
            }
    }

    Label {
        text: qsTr("Электронная почта:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: email
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: grid.placeholderText
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: email.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        inputMethodHints: Qt.ImhEmailCharactersOnly
    }

    Label {
        text: qsTr("Дата рождения:")
        Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
        font: labelStyle.font
        color: labelStyle.color
    }

    TextField {
        id: birthDate
        Layout.fillWidth: true
        Layout.minimumWidth: grid.minimumInputSize
        placeholderText: qsTr("дд.мм.гггг")
        font: fieldStyle.font
        background: Rectangle {
            color: fieldStyle.background.color
            border.color: birthDate.activeFocus ? "#4a90e2" : fieldStyle.background.border.color
            border.width: fieldStyle.background.border.width
            radius: fieldStyle.background.radius
        }
        inputMethodHints: Qt.ImhDate
        validator: RegularExpressionValidator {
                regularExpression: /^(\d{0,2})(\.?)(\d{0,2})(\.?)(\d{0,4})$/ // Формат даты
            }
            onTextChanged: {
                // Форматирование даты
                var digits = text.replace(/\D/g, '');
                var formatted = '';

                if (digits.length > 0) {
                    formatted = digits.substring(0, 2);
                    if (digits.length > 2) {
                        formatted += '.' + digits.substring(2, 4);
                        if (digits.length > 4) {
                            formatted += '.' + digits.substring(4, 8);
                        }
                    }
                }

                if (formatted !== text) {
                    text = formatted;
                }
            }
    }
    function validate() {
        var nameValid = fullName.text.trim() !== "";
        var phoneValid = number.text.trim() !== "";

        fullName.error = !nameValid;
        number.error = !phoneValid;

        return nameValid && phoneValid;
    }

}
