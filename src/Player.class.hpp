/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Player.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "AUnit.class.hpp"
class Fireball;

#define MAX_BULLETS 100

class Player: public AUnit {

private:
	Fireball*	_bullets[MAX_BULLETS];
	static int	_qBullets;

public:
	Player(void);
	~Player(void);

	virtual void	moveDown(void);
	void			shoot(t_settings& settings);
	void			moveBullets(t_settings& settings);
};

#endif
