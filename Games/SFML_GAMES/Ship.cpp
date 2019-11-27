#include "Ship.h"


void Ship::createship(char**&texture, int numbers_textures)
{
		ship_texture.loadFromFile(texture[rand()% numbers_textures]);
		ship_sprite.setTexture(ship_texture);
}



void Ship::shoot()
{

	if (MyBoard.isKeyPressed(MyBoard.Space))
	{
		CircleShape n(5);
		n.setPosition(ship_sprite.getPosition().x+45, ship_sprite.getPosition().y);
		AddShotToArray(bullets, size_bullets, n);	
		total_bullets++;
	}
}

void Ship::shoot_delete(int index_to_delete)
{
	CircleShape* temp = new CircleShape[size_bullets - 1];
	int count = 0;
	for (int i = 0; i < size_bullets; i++)
	{
		if (i == index_to_delete) continue;
		temp[count++] = bullets[i];
	}
	if (bullets != nullptr) delete[] bullets;
	bullets = temp;
	size_bullets--;
}


void Ship::move_bullets()
{

	for (int i = 0; i < size_bullets; i++)
	{
		bullets[i].move(0, speed_bullet);
	}
}

void Ship::show_bullets(RenderWindow& window)
{
	
	if (size_bullets > 0)
	{
		for (int i = 0; i < size_bullets; i++)
		{
			window.draw(bullets[i]);
		}
	}

}


void Ship::setposition(float x, float y)
{
	ship_sprite.setPosition(x, y);

}

void Ship::setmusic(char**s)
{
	int count = _msize(s) / sizeof(char**);
	music_buffer = new SoundBuffer[count];
	music = new Sound[count];
	for (int i = 0; i < count; i++)
	{
		music_buffer[i].loadFromFile(s[i]);
		music[i].setBuffer(music_buffer[i]);
	}
}





