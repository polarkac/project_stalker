#include "mainwindow.h"
#include "ui_mainwindow.h"

CScene *scene;
CStalker *hero;
CItem *items;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new CScene(this);
    hero = new CStalker(scene);
    items = new CItem[5];
    //items[1].SetItem(":/images/chest", 80, 300, 3);
    items[2].SetItem(":/images/chest", 0, 380, 3);
    items[3].SetItem(":/images/chest", 0, 200, 3);

    ui->graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete items;
    delete hero;
    delete scene;
}
