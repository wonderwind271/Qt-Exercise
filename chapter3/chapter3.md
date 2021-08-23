### QPropertyAnimation 

```c++
QPropertyAnimation *animation = new QPropertyAnimation(myWidget, "geometry");
      animation->setDuration(10000);
      animation->setStartValue(QRect(0, 0, 100, 30));
      animation->setEndValue(QRect(250, 250, 100, 30));
      animation->start();
```



### QTimer

```C++
QTimer* timer=new QTimer(this);
    connect(timer,&QTimer::timeout,ui->label_score_num,[&](){
        score++;
        ui->label_score_num->setNum((score));

    });
    timer->start(500);
```

