// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDataStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toolButton_clicked();
    void toolButton_2_clicked();
    void toolButton_3_clicked();
    void toolButton_4_clicked();

private:
    Ui::MainWindow *ui;
    struct ButtonData {
        quint16 buttonID; //16 bitlik buttonıd
        quint8 counter;   //8 bitlik button id
    };
    ButtonData buttonData[4]; // Dört buton structure için veri yapısı
    QString fileName = "flash.bin"; // Dosya adı
    void saveToFile();
    void readFromFile();
};

#endif // MAINWINDOW_H
