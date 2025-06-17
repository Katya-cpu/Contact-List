pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Controls
import contactlist

ListView {
    id: listView

    signal pressAndHold(int index)

    width: 320
    height: 480

    focus: true
    boundsBehavior: Flickable.StopAtBounds

    header: TextField {
        id: searchField
        width: listView.width
        placeholderText: qsTr("Поиск контактов...")
        onTextChanged: filterModel.searchTerm = text
        property string previousText: ""

    }
    Connections {
        target: filterModel
        function onSearchPerformance(nanoseconds) {
            const microseconds = nanoseconds / 1000;
            const milliseconds = microseconds / 1000;
            console.log(
                "Поиск '" + searchField.text + "' выполнен за:",
                nanoseconds + " нс",
                "(" + microseconds.toFixed(3) + " µs)",
                "Контаков:", filterModel.rowCount
            );
        }
    }

    section.property: "fullName"
    section.criteria: ViewSection.FirstCharacter
    section.delegate: SectionDelegate {
        width: listView.width
    }

    delegate: ContactDelegate {
        id: delegate
        width: listView.width

        required property int index

        onPressAndHold: listView.pressAndHold(index)
    }

    model: ContactFilterModel {
        id: filterModel
        source: ContactModel {}
    }

    ScrollBar.vertical: ScrollBar { }
}
