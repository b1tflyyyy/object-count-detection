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
                let item = _resultComp.createObject(_stackView, { imagePath: path });
                _stackView.push(item);
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