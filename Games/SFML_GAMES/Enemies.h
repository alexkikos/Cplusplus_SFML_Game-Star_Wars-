#pragma once
#include "Ship.h"


struct Enemies
{
	Sprite ship_sprite;
	Texture ship_texture;
	CircleShape* bullets = nullptr;
	float speed_ship = 0.05;
	float speed_bullet = speed_ship * 2;
	int size_bullets = 0;//записываю сколько пуль было выпушено для их подальшего удаления
	int hp_points=1;//количество нр
	bool flag_shoot = false;//флаг для отслеживания стрелял корабль или нет, 1 выстрел при каждом новом респе



	void move_bullet();//двигаю пули по вектору
	void createship(char**& texture, int);//создаю корабли
	void shoot();//стреляем
	void show_bullets(RenderWindow& window);//отрисосываю пули
	void show_ship();//отрисосываю корабли
	void bullet_destroy(int &index);//удаляю пули когда вышли за границы экрана
	void setposition(float x, float y);//устанавливаю пощицию для корабля
	void move_enemies();//двигаю корабли по карте

};