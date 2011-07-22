#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cstalker.h"

CStalker *hero;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    someNumber = 100;
    bEnd = FALSE;
    hero = new CStalker;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer, SIGNAL(timeout()), hero, SLOT(HandleJump()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *paint = new QPainter(this);
    paint->drawImage(hero->GetPosX(), hero->GetPosY(), hero->GetImage());

    delete paint;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{

    switch(event->key())
    {
    // dont change screen resolution so there is rectangle with app size
    /* case Qt::Key_F11:
        setWindowState(windowState() ^ Qt::WindowFullScreen); break; */
    case Qt::Key_F1:
		QMessageBox::information(this, "Help", "How to play this game."); break;
    case Qt::Key_Escape:
        close(); break;
    case Qt::Key_Left:
        hero->Walk(LEFT); break;
    case Qt::Key_Right:
        hero->Walk(RIGHT); break;
    case Qt::Key_Space:
        hero->Jump(); break;
    default:
        break;
    }
}

