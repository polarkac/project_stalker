#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int someNumber;
    bool bEnd;

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
