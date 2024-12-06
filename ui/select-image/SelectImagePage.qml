import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs

Rectangle {
    id: _selectImagePage

    signal imageSelected(string path)

    width: parent.width
    height: parent.height

    FileDialog {
        id: _fileDialog

        onAccepted: {
            objectCountController.Read_Image(selectedFile);
            imageSelected(selectedFile);
        }
    }

    Image {
        id: _mainBackground

        width: parent.width
        height: parent.height
        
        source: "qrc:/assets/main-background.jpg"
    }

    Image {
        id: _selectImageIcon

        anchors {
            left: _text.left
            top: _text.bottom
            topMargin: 40
        }

        width: _text.width
        fillMode: Image.PreserveAspectFit

        source: "qrc:/assets/select-image.png"

        MouseArea {
            anchors.fill: parent
            cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor

            hoverEnabled: true

            onClicked: {
                _fileDialog.open();
            }
        }
    }

    Text {
        id: _text

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top 
            topMargin: 100
        }

        font {
            pointSize: 24
            bold: true
        }

        color: "black"

        text: qsTr("Select your image...")
    }
}