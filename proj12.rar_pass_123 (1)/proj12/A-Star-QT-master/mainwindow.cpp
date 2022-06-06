#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    width = 0;
    height = 0;
    ui->start_x_box->setMinimum(1);
    ui->start_y_box->setMinimum(1);
    ui->goal_x_box->setMinimum(1);
    ui->goal_y_box->setMinimum(1);
    ui->width_box->setMaximum(100);
    ui->height_box->setMaximum(100);
    random = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_width_box_valueChanged(int arg1)
{
    width = arg1;
    ui->start_x_box->setMaximum(width - 2);
    ui->goal_x_box->setMaximum(width - 2);
}

void MainWindow::on_height_box_valueChanged(int arg1)
{
    height = arg1;
    ui->start_y_box->setMaximum(height - 2);
    ui->goal_y_box->setMaximum(height - 2);
}

void MainWindow::on_random_yes_pressed()
{
    random = true;

    ui->start_x_box->setEnabled(false);
    ui->start_y_box->setEnabled(false);

    ui->goal_x_box->setEnabled(false);
    ui->goal_y_box->setEnabled(false);
}

void MainWindow::on_random_no_pressed()
{
    random = false;
    ui->start_x_box->setEnabled(true);
    ui->start_y_box->setEnabled(true);
    ui->start_x_box->setMaximum(width - 2);
    ui->start_y_box->setMaximum(height - 2);
    ui->start_x_box->setMinimum(1);
    ui->start_y_box->setMinimum(1);

    ui->goal_x_box->setEnabled(true);
    ui->goal_y_box->setEnabled(true);
    ui->goal_x_box->setMaximum(width - 2);
    ui->goal_y_box->setMaximum(height - 2);
    ui->goal_x_box->setMinimum(1);
    ui->goal_y_box->setMinimum(1);
}

void MainWindow::on_start_x_box_valueChanged(int arg1)
{
    start_x = arg1;
}

void MainWindow::on_start_y_box_valueChanged(int arg1)
{
    start_y = arg1;
}

void MainWindow::on_goal_x_box_valueChanged(int arg1)
{
    goal_x = arg1;
}

void MainWindow::on_goal_y_box_valueChanged(int arg1)
{
    goal_y = arg1;
}

void MainWindow::on_show_button_clicked()
{
    QFile file(":/rec/Resources/Read.xml");
    file.open(QIODevice::ReadOnly);

    int road;
    int dirtyRoad;
    int lake;

    QXmlStreamReader xmlReader(&file);
    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if(token == QXmlStreamReader::StartElement)
        {
            if (xmlReader.name() == "road")
                road = xmlReader.readElementText().toInt();
            else if(xmlReader.name() == "dirtyRoad")
                dirtyRoad = xmlReader.readElementText().toInt();
            else if(xmlReader.name() == "lake")
                lake = xmlReader.readElementText().toInt();
        }
    }

    file.close();

    //QFile file2(":/rec/Resources/Write.xml");
    //file.open(QIODevice::WriteOnly);

    //QXmlStreamWriter xmlWriter(&file2);
    //xmlWriter.setAutoFormatting(true);
    //xmlWriter.writeStartDocument();
    //xmlWriter.writeStartElement("info");

    if ((goal_x <= 0 || goal_y <= 0 || start_x <= 0 || start_y <= 0 || width <= 0 || height <= 0) && random == false){
        QMessageBox::warning(this, "Ошибка задачи параметров", "Параметры должныы быть больше 0");
    }
    else{
        int cellSize = 50;
        /*if (width * height <= 1000 * 1000 && width * height > 500 * 500)
           cellSize = 50;
        else if (width * height <= 500 * 500 && width * height > 250 * 250)
           cellSize = 50;
        else cellSize = 50;*/
        Labyrinth lab(width, height, random, start_x, start_y, goal_x, goal_y);
        lab.setWeight(road, dirtyRoad, lake);
        if (lab.findWay()){
            lab.drawWay();
            Widget *w = new Widget(cellSize, width, height, lab.getLabyrinth());
            w->show();

        }
        else{
           QMessageBox::critical(this, "A* ошибка", "Не удалось найти путь");
       }
   }
}
