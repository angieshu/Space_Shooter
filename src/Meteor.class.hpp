/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Meteor.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#ifndef METEOR_CLASS_HPP
#define METEOR_CLASS_HPP

#include "AUnit.class.hpp"
#include "SpaceShooter.hpp"

class Meteor: public AUnit {

public:
	Meteor(int x);
	~Meteor(void);

	virtual void	moveDown(void);
};

#endif
