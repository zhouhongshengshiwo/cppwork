#include "timerbtn.h"
#include <QMouseEvent>
#include <QDebug>

TimerBtn::TimerBtn(QWidget *parent):QPushButton(parent),_counter(10)
{
    _timer = new QTimer(this);
//connect 用于将信号和槽连接起来。具体地说，
    //它将 _timer 对象的 timeout 信号连接到一个 Lambda 函数
   //每隔一定的时间（如一秒），定时器会发出 timeout 信号
    connect(_timer, &QTimer::timeout, [this](){
        _counter--;
        if(_counter <= 0){
            _timer->stop();
            _counter = 10;
            this->setText("获取");
            this->setEnabled(true);
            return;
        }
        this->setText(QString::number(_counter));
    });
}

TimerBtn::~TimerBtn()
{
    _timer->stop();
}

void TimerBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        // 在这里处理鼠标左键释放事件
        qDebug() << "MyButton was released!";
        this->setEnabled(false);
         this->setText(QString::number(_counter));
        _timer->start(1000);//定时发送timeout信号给lambda
        emit clicked();//语句会在用户释放鼠标按钮时发射这个信号，通常用于通知其他对象有一个点击事件发生
    }
    // 调用基类的mouseReleaseEvent以确保正常的事件处理（如点击效果）
    QPushButton::mouseReleaseEvent(e);
}


