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
	FindItems *finditems=nullptr;//���������� ������ �� ����� = ����� ���� �����

	float time_for_display_items = 10;//����� ��� ����������� ��������� ������ �� �����, � ��������
	int get_more_hp_for_items = 5;//����� �������� ���� �� ���������� ������


	

	int size_finders_items = 0;//������� ������ �� ����� �������� ��� ���������� � �����������
	int total_stat_bar=3;// ������� ��������  = ������ ����� ����������, ������ 3 = ��, ���������� ������ ������, ����� ����������� ����
	int Height;//������ � ������ �������� ����
	int Width;


	int size_enemies=0;
	int damage_from_bullet = 3;//��������� ������ �� � ������� ��� ������������ � �����
	int damafe_when_collisium_ships = 5;//������� �� �������� ��� ������������ ��������
	int time_for_call_rb = 120;//sec
	int total_time_om_map = 0;//����� ������� ������� �� �����





	int fps_down_time = 300;
	int time_wave = 55;//������� ������� ������ 1 �����, ����� ��������� �������� ���� ��������
	int percent_to_add_param_for_wave_enemies = 4;//���������� ��������� �������� ��������, �������� �� 1/6 �����
	//int percent_to_add_for_bullets = 8;//���������� ��������� �������� �������� ���� �������� �� 1/4�����
	int percent_to_add_move_myship = 2;


	bool rb_room = false;


	void setzonemusic(string s);//������������ ������ �����
	void createzone(string texture);//������ ����� = ������� ���������
	void showzone(RenderWindow& window);//������� �� ������ ����� ���� ��� ��� �������������� � ��������� ����
	void showallenemies(RenderWindow& window);//������������ ��������� �������
	void CreateEnemiesOnmap(char**textures, int size_textures);//�������� ��������� ��������
	void SetVectorMoviesForenemies(float speed);//������������ ��� ���� ������ ������ ��������
	void zonemoveallenemies();//�������� ���� ������ ��������� � ���� ������� �� ����� �������� , �������� ��������������� ����
	void EnemyShoot();//�������� ��������� ��������
	void ShowEnemieshBullet(RenderWindow& window);//����������� ���� ������
	void ChangePositionEnemies();//����� ����� �������� ����� ������, ������ ���� ������� � ������������ ���� ��������
	void ColliSium();//������������ � ������ ������ ����
	void move_ship();//�������� ������ ������� � ��������
	void UpspeedAllenemies();//� ������ ������, �������� ������ ����������
	void showstatbar(RenderWindow& window);//����������� ���������� ��������
	void showitems(RenderWindow& window);//��������� ����� ������� ����� �������� ���������� �� �����
	void SaveResults(bool save_fort=false);//�������� ����������, ��� ���� = ��������� ��� �����
	string setshifr(string name);//�������� ������ ��� �������
	void setshifr(int& name);//��� �����

	void SetZoneFont(string source_font, int size_letter=30);//�������� � ������������ ����� ����,
	void ShowZoneName(RenderWindow& window, float posx, float posy);//��������� �������� ����, ���� ��� �������� ��� ������ ����������� ����� �������


	void ZoneStart(RenderWindow& window);//����� ����


};