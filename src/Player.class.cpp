/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Player.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "Player.class.hpp"

Player::Player(void) {
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_HEIGHT);
	setX(PLAYER_START_X);
	setY(PLAYER_START_Y);
}

Player::~Player(void) {
}

void		Player::moveDown(void) {
	if (getY() >= WINDOW_HEIGHT - PLAYER_HEIGHT - 3)
		return;
	setY(getY() + 3);
}
