#pragma once
#include <SFML/Graphics.hpp>

namespace mt // ��������� ������������ ���
{
    class Circle // ������ ����� ��� �����
    {
        float m_r; // ���������� ��� �������
        float m_x, m_y; //���������� ��� ��������� 
        sf::CircleShape m_shape; // ����� ��� ������ � �������

    public:
        Circle() = default; //����������� ��-��������� 
        Circle(float x, float y, float r)  //����������� ��� ������������� ��������� � ������� 
        {
            Setup(x, y, r);
        }

       void Setup(float x, float y, float r) // ����� ��� ��������� ���������� ����� 
        {
            m_x = x; // ���������� �� X
            m_y = y; // ���������� �� Y
            m_r = r; // ������
            m_shape.setRadius(m_r); // ������(�� SFML) ������������� ������
            m_shape.setPosition(m_x, m_y); //�������(�� SFML) ������������� ���������� 
            m_shape.setFillColor(sf::Color::Color(255, 0, 0, 255)); // ������(�� SFML) ������������� ����(�������)
        }

        sf::CircleShape& Get() //������(���������� ������ �� ������ ��� ��������� ������� � ������)
        {
            return m_shape;
        }
    };

    class Triangle // ������ ����� ��� ������������ 
    {
        sf::CircleShape m_shape; // ���������� CircleShape ��� ������������(����� ������� ������)

    public:
        Triangle() = default; // ����������� ��-���������
        Triangle(float x, float y, float size) // ����������� ������������� ���������� � ������
        {
            m_shape.setPointCount(3); // ������������� ���������� �����(��� ������������ 3)
            m_shape.setRadius(size); // ������������� ������ �����, � ������� ����� ������ �����������(��� ����� ��� ��� ����������� ����� CircleShape)
            m_shape.setPosition(x, y); //������������� ���������� 
            m_shape.setFillColor(sf::Color::Color(0, 255, 0, 255)); // ������������ ���� ������������(������)
        }

        sf::CircleShape& Get() //������(���������� ������ �� ������ ��� ��������� ������� � ������)
        {
            return m_shape;
        }
    };

    class Rectangle // ������ ����� ��� �������������� 
    {
        sf::RectangleShape m_shape; // ����� ��� ������ � ���������������� 

    public:
        Rectangle() = default; // ����������� ��-���������
        Rectangle(float x, float y, float width, float height) // ����������� �������������� ����������, ����� � ������ 
        {
            m_shape.setSize(sf::Vector2f(width, height)); // ������������� ����� � ������(���������� ����� �� SFML "Vector2f" - ���������� ������)
            m_shape.setPosition(x, y); // ������������� ����������
            m_shape.setFillColor(sf::Color::Color(0, 0, 255, 255)); // ������������� ���� ��������������(�����)
        }

        sf::RectangleShape& Get() //������(���������� ������ �� ������ ��� ��������� ������� � ������)
        {
            return m_shape;
        }
    };

    class Line //����� ��� ������
    {
        sf::Vertex m_line[2]; // ������ �� ���� ����� ��� ������� ������ 

    public:
        Line() = default; // ����������� ��-���������
        Line(float x1, float y1, float x2, float y2) // ����������� �������������� ���������� ���� �����
        {
            m_line[0] = sf::Vertex(sf::Vector2f(x1, y1), sf::Color::Yellow); // ������ �����(�����)
            m_line[1] = sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Yellow); // ������ ����(�����)
        }

        sf::Vertex* Get() //������(���������� ��������� �� ������ ������ ��� ��������� ������� � ������)
        {
            return m_line;
        }
    };
}

