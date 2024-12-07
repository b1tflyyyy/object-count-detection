import QtQuick 2.15
import QtQuick.Controls 2.15

import "../select-image"
import "../result-page"

StackView {
    id: _stackView

    anchors.fill: parent
    initialItem: _mainComp

    Component {
        id: _mainComp

        SelectImagePage {
            id: _selectImage

            onImageSelected: function(path) {
                _stackView.push(_resultComp, { imagePath: path, height: _stackView.height, width: _stackView.width });
            }
        }
    }

    Component {
        id: _resultComp

        ResultPage {
            id: _resultPage

            onGoBack: {
                _stackView.pop();
            }
        }
    }
}