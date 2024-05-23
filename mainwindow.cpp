#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , temp()

{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_oneButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("1");
}

void MainWindow::on_twoButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("2");
}

void MainWindow::on_threeButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("3");
}

void MainWindow::on_fourButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("4");
}

void MainWindow::on_fiveButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("5");
}

void MainWindow::on_sixButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("6");
}

void MainWindow::on_sevenButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("7");
}

void MainWindow::on_eightButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("8");
}

void MainWindow::on_nineButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("9");
}

void MainWindow::on_zeroButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("0");
}

void MainWindow::on_dotButton_clicked()
{

    ui->PlainTextEdit->insertPlainText(".");
}


void MainWindow::on_leftBracketButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("(");
}

void MainWindow::on_rightBracketButton_clicked()
{

    ui->PlainTextEdit->insertPlainText(")");
}



void MainWindow::on_plusButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("+");
}

void MainWindow::on_minusButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("-");
}

void MainWindow::on_asteriskButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("*");
}

void MainWindow::on_divisionButton_clicked()
{

    ui->PlainTextEdit->insertPlainText("/");
}

//UNIQUE BUTTONS
void MainWindow::on_equalButton_clicked()
{
    QString qstr = ui->PlainTextEdit->toPlainText();
    std::string str = qstr.toStdString();
    temp.newValue(str);
    D_Algorithm algorithm(str);
    std::string answer = algorithm.Calc();

    // Удаление лишних нулей из ответа
    std::string::size_type pos = answer.find_last_not_of('0');
    if (pos != std::string::npos) {
        if (answer[pos] == '.') {
            pos--;
        }
        answer = answer.substr(0, pos + 1);
    }
    if (answer == "inf"){
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=m4QO5jyEw2E&list=PLcUo0aMKmchgJ8hJQDPqaaMs82-tnQ1qW", QUrl::TolerantMode));
        ui->PlainTextEdit->setPlainText(":)");
        QTextCursor cursor = ui->PlainTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->PlainTextEdit->setTextCursor(cursor);
    }
    else {
        const QString stringAnswer = QString::fromStdString(answer);
        ui->PlainTextEdit->setPlainText(stringAnswer);
        QTextCursor cursor = ui->PlainTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->PlainTextEdit->setTextCursor(cursor);
    }
}

void MainWindow::on_cButton_clicked()
{
    temp.Clear();
    ui->PlainTextEdit->setPlainText("");
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Backspace) {
        MainWindow::on_deleteButton_clicked();
    }
    if (event->key() == Qt::Key_Return && (event->modifiers() & Qt::ControlModifier)) {
        on_equalButton_clicked();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QString qstr = ui->PlainTextEdit->toPlainText();
    std::string str = qstr.toStdString();


    // Check if the string is not empty
    if (!str.empty()) {
        // Delete the last character
        str.pop_back();
        temp.newValue(str);

        // Update the text in the QPlainTextEdit
        ui->PlainTextEdit->setPlainText(QString::fromStdString(str));

        // Move the cursor to the end of the text
        QTextCursor cursor = ui->PlainTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->PlainTextEdit->setTextCursor(cursor);
    }
}

