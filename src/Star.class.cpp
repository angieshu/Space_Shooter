/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Star.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "Star.class.hpp"

Star::Star(int x) {
	setWidth(STAR_WIDTH);
	setHeight(STAR_HEIGHT);
	setX(x);
	setY(-STAR_HEIGHT - 1);
}

Star::~Star(void) {
}

void	Star::moveDown(void) {
	setY(getY() + 1);
}
