#pragma once
#include<SFML\Graphics.hpp>

class Player
{
private:

	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	sf::Vector2f mPosition;
	sf::Sprite mSprite;
	sf::Texture mTexture;

	sf::Vector2f mResolution;
	sf::IntRect mArena;
	int mTileSize;

	bool mUpPressed;
	bool mDownPressed;
	bool mRightPressed;
	bool mLeftPressed;

	int mHealth;
	int mMaxHealth;
	
	sf::Time mLastHit;
	float mSpeed;

public:
	Player();
	void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
	void resetPlayerStats();
	bool hit(sf::Time timeHit);
	sf::Time getLastHitTime();
	sf::FloatRect getPosition();
	sf::Vector2f getCenter();
	float getRotation();
	sf::Sprite getSprite();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update(float elapsedTime, sf::Vector2i mousePosition);
	void upgradeSpeed();
	void upgradeHealth();
	void increaseHealthLevel(int amount);
	int getHealth();

};