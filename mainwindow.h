/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*--------------------------------------------------------------------*/
#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
/*--------------------------------------------------------------------*/
#include "ataripic.h"
/*--------------------------------------------------------------------*/
namespace Ui {
class MainWindow;
}
/*--------------------------------------------------------------------*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ATARIpic *apic;
    QImage *qimage;
    QGraphicsScene *scene;
    quint8 opt;
    bool ready;
    quint32 pic[320*240];
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void preview();
    void paintImage();

private slots:
    void on_pushButton_Exit_clicked();
    void on_pushButton_Load_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_Compile_clicked();
    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_6_clicked();
    void on_radioButton_7_clicked();
    void on_horizontalSlider_1_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;

};
/*--------------------------------------------------------------------*/
#endif // MAINWINDOW_H
/*--------------------------------------------------------------------*/
