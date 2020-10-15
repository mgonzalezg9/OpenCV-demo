#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <opencv2/opencv.hpp>
using namespace cv;

Mat img;
int radioPincel = 10;

void mousecb(int event, int x, int y, int flags, void * param)
{
    // Si pulsa el ratón añade un círculo
    if (flags == EVENT_FLAG_LBUTTON) {
        circle(img, Point(x, y), radioPincel, CV_RGB(255, 0, 0), -1);
        imshow("Imagen", img);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nombre = QFileDialog::getOpenFileName();
    if (!nombre.isNull()) {
        img = imread(nombre.toLatin1().data());
        if (!img.empty()) {
            namedWindow("Imagen", 0);
            imshow("Imagen", img);
            setMouseCallback("Imagen", mousecb);
        }
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    radioPincel = value;
}
