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


#include "object-count-controller.hpp"

// ----------------------------------------------------------------------------------------------------------------
QVector<QPair<std::ptrdiff_t, std::ptrdiff_t>> AObject_Count_Controller::Directions 
{
    { -1, 0 }, // left
    { 1, 0 }, // right
    { 0, 1 }, // up
    { 0, -1 } // down
};

// ----------------------------------------------------------------------------------------------------------------
AObject_Count_Controller::AObject_Count_Controller(QObject* parent) :
    QObject{ parent }, Image{}, Visited{}, Objects_Count{}
{ }   

// ----------------------------------------------------------------------------------------------------------------
void AObject_Count_Controller::Read_Image(const QString& path)
{
    auto local_path{ QUrl(path).toLocalFile() };
    Image = cv::imread(local_path.toStdString(), cv::IMREAD_GRAYSCALE);

    CV_Assert(Image.type() == CV_8U);
    CV_Assert(Image.channels() == 1);
}

// ----------------------------------------------------------------------------------------------------------------
void AObject_Count_Controller::Calculate_Objects_Count()
{
    const auto rows{ Image.rows };
    const auto cols{ Image.cols };

    qDebug() << std::format("rows count: {}, cols count: {}", rows, cols);

    Visited.resize(rows);
    for (auto& row : Visited)
    {
        row.resize(cols);
        std::ranges::fill(std::ranges::begin(row), std::ranges::end(row), false);
    }

    std::size_t counter{};
    for (std::ptrdiff_t y{}; y < rows; ++y)
    {
        uchar* ptr{ Image.ptr(y) };
        for (std::ptrdiff_t x{}; x < cols; ++x)
        {
            if (ptr[x] < 100 && !Visited[y][x]) // < 100 (-> smth like black)
            {
                ++counter;
                DFS(y, x, rows, cols);
            }
        }
    }

    // TODO: handle visual 
    if (counter != Objects_Count)
    {
        Objects_Count = counter;

        qDebug() << "Objects count: " << counter;
        emit objectsCountChanged(Objects_Count);
    }
}

// ----------------------------------------------------------------------------------------------------------------
std::size_t AObject_Count_Controller::Get_Objects_Count() const noexcept
{
    return Objects_Count;
}

// ----------------------------------------------------------------------------------------------------------------
void AObject_Count_Controller::DFS(std::ptrdiff_t y, std::ptrdiff_t x, const std::ptrdiff_t rows, const std::ptrdiff_t cols)
{
    // TODO: remove recursion
    Visited[y][x] = true;

    for (const auto [dx, dy] : Directions)
    {
        const auto nx{ x + dx };
        const auto ny{ y + dy };

        if (nx >= 0 && nx < cols && ny >= 0 && ny < rows)
        {
            if (!Visited[ny][nx])
            {
                uchar* ptr{ Image.ptr(ny) };
                if (ptr[nx] < 100) // < 100 (-> smth like black)
                {
                    DFS(ny, nx, rows, cols);
                }
            }
        }
    }
}