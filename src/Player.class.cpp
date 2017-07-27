/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Player.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#include "Player.class.hpp"
#include "Fireball.class.hpp"

int		Player::_qBullets = 0;
int		Player::_lives = 3;
int		Player::_hitPoints = 100;
long	Player::_score = 0;

Player::Player(void) {
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_HEIGHT);
	setX(PLAYER_START_X);
	setY(PLAYER_START_Y);
	for (int i = 0; i < MAX_BULLETS; i++)
		_bullets[i] = NULL;
	_colliders.resize(2);
	_colliders[0].w = PLAYER_WIDTH / 3;
	_colliders[0].h = PLAYER_HEIGHT / 3;
	_colliders[1].w = (PLAYER_WIDTH / 3) * 2;
	_colliders[1].h = (PLAYER_HEIGHT / 3) * 2;
	shiftColliders();
}

Player::~Player(void) {
}

int			Player::getPoints(void) {
	return _score;
}

int			Player::getLives(void) {
	return _lives;
}

int			Player::getHitPoints(void) {
	return _hitPoints;
}

void		Player::setPoints(int points) {
	_score += points;
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

void		Player::shiftColliders(void) {
	_colliders[0].x = getX() + (PLAYER_WIDTH / 3);
	_colliders[0].y = getY();
	_colliders[1].x = getX();
	_colliders[1].y = getY() + (PLAYER_HEIGHT / 3);
}

bool		Player::containes(Enemy* enemy) {
	shiftColliders();
	int topPlayer_0 = _colliders[0].y;
	int bottomPlayer_0 = _colliders[0].y + _colliders[0].h;
	int leftPlayer_0 = _colliders[0].x;
	int rightPlayer_0 = _colliders[0].x + _colliders[0].w;

	int topPlayer_1 = _colliders[1].y;
	int bottomPlayer_1 = _colliders[1].y + _colliders[1].h;
	int leftPlayer_1 = _colliders[1].x;
	int rightPlayer_1 = _colliders[1].x + _colliders[1].w;

	int topEnemy = enemy->getY();
	int bottomEnemy = enemy->getY() + ENEMY_HEIGHT;
	int leftEnemy = enemy->getX();
	int rightEnemy = enemy->getX() + ENEMY_WIDTH;

	if ((	(bottomPlayer_0 <= topEnemy) ||
			(topPlayer_0 >= bottomEnemy) ||
			(rightPlayer_0 <= leftEnemy) ||
			(leftPlayer_0 >= rightEnemy)) == false)
			return true;

	if ((	(bottomPlayer_1 <= topEnemy) ||
			(topPlayer_1 >= bottomEnemy) ||
			(rightPlayer_1 <= leftEnemy) ||
			(leftPlayer_1 >= rightEnemy)) == false)
			return true;

	return false;
}

bool		Player::containes(Meteor* meteor) {
	shiftColliders();
	int topPlayer_0 = _colliders[0].y;
	int bottomPlayer_0 = _colliders[0].y + _colliders[0].h;
	int leftPlayer_0 = _colliders[0].x;
	int rightPlayer_0 = _colliders[0].x + _colliders[0].w;

	int topPlayer_1 = _colliders[1].y;
	int bottomPlayer_1 = _colliders[1].y + _colliders[1].h;
	int leftPlayer_1 = _colliders[1].x;
	int rightPlayer_1 = _colliders[1].x + _colliders[1].w;

	int topMeteor = meteor->getY();
	int bottomMeteor = meteor->getY() + METEOR_HEIGHT;
	int leftMeteor = meteor->getX();
	int rightMeteor = meteor->getX() + METEOR_WIDTH;

	if ((	(bottomPlayer_0 <= topMeteor) ||
			(topPlayer_0 >= bottomMeteor) ||
			(rightPlayer_0 <= leftMeteor) ||
			(leftPlayer_0 >= rightMeteor)) == false)
			return true;

	if ((	(bottomPlayer_1 <= topMeteor) ||
			(topPlayer_1 >= bottomMeteor) ||
			(rightPlayer_1 <= leftMeteor) ||
			(leftPlayer_1 >= rightMeteor)) == false)
			return true;

	return false;
}

bool		Player::kill(int index, Enemy* enemy) {
	if (index >= MAX_BULLETS || !_bullets[index])
		return false;
	if (_bullets[index]->contains(enemy)) {
		delete _bullets[index];
		_bullets[index] = NULL;
		return true;
	}
	return false;
}

bool		Player::kill(int index, Meteor* meteor) {
	if (index >= MAX_BULLETS || !_bullets[index])
		return false;
	if (_bullets[index]->contains(meteor)) {
		delete _bullets[index];
		_bullets[index] = NULL;
		return true;
	}
	return false;
}

bool		Player::getKilled(int hit_points) {
	_hitPoints -= hit_points;
	if (_hitPoints < 0) {
		_lives--;
		if (_lives == 0)
			return true;
		_hitPoints = 100 + _hitPoints;
	}
	return false;
}
