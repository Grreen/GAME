#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QgraphicsView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* GetInstance(QWidget* parent = 0);
    QGraphicsView* GetInstanceGraphicsView();

    static MainWindow* mainInstance;

//    void question_count_players();

public:
    Ui::MainWindow *ui;


private slots:
    void on_pushButton_clicked();
};


class New_Form : public QWidget
{
    Q_OBJECT
public:
    int count_players = 2;//количество игроков
    QList <QString> list_name_players;//Имена всех игроков

    void create_window(MainWindow *parent_window);//Функция создания нового окна(ввод количества игроков и ввод имён)


public slots:
    void spinboxValueChanged(int value){count_players = value;}//Слот передающий значения в переменную класс при изменении значения в QSpinBox


};



#endif // MAINWINDOW_H
