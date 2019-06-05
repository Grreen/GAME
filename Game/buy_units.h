#ifndef BUY_UNITS_H
#define BUY_UNITS_H
#include <QWidget>
#include "mainwindow.h"
#include <iostream>

class Buy_units : public QWidget
{
    Q_OBJECT
public:
    QWidget *window;
    explicit Buy_units(QWidget *perant = 0);

public slots:
    void buy_melle_first();
    void buy_melle_second();
    void buy_range_first();
    void buy_range_second();
};

#endif // BUY_UNITS_H
