#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;//�������� sfml ������ "���", ������� � �������� �������

void getplayercoordinateforview(float x, float y) { //������� ��� ���������� ��������� ������


	view.setCenter(x + 100, y); //������ �� �������, ��������� ��� ���������� ������. +100 - �������� ������ �� ���� ������. �����������������


}

