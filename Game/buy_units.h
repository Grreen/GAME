#ifndef BUY_UNITS_H
#define BUY_UNITS_H
#include <QWidget>
#include "mainwindow.h"
#include <iostream>


/**
 * @brief Класс для покупки юнитов
 * @details С помощью данного класа очуществляется создание окна,
 * с помощью которого осуществляется покупка,
 * а затем добавление на сцену юнита
*/
class Buy_units : public QWidget
{
    Q_OBJECT
public:
/**
 * @brief Конструктор
 * @details Создается окно с выбором 1 из 4 юнитов,
 * затем при выборе юнита вызывается buy_unit
 * @param perant - родитель
 */
    explicit Buy_units(QWidget *perant = 0);
private:
    QWidget *window;            ///< указатель на создваемое окно
public slots:
/**
 * @brief Функция покупки бнита
 * @details С помощью данной функции осуществляется покупка юнита,
 * а затем добавление его на сцену с опрределенными параметрами
 * @param id_unit - индентификатор юнита (11,12,13,14)
 */
    void buy_unit(int id_unit);
/**
 * @brief Функция закрытия окна
 * @details Осуществляет закрытие окна и
 * активацию главного окна
 */
    void close_window();
};

#endif // BUY_UNITS_H
