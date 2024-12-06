import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: _resultPage

    property string imagePath: ""

    signal goBack()

    width: parent.width
    height: parent.height

    ImageArea {
        id: _imageArea
        
        height: parent.height * 0.80
        imagePath: _resultPage.imagePath

        anchors {
            left: parent.left 
            right: parent.right
            bottom: parent.bottom
        }
    }

    TopBar {
        id: _topBar

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: _imageArea.top
        }

        onGoBackClicked: {
            goBack();
        }
    }
}
