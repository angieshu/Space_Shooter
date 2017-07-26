/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Fireball.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "Fireball.class.hpp"

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
