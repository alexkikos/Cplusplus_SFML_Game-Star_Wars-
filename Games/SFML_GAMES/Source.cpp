#include "Zone.h"
#include "Menu.h"

#define zone_down_fps 300

#define my_speed_ship 0.14
#define my_speed_bullet -0.12
#define count_enemies 25


#define my_ship_hp  50
#define my_score 0
#define my_total_bullets  0

#define my_ship_time_on_map  0
#define my_ship_delay_shoot 70 //milisec


#define enemies_speed_ships 0.05;
#define raid_hp 20;






int main()
{
	srand(time(0));

	//VideoMode desk = VideoMode(1024, 768);

	VideoMode desk = VideoMode::getDesktopMode();
	RenderWindow window(desk, "StarWars");
	Vector2u wind_size = window.getSize();
	Event event;
	Zone zone1, raid;
	Menu menu;
	Keyboard Myboard;
	int Height = wind_size.y - 50;
	int Width = wind_size.x - 50;


	/////////////������ ����
	menu.size_menus = 11;
	char** menus = new  char* [menu.size_menus];
	menus[0] = new char[50]{ "Menu/menu.jpg" };//������� �������� ������ ����
	menus[1] = new char[50]{ "Menu/new_game.png" };//��������� ������ ��������� ��� ����� ������
	menus[2] = new char[50]{ "Menu/continue.png" };	//������ ������ ����
	menus[3] = new char[50]{ "Menu/newuser.png" };//Monotype Corsiva 16
	menus[4] = new char[50]{ "Menu/showinfo_game.png" };//Monotype Corsiva 16
	menus[5] = new char[50]{ "Menu/info.png" };
	menus[6] = new char[50]{ "Menu/exit.png" };
	menus[7] = new char[50]{ "Menu/Winner.png" };
	menus[8] = new char[50]{ "Menu/Looser.png" };
	menus[9] = new char[50]{ "Menu/standart.png" };
	menus[10] = new char[50]{ "Menu/fort.png" };
	menu.setmenu(menus, 60, 150);//�������� ����
	menu.setmusic("Sounds/menu_music.ogg");
	menu.setsound("Sounds/enemies_down.ogg");



	/////��������� �����/////////////////////////////////////////	
	zone1.createzone("textures/fonart.jpg");
	zone1.setzonemusic("Sounds/zone1.ogg");
	zone1.zone_music.setVolume(100);
	zone1.zone_sprite.scale(2, 1);//������� �������� ���������������
	zone1.Height = Height;
	zone1.Width = Width;
	zone1.size_finders_items = 1;
	zone1.finditems = new FindItems[zone1.size_finders_items];
	zone1.finditems[0].createitemlist("textures/medical.png");
	zone1.finditems[0].setmusic("Sounds/new_item_map.ogg");
	zone1.SetZoneFont("Fonts/8209.ttf");


	//////��������� ������ ����////////////////
	zone1.total_stat_bar = 4;
	zone1.statbar = new StatBat[zone1.total_stat_bar];
	zone1.statbar[0].setbar("textures/life.png", "Fonts/8209.ttf", 10, 10);
	zone1.statbar[1].setbar("textures/cill_count.png", "Fonts/8209.ttf", 10, 70);
	zone1.statbar[2].setbar("textures/bullet_count.png", "Fonts/8209.ttf", 10, 140);
	zone1.statbar[3].setbar("textures/timer.png", "Fonts/8209.ttf", Width / 2 - 50, 20);




	///////////���� ������//////////////
	char** texture_ship = new char* [1];
	texture_ship[0] = new char[30]{ "textures/ship1.png" };
	zone1.myship.createship(texture_ship, 1);
	zone1.myship.speed_bullet = my_speed_bullet;//������  0.15
	zone1.myship.speed_ship = my_speed_ship;
	zone1.myship.score = my_score;
	zone1.myship.total_bullets = my_total_bullets;
	zone1.myship.hp_points = my_ship_hp;
	zone1.total_time_om_map = my_ship_time_on_map;
	zone1.myship.delay_myship_shutting = my_ship_delay_shoot;
	zone1.myship.setposition(zone1.Height - 100, zone1.Width / 2);

	/////////////////////////////////////	




	/////////////////////////////////////	  
	////��������� �������� �������� �����
	char** sounds = new char* [5];
	sounds[0] = new char[30]{ "Sounds/shot_my_ship.ogg" };
	sounds[1] = new char[30]{ "Sounds/enemies_down.ogg" };
	sounds[2] = new char[30]{ "Sounds/bad_driver.ogg" };
	sounds[3] = new char[50]{ "Sounds/bullet_from_enemies.ogg" };
	sounds[4] = new char[50]{ "Sounds/apteka.ogg" };
	zone1.myship.setmusic(sounds);
	//////////////////////////////








	///////////�����/////////////////////////////////////	
	zone1.size_enemies = count_enemies;
	float enemys_speed_ship = enemies_speed_ships;
	zone1.enemies = new Enemies[zone1.size_enemies];
	char** texture_ship1 = new char* [7];
	int size_texutres = 7;
	texture_ship1[0] = new char[30]{ "textures/enemies1.png" };
	texture_ship1[1] = new char[30]{ "textures/enem2.png" };
	texture_ship1[2] = new char[30]{ "textures/enem3.png" };
	texture_ship1[3] = new char[30]{ "textures/enem4.png" };
	texture_ship1[4] = new char[30]{ "textures/enem5.png" };
	texture_ship1[5] = new char[30]{ "textures/enem6.png" };
	texture_ship1[6] = new char[30]{ "textures/enem7.png" };
	zone1.CreateEnemiesOnmap(texture_ship1, size_texutres);
	zone1.SetVectorMoviesForenemies(enemys_speed_ship);
	///////////////////////////////////////////////////////


	//--------------------RAID BOSS--------------------------------------------------------------------------------------------------------------

	///RAID ZONA///////
	raid.zonename = "Raid";
	raid.time_wave = 30;
	raid.createzone("textures/raid_room.jpg");
	raid.setzonemusic("Sounds/raid_boss.ogg");
	raid.SetZoneFont("Fonts/8209.ttf");
	//raid.zone_sprite.scale(2, 1);
	raid.Height = Height;
	raid.Width = Width;
	raid.damafe_when_collisium_ships = 5;
	raid.damage_from_bullet = 3;
	//////��������� ������ ����////////////////
	raid.total_stat_bar = 5;
	raid.statbar = new StatBat[raid.total_stat_bar];
	raid.statbar[0].setbar("textures/life.png", "Fonts/8209.ttf", 10, 10);
	raid.statbar[1].setbar("textures/cill_count.png", "Fonts/8209.ttf", 10, 70);
	raid.statbar[2].setbar("textures/bullet_count.png", "Fonts/8209.ttf", 10, 140);
	raid.statbar[3].setbar("textures/timer.png", "Fonts/8209.ttf", Width / 2 - 50, 20);
	raid.statbar[4].setbar("textures/life.png", "Fonts/8209.ttf", Width - 100, 10);




	///////////���� ������//////////////
	char** raidtexture_ship = new char* [1];
	raidtexture_ship[0] = new char[30]{ "textures/ship1.png" };
	raid.myship.createship(texture_ship, 1);
	raid.myship.speed_bullet = zone1.myship.speed_bullet;//������	
	raid.myship.setposition(raid.Height - 100, raid.Width / 2);
	raid.myship.delay_myship_shutting = my_ship_delay_shoot;
	/////////////////////////////////////	

	/////////////////////////////////////	  
	////��������� �������� ��������
	char** raidsounds = new char* [4];
	raidsounds[0] = new char[30]{ "Sounds/shot_my_ship.ogg" };
	raidsounds[1] = new char[30]{ "Sounds/enemies_down.ogg" };
	raidsounds[2] = new char[30]{ "Sounds/bad_driver.ogg" };
	raidsounds[3] = new char[50]{ "Sounds/bullet_from_enemies.ogg" };
	raid.myship.setmusic(raidsounds);
	//////////////////////////////
	///////////���� ����/////////////////////////////////////	
	raid.size_enemies = 12;
	raid.enemies = new Enemies[raid.size_enemies];
	char** raidtexture_ship1 = new char* [6];
	int raidsize_texutres = 6;
	raidtexture_ship1[0] = new char[30]{ "textures/raid1.png" };
	raidtexture_ship1[1] = new char[30]{ "textures/enemr1.png" };
	raidtexture_ship1[2] = new char[30]{ "textures/enemr2.png" };
	raidtexture_ship1[3] = new char[30]{ "textures/enemr3.png" };
	raidtexture_ship1[4] = new char[30]{ "textures/enemr4.png" };
	raidtexture_ship1[5] = new char[30]{ "textures/enemr5.png" };
	raid.CreateEnemiesOnmap(raidtexture_ship1, raidsize_texutres);
	float spped_rb = 1.5 * enemies_speed_ships;
	raid.SetVectorMoviesForenemies(spped_rb);
	raid.enemies[0].hp_points = raid_hp;
	//----------------------------------------------------------------------------------------------------------------------------------



	float rb_time;
	int ship_hp = my_ship_hp;
	int result=0;
	bool check = true;
	bool reset = false;
	bool fort = false;
	Clock   time_to_raid;
	Clock time_map;
	Clock fps;
	float getfps;


	while (window.isOpen())
	{



		while (window.pollEvent(event))// ������� �����, ��� ����������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
		}

		rb_time = time_to_raid.getElapsedTime().asSeconds();//������� ����� � ��� �� ���� �������
		result = menu.ShowStartMenu(window, ship_hp, Height, Width); //��������� ���������� � ���� � ����� ���

		
		getfps = fps.getElapsedTime().asMicroseconds();//������� ������� ������� ������ ����� ��������� ���� ��������
		fps.restart();


		if ((rb_time >= zone1.time_for_call_rb) and (fort == false))
		{
			if (check)//���� �� ������ � ��, �������� ���� ��������� � ���� 1 � �� ����, ��� �� ���������� � ����������� �����������
			{
				raid.myship.hp_points = zone1.myship.hp_points; //�������� ���� ���������� � ����� ����
				raid.myship.score = zone1.myship.score;
				raid.myship.total_bullets = zone1.myship.total_bullets;
				raid.myship.speed_ship = zone1.myship.speed_ship;
				zone1.zone_music.stop();
				ship_hp = raid.myship.hp_points;
				check = false;
				raid.rb_room = true;
			}
			raid.total_time_om_map = time_map.getElapsedTime().asSeconds();//��������� ����� ����������� �� ����� = ���������
			ship_hp = raid.myship.hp_points;//��������� �� ������� �� ������� ���������� ��� ������������ ��������� � ����, ��� ������ �������� ������ ���, ��� ���� ���
			raid.ZoneStart(window);//����� ����� �����
			if (getfps > 0)
			{
				///////////����������� ��� ������ ��////////////////////////
				getfps /= raid.fps_down_time;//���� ���������� �������� ���� �� ����������� �������� ��������, ����������� ��� ������ �� ���������
				raid.myship.speed_bullet = getfps * my_speed_bullet;//��������� �������� �������� �� ���������� ������� �������� ����
				raid.myship.speed_ship = getfps * my_speed_ship;
				enemys_speed_ship = getfps * enemies_speed_ships;
				raid.SetVectorMoviesForenemies(enemys_speed_ship);
				///////////////////////////////////////////////////////////////////////
			}

			if (raid.rb_room and raid.enemies[0].hp_points < 1)//���� � � ���� ������� � �� ����� ������ 1, � ��� ����, ��������� ����, ��������� ������ ������������, ���������� � ��������� ��� � ����
			{
				menu.menu_flag = true;
				raid.zone_music.stop();
				if (menu.username.length() != 0) raid.myship.ship_name = menu.username;//������� ��� ������������ ����������� � ����
				raid.SaveResults();
				ship_hp = my_ship_hp;
				result = menu.ShowStartMenu(window, ship_hp, Height, Width, true); //��������� ���������� � ����

			}
		}
		else
		{
			if (result >= 0 and result <= 2)
			{
				zone1.total_time_om_map = time_map.getElapsedTime().asSeconds();
				zone1.ZoneStart(window);
				///////////����������� ��� ������ ��////////////////////////
				if (getfps > 0)
				{
					getfps /= zone1.fps_down_time;//������� ����� ������� ���� ����
					zone1.myship.speed_bullet = getfps * my_speed_bullet;//��������� �������� �������� �� ���������� ������� �������� ����
					zone1.myship.speed_ship = getfps * my_speed_ship;
					enemys_speed_ship = getfps * enemies_speed_ships;
					zone1.SetVectorMoviesForenemies(enemys_speed_ship);
					/////////////////////////////////////////////////////////////////
				}
				ship_hp = zone1.myship.hp_points;

			}
		}






		if (result == 4)//����� �����
		{
			fort = true;//��������� ����� �����
			zone1.zonename = "Game: Fort";
			zone1.time_wave = 30;//����� �� �������� �������� ������������ ������ � ���
			reset = true;//��������� ����� �������� ��� ������� �� ������ ����� ����
		}
		else
			if (result == 3)//�������� �����
			{
				zone1.zonename = "Game: Standart";
				time_to_raid.restart();
				zone1.time_wave = 50;
				fort = false;//�������� ����� ������
				reset = true;
			}



		if (result == 1 or reset)//����� �������� ��� �������� �� ���� 1 == ����� ���� � ��� ����� ������ ����
		{
			zone1.fps_down_time = zone_down_fps;
			zone1.zone_music.stop();//������� ��� �������� ���� ������ �� ����� ����
			time_to_raid.restart();
			time_map.restart();
			rb_time = 0;
			zone1.myship.speed_bullet = my_speed_bullet;//������  0.15
			zone1.myship.speed_ship = my_speed_ship;
			zone1.myship.score = my_score;
			zone1.myship.total_bullets = my_total_bullets;
			zone1.myship.hp_points = my_ship_hp;
			zone1.total_time_om_map = my_ship_time_on_map;
			zone1.myship.delay_myship_shutting = my_ship_delay_shoot;
			zone1.myship.size_bullets = 0;
			zone1.total_time_om_map = 0;
			zone1.myship.setposition(zone1.Height - 100, zone1.Width / 2);
			enemys_speed_ship = enemies_speed_ships;
			zone1.SetVectorMoviesForenemies(enemys_speed_ship); //����� ������ �������� ���� � ����� ��������� � ����� �� ��������


			raid.fps_down_time = zone_down_fps;
			raid.total_time_om_map = 0;
			raid.rb_room = false;//������� ��� �������� ���� ������ �� ����� ����
			raid.zone_music.stop();
			check = true;
			raid.myship.speed_bullet = my_speed_bullet;//������  0.15
			raid.myship.speed_ship = 0.75*my_speed_ship;
			raid.myship.score = my_score;
			raid.myship.total_bullets = my_total_bullets;
			raid.myship.hp_points = my_ship_hp;
			raid.total_time_om_map = my_ship_time_on_map;
			raid.myship.delay_myship_shutting = my_ship_delay_shoot;
			raid.myship.size_bullets = 0;
			raid.enemies[0].hp_points = raid_hp;
			raid.myship.setposition(zone1.Height - 100, zone1.Width / 2);
			spped_rb = 1.5 * enemies_speed_ships;
			raid.SetVectorMoviesForenemies(spped_rb);
			ship_hp = my_ship_hp;
			reset = false;
		}

		/////////��������� ����
		if (Myboard.isKeyPressed(Myboard.Escape))//��� ������� ������� �������� ����
		{
			menu.menu_flag = true;//���� ����� � ����		
		}

		if (ship_hp < 1)//���� ������� ����� ����� � ����
		{
			menu.menu_flag = true;
			if (fort == true)
			{
				if (menu.username.length() != 0) zone1.myship.ship_name = menu.username;//������� ��� ������������ ����������� � ����
				zone1.SaveResults(true);
			}
		}
		if (menu.menu_flag)//���� �������� ������ �� ����, �������� ������ ���
		{
			zone1.zone_music.stop();//���� ������ ����
			raid.zone_music.stop();
		}




		window.display();//����� ����
		window.clear();//������ �� ������

	}

	return 0;
}

