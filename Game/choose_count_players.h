#ifndef CHOOSE_COUNT_PLAYERS_H
#define CHOOSE_COUNT_PLAYERS_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>


/**
 * @brief Класс выбора количества игроков
 * @details Вызываетя в начале игры,
 * чтобы узнать сколько будет игроуов (от 2 до 4),
 * затем вводится имена каждого,
 * после чего проводится проверка на пустоту вводимых данных,
 * далее начинается игра
 */
class Choose_count_players : public QWidget
{
    Q_OBJECT
private:
    QWidget *Window;                    ///< Указатель на окно класса
    QVBoxLayout *main_layout;           ///< Главный Qlayout
    QList <QLineEdit*> list_line_edit;  ///< Список всех QLineEdit, в которые вводятся имена игроков
    QList <QLabel*> list_lable;         ///< Список всех QLabel, которые содеражат текс по примеру:"Имя первого игрока:"
    bool past_happen = false;
    int count_choose = 2;               ///< Количество выбранных игроков
public:
/**
 * @brief Конструктор
 * @details Создает окно для выбора количества игроков,
 * после выбора количества игроков вводяится их имена,
 * затем создаются игроки
 * @param parent - родитель
 */
    explicit Choose_count_players(QWidget *parent =0);
/**
 * @brief Деструктор
*/
    ~Choose_count_players();
private slots:
/**
 * @brief Функция, которая при изменении значений в QSpinBox
 * изменяет значение count_choose
 * @param value - значение, выбранное в QSpinBox
 */
    void spinboxValueChanged(int value){count_choose = value;}
/**
 * @brief Функция содает поля ввода(QLineEdit) имен игроков
 */
    void create_edit_lines();
/**
 * @brief Функция проверяет все QLineEdit на пустоту
 * @details Если хотя бы одно поле осталось пустым,
 * то выводится ошибка ввода и рамка данного поля становится красным,
 * если же все поля не пустые, то создаются игроки с введенными именами
 */
    void check_data();
};

#endif // CHOOSE_COUNT_PLAYERS_H
