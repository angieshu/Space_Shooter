/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Player.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "Player.class.hpp"
#include "Fireball.class.hpp"

int Player::_qBullets = 0;

Player::Player(void) {
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_HEIGHT);
	setX(PLAYER_START_X);
	setY(PLAYER_START_Y);
	for (int i = 0; i < MAX_BULLETS; i++)
		_bullets[i] = NULL;
}

Player::~Player(void) {
}

void		Player::moveDown(void) {
	if (getY() >= WINDOW_HEIGHT - PLAYER_HEIGHT - 3)
		return;
	setY(getY() + 3);
}

void		Player::shoot(t_settings& settings) {
	if (_qBullets >= MAX_BULLETS) return;
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (_bullets[i]) continue;
		_bullets[i] = new Fireball(this);
		_bullets[i]->load(FIREBALL_IMG, settings);
		_qBullets++;
		break;
	}
}

void		Player::moveBullets(t_settings& settings) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (_bullets[i]) {
			if (_bullets[i]->getY() <= -FIREBALL_HEIGHT) {
				delete _bullets[i];
				_bullets[i] = NULL;
				_qBullets--;
				continue;
			}
			_bullets[i]->moveDown();
			_bullets[i]->render(settings);
		}
	}
}
