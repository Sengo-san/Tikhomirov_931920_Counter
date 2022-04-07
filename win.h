#ifndef win_h
#define win_h

#include <QWidget>
#include <QtGui>


//<QtGui> в моей версии Qt не подключает библиотеки виджетов, поэтому каждый подключаю отдельно.
//Также не распознается библиотека <QTextCodec>,
//поэтому всё что связано с перекодировкой в русский алфавит закомментировано, интерфейс написан на английском

//#include <QTextCodec>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Counter : public QLineEdit //класс счетчик
{
     Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
public:
     Counter(const QString & contents, QWidget *parent=0):
     QLineEdit(contents, parent){}

  signals:
     void tick_signal();

public slots:
     void add_one() //слот увеличения значений счетчика +1
     {
         //получаем значение:
         QString str = text();
         int r = str.toInt();

         if (r!=0 && r%5 ==0) emit tick_signal(); //генерируем сигнал на счетчик пятерок по достижению пяти нажатий
         //устанавливаем новое значение:
         r++;
         str.setNum(r);
         setText(str);
     }
};


class Win: public QWidget   //класс окна
{
 Q_OBJECT
protected:
     //QTextCodec *codec;
     QLabel *label1, *label2; //информационные тексты
     Counter *edit1, *edit2; //счетчики
     QPushButton *calcbutton; //кнопка +1
     QPushButton *exitbutton; //кнопка выхода
public:
    Win(QWidget *parent = 0); // конструктор
};
#endif
