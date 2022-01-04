/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*--------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    opt=0;
    ui->setupUi(this);
    ready=false;
    apic = new ATARIpic;
    qimage = new QImage(apic->width,apic->height,QImage::Format_RGB32);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,apic->width,apic->height);
    paintImage();
}
/*--------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
    delete scene;
    delete qimage;
    delete apic;
    delete ui;
}
/*--------------------------------------------------------------------*/
void MainWindow::on_pushButton_Exit_clicked()
{
    this->close();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_pushButton_Load_clicked()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this, tr("Open JPG"), "", tr("JPG Files (*.jpg)"));
    if (filename.length()>0)
    {
        QImage image(filename);
        QImage scaled=image.scaled(320,240, Qt::IgnoreAspectRatio);
        for (int y=0; y<240; y++)
        {
            for (int x=0; x<320; x++)
            {
                pic[y*320+x]=scaled.pixel(x,y);
            };
        };
        apic->copy(pic);
        ready=true;
        preview();
    };
}
/*--------------------------------------------------------------------*/
void MainWindow::on_pushButton_Save_clicked()
{
    QString filename;
    filename=QFileDialog::getSaveFileName(this, tr("Save ASM"), "", tr("ASM Files (*.asm)"));
    if (filename.length()>0)
    {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream outdata(&file);
            apic->saveASM(outdata);
            file.close();
        };
    };
}
/*--------------------------------------------------------------------*/
void MainWindow::on_pushButton_Compile_clicked()
{
    QString filename;
    filename=QFileDialog::getSaveFileName(this, tr("Save XEX"), "", tr("XEX Files (*.xex)"));
    if (filename.length()>0)
    {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly))
        {
            QDataStream outdata(&file);
            apic->saveXEX(outdata);
            file.close();
        };
    };
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_1_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_2_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_3_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_4_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_5_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_6_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_radioButton_7_clicked()
{
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::preview()
{
    if (ui->radioButton_1->isChecked()) {opt=0;} else
        if (ui->radioButton_2->isChecked()) {opt=1;} else
            if (ui->radioButton_3->isChecked()) {opt=2;} else
                if (ui->radioButton_4->isChecked()) {opt=3;} else
                    if (ui->radioButton_5->isChecked()) {opt=4;} else
                        if (ui->radioButton_6->isChecked()) {opt=5;} else
                            if (ui->radioButton_7->isChecked()) {opt=6;};
    ui->pushButton_Save->setEnabled(ready);
    ui->pushButton_Compile->setEnabled(ready);
    paintImage();
}
/*--------------------------------------------------------------------*/
void MainWindow::paintImage()
{
    quint32 x,y;
    for (y=0; y<apic->height; y++)
    {
        int *p=(int *)(qimage->scanLine(y));
        for (x=0; x<apic->width; x++)
        {
            quint32 c=apic->getPixel(x,y,opt);
            p[x]=(c|0xFF000000);
        };
    };
    scene->addPixmap(QPixmap::fromImage(*qimage));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_horizontalSlider_1_valueChanged(int value)
{
    qreal v=value;
    apic->newSaturation(v);
    if (ready)
    {
        apic->letsGo();
    }
    else
    {
        apic->Demo();
    };
    preview();
}
/*--------------------------------------------------------------------*/
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    qreal v=value;
    apic->newThreshold(v);
    if (ready)
    {
        apic->letsGo();
    }
    else
    {
        apic->Demo();
    };
    preview();
}
/*--------------------------------------------------------------------*/
