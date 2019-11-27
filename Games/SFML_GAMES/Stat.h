#pragma once
#include "Ship.h"

struct StatBat
{
	Sprite stat_bar_sprite;//спрайт нашего нр и снарядов
	Texture texture;
	Font font;
	Text text;
	void setbar(string source_sprite, string source_fonts, float posx_where_put,float posy_where_put);//загружаю спрайты для меню
	void showstatbat(RenderWindow&windiw); //вывожу на экране спрайты
	void StatBarShowInfo(int param_for_show, RenderWindow& window, string command = "1");//отображаю определенные параметры на жкране

};