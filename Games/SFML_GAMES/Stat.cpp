#include "Stat.h"

void StatBat::setbar(string source_sprite, string source_fonts, float posx_where_put, float posy_where_put)
{

	texture.loadFromFile(source_sprite);
	stat_bar_sprite.setTexture(texture);
	stat_bar_sprite.setPosition(posx_where_put, posy_where_put);
	font.loadFromFile(source_fonts);
	text.setFont(font);
}


void StatBat::showstatbat(RenderWindow& window)
{
	window.draw(stat_bar_sprite);

}

void StatBat::StatBarShowInfo(int param_for_show, RenderWindow& window, string command )
{
	if (command == "timer")
	{
		Color c;

		text.setPosition(stat_bar_sprite.getPosition().x + 40, stat_bar_sprite.getPosition().y);
		text.setFillColor(c.Red);
		int min = param_for_show / 60;
		int sec = param_for_show%60;
		string s = to_string(min);
		text.setString(s);
		window.draw(text);
		s = ":" + to_string(sec);
		text.setPosition(stat_bar_sprite.getPosition().x + 55, stat_bar_sprite.getPosition().y);
		text.setFillColor(c.Green);
		text.setString(s);
		window.draw(text);
	}
	else
	{
		string s = to_string(param_for_show);
		Color c;
		text.setPosition(stat_bar_sprite.getPosition().x + 50, stat_bar_sprite.getPosition().y + 10);
		text.setFillColor(c.Green);
		text.setString(s);
		window.draw(text);
	}

}

