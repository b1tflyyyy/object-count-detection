import QtQuick 2.15

Rectangle {
    id: _topBar

    signal goBackClicked()

    Image {
        id: _goBack

        anchors {
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: 20
        }

        fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/turn-back.png"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
            onClicked: {
                console.log("go back clicked");
                goBackClicked();
            }
        }
    }

    Text {
        id: _calcText

        anchors {
            verticalCenter: parent.verticalCenter
            left: _goBack.right
            leftMargin: 100
        }

        font {
            pointSize: 22
            bold: true 
        }

        text: qsTr("Calculate objects count ->")
    }

    Image {
        id: _calcImage

        anchors {
            verticalCenter: parent.verticalCenter
            left: _calcText.right
            leftMargin: 10
        }

        fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/calc.png"

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
            onClicked: {
                objectCountController.Calculate_Objects_Count();
                console.log("calc clicked");
            }
        }
    }
}