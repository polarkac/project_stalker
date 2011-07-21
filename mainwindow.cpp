#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    someNumber = 100;
    bEnd = FALSE;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(25);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);
    QImage *image = new QImage(":/images/online");
    QLine *line = new QLine(0, 0, someNumber, 100);
    painter->drawImage(someNumber, 100, *image);
    painter->drawLine(*line);

    if(image->width()+someNumber >= 1024)
        bEnd = TRUE;
    else if(someNumber <= 0)
        bEnd = FALSE;

    switch(bEnd)
    {
    case TRUE:
        someNumber -= 5; break;
    case FALSE:
        someNumber += 5; break;
    }

    delete painter;
    delete image;
    delete line;
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
    // dont change screen resolution so there is rectangle with app size
    /* case Qt::Key_F11:
        setWindowState(windowState() ^ Qt::WindowFullScreen); break; */
    case Qt::Key_F1:
        QMessageBox::information(this, "Help", "Play game"); break;
    case Qt::Key_Escape:
        close(); break;
    default:
        break;
    }
}

