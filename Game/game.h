#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"
#include "graphicsview.h"
#include "graphicspanel.h"
#include <QList>


/**
 * @brief Главный класс игры
 * @details Почти все процессы проходят через этот класс,
 * хранит список всех игрокоа и основные графические элементы
 */
class Game : public QObject
{
    Q_OBJECT
public:
    Map map;                        ///< экземпляр класса Map(карта)
    QList <Player*> list_players;   ///< сртсок всех живых игроков
    GraphicsView *graphicsView;     ///< Виджет для отображения главной сцены(где размещены юниты)
    GraphicsPanel *graphicsScene;   ///< графическая сцена, на которой изображены все юниты игрока, который ходит

    bool game_play = false;         ///< идёт ли игра
    int number_moves = 0;           ///< колисечтво прошеших ходов

/**
 * @brief Функция сохдания и добавления игрока в list_players
 * @param name_player - имя игрока
 * @param id_image - индентификатор изображения игрока
 * @param number_player - номер игрока
 */
    void addPlayer(QString name_player, QString id_image, int number_player);
/**
 * @brief Функция поиска игрока, который ходит в данный момент
 * @return Ссылка на игрока
 */
    Player* move_player();
/**
 * @brief Функция для получения ссылки на данный класс (Game)
 * @return Сыылка на класс Game
 */
    static Game* GetInstance();
private:
//    QWidget *window_qestion;
    static Game *GameInstance;      ///< ссылка на данный класс (Game)
/**
 * @brief Функция обновления данных всех игроков
 * @details Все данные игрока обновляются,
 * если у игрока не осталось ни юнитов, ни замка,
 * то данный игрок удаляется из списка
 */
    void refresh_data_players();
/**
 * @brief Функция для проверки готовности игрока начать свой ход
 * @details Создается окно, в котором есть вопрос о готовности игрока
 * начать свой ход, при нажатии на единственную кнопку начинается
 * ход данного игрока
 * @param player - ссылка на игрока, который должен начать свой ход
 */
    void willingness_player(Player *player);

public slots:
/**
 * @brief Функция делает главное окно неактивным
 */
    void disenable_window();
/**
 * @brief Функция делает главное окно активным
 */
    void enable_window();
/**
 * @brief Функция, которая передает ход следующему игроку
 */
    void next_player();

};

#endif // GAME_H
