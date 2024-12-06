import QtQuick 2.15

Rectangle {
    id: _imageArea

    property string imagePath: ""

    Image {
        id: _image

        anchors.fill: parent
        source: _imageArea.imagePath
    }
}