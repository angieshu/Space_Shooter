/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Fireball.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#include "Fireball.class.hpp"
#include "Enemy.class.hpp"
#include "Meteor.class.hpp"

Fireball::Fireball(Player* player) {
	setWidth(FIREBALL_WIDTH);
	setHeight(FIREBALL_HEIGHT);
	setX(PLAYER_WIDTH / 3 + player->getX() + 1);
	setY(player->getY());
}

Fireball::~Fireball(void) {
}

void	Fireball::moveDown(void) {
	setY(getY() - 1);
}

bool	Fireball::contains(Enemy* enemy) {
	int topBullet = getY();
	int bottomBullet = getY() + FIREBALL_HEIGHT;
	int leftBullet = getX();
	int rightBullet = getX() + FIREBALL_WIDTH;

	int topEnemy = enemy->getY();
	int bottomEnemy = enemy->getY() + ENEMY_HEIGHT;
	int leftEnemy = enemy->getX();
	int rightEnemy = enemy->getX() + ENEMY_WIDTH;

	if ((	(bottomBullet <= topEnemy) ||
			(topBullet >= bottomEnemy) ||
			(rightBullet <= leftEnemy) ||
			(leftBullet >= rightEnemy)) == false)
			return true;

	return false;
}

bool	Fireball::contains(Meteor* meteor) {
	int topBullet = getY();
	int bottomBullet = getY() + FIREBALL_HEIGHT;
	int leftBullet = getX();
	int rightBullet = getX() + FIREBALL_WIDTH;

	int topMeteor = meteor->getY();
	int bottomMeteor = meteor->getY() + METEOR_HEIGHT;
	int leftMeteor = meteor->getX();
	int rightMeteor = meteor->getX() + METEOR_WIDTH;

	if ((	(bottomBullet <= topMeteor) ||
			(topBullet >= bottomMeteor) ||
			(rightBullet <= leftMeteor) ||
			(leftBullet >= rightMeteor)) == false)
			return true;

	return false;
}
