#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/rendi//Pictures/qt/gambar.png");
    ui->label_pic->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio));
	
	//option
    ui->comboBox->addItem("Delux");
    ui->comboBox->addItem("Family");
    ui->comboBox->addItem("Suite");
    ui->comboBox->addItem("VVIP");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int d, f, g, dis = 10;
    float h;
    float km_del = 500.000;
    QString a, name, c, combo, e, diskon;
    QString text = "Rp. ";

    //input
    name=ui->txt_nama->text();
    a=ui->txt_masuk->text();
    c=ui->lineEdit_4->text();
    d=ui->lineEdit_5->text().toInt();
    e=ui->lineEdit_6->text();
    f=ui->lineEdit_7->text().toInt();
    g=ui->lineEdit_8->text().toInt();
    diskon=ui->lineEdit_3->text();

    //output
    ui->lineEdit_2->setText(QString(name));
    ui->lineEdit_9->setText(QString(a));
    ui->lineEdit_10->setText(QString(c));
    ui->lineEdit_11->setText(QString::number(d));
    ui->lineEdit_12->setText(QString(e));
    ui->lineEdit_14->setText(QString::number(f));
    ui->lineEdit_15->setText(QString::number(g));

    //tampilan harga kamar
    combo=ui->comboBox->currentText();
    ui->lineEdit_16->setText(combo);
    if (combo == "Delux")(
        ui->lineEdit_16->setText("Rp. 500.000"));

    else if (combo == "Family")(
        ui->lineEdit_16->setText("Rp. 650.000"));

    else if (combo == "Suite")(
        ui->lineEdit_16->setText("Rp. 1.000.000"));

    else (ui->lineEdit_16->setText("Rp. 1.250.000"));

    //total harga
    if (combo == "Delux")(ui->lineEdit->setText(QString(text)+(QString::number(f*500000*g))));

    else if (combo == "Family")(ui->lineEdit->setText(QString(text)+(QString::number(f*650000*g))));

    else if (combo == "Suite")(ui->lineEdit->setText(QString(text)+(QString::number(f*100000*g))));

    else (ui->lineEdit->setText(QString(text)+(QString::number(f*1250000*g))));

    //diskon
    if (combo == "Delux" && diskon == "Ravia")(ui->lineEdit->setText(QString(text)+(QString::number(f*500000*g-f*500000*g*10/100))));

    else if (combo == "Family" && diskon == "Ravia")(ui->lineEdit->setText(QString(text)+(QString::number(f*650000*g-f*650000*g*10/100))));

    else if (combo == "Suite" && diskon == "Ravia")(ui->lineEdit->setText(QString(text)+(QString::number(f*1000000*g-f*1000000*g*10/100))));

    else if (combo == "VVIP" && diskon == "Ravia")(ui->lineEdit->setText(QString(text)+(QString::number(f*1250000*g-1250000*f*g*10/100))));

    //persen diskon
    if (diskon == "Ravia")(ui->lineEdit_13->setText(QString::number(dis)));


}

void MainWindow::on_pushButton_3_clicked()
{

}
