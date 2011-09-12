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
    for(int a = 0; a < 10; a++)
        items[a].SetItem(":/images/chest", a*40, 372, 3);

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
