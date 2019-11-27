#include "Zone.h"

void Zone::setzonemusic(string s)
{
	zone_music.openFromFile(s);
}

void Zone::createzone(string texture)
{
	zone_texture.loadFromFile(texture);
	zone_sprite.setTexture(zone_texture);
}

void Zone::showzone(RenderWindow& window)
{
	window.draw(zone_sprite);

}

void Zone::showallenemies(RenderWindow& window)
{
	for (int i = 0; i < size_enemies; i++)
	{
		window.draw(enemies[i].ship_sprite);
	}


}

void Zone::CreateEnemiesOnmap(char** textures, int size_textures)
{
	int count = 0;
	for (int i = 0; i < size_enemies; i++)
	{
		if (count >= size_textures) count = 0;
		enemies[i].createship(textures, count++);
		enemies[i].setposition(rand() % Height, rand() % Width / 4);

	}
}

void Zone::SetVectorMoviesForenemies(float speed)
{
	for (int i = 0; i < size_enemies; i++)
	{
		enemies[i].speed_ship = speed;
		enemies[i].speed_bullet = speed *2;
	}

}






void Zone::zonemoveallenemies()
{
	for (int i = 0; i < size_enemies; i++)
	{
		enemies[i].move_bullet();
		enemies[i].move_enemies();
	
	}
}

void Zone::EnemyShoot()
{
	for (int i = 0; i < size_enemies; i++)
	{
		if (enemies[i].flag_shoot == false)
		{
			enemies[i].shoot();
		}

	}
}

void Zone::ShowEnemieshBullet(RenderWindow& window)
{
	for (int i = 0; i < size_enemies; i++)
	{

		enemies[i].show_bullets(window);

	}

}

void Zone::ChangePositionEnemies()
{

	for (int i = 0; i < size_enemies; i++)
	{
		if (enemies[i].ship_sprite.getPosition().y > Height)
		{
			enemies[i].flag_shoot = false;
			enemies[i].setposition(rand() % Width, rand() % Height / 8);
		}
	}


}



void Zone::ColliSium()
{

	float sh1 = myship.ship_sprite.getTextureRect().height;
	float sh2 = myship.ship_sprite.getTextureRect().width;//размер корабл€
	FloatRect colisium_myship(myship.ship_sprite.getPosition().x, myship.ship_sprite.getPosition().y, sh2, sh1);
	for (int i = 0; i < myship.size_bullets; i++)//удаление пуль из массива когда внеэкрана
	{
		if (myship.bullets[i].getPosition().y < 2)
		{
			myship.shoot_delete(i);
			i--;
		}
	}
	//проверка нахождени€ итемов
	for (int i = 0; i < size_finders_items; i++)
	{

		if (colisium_myship.contains(finditems[i].item_sprite.getPosition().x, finditems[i].item_sprite.getPosition().y))
		{
			if (i == 0)
			{
				myship.hp_points += get_more_hp_for_items;
				finditems[i].item_sprite.setPosition(0, 0);
				finditems[i].show = true;
				myship.music[4].play(); //apte4ka
				finditems[i].starttime("restart");//рестарчу врем€ респа итема после его подбора
			}
		}
	}

	for (int i = 0; i < size_enemies; i++)
	{
		for (int c = 0; c < enemies[i].size_bullets; c++)
		{
			if (colisium_myship.contains(enemies[i].bullets[c].getPosition().x, enemies[i].bullets[c].getPosition().y))//проверка попадани€ пули в наш корабль
			{
				if (enemies[i].size_bullets > 0)
				{
					enemies[i].bullet_destroy(c);//столкнулись и удалили пулю
					myship.hp_points -= damage_from_bullet;
					myship.music[3].play();
					c--;
				}
			}

		}
		for (int c1 = 0; c1 < enemies[i].size_bullets; c1++)
		{
			if (enemies[i].bullets[c1].getPosition().y > Height)//проверка выхода пули за границу экрана
			{
				enemies[i].bullet_destroy(c1);
				c1--;
			}
		}

		//проверка столкновений обоих кораблей
		float r1 = enemies[i].ship_sprite.getTextureRect().height;//дл€ простых врагов
		float r2 = enemies[i].ship_sprite.getTextureRect().width;
		//дл€ карты где простые корабли, провер€ю вхождение корабл€ врагов в свою текстуру
		if (colisium_myship.contains(enemies[i].ship_sprite.getPosition().x, enemies[i].ship_sprite.getPosition().y))
		{
			myship.hp_points -= damafe_when_collisium_ships;
			enemies[i].ship_sprite.setPosition(rand() % Width - Width / 12, rand() % Height / 4);//мен€ем позицию текстурки
			myship.music[2].play();

		}
		for (int j = 0; j < myship.size_bullets; j++)//коллизи€ моей пули и текстурки врагов
		{
			FloatRect enemy1(enemies[i].ship_sprite.getPosition().x, enemies[i].ship_sprite.getPosition().y, r2, r1);
			if (enemy1.contains(myship.bullets[j].getPosition().x, myship.bullets[j].getPosition().y))
			{		
				myship.shoot_delete(j);
				myship.score++;//+++к рейтингу за попадание		
				enemies[i].hp_points--;
				myship.music[1].play();
				enemies[i].ship_sprite.setPosition(rand() % Width - Width / 12, rand() % Height / 4);
				enemies[i].flag_shoot = false;
				j--;
			}
		}

	}
}

void Zone::move_ship()
{

	if ((MyBoard.isKeyPressed(MyBoard.Up) or MyBoard.isKeyPressed(MyBoard.W)) and myship.ship_sprite.getPosition().y > 5) myship.ship_sprite.move(0, -myship.speed_ship);
	if ((MyBoard.isKeyPressed(MyBoard.Down) or MyBoard.isKeyPressed(MyBoard.S)) and myship.ship_sprite.getPosition().y < Height - 100) myship.ship_sprite.move(0, +myship.speed_ship);
	if ((MyBoard.isKeyPressed(MyBoard.Left) or MyBoard.isKeyPressed(MyBoard.A)) and myship.ship_sprite.getPosition().x > 5)  myship.ship_sprite.move(-myship.speed_ship, 0);
	if ((MyBoard.isKeyPressed(MyBoard.Right) or MyBoard.isKeyPressed(MyBoard.D)) and myship.ship_sprite.getPosition().x < Width - 10)  myship.ship_sprite.move(+myship.speed_ship, 0);

}





void Zone::UpspeedAllenemies()
{

	fps_down_time -= fps_down_time/ percent_to_add_param_for_wave_enemies;
	myship.speed_ship += myship.speed_ship / percent_to_add_move_myship;

}








void Zone::showstatbar(RenderWindow& window)
{
	for (int i = 0; i < total_stat_bar; i++)
	{
		statbar[i].showstatbat(window);
	}
}

void Zone::showitems(RenderWindow& window)
{
	for (int i = 0; i < size_finders_items; i++)
	{

		float a = finditems[i].starttime("gettime");
		if ((finditems[i].show == true) and a >= time_for_display_items)
		{

			finditems[i].show = false;
			finditems[i].music.play();
			finditems[i].item_sprite.setPosition(rand() % (Width - 100) + 40, rand() % (Height - 100) + 40);

		}
		if ((finditems[i].show == true and finditems[i].start == false))
		{
			finditems[i].starttime("start");
			finditems[i].start = true;
		}
	}


	for (int i = 0; i < size_finders_items; i++)
	{
		if (finditems[i].show == false)
		{
			window.draw(finditems[i].item_sprite);
		}
	}

}



string  Zone::setshifr(string name)
{
	string s = name;
	for (int i = 0; i < s.length(); i++)
	{
		s[i] -= SHIFR;
	}
	return s;
}

void  Zone::setshifr(int& name)
{
	name -= SHIFR;
}

void Zone::SetZoneFont(string source_font, int size_letter)
{
	font.loadFromFile(source_font);
	text.setFont(font);
	text.setCharacterSize(size_letter);
}

void Zone::ShowZoneName(RenderWindow& window, float posx, float posy)
{

	text.setString(zonename);
	text.setFillColor(color.Red);
	text.setPosition(posx, posy);
	window.draw(text);
}

void Zone::SaveResults(bool save_fort)
{
	if (save_fort==true)
	{
		ofstream write("fort.dat", ios::app);
		if (write.is_open())
		{

			string tmp = setshifr(myship.ship_name);
			setshifr(myship.hp_points);
			setshifr(myship.score);
			setshifr(myship.total_bullets);
			setshifr(total_time_om_map);
			write << tmp << " " << myship.hp_points << " " << myship.score << " " << myship.total_bullets << " " << total_time_om_map << "\n";
		}
		write.close();
	}
	else
	{
		ofstream write("game_result.dat", ios::app);
		if (write.is_open())
		{

			string tmp  = setshifr(myship.ship_name);
			setshifr(myship.hp_points);
			setshifr(myship.score);
			setshifr(myship.total_bullets);
			setshifr(total_time_om_map);
			write << tmp << " " << myship.hp_points << " " << myship.score << " " << myship.total_bullets << " " << total_time_om_map << "\n";
		}
		write.close();
	}
	

}








void Zone::ZoneStart(RenderWindow& window)
{
	showzone(window);//показываю спрайт карты
	ShowZoneName(window,  130, 10);
	statbar[0].StatBarShowInfo(myship.hp_points, window);//рисую статбары слева в углу, нр, количество убитых врагов, потаченные пули и таймер часов на карте
	statbar[1].StatBarShowInfo(myship.score, window);
	statbar[2].StatBarShowInfo(myship.total_bullets, window);
	statbar[3].StatBarShowInfo(total_time_om_map, window, "timer");
	if (rb_room)//статус бар с нр дл€ рб
	{
		statbar[4].StatBarShowInfo(enemies[0].hp_points, window);//спрайт рейд босса
	}
	if (zone_music.getStatus() == 0)
	{
		zone_music.play();
	}	

	Clock static time1;
	float time_shoot = time1.getElapsedTime().asMilliseconds();

	if (time_shoot >= myship.delay_myship_shutting)//задержка на выстрелы с нашего корабл€, чтобы небыло дикого спама пуль
	{
		time1.restart();
		myship.shoot();
		
	}


	///////////
	///////////////////////////√–ј‘» ј ¬–ј√ќ¬
	showallenemies(window);//рисую врагов
	ShowEnemieshBullet(window);//рисую пули врагов
	zonemoveallenemies();//двигаем все элименты врагов по вектору
	ChangePositionEnemies();//мен€ю позиции врагам с соотв услови€ми
	EnemyShoot();//стрельба врагов
	showitems(window);//оотображение рандом итемов на карте, структура find_items
	////////////////////////////////////////
	//////////√–ј‘» ј ЌјЎ≈√ќ  ќ–јЅЋя
	Clock static clock;
	float time = clock.getElapsedTime().asSeconds();
	if (time > time_wave)//ап скорость всех врагов через определенное врем€
	{
		clock.restart();
		time = 0;
		UpspeedAllenemies();
	}
	showstatbar(window);//рисую спрайта статус бара
	window.draw(myship.ship_sprite);//рисую спрайт корабл€ нашего
	move_ship();//движение корабл€

	myship.move_bullets();//двигаю по вектору свои пули
	myship.show_bullets(window);//рисуюсвои пули
	ColliSium();//вс€ физика игры - взаимодействие с различными врагами и тд
	/////////////////////////////////////////

}
