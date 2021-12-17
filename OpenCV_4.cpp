#include <iostream>
#include <fstream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Определим режим сшивания как панорома
Stitcher::Mode mode = Stitcher::PANORAMA;

// Массив для картинок
vector<Mat> images;

int main(int argc, char* argv[])
{
    // Получить все изображения, которые должны быть
    // сшиты как аргументы из командной строки
    for (int i = 1; i < argc; ++i)
    {
        Mat images = imread(argv[i]);
        if (images.empty())
        {
            cout << "Can't read image '" << argv[i] << "'\n";
            cin.get();
            return -1;
        }
        images.push_back(img);
    }
   
    // Определяем объект для хранения сшитого изображения
    Mat pano;

    // Создание объекта класса Stitcher с режимом панорома
    Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA);

    // Команда для сшивания всех изображений, присутствующих в массиве изображений
    Stitcher::Status status = stitcher->stitch(images, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images\n";
        return -1;
    }

    namedWindow("Panorama_image");
    imshow("Panorama_image", pano);
    // Сохраняем новое изображение, сшитое из заданных
    imwrite("Panorama_image.jpg", pano);
    waitKey(0);
    
    return 0;

}
