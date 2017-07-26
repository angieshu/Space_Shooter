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

class Player: public AUnit {

public:
	Player(void);
	~Player(void);

	virtual void	moveDown(void);
};

#endif
