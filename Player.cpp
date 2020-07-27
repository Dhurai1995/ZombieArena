#include "Player.h"

Player::Player()
{
	mSpeed = START_SPEED;
	mHealth = START_HEALTH;
	mMaxHealth = START_HEALTH;

	mTexture.loadFromFile("graphics/player.png");
	mSprite.setTexture(mTexture);

	mSprite.setOrigin(25, 25);
}

void Player::spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
	mPosition.x = arena.width / 2;
	mPosition.y = arena.height / 2;

	mArena.left = arena.left;
	mArena.width = arena.width;
	mArena.height = arena.height;
	mArena.top = arena.top;

	mTileSize = tileSize;

	mResolution.x = resolution.x;
	mResolution.y = resolution.y;

}

void Player::resetPlayerStats()
{
	mSpeed = START_SPEED;
	mHealth = START_HEALTH;
	mMaxHealth = START_HEALTH;
}

sf::Time Player::getLastHitTime()
{
	return mLastHit;
}

bool Player::hit(sf::Time timeHit)
{
	if ((timeHit.asMilliseconds() - mLastHit.asMilliseconds()) > 200)
	{
		mLastHit = timeHit;
		mHealth -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

sf::FloatRect Player::getPosition()
{
	return mSprite.getGlobalBounds();
}

sf::Vector2f Player::getCenter()
{
	return mPosition;
}

float Player::getRotation()
{
	return mSprite.getRotation();
}

sf::Sprite Player::getSprite()
{
	return mSprite;
}

int Player::getHealth()
{
	return mHealth;
}

void Player::moveLeft()
{
	mLeftPressed = true;
}

void Player::moveRight()
{
	mRightPressed = true;
}

void Player::moveDown()
{
	mDownPressed = true;
}

void Player::moveUp()
{
	mUpPressed = true;
}

void Player::stopDown()
{
	mDownPressed = false;
}

void Player::stopLeft()
{
	mLeftPressed = false;
}

void Player::stopRight()
{
	mRightPressed = false;
}

void Player::stopUp()
{
	mUpPressed = false;
}


void Player::update(float elapsedTime, sf::Vector2i mousePosition)
{
	if (mUpPressed)
	{
		mPosition.y = mPosition.y-  mSpeed * elapsedTime;
	}

	if (mDownPressed)
	{
		mPosition.y = mPosition.y - mSpeed * elapsedTime;
	}

	if (mRightPressed)
	{
		mPosition.x = mPosition.x + mSpeed * elapsedTime;
	}

	if (mLeftPressed)
	{
		mPosition.x  = mPosition.x -  mSpeed * elapsedTime;
	}

	mSprite.setPosition(mPosition);

	if (mPosition.x > mArena.width - mTileSize)
	{
		mPosition.x = mArena.width - mTileSize;
	}

	if (mPosition.x < mArena.left + mTileSize)
	{
		mPosition.x = mArena.left + mTileSize;
	}

	if (mPosition.y > mArena.height - mTileSize)
	{
		mPosition.y = mArena.height - mTileSize;
	}

	if (mPosition.y < mArena.top + mTileSize)
	{
		mPosition.y = mArena.top + mTileSize;
	}

	float angle = (atan2(mousePosition.y - mResolution.y / 2, mousePosition.x - mResolution.x / 2) * 180) / 3.141;
	mSprite.setRotation(angle);
}

void Player::upgradeHealth()
{
	mHealth += (START_HEALTH * 0.2f);
}

void Player::upgradeSpeed()
{
	mSpeed += (START_SPEED * 0.2f);
}

void Player::increaseHealthLevel(int amount)
{
	mHealth += amount;
	if (mHealth > mMaxHealth)
	{
		mHealth = mMaxHealth;
	}
}