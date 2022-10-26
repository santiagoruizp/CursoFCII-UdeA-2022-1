//#pragma once

#include<map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <string>


class Game
{
	
private:

	// clock 
	sf::Clock clock;

	int puntos;

	// Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures; //there is a texture for each string 
	std::vector<Bullet*> bullets;

	//Background
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	float bulletDirX;
	

	// Player
	Player* player;

	// Enemy
	float enemyTimer;
	float enemyTimerMax;
	std::vector<Enemy*> enemies;


	//GUI
	sf::Font font;
	sf::Text pointText;

	// Private functions
	void initWindow();
	void initTextures();
	void initBackground();

	void initGUI();
	void initPlayer();
	void initEnemies();


public:
	Game();
	virtual ~Game();
	
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void renderGUI();
	void updateBullets();
	void updateEnemies();
	void run();
	void update();
	void render(); //renders the updates
	void renderBackground();

};