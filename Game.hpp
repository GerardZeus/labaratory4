#pragma once
#include <string> //Библиотека для работы со строками 
#include <ctime> //Библиотка для работы со временем(используем для генерации случайных чисел)
#include "Circle.hpp"

namespace mt //Объвляем пространство имён
{
    class Game // Создаём клаас Game(для настроек игры)
    {
        int m_width; // Длина окна
        int m_height; // Ширина окна
        std::string m_capture; // Заголовок окна
        int m_n; // Количество фигур
        sf::RenderWindow m_window; // Переменная для отрисовки окна

        mt::Circle* m_circles; // Указатель на массив кругов 
        mt::Triangle* m_triangles; // Указатель на массив треугольников
        mt::Rectangle* m_rectangles; //Указатель на массив прямоугольников
        mt::Line* m_lines; //Указатель на массив прямых

    public:
        Game(int width, int height, const std::string& capture) // Конструктор иницилизирует длину, ширину и заголовок окна 
        {
            m_width = width; // Устанавливаем дину окна
            m_height = height; // Устанавливае ширину окна
            m_capture = capture; // Устанавливаем заголовок окна 
            srand(time(0)); // Создаём генератор случайных чисел(нужен, чтобы при новом запуски генерировались новые числа)
        }

        void Setup() //Метод для настройки игры
        {
            m_n = rand() % 10 + 1;  // Количество фигур от 1 до 10

            m_window.create(sf::VideoMode(m_width, m_height), m_capture); // Создаём окно с заданными параметрами 

            m_circles = new mt::Circle[m_n]; // Выделяем паямть для массива кругов
            m_triangles = new mt::Triangle[m_n]; // Выделяем паямть для массива треугольников
            m_rectangles = new mt::Rectangle[m_n]; // Выделяем паямть для массива прямоугольников
            m_lines = new mt::Line[m_n]; // Выделяем паямть для массива прямых

            for (int i = 0; i < m_n; i++) // Цикл для настройки фигур
            {

                float x1 = rand() % 1000; // Случайная координата X для круга 
                float y1 = rand() % 600; // Случайная координата Y для круга
                float radius = rand() % 100 + 1; // Случайный радиус для круга
                m_circles[i].Setup(x1, y1, radius); // Настраиваем круг с заданными параметрами

                float x2 = rand() % 1000; // Случайная координата X для треугольника 
                float y2 = rand() % 600; // Случайная координата Y для треугольника 
                float size = rand() % 100 + 1; // Случайный размер треугольника 
                m_triangles[i] = mt::Triangle(x2, y2, size); // Настраиваем треугольник с заданными параметрами 

                float x3 = rand() % 1000; // Случайная координата X для прямоугольника   
                float y3 = rand() % 600; // Случайная координата Y для прямоугольника
                float width = rand() % 200 + 50; // Случайная длина прямоугольника
                float height = rand() % 100 + 25; // Случайная координата ширина прямоугольника
                m_rectangles[i] = mt::Rectangle(x3, y3, width, height); // Настраиваем прямоугольник с заданными параметрами 

                float x4 = rand() % 1000; // Случайаня координата X для прямой
                float y4 = rand() % 600; // Случайная координта Y для прямой
                float x2_line = x4 + rand() % 200 + 50; // Слуачайная вторая координата X для прямой 
                m_lines[i] = mt::Line(x4, y4, x2_line, y4); // Настраиваем прямую с заданными параметрами
            }
        }

        void LifeCycle() // Метод для отоброжения всего на экран
        {
            while (m_window.isOpen()) // Пока открыто окно
            {
                sf::Event event;
                while (m_window.pollEvent(event)) // Обрабатывать события 
                {
                    if (event.type == sf::Event::Closed) // Если событие - закрыть окно
                        m_window.close(); // Закрываем онно
                }

                m_window.clear(); // Очищаем окно для отрисовки 

                for (int i = 0; i < m_n; i++) // Цикл для отрисовки кругов
                    m_window.draw(m_circles[i].Get());

                for (int i = 0; i < m_n; i++) // Цикл для отрисовки треугольников 
                    m_window.draw(m_triangles[i].Get());

                for (int i = 0; i < m_n; i++) // Цикл для отрисовка прямоугольников
                    m_window.draw(m_rectangles[i].Get());

                for (int i = 0; i < m_n; i++) // Цикл для отрисовки прямых
                    m_window.draw(m_lines[i].Get(), 2, sf::Lines);

                m_window.display(); // Отображаем фигуры на экран
            }
        }
    };
}
