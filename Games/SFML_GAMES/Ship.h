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
	CircleShape* bullets=nullptr;//массив пуль которые мы стреляем = белыю пули на экране
	Sound *music=nullptr;//звуки при столкновении, попадании пуль по нам, использование аптечки на карте
	SoundBuffer *music_buffer=nullptr;//
	string ship_name= "default";//параметр для сохранения имени пользхователя в статистику
	float speed_ship = 0.13;//скорость перемещения корабле по карте
	float speed_bullet = -0.13;
	int size_bullets = 0;//количество пуль которые были выпущены 
	int hp_points=30;//количество нр корабля
	int total_bullets = 0;//количество сделанных выстрелов за все время на карте, для статистики
	int score = 0;//сколько врагов подбили, для статистики
	int delay_myship_shutting = 100;//задержка на выстрелы, работает в связке с майклок  milisec


	void createship(char**&texture, int);//создаю корабдь
	void shoot();//стреляем
	void shoot_delete(int index_to_delete);//удаление пули с экрана
	void move_bullets();//векторное движение пуль
	void show_bullets(RenderWindow &window);//рисуем пули на жкране
	void setposition(float x, float y);//устанавливаю позицию корабля
	void setmusic(char**);//загружаю музыку

};

