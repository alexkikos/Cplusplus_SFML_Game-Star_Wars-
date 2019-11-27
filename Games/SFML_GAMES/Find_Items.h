#pragma once
#include "Ship.h"

struct FindItems
{
	Sprite item_sprite;
	Texture item_texture;
	Sound music;//кода мы стреляем
	SoundBuffer music_buffer;
	bool show = true;//показываю итем
	bool start = false;//слежу стартовал отсчет времени до появления итема или нет

	void createitemlist(string source);//создаю итемы для отображения на карте
	void setmusic(string path_to_music);//подгружаю для каждого итема музыку, по желани.
	float starttime(string command);//обработка комманд для итемов


};