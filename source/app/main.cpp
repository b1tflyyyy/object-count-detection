// MIT License

// Copyright (c) 2024 @Who

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <object-count-controller.hpp>

int main(int argc, char** argv)
{
    QGuiApplication app{ argc, argv };
    QQmlApplicationEngine engine{};
    
    AObject_Count_Controller object_count_controller{};

    auto* ctx{ engine.rootContext() };

    ctx->setContextProperty("objectCountController", &object_count_controller);

    const QUrl& url{ QStringLiteral("qrc:/main-window/MainWindow.qml") };
    engine.load(url);

    return QGuiApplication::exec();
}