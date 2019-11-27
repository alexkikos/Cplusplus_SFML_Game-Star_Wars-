#pragma once
#include "Ship.h"

struct FindItems
{
	Sprite item_sprite;
	Texture item_texture;
	Sound music;//���� �� ��������
	SoundBuffer music_buffer;
	bool show = true;//��������� ����
	bool start = false;//����� ��������� ������ ������� �� ��������� ����� ��� ���

	void createitemlist(string source);//������ ����� ��� ����������� �� �����
	void setmusic(string path_to_music);//��������� ��� ������� ����� ������, �� ������.
	float starttime(string command);//��������� ������� ��� ������


};