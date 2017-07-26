/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Enemy.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

#include "AUnit.class.hpp"
#include "SpaceShooter.hpp"

class Enemy: public AUnit {

public:
	Enemy(int x);
	~Enemy(void);

	virtual void moveDown(void);
};

#endif
