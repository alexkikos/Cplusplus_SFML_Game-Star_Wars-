#pragma once
#include "Ship.h"


struct Menu
{

	Texture* menut_text = nullptr;
	Sprite *menu_sprites = nullptr;
	Music music;
	Sound sound;
	SoundBuffer soundbuffer;
	string username;//записываю юзера в меню а потом передаю название в название нашего корабл€
	int music_sound = 2;//количество звуков в мен€, 1 музыка - фонова€, 2 музыка отвечает за щелканье по спрайтам меню(кнопкам)
	int size_menus = 3;//количество спрайтов в меню
	bool menu_flag = true;//флаг активируетс€ и наоборот при наведении на спрайт в меню




	void setmenu(char **menus_textures, float posx, float posy);//устанавливаю меню
	void setmusic(string source);//загружаю музыку
	void setsound(string sound_source);//загружаю звуки
	void getshifr(string& name);//выполн€ю расшифровку данных
	void getshifr(int& name);//расшифровка дл€ цифр данных

	int ShowStartMenu(RenderWindow& window, int ship_hp, int window_Height, int window_Width, bool winner=false);

};