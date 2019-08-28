#include "choose_count_players.h"
#include <QBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QFontDatabase>
#include <QLabel>
#include <QMessageBox>

#include "game.h"
#include "mainwindow.h"
#include "graphicspanel.h"
#include "datagraphicsscene.h"

Choose_count_players::Choose_count_players(QWidget *parent)
    :QWidget (parent)
{
    if(parent)
        parent->setEnabled(false);

    Window = new QWidget(parent);

    Window->setFixedSize(660,150);
    Window->setWindowFlag(Qt::ToolTip);

    QBrush *brush = new QBrush;
    QPalette *palette = new QPalette;
    brush->setTextureImage(QImage("../Game/background-2.png"));
    palette->setBrush(QPalette::Window, *brush);
    Window->setPalette(*palette);

    main_layout = new QVBoxLayout;
    main_layout->setAlignment(Qt::AlignHCenter);
    QHBoxLayout *layot = new QHBoxLayout;
    layot->setAlignment(Qt::AlignHCenter);

    QSpinBox *spin_box = new QSpinBox;
    spin_box->setFixedSize(100,60);
    spin_box->setRange(2,4);
    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).first());
    font.setPixelSize(50);
    spin_box->setFont(font);
    spin_box->setStyleSheet("border: 3px solid black;"
                            "color: white;"
                            "text-align:center;"
                            "background:url(../Game/background-2.png);");
    connect(spin_box, SIGNAL(valueChanged(int)), this, SLOT(spinboxValueChanged(int)));

    QPushButton *choose_button = new QPushButton;
    choose_button->setText("Выбрать");
    choose_button->setFont(font);
    choose_button->setFixedSize(300,spin_box->size().height());
    choose_button->setStyleSheet("background:url(../Game/background-1.png);"
                                 "border: 5px solid balck;"
                                 "color:white;");
    connect(choose_button, SIGNAL(clicked()), this, SLOT(create_edit_lines()));
    
    layot->addWidget(spin_box);
    layot->addWidget(choose_button);

    QLabel *text = new QLabel;
    text->setText("Выберете количество игроков!");
    text->setStyleSheet("background:url(../Game/background-3.png);"
                        "border: 3px solid rgb(64, 64, 64);"
                        "color:white;");
    font.setPixelSize(30);
    text->setFont(font);

    main_layout->addWidget(text);
    main_layout->addLayout(layot);

    Window->setLayout(main_layout);
    Window->setEnabled(true);
    Window->show();
}

Choose_count_players::~Choose_count_players()
{
    delete this;
}

void Choose_count_players::create_edit_lines()
{
    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).first());

    if(count_choose>list_line_edit.length())
    {
        for(int i=list_line_edit.length();i<count_choose;i++)
        {
            if(!past_happen)
            {
                QPushButton *accept = new QPushButton;
                accept->setText("Применить");
                accept->setFixedSize(500,60);
                font.setPixelSize(50);
                accept->setFont(font);
                accept->setStyleSheet("background:url(../Game/background-1.png);"
                                      "border: 5px solid balck;"
                                      "color:white;");

                QHBoxLayout *layout = new QHBoxLayout;
                layout->setAlignment(Qt::AlignHCenter);
                layout->addWidget(accept);

                main_layout->addLayout(layout);
                past_happen = true;

                connect(accept, SIGNAL(clicked()), this, SLOT(check_data()));
            }

            QLineEdit *line = new QLineEdit;
            line->setFixedSize(500,70);
            line->setMaxLength(12);
            font.setPixelSize(50);
            line->setFont(font);
            line->setStyleSheet("background:url(../Game/background-3.png);"
                                "border: 3px solid rgb(64, 64, 64);"
                                "color:white;");
            line->setAlignment(Qt::AlignCenter);

            QHBoxLayout *second = new QHBoxLayout;
            second->setAlignment(Qt::AlignHCenter);
            second->addWidget(line);

            QLabel *text = new QLabel;
            font.setPixelSize(30);
            text->setFont(font);
            text->setAlignment(Qt::AlignCenter);
            text->setStyleSheet("border: 0px;"
                                "background:url(../Game/Transparent.png);"
                                "color:white;");
            switch (i)
            {
                case 0:
                text->setText("Имя первого игрока:");
                break;
                case 1:
                text->setText("Имя второго игрока:");
                break;
                case 2:
                text->setText("Имя третьего игрока:");
                break;
                case 3:
                text->setText("Имя четвертого игрока:");
                break;
            }

            main_layout->insertWidget(main_layout->count()-1,text);
            main_layout->insertLayout(main_layout->count()-1,second);

            list_line_edit.append(line);
            list_lable.append(text);

            Window->setGeometry(Window->pos().x(),Window->pos().y()-70,Window->width(), Window->height()+140);
            Window->setFixedHeight(Window->height()+140);
        }
    }
    else if(count_choose<list_line_edit.length())
    {
        for (int i=list_line_edit.length();i>count_choose;i--)
        {
            delete list_line_edit.back();
            delete list_lable.back();
            list_line_edit.removeAt(list_line_edit.count()-1);
            list_lable.removeAt(list_lable.count()-1);
            Window->setGeometry(Window->pos().x(),Window->pos().y()+70,Window->width(), Window->height()-140);
            Window->setFixedHeight(Window->height()-140);
        }
    }
}

void Choose_count_players::check_data()
{
    bool warning = false;
    for (int i=0;i<list_line_edit.length();i++)
    {
        if(list_line_edit[i]->text().length()==0)
        {
           list_line_edit[i]->setStyleSheet("background:url(../Game/background-3.png);"
                               "border: 3px solid red;"
                               "color:white;");
            warning = true;
        }
        else
        {
            list_line_edit[i]->setStyleSheet("background:url(../Game/background-3.png);"
                                "border: 3px solid rgb(64, 64, 64);"
                                "color:white;");
        }
    }
    if(warning)
        QMessageBox::warning(this->Window, "", "Введены не все имена игроков!", QMessageBox::Ok);
    else
    {
        Game *game = Game::GetInstance();
        for (int i=0;i<list_line_edit.length();i++)
        {
            game->addPlayer(list_line_edit[i]->text(),"01",i);
        }

        DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
        scene->refresh_scene(game->list_players.first());


        game->graphicsScene->refresh_panel(game->list_players[0]);

        this->Window->close();
        delete this->Window;
        MainWindow::GetInstance()->setEnabled(true);
    }

}
