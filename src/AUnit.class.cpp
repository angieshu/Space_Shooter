/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-24-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: AUnit.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-24-2017
 */


#include "AUnit.class.cpp"

AUnit::Aunit(void):	_width(0),
					_height(0),
					_x(0),
					_y(0),
					_texture(NULL) {
}

AUnit::~AUnit(void) {
	free();
}

int		AUnit::getWidth(void) {
	return _width;
}

int		AUnit::getHeight(void) {
	return _height;
}

int		AUnit::getX(void) {
	return _x;
}

int		AUnit::getY(void) {
	return _y;
}

void	AUnit::setX(int x) {
	_x = x;
}

void	AUnit::setY(int y) {
	_y = y;
}

bool	AUnit::load(std::string path) {
	SDL_Texture* newTexture = NULL;

	free();
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
		std::cout << IMG_GetError() << std::endl;
	else {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x4F, 0x24, 0x7A));
		newTexture = SDL_CreateTextureFromSurface
	}
}
