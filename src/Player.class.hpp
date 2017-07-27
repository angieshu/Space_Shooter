/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Player.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "AUnit.class.hpp"
#include "Enemy.class.hpp"
#include "Meteor.class.hpp"

class Fireball;

class Player: public AUnit {

private:
	Fireball*				_bullets[MAX_BULLETS];
	static int				_qBullets;
	std::vector<SDL_Rect>	_colliders;
	static int				_lives;
	static int				_hitPoints;
	static long				_score;

public:
	Player(void);
	~Player(void);

	int				getPoints(void);
	int				getLives(void);
	int				getHitPoints(void);

	void			setPoints(int points);

	virtual void	moveDown(void);
	void			moveBullets(t_settings& settings);

	void			shoot(t_settings& settings);
	void			shiftColliders(void);

	bool			containes(Enemy* enemy);
	bool			containes(Meteor* meteor);

	bool			kill(int index, Enemy* enemy);
	bool			kill(int index, Meteor* meteor);

	bool			getKilled(int hit_points);

};

#endif
