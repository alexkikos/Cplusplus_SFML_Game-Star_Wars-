#include "Find_Items.h"

void FindItems::createitemlist(string source)
{

	item_texture.loadFromFile(source);
	item_sprite.setTexture(item_texture);

}

void FindItems::setmusic(string path_to_music)
{
	music_buffer.loadFromFile(path_to_music);
	music.setBuffer(music_buffer);	
}

float FindItems::starttime(string command) // start - timer start //restart // gettime
{
	Clock static clock;
	float time;
	if (command == "start")
	{		
		 time = clock.getElapsedTime().asSeconds();
	}
	else
	if (command == "restart")
	{
		clock.restart();
	}
	else
	if (command == "gettime")
	{
		return  time = clock.getElapsedTime().asSeconds();
	}
	return 0;
}





