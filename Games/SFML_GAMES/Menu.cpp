#include "Menu.h"
#include <fstream>
#include <iomanip>
void Menu::setmenu(char** menus_textures, float posx, float posy)
{
	float height = 0;
	menut_text = new Texture[size_menus];
	menu_sprites = new Sprite[size_menus];
	for (int i = 0; i < size_menus; i++)
	{
		menut_text[i].loadFromFile(menus_textures[i]);
		menu_sprites[i].setTexture(menut_text[i]);
		if (i == 0)
		{
			continue; //первый спрайт идет фоном
		}
		else
		{
			if ( i > 1) height = menu_sprites[i - 1].getTextureRect().height;
			menu_sprites[i].setPosition(posx, posy += 10+height);
		}
	}



}

void Menu::setmusic(string source)
{
	music.openFromFile(source);

}

void Menu::setsound(string sound_source)
{
		soundbuffer.loadFromFile(sound_source);
		sound.setBuffer(soundbuffer);
}


void  Menu::getshifr(string& name)
{
	for (int i = 0; i < name.length(); i++)
	{
		name[i] += SHIFR;
	}
}

void  Menu::getshifr(int& name)
{
	name += SHIFR;
}


int Menu::ShowStartMenu(RenderWindow& window, int ship_hp, int window_Height, int window_Width, bool winner)
{
	//ретурн коды 1 - перезапуск игры, 2 - продолжить, 3 - standart 4 - fort
	Event my;
	bool check_name = false;
	bool stat = false;
	bool infogame = false;
	bool fort = false;
	bool menu_stat = false;
	Font font;
	Text text, text2;
	Color color;
	string playerInput;
	int shifr = 10;
	while (menu_flag)
	{
	
		if (music.getStatus() == 0 or music.getStatus() == 1)  music.play();
		while (window.pollEvent(my))
		{
			if (my.type == Event::Closed)
				window.close();

			Mouse mouse;
			for (int i = 0; i < size_menus; i++)
			{	
				float height1 = menu_sprites[i].getTextureRect().height;
				float widht1 = menu_sprites[i].getTextureRect().width;
				if (i == 1) //начать игру
				{	
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Magenta);
						if (mouse.isButtonPressed(mouse.Left))
						{						
							menu_flag = false;	
							stat = false;
							check_name = false;
							infogame = false;
							return 1;
						}				
					}
					else 		
					{
						menu_sprites[i].setColor(color.White);
						
					}				
				}
				if (i == 2 and ship_hp > 0 and !winner) //продолжить игру
				{		
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Blue);
						if (mouse.isButtonPressed(mouse.Left))
						{
							menu_flag = false;		
							stat = false;
							check_name = false;
							infogame = false;				
							fort = false;
							menu_stat = false;
							return 2;
						}
					}
					else
					{
						menu_sprites[i].setColor(color.White);

					}

				}
				if (i == 3) //пновый игрок
				{
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Red);
						if (mouse.isButtonPressed(mouse.Left))
						{
							check_name = true;		
							stat = false;
							infogame = false;
							fort = false;		
							menu_stat = false;
							text2.setPosition(menu_sprites[i].getPosition().x + 200, menu_sprites[i].getPosition().y);
							text.setPosition(menu_sprites[i].getPosition().x+350, menu_sprites[i].getPosition().y);
						}					
					} 
					else
					{
						menu_sprites[i].setColor(color.White);
					}
		
				}
				if (i == 4) //статистика
				{
					
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Green);
						if (mouse.isButtonPressed(mouse.Left))
						{					
							check_name = false;
							infogame = false;
							menu_stat = true;
						}

					}
					else
					{
						menu_sprites[i].setColor(color.White);
					}
					if (menu_stat)
					{
						menu_sprites[9].setPosition(menu_sprites[i].getPosition().x + 170, menu_sprites[i].getPosition().y);
						menu_sprites[10].setPosition(menu_sprites[i].getPosition().x + 170, menu_sprites[i].getPosition().y + 40);
						window.draw(menu_sprites[9]);
						window.draw(menu_sprites[10]);
						if (IntRect(menu_sprites[9].getPosition().x, menu_sprites[9].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
						{
							sound.play();
							menu_sprites[9].setColor(color.Red);
							if (mouse.isButtonPressed(mouse.Left))
							{

								stat = true;
								fort = false;
							}
						}
						else
						{
							menu_sprites[9].setColor(color.White);
						}

						if (IntRect(menu_sprites[10].getPosition().x, menu_sprites[10].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
						{
							sound.play();
							menu_sprites[10].setColor(color.Green);
							if (mouse.isButtonPressed(mouse.Left))
							{

								fort = true;
								stat = true;
							}
						}
						else
						{
							menu_sprites[10].setColor(color.White);
						}
					}			

							
				}
				if (i == 5) //режим игры
				{
					if (infogame)
					{
						menu_sprites[9].setPosition(menu_sprites[i].getPosition().x + 170, menu_sprites[i].getPosition().y);
						menu_sprites[10].setPosition(menu_sprites[i].getPosition().x + 170, menu_sprites[i].getPosition().y+40);
						window.draw(menu_sprites[9]);		
						window.draw(menu_sprites[10]);
						if (IntRect(menu_sprites[9].getPosition().x, menu_sprites[9].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
						{
							sound.play();
							menu_sprites[9].setColor(color.Red);
							if (mouse.isButtonPressed(mouse.Left))
							{
								infogame = false;	
								fort = false;
								menu_stat = false;
								stat = false;
								return 3;//standart
							}
						}
						else
						{
							menu_sprites[9].setColor(color.White);
						}

			
						if (IntRect(menu_sprites[10].getPosition().x, menu_sprites[10].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
						{
							sound.play();
							menu_sprites[10].setColor(color.Green);
							if (mouse.isButtonPressed(mouse.Left))
							{
								infogame = false;//fort
								fort = false;
								menu_stat = false;
								stat = false;
								return 4;
							}

						}
						else
						{
							menu_sprites[10].setColor(color.White);
						}


					}
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Blue);
						if (mouse.isButtonPressed(mouse.Left))
						{
							check_name = false;
							stat = false;
							infogame = true;
							fort = false;
							menu_stat = false;
						}
					}
					else
					{
						menu_sprites[i].setColor(color.White);
					}

				}
				if (i == 6) //выйти
				{
					if (IntRect(menu_sprites[i].getPosition().x, menu_sprites[i].getPosition().y, widht1, height1).contains(mouse.getPosition(window)))
					{
						sound.play();
						menu_sprites[i].setColor(color.Yellow);
						if (mouse.isButtonPressed(mouse.Left))
						{
							window.close();
						}
					}
					else 
					{
						menu_sprites[i].setColor(color.White);
					}
		
				}
				if (i == 7 and winner) //спрайт winn
				{
					menu_sprites[i].setPosition(menu_sprites[i - 1].getPosition().x, menu_sprites[i - 1].getPosition().y);
					window.draw(menu_sprites[i]);
				}
				if (i == 8 and ship_hp < 1) //спрайт луза
				{
					menu_sprites[i].setPosition(menu_sprites[i-2].getPosition().x, menu_sprites[i-2].getPosition().y);		
					window.draw(menu_sprites[i]);
				}	
				

				if (i == 7 or i == 8 or i == 9 or i == 10) continue; else  window.draw(menu_sprites[i]);
			}
			if (check_name)
			{
				font.loadFromFile("Fonts/8209.ttf");
				text.setFont(font);
				text.setFillColor(color.Yellow);
				text2.setFont(font);
				text2.setString("enter name: ");
				text2.setFillColor(color.Red);
				text2.setCharacterSize(36);
				text.setCharacterSize(36);
				if (my.type == my.TextEntered)
				{
					if (my.text.unicode != 8 and my.text.unicode != 13 and playerInput.length() < 11)
					{
						playerInput += my.text.unicode;			
						text.setString(playerInput);
					}
					else
					if (my.text.unicode == 13)
					{
						username = playerInput;
						check_name = false;
					}
					else
					if (my.text.unicode == 8 and playerInput.length() > 0)
					{		
						playerInput.pop_back();
						text.setString(playerInput);
					}
				}
				window.draw(text2);
				window.draw(text);
			}
			if (stat) //рисую статистику
			{
				ifstream read;
				if (fort==true)
				{
					read.open("fort.dat");
				}
				else  read.open("game_result.dat");

				if (read.is_open())
				{
					string s,s1;
					Text mtext, table;
					Font mfont,fonttable;
					Color b;
			
					fonttable.loadFromFile("Fonts/8209.ttf");
					table.setFont(mfont);
					table.setFillColor(b.Green);
					s1 = "Player name     PlayerHP     CillCOunt     SpendBullet    TimeOnMap";
					table.setPosition(window_Width / 2-250, 20);
					table.setString(s1);
			



					mfont.loadFromFile("Fonts/8209.ttf");
					mtext.setFont(mfont);
					int temp_y = 25;
					int temp_x = 240;
					mtext.setCharacterSize(26);				
					while (!read.eof())
					{
						string name;
						Color g;
						int a, b, c,e;
						read >> name >> a >> b >> c >> e;
						if (name.length() != 0)
						{
							getshifr(name);
							mtext.setString(name);
							mtext.setPosition(window_Width / 2 - temp_x, temp_y += mtext.getCharacterSize() + 10);
							mtext.setFillColor(g.Yellow);
							window.draw(mtext);
							window.draw(table);	

							getshifr(a);
							mtext.setString(to_string(a));
							mtext.setPosition(window_Width / 2 - temp_x + 190, temp_y);
							mtext.setFillColor(g.Cyan);
							window.draw(mtext);
							window.draw(table);


							getshifr(b);
							mtext.setString(to_string(b));
							mtext.setPosition(window_Width / 2 - temp_x + 340, temp_y);
							mtext.setFillColor(g.Red);
							window.draw(mtext);
							window.draw(table);

							getshifr(c);
							mtext.setString(to_string(c));
							mtext.setPosition(window_Width / 2 - temp_x + 490, temp_y);
							mtext.setFillColor(g.Magenta);
							window.draw(mtext);
							window.draw(table);

							getshifr(e);
							mtext.setString(to_string(e));
							mtext.setPosition(window_Width / 2 - temp_x + 645, temp_y);
							mtext.setFillColor(g.Cyan);
							window.draw(mtext);
							window.draw(table);
						}
					}	
					read.close();
				}
				
				read.close();
			}
			window.display();
		}
	}
	if (music.getStatus() == 2) music.stop();
	return 0;
}
