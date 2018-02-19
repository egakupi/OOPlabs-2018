#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "polinom.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        connect(ui->pushButtonValue, SIGNAL(pressed()), this, SLOT(value()));
        connect(ui->pushButtonRoot, SIGNAL(pressed()), this, SLOT(roots()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::value() {
    Polinom p(ui->lineEdit->text().toDouble(), ui->lineEdit_2->text().toDouble(), ui->lineEdit_3->text().toDouble());
    number num4 = p.value(ui->lineEdit_4->text().toDouble());
    ui->valueResult->setText(QString().setNum(num4));
}

int MainWindow::roots() {
    number nums[2];
    Polinom p(ui->lineEdit->text().toDouble(), ui->lineEdit_2->text().toDouble(), ui->lineEdit_3->text().toDouble());
    int count = p.roots(nums);
    if (count == 2) {
        ui->labelRoot1->setText(QString().setNum(nums[0]));
        ui->labelRoot2->setText(QString().setNum(nums[1]));
    } else if (count == 1) {
        ui->labelRoot1->setText((QString().setNum(nums[0])));
        ui->labelRoot2->setText("");
    } else {
        ui->labelRoot1->setText("NaN");
        ui->labelRoot2->setText("NaN");
    }
    return count;
}
