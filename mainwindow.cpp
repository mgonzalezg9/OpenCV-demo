#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

#include <opencv2/opencv.hpp>
using namespace cv;

Mat img;

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
    img = imread(nombre.toLatin1().data());
    namedWindow("Imagen", 0);
    imshow("Imagen", img);

}
