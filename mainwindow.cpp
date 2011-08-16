#include "mainwindow.h"
#include "ui_mainwindow.h"

CStalker *hero;
CScene *scene;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hero = new CStalker;
    scene = new CScene;

    QGLWidget *ogl = new QGLWidget(QGLFormat(QGL::SampleBuffers));

    ui->graphicsView->setViewport(ogl);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 800, 600);

    scene->addItem(hero->GetImage());
}


MainWindow::~MainWindow()
{
    delete ui;
}
