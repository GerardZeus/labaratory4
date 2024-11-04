#pragma once
#include <string> //���������� ��� ������ �� �������� 
#include <ctime> //��������� ��� ������ �� ��������(���������� ��� ��������� ��������� �����)
#include "Circle.hpp"

namespace mt //�������� ������������ ���
{
    class Game // ������ ����� Game(��� �������� ����)
    {
        int m_width; // ����� ����
        int m_height; // ������ ����
        std::string m_capture; // ��������� ����
        int m_n; // ���������� �����
        sf::RenderWindow m_window; // ���������� ��� ��������� ����

        mt::Circle* m_circles; // ��������� �� ������ ������ 
        mt::Triangle* m_triangles; // ��������� �� ������ �������������
        mt::Rectangle* m_rectangles; //��������� �� ������ ���������������
        mt::Line* m_lines; //��������� �� ������ ������

    public:
        Game(int width, int height, const std::string& capture) // ����������� ������������� �����, ������ � ��������� ���� 
        {
            m_width = width; // ������������� ���� ����
            m_height = height; // ������������ ������ ����
            m_capture = capture; // ������������� ��������� ���� 
            srand(time(0)); // ������ ��������� ��������� �����(�����, ����� ��� ����� ������� �������������� ����� �����)
        }

        void Setup() //����� ��� ��������� ����
        {
            m_n = rand() % 10 + 1;  // ���������� ����� �� 1 �� 10

            m_window.create(sf::VideoMode(m_width, m_height), m_capture); // ������ ���� � ��������� ����������� 

            m_circles = new mt::Circle[m_n]; // �������� ������ ��� ������� ������
            m_triangles = new mt::Triangle[m_n]; // �������� ������ ��� ������� �������������
            m_rectangles = new mt::Rectangle[m_n]; // �������� ������ ��� ������� ���������������
            m_lines = new mt::Line[m_n]; // �������� ������ ��� ������� ������

            for (int i = 0; i < m_n; i++) // ���� ��� ��������� �����
            {

                float x1 = rand() % 1000; // ��������� ���������� X ��� ����� 
                float y1 = rand() % 600; // ��������� ���������� Y ��� �����
                float radius = rand() % 100 + 1; // ��������� ������ ��� �����
                m_circles[i].Setup(x1, y1, radius); // ����������� ���� � ��������� �����������

                float x2 = rand() % 1000; // ��������� ���������� X ��� ������������ 
                float y2 = rand() % 600; // ��������� ���������� Y ��� ������������ 
                float size = rand() % 100 + 1; // ��������� ������ ������������ 
                m_triangles[i] = mt::Triangle(x2, y2, size); // ����������� ����������� � ��������� ����������� 

                float x3 = rand() % 1000; // ��������� ���������� X ��� ��������������   
                float y3 = rand() % 600; // ��������� ���������� Y ��� ��������������
                float width = rand() % 200 + 50; // ��������� ����� ��������������
                float height = rand() % 100 + 25; // ��������� ���������� ������ ��������������
                m_rectangles[i] = mt::Rectangle(x3, y3, width, height); // ����������� ������������� � ��������� ����������� 

                float x4 = rand() % 1000; // ��������� ���������� X ��� ������
                float y4 = rand() % 600; // ��������� ��������� Y ��� ������
                float x2_line = x4 + rand() % 200 + 50; // ���������� ������ ���������� X ��� ������ 
                m_lines[i] = mt::Line(x4, y4, x2_line, y4); // ����������� ������ � ��������� �����������
            }
        }

        void LifeCycle() // ����� ��� ����������� ����� �� �����
        {
            while (m_window.isOpen()) // ���� ������� ����
            {
                sf::Event event;
                while (m_window.pollEvent(event)) // ������������ ������� 
                {
                    if (event.type == sf::Event::Closed) // ���� ������� - ������� ����
                        m_window.close(); // ��������� ����
                }

                m_window.clear(); // ������� ���� ��� ��������� 

                for (int i = 0; i < m_n; i++) // ���� ��� ��������� ������
                    m_window.draw(m_circles[i].Get());

                for (int i = 0; i < m_n; i++) // ���� ��� ��������� ������������� 
                    m_window.draw(m_triangles[i].Get());

                for (int i = 0; i < m_n; i++) // ���� ��� ��������� ���������������
                    m_window.draw(m_rectangles[i].Get());

                for (int i = 0; i < m_n; i++) // ���� ��� ��������� ������
                    m_window.draw(m_lines[i].Get(), 2, sf::Lines);

                m_window.display(); // ���������� ������ �� �����
            }
        }
    };
}
