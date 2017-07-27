/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Fireball.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#ifndef FIREBALL_CLASS_HPP
#define FIREBALL_CLASS_HPP

#include "AUnit.class.hpp"
#include "SpaceShooter.hpp"
#include "Player.class.hpp"

class Enemy;
class Meteor;

class Fireball: public AUnit {

public:
	Fireball(Player* player);
	~Fireball(void);

	virtual void	moveDown(void);
	bool			contains(Enemy* enemy);
	bool			contains(Meteor* meteor);

};

#endif
