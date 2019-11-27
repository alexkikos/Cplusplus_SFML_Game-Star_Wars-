#pragma once
#include "Ship.h"


struct Enemies
{
	Sprite ship_sprite;
	Texture ship_texture;
	CircleShape* bullets = nullptr;
	float speed_ship = 0.05;
	float speed_bullet = speed_ship * 2;
	int size_bullets = 0;//��������� ������� ���� ���� �������� ��� �� ���������� ��������
	int hp_points=1;//���������� ��
	bool flag_shoot = false;//���� ��� ������������ ������� ������� ��� ���, 1 ������� ��� ������ ����� �����



	void move_bullet();//������ ���� �� �������
	void createship(char**& texture, int);//������ �������
	void shoot();//��������
	void show_bullets(RenderWindow& window);//����������� ����
	void show_ship();//����������� �������
	void bullet_destroy(int &index);//������ ���� ����� ����� �� ������� ������
	void setposition(float x, float y);//������������ ������� ��� �������
	void move_enemies();//������ ������� �� �����

};