#include "win.h"


Win::Win(QWidget *parent) : QWidget(parent) //класс окна
{
     //codec = QTextCodec::codecForName("Windows-1251");
     //this->setWindowTitle(codec->toUnicode("Счетчик"));
     this->setWindowTitle("Counter"); //заголовок окна
     //label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
     label1 = new QLabel("Counter by 1", this);
     //label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);
     label2 = new QLabel("Counter by 5", this);
     //виджеты счетчиков:
     edit1 = new Counter("0", this);
     edit2 = new Counter("0", this);
     //кнопки:
     calcbutton = new QPushButton("+1", this);
     //exitbutton = new QPushButton(codec->toUnicode("Выход"),this);
     exitbutton = new QPushButton("Exit",this);


     /*компановка*/
     //первая пара горизонтальных виджетов:
     QHBoxLayout *layout1 = new QHBoxLayout();
     layout1->addWidget(label1);
     layout1->addWidget(label2);
     //вторая пара горизонтальных виджетов:
     QHBoxLayout *layout2 = new QHBoxLayout();
     layout2->addWidget(edit1);
     layout2->addWidget(edit2);
     //третья пара горизонтальных виджетов:
     QHBoxLayout *layout3 = new QHBoxLayout();
     layout3->addWidget(calcbutton);
     layout3->addWidget(exitbutton);
     //вертикально располагаем три пары горизонтальных виджетов:
     QVBoxLayout *layout4 = new QVBoxLayout(this);
     layout4->addLayout(layout1);
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);
     //связь сигналов и слотов:
     connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one())); //нажание кнопки "+1" посылает сигнал на счетчик едениц
     connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one())); //сигнал от счетчика едениц на слот счетчика пятерок (по достижении пятерки)
     connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close())); // нажатие кнопки выхода и слота закрытия окна
}
