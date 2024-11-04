#pragma once
#include <SFML/Graphics.hpp>

namespace mt // Объявляем пространство имён
{
    class Circle // Создаём класс для круга
    {
        float m_r; // Переменная для радиуса
        float m_x, m_y; //Переменные для координат 
        sf::CircleShape m_shape; // Класс для работы с кругами

    public:
        Circle() = default; //Конструктор по-умолчанию 
        Circle(float x, float y, float r)  //Конструктор для инициализации координат и радиуса 
        {
            Setup(x, y, r);
        }

       void Setup(float x, float y, float r) // Метод для настройки параметров круга 
        {
            m_x = x; // Координата по X
            m_y = y; // Координата по Y
            m_r = r; // Радиус
            m_shape.setRadius(m_r); // Функия(из SFML) устанавливаем радуис
            m_shape.setPosition(m_x, m_y); //Функция(из SFML) устанавливаем координаты 
            m_shape.setFillColor(sf::Color::Color(255, 0, 0, 255)); // Функия(из SFML) устанавливаем цвет(красный)
        }

        sf::CircleShape& Get() //Геттер(возвращает ссылку на фигуру для получения доступа к фигуре)
        {
            return m_shape;
        }
    };

    class Triangle // Создаём класс для треугольника 
    {
        sf::CircleShape m_shape; // Используем CircleShape для треугольника(далее объясню почему)

    public:
        Triangle() = default; // Конструктор по-умолчанию
        Triangle(float x, float y, float size) // Конструктор инициалзирует координаты и размер
        {
            m_shape.setPointCount(3); // Устанавливаем количество точек(для треугольника 3)
            m_shape.setRadius(size); // Устанавилваем радиус круга, в который будет вписан треугольник(для этого как раз применяется класс CircleShape)
            m_shape.setPosition(x, y); //Устанавливаем координаты 
            m_shape.setFillColor(sf::Color::Color(0, 255, 0, 255)); // Устанвливаем цвет треугольника(зелёный)
        }

        sf::CircleShape& Get() //Геттер(возвращает ссылку на фигуру для получения доступа к фигуре)
        {
            return m_shape;
        }
    };

    class Rectangle // Создаём класс для прямоугольника 
    {
        sf::RectangleShape m_shape; // Класс для работы с прямоугольниками 

    public:
        Rectangle() = default; // Конструктор по-умолчанию
        Rectangle(float x, float y, float width, float height) // Конструктор инициализирует координаты, длину и ширину 
        {
            m_shape.setSize(sf::Vector2f(width, height)); // Устанавливаем длину и ширину(используем класс из SFML "Vector2f" - двуемерный вектор)
            m_shape.setPosition(x, y); // Устанавливаем координаты
            m_shape.setFillColor(sf::Color::Color(0, 0, 255, 255)); // Устанавливаем цвет прямоугольника(синий)
        }

        sf::RectangleShape& Get() //Геттер(возвращает ссылку на фигуру для получения доступа к фигуре)
        {
            return m_shape;
        }
    };

    class Line //Класс для прямой
    {
        sf::Vertex m_line[2]; // Массив из двух точек для задания прямой 

    public:
        Line() = default; // Конструктор по-умолчанию
        Line(float x1, float y1, float x2, float y2) // Конструктор инициализирует координаты двух точек
        {
            m_line[0] = sf::Vertex(sf::Vector2f(x1, y1), sf::Color::Yellow); // Первая точка(жёлтая)
            m_line[1] = sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Yellow); // Вторая тока(жёлтая)
        }

        sf::Vertex* Get() //Геттер(возвращает указатель на массив вершин для получения доступа к фигуре)
        {
            return m_line;
        }
    };
}

