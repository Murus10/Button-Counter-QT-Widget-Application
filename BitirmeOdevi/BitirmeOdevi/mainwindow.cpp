
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // -ButonID si 16 bit olacak.
    buttonData[0].buttonID = 0xF0B1;
    buttonData[1].buttonID = 0xF0B2;
    buttonData[2].buttonID = 0xF0B3;
    buttonData[3].buttonID = 0xF0B4;

    // Dosyadan okuma
    readFromFile();

    // Etiketlere değerleri yazma
    ui->label->setText(QString::number(buttonData[0].counter));
    ui->label_2->setText(QString::number(buttonData[1].counter));
    ui->label_3->setText(QString::number(buttonData[2].counter));
    ui->label_4->setText(QString::number(buttonData[3].counter));

    // Buton tıklama olaylarını bağlama
    connect(ui->toolButton, &QToolButton::clicked, this, &MainWindow::toolButton_clicked);
    connect(ui->toolButton_2, &QToolButton::clicked, this, &MainWindow::toolButton_2_clicked);
    connect(ui->toolButton_3, &QToolButton::clicked, this, &MainWindow::toolButton_3_clicked);
    connect(ui->toolButton_4, &QToolButton::clicked, this, &MainWindow::toolButton_4_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toolButton_clicked()
{
    buttonData[0].counter++;
    if (buttonData[0].counter == 255)
        buttonData[0].counter = 0;

    ui->label->setText(QString::number(buttonData[0].counter));
    saveToFile();
}

void MainWindow::toolButton_2_clicked()
{
    buttonData[1].counter++;
    if (buttonData[1].counter == 255)
        buttonData[1].counter = 0;

    ui->label_2->setText(QString::number(buttonData[1].counter));
    saveToFile();
}

void MainWindow::toolButton_3_clicked()
{
    buttonData[2].counter++;
    if (buttonData[2].counter == 255)
        buttonData[2].counter = 0;

    ui->label_3->setText(QString::number(buttonData[2].counter));
    saveToFile();
}

void MainWindow::toolButton_4_clicked()
{
    buttonData[3].counter++;
    if (buttonData[3].counter == 255)
        buttonData[3].counter = 0;

    ui->label_4->setText(QString::number(buttonData[3].counter));
    saveToFile();
}

//Dosya Save islemi
void MainWindow::saveToFile()
{

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        for (int i = 0; i < 4; ++i) {
            out << buttonData[i].buttonID << buttonData[i].counter;
        }
        file.close();
    } else {
        qDebug() << "Dosya açılamadı!";
    }

}
//Dosya Okuma
void MainWindow::readFromFile()
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        // Buton verilerini dosyadan oku
        for (int i = 0; i < 4; ++i) {
            in >> buttonData[i].buttonID >> buttonData[i].counter;
        }
        file.close();
    }
    else {
        qDebug() << "Dosya açılamadı!";
    }
}



