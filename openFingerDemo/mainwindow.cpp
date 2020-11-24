#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<PREPROCESSING_ALL_RESULTS >("PREPROCESSING_ALL_RESULTS");
    connect(&p, SIGNAL(preprocessingDoneSignal(PREPROCESSING_ALL_RESULTS)), this, SLOT(preprocessingSlot(PREPROCESSING_ALL_RESULTS)));
    p.loadInput("/home/admin/Downloads/DB3_B/101_1.tif");
    p.setFeatures(true);
    //p.setCPUOnly(true);
    p.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::preprocessingSlot(PREPROCESSING_ALL_RESULTS res)
{
    //cv::imshow("name", res.imgOrientationMap);
    //std::cout << res.orientationMap;
    std::cout << res.orientationMap.rows;
    std::cout << res.orientationMap.cols;
}
