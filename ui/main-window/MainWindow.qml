import QtQuick 2.15
import QtQuick.Window 2.15

import "../pages-controller"
import "../result-page"

Window {
    id: _mainWindow

    visible: true
    title: qsTr("Object Count Detection")

    width: Screen.width * 0.50
    height: Screen.height * 0.50

    minimumHeight: 400

    PagesController {
        id: _pagesController
    }
}