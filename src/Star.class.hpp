/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Star.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#ifndef STAR_CLASS_HPP
#define STAR_CLASS_HPP

#include "AUnit.class.hpp"
#include "SpaceShooter.hpp"

class Star: public AUnit {

public:
	Star(int x);
	~Star(void);

	virtual void	moveDown(void);

};

#endif
