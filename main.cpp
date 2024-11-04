#include "Circle.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    mt::Game game(1000, 600, "Game!!!"); // Создаём объект класса Game и задаём длину, ширину и заголовок окна
    game.Setup(); // Вызываем метод для настройки и создания фигур
    game.LifeCycle(); // Вызвываем метод для отрисовки фигур

    return 0;
}