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
	// load("player.png", settings);
	// render(PLAYER_START_X, PLAYER_START_Y, settings);
}

Player::~Player(void) {
}
//
// std::string	Player::getPath(void) {
// 	return _path;
// }

void		Player::moveDown(void) {
	if (getY() >= WINDOW_HEIGHT - PLAYER_HEIGHT - 3)
		return;
	setY(getY() + 3);
}
