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

/**
 * @brief Класс главного окна
 * @details Отображает все элементы
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/**
 * @brief Констуктор
 * @details Создается главное окно,
 * затем применяются стили к кнопкам:
 * "Выход", "Ход следующего игрока"
 * @param parent - родитель
 */
    explicit MainWindow(QWidget *parent = nullptr);
/**
 * @brief Деструктор
*/
    ~MainWindow();
/**
 * @brief Функция для получения ссылки на главное окно
 * @param parent - родмтель
 * @return Ссылка на главное окно
 */
    static MainWindow* GetInstance(QWidget* parent = 0);
/**
 * @brief Функция получения ссылки на нужный виджет для отображения грфической сцены
 * @param number - номер виджета для отображения грфической сцены
 * @return Ссылка на выбранный виджет для отображения грфической сцены
 */
    QGraphicsView* GetInstanceGraphicsView(int number);
/**
 * @brief Функция для получения ссылки на нужную кнопку
 * @param number - номер кнопки
 * @return Ссылка на нужную кнопку
 */
    QPushButton* GetInstanceButton(int number);

    static MainWindow* mainInstance;    ///< Ссылка на главное окно

//    void question_count_players();

public:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
