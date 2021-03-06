#include "game.h"


void Game::Loop()
{


	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
	player.timer += time;

	if (timer > delay)
	{
		timer = 0;

		//Takes in the player's keyboard controls
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			player.x -= 3;

		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			player.x += 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {

		
			if (player.contact(ground) || player.contact(ground2) || player.contact(ground3)
				|| player.contact(brick) || player.contact(brick2) || player.contact(brick3)
				|| player.contact(brick4) || player.contact(brick5) || player.contact(brick6)
				|| player.contact(brick7) || player.contact(brick8))
			{
				player.jump = true;
			}

		}

		//Creates the player's jump
		if (player.jump == true)
		{
			float energy = 15;
			player.y -= energy;
		}

		//Animates the player's walk
		if (player.timer > player.delay &&
			(player.x != player.lastx || player.y != player.lasty))
		{
			player.timer = 0;

			if (player.walk == false || player.jump == true)
				player.walk = true;
			else
				player.walk = false;
		}
		else if (player.x == player.lastx && player.y == player.lasty)
		{
			player.walk = false;
		}
		//Applies the gravity to the player, enemy, and the powerups
		player.Gravity();
		enemy.Gravity();
		enemy1.Gravity();
		powerup.Gravity();
		//Places the bricks in the environment and gives them collision
		
		//enemy1.Physics(enemy1.x,enemy1.y);
		player.Physics(brick);
		player.Physics(brick2);
		player.Physics(brick3);
		player.Physics(brick4);
		player.Physics(brick5);
		player.Physics(brick6);
		player.Physics(brick7);
		player.Physics(brick8);
		player.Physics(ground);
		player.Physics(ground2);
		player.Physics(ground3);
		enemy.Physics(brick);
		enemy.Physics(brick2);
		enemy.Physics(brick3);
		enemy.Physics(brick4);
		enemy.Physics(brick5);
		enemy.Physics(brick6);
		enemy.Physics(brick7);
		enemy.Physics(brick8);
		enemy.Physics(ground);
		enemy.Physics(ground2);
		enemy.Physics(ground3);
		enemy1.Physics(brick);
		enemy1.Physics(brick2);
		enemy1.Physics(brick3);
		enemy1.Physics(brick4);
		enemy1.Physics(brick5);
		enemy1.Physics(brick6);
		enemy1.Physics(brick7);
		enemy1.Physics(brick8);
		enemy1.Physics(ground);
		enemy1.Physics(ground2);
		enemy1.Physics(g);
		powerup.Physics(brick);
		powerup.Physics(brick2);
		powerup.Physics(brick3);
		powerup.Physics(brick4);
		powerup.Physics(brick5);
		powerup.Physics(brick6);
		powerup.Physics(brick7);
		powerup.Physics(brick8);
		powerup.Physics(ground);
		powerup.Physics(ground2);
		powerup.Physics(ground3);

		//Gives the enemies and powerups their respective AI
		powerup.AI();


		//Dictates whether the enemy or player has been healed or killed
		enemy1.Kill(player);
		powerup.Heal(player);
		enemy.Kill(player);

		coin1.Poof(player);
		coin2.Poof(player);
		coin3.Poof(player);
		coin4.Poof(player);
		coin5.Poof(player);
		coin6.Poof(player);
		coin7.Poof(player);
		coin8.Poof(player);
		coin9.Poof(player);
		coin10.Poof(player);
		coin11.Poof(player);
		coin12.Poof(player);
		coin1.Collect();
		coin2.Collect();
		coin3.Collect();
		coin4.Collect();
		coin5.Collect();
		coin6.Collect();
		coin7.Collect();
		coin8.Collect();
		coin9.Collect();
		coin10.Collect();
		coin11.Collect();
		coin12.Collect();

		//Ends the game
		if (player.y >HEIGHT)
		{
			player.end = true;
#ifdef sound	
			themesong.stop();
#endif
		}
	}


}

//Shifts the camera so that if follows the player
void Camera::Shift(Player &player)
{
	if (player.x > osszx + 700)
	{
		x = 4;
		osszx += x;
	} else
	{
		x = 0;
	}
}

//Specifies the collision detection for the powerups
void PowerUp::Physics(Ground &ground)
{
	if (y >= ground.y - height
		&& y < ground.y + ground.dimension
		&& x + width > ground.x
		&& x < ground.x + ground.width && dead == false)
	{
		gravity = 0;
		y = ground.y - height;
	}
}

//Sets the value of gravity for the powerups
void PowerUp::Gravity()
{
	gravity += velocity;
	y += gravity;
}

//Makes the powerups move forward continuously
void PowerUp::AI()
{
	x += 2;
}

//Gives the player more health if they grab the powerup
void PowerUp::Heal(Player &player)
{
	if (x <= player.x + player.width &&
		x + width >= player.x &&
		y <= player.y + player.height &&
		y + height >= player.y && dead == false)
	{
		dead = true;
		player.health++;
	}
}

//Populates the environment with the player, enemies, bricks, and ground tiles
//creation of level 1
void Game::Level1()
{
	//places player on the floor
	player.x = 200;
	player.y = 500;

	//Sets the goal flag
	flag.x = 2365;
	flag.y = 325;

	//sets the location of the enemies
	enemy.x = 600;
	enemy.y = 278;
	

	enemy1.x = 900;
	enemy1.y = 220;

	//sets the location of the powerup
	powerup.x = 100;
	powerup.y = 100;

	coin1.x = 100;
	coin1.y = 370;
	coin1.width = 1 * coin1.dimension;
	coin1.height = 1 * coin1.dimension;

	coin2.x = 152;
	coin2.y = 370;
	coin2.width = 1 * coin2.dimension;
	coin2.height = 1 * coin2.dimension;

	coin3.x = 204;
	coin3.y = 370;
	coin3.width = 1 * coin3.dimension;
	coin3.height = 1 * coin3.dimension;

	coin4.x = 256;
	coin4.y = 370;
	coin4.width = 1 * coin4.dimension;
	coin4.height = 1 * coin4.dimension;

	coin5.x = 308;
	coin5.y = 370;
	coin5.width = 1 * coin5.dimension;
	coin5.height = 1 * coin5.dimension;

	//everything beyond this, is the layout for the level
	ground.x = 0;
	ground.y = HEIGHT - (2 * ground.dimension);
	ground.width = 10 * ground.dimension;
	ground.height = 2 * ground.dimension;

	brick4.x = 535;
	brick4.y = 320;
	brick4.width = 5 * brick.dimension;
	brick4.height = 1 * brick.dimension;

	coin11.x = 577;
	coin11.y = 150;
	coin11.width = 1 * coin11.dimension;
	coin11.height = 1 * coin11.dimension;

	coin12.x = 661;
	coin12.y = 150;
	coin12.width = 1 * coin12.dimension;
	coin12.height = 1 * coin12.dimension;

	ground2.x = 850;
	ground2.y = HEIGHT - (2 * ground2.dimension);
	ground2.width = 5 * ground2.dimension;
	ground2.height = 2 * ground2.dimension;

	coin6.x = 876;
	coin6.y = 370;
	coin6.width = 1 * coin6.dimension;
	coin6.height = 1 * coin6.dimension;

	coin7.x = 934;
	coin7.y = 370;
	coin7.width = 1 * coin7.dimension;
	coin7.height = 1 * coin7.dimension;

	coin8.x = 992;
	coin8.y = 370;
	coin8.width = 1 * coin8.dimension;
	coin8.height = 1 * coin8.dimension;

	brick.x = 1150;
	brick.y = 320;
	brick.width = 3 * brick.dimension;
	brick.height = 1 * brick.dimension;

	coin9.x = 1192;
	coin9.y = 150;
	coin9.width = 1 * coin9.dimension;
	coin9.height = 1 * coin9.dimension;

	brick2.x = 1420;
	brick2.y = 150;
	brick2.width = 3 * brick.dimension;
	brick2.height = 1 * brick.dimension;

	brick3.x = 1720;
	brick3.y = 320;
	brick3.width = 3 * brick.dimension;
	brick3.height = 1 * brick.dimension;

	coin10.x = 1762;
	coin10.y = 150;
	coin10.width = 1 * coin10.dimension;
	coin10.height = 1 * coin10.dimension;

	ground3.x = 1980;
	ground3.y = HEIGHT - (2 * ground2.dimension);
	ground3.width = 50 * ground2.dimension;
	ground3.height = 2 * ground2.dimension;

	g.x = 850;
	g.y = 220;
	g.width = 5 * g.dimension;
	g.height = 1 * g.dimension;
}

//creation of level 2
void Game::Level2()
{
	player.x = 50;
	player.y = 500;

	coin1.Collected = false;
	coin2.Collected = false;
	coin3.Collected = false;
	coin4.Collected = false;
	coin5.Collected = false;
	coin6.Collected = false;
	coin7.Collected = false;
	coin8.Collected = false;
	coin9.Collected = false;
	coin10.Collected = false;
	coin11.Collected = false;
	coin12.Collected = false;

	enemy.dead = false;
	enemy.gravity = 0;
	enemy.counter = 0;
	enemy1.dead = false;
	enemy1.gravity = 0;
	enemy1.counter = 0;


	//Sets the goal flag
	flag.x = 2465;
	flag.y = 325;

	enemy.x = 1000;
	enemy.y = 474;
	
	enemy1.x = 1500;
	enemy1.y = 300;

	ground.x = 0;
	ground.y = HEIGHT - (2 * ground.dimension);
	ground.width = 5 * ground.dimension;
	ground.height = 2 * ground.dimension;

	coin1.x = 21;
	coin1.y = 370;
	coin1.width = 1 * coin1.dimension;
	coin1.height = 1 * coin1.dimension;

	coin2.x = 63;
	coin2.y = 370;
	coin2.width = 1 * coin2.dimension;
	coin2.height = 1 * coin2.dimension;

	coin3.x = 105;
	coin3.y = 370;
	coin3.width = 1 * coin3.dimension;
	coin3.height = 1 * coin3.dimension;

	coin4.x = 147;
	coin4.y = 370;
	coin4.width = 1 * coin4.dimension;
	coin4.height = 1 * coin4.dimension;

	brick.x = 300;
	brick.y = 320;
	brick.width = 2 * brick.dimension;
	brick.height = 1 * brick.dimension;

	coin5.x = 321;
	coin5.y = 150;
	coin5.width = 1 * coin5.dimension;
	coin5.height = 1 * coin5.dimension;

	brick2.x = 530;
	brick2.y = 150;
	brick2.width = 2 * brick.dimension;
	brick2.height = 1 * brick.dimension;

	coin6.x = 551;
	coin6.y = 100;
	coin6.width = 1 * coin6.dimension;
	coin6.height = 1 * coin6.dimension;

	brick3.x = 780;
	brick3.y = 320;
	brick3.width = 2 * brick.dimension;
	brick3.height = 1 * brick.dimension;

	coin7.x = 801;
	coin7.y = 150;
	coin7.width = 1 * coin7.dimension;
	coin7.height = 1 * coin7.dimension;

	ground2.x = 930;
	ground2.y = HEIGHT - (2 * ground2.dimension);
	ground2.width = 5 * ground2.dimension;
	ground2.height = 2 * ground2.dimension;

	coin8.x = 951;
	coin8.y = 370;
	coin8.width = 1 * coin8.dimension;
	coin8.height = 1 * coin8.dimension;

	coin9.x = 993;
	coin9.y = 370;
	coin9.width = 1 * coin9.dimension;
	coin9.height = 1 * coin9.dimension;

	coin10.x = 1035;
	coin10.y = 370;
	coin10.width = 1 * coin10.dimension;
	coin10.height = 1 * coin10.dimension;

	brick4.x = 1230;
	brick4.y = 320;
	brick4.width = 1 * brick.dimension;
	brick4.height = 1 * brick.dimension;

	brick5.x = 1425;
	brick5.y = 320;
	brick5.width = 1 * brick.dimension;
	brick5.height = 1 * brick.dimension;

	coin11.x = 1425;
	coin11.y = 200;
	coin11.width = 1 * coin11.dimension;
	coin11.height = 1 * coin11.dimension;

	brick6.x = 1610;
	brick6.y = 320;
	brick6.width = 1 * brick.dimension;
	brick6.height = 1 * brick.dimension;

	brick7.x = 1790;
	brick7.y = 320;
	brick7.width = 1 * brick.dimension;
	brick7.height = 1 * brick.dimension;

	coin12.x = 1790;
	coin12.y = 200;
	coin12.width = 1 * coin12.dimension;
	coin12.height = 1 * coin12.dimension;

	ground3.x = 2000;
	ground3.y = HEIGHT - (2 * ground2.dimension);
	ground3.width = 50 * ground2.dimension;
	ground3.height = 2 * ground2.dimension;

	g.x = 1230;
	g.y = 300;
	g.width = 13 * g.dimension;
	g.height = 1 * g.dimension;
}

//creation of level 3
void Game::Level3()
{
	player.x = 50;
	player.y = 500;

	//Sets the goal flag
	flag.x = 2665;
	flag.y = 325;

	coin1.Collected = false;
	coin2.Collected = false;
	coin3.Collected = false;
	coin4.Collected = false;
	coin5.Collected = false;
	coin6.Collected = false;
	coin7.Collected = false;
	coin8.Collected = false;
	coin9.Collected = false;
	coin10.Collected = false;
	coin11.Collected = false;
	coin12.Collected = false;

	enemy.dead = false;
	enemy.gravity = 0;
	enemy.counter = 0;
	enemy1.dead = false;
	enemy1.gravity = 0;
	enemy1.counter = 0;

	enemy.x = 1125;
	enemy.y = 474;

	enemy1.x = 2000;
	enemy1.y = 425;

	ground.x = 0;
	ground.y = HEIGHT - (2 * ground.dimension);
	ground.width = 5 * ground.dimension;
	ground.height = 2 * ground.dimension;

	coin1.x = 21;
	coin1.y = 370;
	coin1.width = 1 * coin1.dimension;
	coin1.height = 1 * coin1.dimension;

	coin2.x = 63;
	coin2.y = 370;
	coin2.width = 1 * coin2.dimension;
	coin2.height = 1 * coin2.dimension;

	coin3.x = 105;
	coin3.y = 370;
	coin3.width = 1 * coin3.dimension;
	coin3.height = 1 * coin3.dimension;

	coin4.x = 147;
	coin4.y = 370;
	coin4.width = 1 * coin4.dimension;
	coin4.height = 1 * coin4.dimension;

	brick.x = 300;
	brick.y = 400;
	brick.width = 1 * brick.dimension;
	brick.height = 1 * brick.dimension;

	coin5.x = 300;
	coin5.y = 348;
	coin5.width = 1 * coin5.dimension;
	coin5.height = 1 * coin5.dimension;

	brick2.x = 450;
	brick2.y = 250;
	brick2.width = 1 * brick.dimension;
	brick2.height = 1 * brick.dimension;

	coin6.x = 450;
	coin6.y = 208;
	coin6.width = 1 * coin6.dimension;
	coin6.height = 1 * coin6.dimension;

	brick3.x = 650;
	brick3.y = 100;
	brick3.width = 1 * brick.dimension;
	brick3.height = 1 * brick.dimension;

	coin7.x = 650;
	coin7.y = 50;
	coin7.width = 1 * coin7.dimension;
	coin7.height = 1 * coin7.dimension;

	brick4.x = 900;
	brick4.y = 400;
	brick4.width = 1 * brick.dimension;
	brick4.height = 1 * brick.dimension;

	coin8.x = 900;
	coin8.y = 352;
	coin8.width = 1 * coin8.dimension;
	coin8.height = 1 * coin8.dimension;

	ground2.x = 1050;
	ground2.y = HEIGHT - (2 * ground2.dimension);
	ground2.width = 5 * ground2.dimension;
	ground2.height = 2 * ground2.dimension;

	coin9.x = 1092;
	coin9.y = 370;
	coin9.width = 1 * coin9.dimension;
	coin9.height = 1 * coin9.dimension;

	coin10.x = 1176;
	coin10.y = 370;
	coin10.width = 1 * coin10.dimension;
	coin10.height = 1 * coin10.dimension;

	brick5.x = 1400;
	brick5.y = 320;
	brick5.width = 1 * brick.dimension;
	brick5.height = 1 * brick.dimension;

	brick6.x = 1620;
	brick6.y = 400;
	brick6.width = 1 * brick.dimension;
	brick6.height = 1 * brick.dimension;

	coin11.x = 1620;
	coin11.y = 358;
	coin11.width = 1 * coin11.dimension;
	coin11.height = 1 * coin11.dimension;

	brick7.x = 1850;
	brick7.y = 320;
	brick7.width = 1 * brick.dimension;
	brick7.height = 1 * brick.dimension;

	brick8.x = 2050;
	brick8.y = 475;
	brick8.width = 1 * brick.dimension;
	brick8.height = 1 * brick.dimension;

	coin12.x = 2050;
	coin12.y = 433;
	coin12.width = 1 * coin12.dimension;
	coin12.height = 1 * coin12.dimension;

	ground3.x = 2275;
	ground3.y = HEIGHT - (2 * ground2.dimension);
	ground3.width = 50 * ground2.dimension;
	ground3.height = 2 * ground2.dimension;
	
	g.x = 1987;
	g.y = 425;
	g.width = 5 * g.dimension;
	g.height = 1 * g.dimension;
}

//creation of level 4
void Game::Level4()
{
	player.x = 50;
	player.y = 500;

	//Sets the goal flag
	flag.x = 2126;
	flag.y = 34;

	coin1.Collected = false;
	coin2.Collected = false;
	coin3.Collected = false;
	coin4.Collected = false;
	coin5.Collected = false;
	coin6.Collected = false;
	coin7.Collected = false;
	coin8.Collected = false;
	coin9.Collected = false;
	coin10.Collected = false;
	coin11.Collected = false;
	coin12.Collected = false;

	enemy.dead = false;
	enemy.gravity = 0;
	enemy.counter = 0;
	enemy1.dead = false;
	enemy1.gravity = 0;
	enemy1.counter = 0;

	player.x = 50;
	player.y = 500;

	enemy.x = 1184;
	enemy.y = 474;

	enemy1.x = 1700;
	enemy1.y = 210;

	ground.x = 0;
	ground.y = HEIGHT - (2 * ground.dimension);
	ground.width = 10 * ground.dimension;
	ground.height = 2 * ground.dimension;

	brick.x = 500;
	brick.y = 450;
	brick.width = 12 * brick.dimension;
	brick.height = 1 * brick.dimension;

	coin1.x = 521;
	coin1.y = 400;
	coin1.width = 1 * coin1.dimension;
	coin1.height = 1 * coin1.dimension;

	coin2.x = 605;
	coin2.y = 400;
	coin2.width = 1 * coin2.dimension;
	coin2.height = 1 * coin2.dimension;

	coin3.x = 689;
	coin3.y = 400;
	coin3.width = 1 * coin3.dimension;
	coin3.height = 1 * coin3.dimension;

	coin4.x = 1410;
	coin4.y = 400;
	coin4.width = 1 * coin4.dimension;
	coin4.height = 1 * coin4.dimension;

	brick2.x = 962;
	brick2.y = 198;
	brick2.width = 1 * brick.dimension;
	brick2.height = 6 * brick.dimension;

	brick3.x = 504;
	brick3.y = 324;
	brick3.width = 9 * brick.dimension;
	brick3.height = 1 * brick.dimension;

	coin5.x = 609;
	coin5.y = 274;
	coin5.width = 1 * coin5.dimension;
	coin5.height = 1 * coin5.dimension;

	coin6.x = 693;
	coin6.y = 274;
	coin6.width = 1 * coin6.dimension;
	coin6.height = 1 * coin6.dimension;

	coin7.x = 777;
	coin7.y = 274;
	coin7.width = 1 * coin7.dimension;
	coin7.height = 1 * coin7.dimension;

	coin8.x = 1552;
	coin8.y = 300;
	coin8.width = 1 * coin8.dimension;
	coin8.height = 1 * coin8.dimension;

	brick4.x = 626;
	brick4.y = 198;
	brick4.width = 8 * brick.dimension;
	brick4.height = 1 * brick.dimension;

	ground2.x = 1100;
	ground2.y = HEIGHT - (2 * ground2.dimension);
	ground2.width = 5 * ground2.dimension;
	ground2.height = 2 * ground2.dimension;

	brick5.x = 500;
	brick5.y = 72;
	brick5.width = 1 * brick.dimension;
	brick5.height = 6 * brick.dimension;

	brick6.x = 542;
	brick6.y = 72;
	brick6.width = 11 * brick.dimension;
	brick6.height = 1 * brick.dimension;

	coin9.x = 600;
	coin9.y = 22;
	coin9.width = 1 * coin9.dimension;
	coin9.height = 1 * coin9.dimension;

	coin10.x = 684;
	coin10.y = 22;
	coin10.width = 1 * coin10.dimension;
	coin10.height = 1 * coin10.dimension;

	coin11.x = 768;
	coin11.y = 22;
	coin11.width = 1 * coin11.dimension;
	coin11.height = 1 * coin11.dimension;

	coin12.x = 1958;
	coin12.y = 150;
	coin12.width = 1 * coin12.dimension;
	coin12.height = 1 * coin12.dimension;

	brick7.x = 1410;
	brick7.y = 475;
	brick7.width = 1 * brick.dimension;
	brick7.height = 1 * brick.dimension;

	brick8.x = 1552;
	brick8.y = 375;
	brick8.width = 1 * brick.dimension;
	brick8.height = 1 * brick.dimension;

	ground3.x = 1744;
	ground3.y = 225;
	ground3.width = 13 * ground2.dimension;
	ground3.height = 2 * ground2.dimension;

	g.x = 1660;
	g.y = 210;
	g.width = 5 * g.dimension;
	g.height = 1 * g.dimension;
}

//Deals with the looping and creation of the enemies placements
void Game::Circle(int level) {
	if (level == 1) {
		circleBoi.Physics(circleBoi.x, circleBoi.y);
		circleBoi.Kill1(player);
		circleBoi.Orbit(1462, 320, 300);

		circleBoi2.Physics(circleBoi2.x, circleBoi2.y);
		circleBoi2.Kill1(player);
		circleBoi2.Orbit(5000, 5000, 300);

		enemy.AI(535, 703);
		enemy1.AI(850, 1018);
	}
	if (level == 2) {
		circleBoi.Physics(circleBoi.x, circleBoi.y);
		circleBoi.Kill1(player);
		circleBoi.Orbit(551, 320, 250);

		circleBoi2.Physics(circleBoi2.x, circleBoi2.y);
		circleBoi2.Kill1(player);
		circleBoi2.Orbit(5000, 5000, 100);

		enemy.AI(930, 1098);
		enemy1.AI(1290, 1734);
	}
	if (level == 3) {
		circleBoi.Physics(circleBoi.x, circleBoi.y);
		circleBoi.Kill1(player);
		circleBoi.Orbit(550, 175, 115);

		circleBoi2.Physics(circleBoi2.x, circleBoi2.y);
		circleBoi2.Kill1(player);
		circleBoi2.Orbit(5000, 5000, 300);

		enemy.AI(1050, 1218);
		enemy1.AI(1978, 2146);
	}
	if (level == 4) {
		circleBoi.Physics(circleBoi.x, circleBoi.y);
		circleBoi.Kill1(player);
		circleBoi.Orbit(500, 450, 75);

		circleBoi2.Physics(circleBoi2.x, circleBoi2.y);
		circleBoi2.Kill1(player);
		circleBoi2.Orbit(748, 198, 75);

		enemy.AI(1100, 1268);
		enemy1.AI(1660, 1828);
	}
}