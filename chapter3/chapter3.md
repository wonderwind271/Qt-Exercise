### QPropertyAnimation 

```c++
#include <QPropertyAnimation>
QPropertyAnimation *animation = new QPropertyAnimation(myWidget, "geometry");
      animation->setDuration(10000);
      animation->setStartValue(QRect(0, 0, 100, 30));
      animation->setEndValue(QRect(250, 250, 100, 30));
      animation->start();
```



### QTimer

```C++
#include <QTimer>
QTimer* timer=new QTimer(this);
    connect(timer,&QTimer::timeout,ui->label_score_num,[&](){
        score++;
        ui->label_score_num->setNum((score));

    });
    timer->start(500);
```



### keyboard event

```c++
// in .h file:

#include <QKeyEvent>
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
// in .cpp file:
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape: //if [ESC] is pressed
            qDebug()<<"ESC"<<endl;break;
        case Qt::Key_0: //if [0] is pressed
            qDebug()<<"0"<<endl;break;
        // more cases...
    }
    // general things


}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    // do something with the same method
}
```

