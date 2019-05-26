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


};

class HBoxLayout : public QHBoxLayout
{
public:
    QLabel label;
    QLineEdit name;
};

class New_Form : public QWidget
{
    Q_OBJECT
public:
    int count_players = 2;
    New_Form *win;
    QList <QString> list_name_players;
    QList <QPixmap> list_image_players;
    QHBoxLayout *body_layout = new QHBoxLayout;
    QVBoxLayout *first_layout = new QVBoxLayout;
    QVBoxLayout *second_layout = new QVBoxLayout;


    void create_window(MainWindow *parent_window);


public slots:
    void spinboxValueChanged(int value){count_players = value;}
    void create_line();


};



#endif // MAINWINDOW_H
