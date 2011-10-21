#include "mainwindow.h"
#include "ui_mainwindow.h"

CScene *scene = NULL;
CStalker *hero = NULL;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cMap mapa;
    scene = new CScene;


    hero = new CStalker;
    ui->graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    if(mapa.loadMap(":/maps/testMap"))
        mapa.mapToScene();
    CItem item;
    item.SetItem(":/images/background", 0, 0, 1);
}


MainWindow::~MainWindow()
{
    delete hero;
    delete scene;
    delete ui;
}
