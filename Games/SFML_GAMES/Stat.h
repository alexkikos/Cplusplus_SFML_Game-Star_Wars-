#pragma once
#include "Ship.h"

struct StatBat
{
	Sprite stat_bar_sprite;//������ ������ �� � ��������
	Texture texture;
	Font font;
	Text text;
	void setbar(string source_sprite, string source_fonts, float posx_where_put,float posy_where_put);//�������� ������� ��� ����
	void showstatbat(RenderWindow&windiw); //������ �� ������ �������
	void StatBarShowInfo(int param_for_show, RenderWindow& window, string command = "1");//��������� ������������ ��������� �� ������

};