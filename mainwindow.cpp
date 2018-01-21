#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setGeometry(0,0,800,600);

    QImage img(":/images/food.jpeg");
//    img.invertPixels(QImage::InvertRgb);
//    img.fill(2);
//    QImage img2 = img.rgbSwapped();

    using namespace cv;
    Mat src = imread("/Users/lqlin/Desktop/QtProjects/FuzzyImage/images/food.jpeg");
    Mat GaussianBlur3;
    Mat GaussianBlur5;
    GaussianBlur(src, GaussianBlur3, Size(5,5), 0, 0);
    imshow("GaussianBlur3", GaussianBlur3);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
