#include "Enemies.h"

void Enemies::show_bullets(RenderWindow& window)
{
	if (size_bullets > 0)
	{
		for (int i = 0; i < size_bullets; i++)
		{
			window.draw(bullets[i]);
		}
	}

}

void Enemies::show_ship()
{
	ship_sprite;
}

void Enemies::bullet_destroy(int&index)
{
	DestroyBullet(bullets, index, size_bullets);
}

void Enemies::setposition(float x, float y)
{
	ship_sprite.setPosition(x, y);
}

void Enemies::move_enemies()
{	
	ship_sprite.move(0, +speed_ship);
}




void Enemies::move_bullet()
{
	for (int i = 0; i < size_bullets; i++)
	{		
		bullets[i].move(0,speed_bullet);		
	}
}

void Enemies::createship(char**& texture, int numbers_textures)
{
	ship_texture.loadFromFile(texture[numbers_textures]);
	ship_sprite.setTexture(ship_texture);
}

void Enemies::shoot()
{
	if (flag_shoot == false)
	{		
		flag_shoot = true;
		CircleShape n(5);
		Color color;
		n.setFillColor(color.Magenta);	
		n.setPosition(ship_sprite.getPosition().x, ship_sprite.getPosition().y+20);
		n.move(0,speed_bullet);
		AddShotToArray(bullets, size_bullets, n);	
	}
}

