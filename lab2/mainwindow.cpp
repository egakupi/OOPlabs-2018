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
    Complex c1(ui->lineEdit->text().toDouble());
    Complex c2(ui->lineEdit_2->text().toDouble());
    Complex c3(ui->lineEdit_3->text().toDouble());
    Complex c4(ui->lineEdit_4->text().toDouble());
    Polinom p(c1, c2, c3);
    Complex num4 = p.value(c4);
    ui->valueResult->setText(num4.toString());
}

int MainWindow::roots() {
    Complex nums[2];
    Complex c1(ui->lineEdit->text().toDouble());
    Complex c2(ui->lineEdit_2->text().toDouble());
    Complex c3(ui->lineEdit_3->text().toDouble());
    Polinom p(c1, c2, c3);
    int count = p.roots(nums);
    if (count == 2) {
        ui->labelRoot1->setText(nums[0].toString());
        ui->labelRoot2->setText(nums[1].toString());
    } else if (count == 1) {
        ui->labelRoot1->setText(nums[0].toString());
        ui->labelRoot2->setText("");
    } else {
        ui->labelRoot1->setText("NaN");
        ui->labelRoot2->setText("NaN");
    }
    return count;
}
