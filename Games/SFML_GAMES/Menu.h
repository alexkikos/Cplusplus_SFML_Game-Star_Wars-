#pragma once
#include "Ship.h"


struct Menu
{

	Texture* menut_text = nullptr;
	Sprite *menu_sprites = nullptr;
	Music music;
	Sound sound;
	SoundBuffer soundbuffer;
	string username;//��������� ����� � ���� � ����� ������� �������� � �������� ������ �������
	int music_sound = 2;//���������� ������ � ����, 1 ������ - �������, 2 ������ �������� �� �������� �� �������� ����(�������)
	int size_menus = 3;//���������� �������� � ����
	bool menu_flag = true;//���� ������������ � �������� ��� ��������� �� ������ � ����




	void setmenu(char **menus_textures, float posx, float posy);//������������ ����
	void setmusic(string source);//�������� ������
	void setsound(string sound_source);//�������� �����
	void getshifr(string& name);//�������� ����������� ������
	void getshifr(int& name);//����������� ��� ���� ������

	int ShowStartMenu(RenderWindow& window, int ship_hp, int window_Height, int window_Width, bool winner=false);

};