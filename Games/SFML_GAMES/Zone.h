#pragma once

#include "Enemies.h"
#include "Stat.h"
#include "Find_Items.h"
#include <fstream>



struct Zone
{

	string zonename="Game: Standart";
	Text text;
	Font font;
	Color color;
	Texture zone_texture;
	Sprite zone_sprite;
	Enemies *enemies = nullptr;
	Ship myship;
	Keyboard MyBoard;
	Music zone_music;
	StatBat* statbar = nullptr;
	FindItems *finditems=nullptr;//количество итемов на карте = может быть много

	float time_for_display_items = 10;//время для отображения рандомных итемов на карте, в секуднах
	int get_more_hp_for_items = 5;//какая прибавка идет от нахождения итемов


	

	int size_finders_items = 0;//сколько итемов на карте доступно для нахождения и отображения
	int total_stat_bar=3;// сколько спрайтов  = статус баров отображаем, дефолт 3 = нр, количество убитых врагов, колво потраченных пуль
	int Height;//высота и ширина игрового поля
	int Width;


	int size_enemies=0;
	int damage_from_bullet = 3;//параметры отбора нр у корабля при столкновении с пулей
	int damafe_when_collisium_ships = 5;//сколько нр отбираем при столкновении кораблей
	int time_for_call_rb = 120;//sec
	int total_time_om_map = 0;//время которое провели на карте





	int fps_down_time = 300;
	int time_wave = 55;//сколько времени длится 1 волна, после ускорение скорости всех кораблей
	int percent_to_add_param_for_wave_enemies = 4;//показатель повышения скорости кораблей, повышаем на 1/6 часть
	//int percent_to_add_for_bullets = 8;//показатель повышения скорости движения пуль повыжает на 1/4часть
	int percent_to_add_move_myship = 2;


	bool rb_room = false;


	void setzonemusic(string s);//устанавливаю музыку карты
	void createzone(string texture);//создаю карту = фоновая текстурка
	void showzone(RenderWindow& window);//передаю по ссылке адрес окно где все отрисоыввается и показываю зону
	void showallenemies(RenderWindow& window);//прорисовываю вражеские корабли
	void CreateEnemiesOnmap(char**textures, int size_textures);//создание вражеских кораблей
	void SetVectorMoviesForenemies(float speed);//устанавливаю для всех врагов вектор движения
	void zonemoveallenemies();//указываю всем врагам двигаться в свое векторе на своей скорости , скорость устанавливается выше
	void EnemyShoot();//стрельба вражеских кораблей
	void ShowEnemieshBullet(RenderWindow& window);//прорисоываю пули врагов
	void ChangePositionEnemies();//когда вроги достигли конца экрана, меняют свою позицию и активируется флаг стрельбы
	void ColliSium();//столкновение и чистка лишних пуль
	void move_ship();//движение нашего корабля и стрельба
	void UpspeedAllenemies();//с каждой волной, скорость врагов ускоряется
	void showstatbar(RenderWindow& window);//отображение статистики кораблей
	void showitems(RenderWindow& window);//показываю итемы которые могут рандомно появляться на карте
	void SaveResults(bool save_fort=false);//сохраняю результаты, бул труе = результат для форта
	string setshifr(string name);//шифрация данных для стринга
	void setshifr(int& name);//для интов

	void SetZoneFont(string source_font, int size_letter=30);//загружаю и устанавливаю шрифт щоны,
	void ShowZoneName(RenderWindow& window, float posx, float posy);//отображаю название зоны, ФОрт или стандарт при помощи загруженных ранее шрифтов


	void ZoneStart(RenderWindow& window);//страт зоны


};