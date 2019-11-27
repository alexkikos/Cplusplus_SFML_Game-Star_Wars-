#pragma once
#define SHIFR 10
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include "Header.h"




using namespace std;
using namespace sf;

struct Ship
{
	Sprite ship_sprite;
	Texture ship_texture;
	Keyboard MyBoard;
	CircleShape* bullets=nullptr;//������ ���� ������� �� �������� = ����� ���� �� ������
	Sound *music=nullptr;//����� ��� ������������, ��������� ���� �� ���, ������������� ������� �� �����
	SoundBuffer *music_buffer=nullptr;//
	string ship_name= "default";//�������� ��� ���������� ����� ������������� � ����������
	float speed_ship = 0.13;//�������� ����������� ������� �� �����
	float speed_bullet = -0.13;
	int size_bullets = 0;//���������� ���� ������� ���� �������� 
	int hp_points=30;//���������� �� �������
	int total_bullets = 0;//���������� ��������� ��������� �� ��� ����� �� �����, ��� ����������
	int score = 0;//������� ������ �������, ��� ����������
	int delay_myship_shutting = 100;//�������� �� ��������, �������� � ������ � �������  milisec


	void createship(char**&texture, int);//������ �������
	void shoot();//��������
	void shoot_delete(int index_to_delete);//�������� ���� � ������
	void move_bullets();//��������� �������� ����
	void show_bullets(RenderWindow &window);//������ ���� �� ������
	void setposition(float x, float y);//������������ ������� �������
	void setmusic(char**);//�������� ������

};

