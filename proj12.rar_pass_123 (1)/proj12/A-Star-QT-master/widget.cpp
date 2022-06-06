#include "widget.h"
#include "ui_widget.h"

Widget::Widget(int cellSize, int width, int height, node** maps, QWidget *parent) :
    QWidget(parent)
{
    this->cellSize = cellSize;
    this->width = width;
    this->height = height;
    map = maps;
    this->setGeometry(0, 0, 1000, 1000);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor dirtyRoadColor = qRgb(51, 102, 0);
    for (int y = 0; y < height*cellSize; y+=cellSize){
        for (int x = 0; x < width*cellSize; x+=cellSize){
            if (map[x/cellSize][y/cellSize].typeOfCell == 0){
                int i = rand() % 4;
                    QPixmap image;
                if (i == 0){
                    QPixmap im(":/rec/Resources/road1.jpg");
                    image = im;
                }
                else if (i == 1){
                    QPixmap im(":/rec/Resources/road2.jpg");
                    image = im;
                }
                else if (i == 2){
                    QPixmap im(":/rec/Resources/road3.jpg");
                    image = im;
                }
                else {
                    QPixmap im(":/rec/Resources/road4.jpg");
                    image = im;
                }
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 1){
                int i = rand() % 4;
                    QPixmap image;
                if (i == 0){
                    QPixmap im(":/rec/Resources/swamp1.jpg");
                    image = im;
                }
                else if (i == 1){
                    QPixmap im(":/rec/Resources/swamp2.jpg");
                    image = im;
                }
                else if (i == 2){
                    QPixmap im(":/rec/Resources/swamp3.jpg");
                    image = im;
                }
                else {
                    QPixmap im(":/rec/Resources/swamp4.jpg");
                    image = im;
                }
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 2){
                int i = rand() % 3;
                    QPixmap image;
                if (i == 0){
                    QPixmap im(":/rec/Resources/wall1.jpg");
                    image = im;
                }
                else if (i == 1){
                    QPixmap im(":/rec/Resources/wall2.jpg");
                    image = im;
                }
                else if (i == 2){
                    QPixmap im(":/rec/Resources/wall3.jpg");
                    image = im;
                }
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 3){
                int i = rand() % 4;
                    QPixmap image;
                if (i == 0){
                    QPixmap im(":/rec/Resources/lake1.jpg");
                    image = im;
                }
                else if (i == 1){
                    QPixmap im(":/rec/Resources/lake2.jpg");
                    image = im;
                }
                else if (i == 2){
                    QPixmap im(":/rec/Resources/lake3.jpg");
                    image = im;
                }
                else {
                    QPixmap im(":/rec/Resources/lake4.jpg");
                    image = im;
                }
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 4){
                QPixmap image(":/rec/Resources/start.jpg");
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 5){
                QPixmap image(":/rec/Resources/end.jpg");
                painter.drawPixmap(QRect(QPoint(x, y),QSize(cellSize, cellSize)), image, QRect(QPoint(0, 0),QSize(400, 400)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 7){
                 painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));
            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 8){
                 painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
            else if(map[x/cellSize][y/cellSize].typeOfCell == 9){
                 painter.setBrush(QBrush(dirtyRoadColor, Qt::SolidPattern));
                 painter.drawRect(QRect(QPoint(x, y), QSize(cellSize, cellSize)));

            }
        }

    }

}


