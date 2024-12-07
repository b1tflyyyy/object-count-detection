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


#pragma once 

#include <algorithm>
#include <format>

#include <QObject>
#include <QDebug>
#include <QVector>
#include <QUrl>
#include <QPair>
#include <QStack>

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

class AObject_Count_Controller : public QObject
{
    Q_OBJECT

    Q_PROPERTY(std::size_t objectsCount READ Get_Objects_Count NOTIFY objectsCountChanged)

public:
    explicit AObject_Count_Controller(QObject* parent = nullptr);
    ~AObject_Count_Controller() noexcept override = default;

    Q_INVOKABLE void Read_Image(const QString& path);
    Q_INVOKABLE void Calculate_Objects_Count();

    std::size_t Get_Objects_Count() const noexcept;

signals:
    void objectsCountChanged(std::size_t count);

private:
    void DFS(std::ptrdiff_t y, std::ptrdiff_t x, const std::ptrdiff_t rows, const std::ptrdiff_t cols);

private:
    cv::Mat Image;
    QVector<QVector<bool>> Visited;
    
    std::size_t Objects_Count;
    static QVector<QPair<std::ptrdiff_t, std::ptrdiff_t>> Directions;
};