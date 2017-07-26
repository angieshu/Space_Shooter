/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Enemy.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "Enemy.class.hpp"

Enemy::Enemy(int x) {
	setWidth(ENEMY_WIDTH);
	setHeight(ENEMY_HEIGHT);
	setX(x);
	setY(-ENEMY_HEIGHT - 1);
}

Enemy::~Enemy(void) {
}

void	Enemy::moveDown(void) {
	// if (getY() >= WINDOW_HEIGHT - ENEMY_HEIGHT - 3)
	// 	return;
	setY(getY() + 3);
}
