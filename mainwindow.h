#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCursor>
#include "d_algorithm.h"
#include <QString>
#include "temp.h"
#include <QKeyEvent>
#include <QUrl>
#include <QtCore>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void keyPressEvent(QKeyEvent* event);


private slots:
    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_zeroButton_clicked();

    void on_leftBracketButton_clicked();

    void on_rightBracketButton_clicked();

    void on_dotButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_asteriskButton_clicked();

    void on_divisionButton_clicked();

    void on_equalButton_clicked();

    void on_cButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    Temp temp;
};
#endif // MAINWINDOW_H
