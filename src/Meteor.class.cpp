/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Meteor.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#include "Meteor.class.hpp"

Meteor::Meteor(int x) {
	setWidth(METEOR_WIDTH);
	setHeight(METEOR_HEIGHT);
	setX(x);
	setY(-METEOR_HEIGHT - 1);
}

Meteor::~Meteor(void) {
}

void	Meteor::moveDown(void) {
	setY(getY() + 1);
}
