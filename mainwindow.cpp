#include "mainwindow.h"
#include "ui_mainwindow.h"

CScene *scene = NULL;
CStalker *hero = NULL;
CItem *items = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new CScene;
    hero = new CStalker;
    items = new CItem[10];
    int iCounter = 0;
    items[iCounter++].SetItem(":/images/chest", 0, 380, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 200, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 250, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 300, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 350, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 400, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 450, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 500, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 550, 3);
    items[iCounter++].SetItem(":/images/chest", 0, 600, 3);

    ui->graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
}


MainWindow::~MainWindow()
{
    delete items;
    delete hero;
    delete scene;
    delete ui;
}
