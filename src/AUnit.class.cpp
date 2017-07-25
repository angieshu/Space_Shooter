/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-24-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: AUnit.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "AUnit.class.hpp"

AUnit::AUnit(void):	_width(0),
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

void	AUnit::setWidth(int width) {
	_width = width;
}

void	AUnit::setHeight(int height) {
	_height = height;
}

void	AUnit::setX(int x) {
	_x = x;
}


void	AUnit::setY(int y) {
	_y = y;
}

bool	AUnit::load(std::string path, t_settings& settings) {

	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
		std::cout << IMG_GetError() << std::endl;
	else {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x4F, 0x24, 0x7A));
		newTexture = SDL_CreateTextureFromSurface(settings.renderer, surface);
		if (newTexture == NULL)
			std::cout << SDL_GetError() << std::endl;
		else {
			surface->w = _width;
			surface->h = _height;
		}
		SDL_FreeSurface(surface);
	}
	_texture = newTexture;
	return _texture != NULL;
}

void	AUnit::free(void) {
	if (_texture != NULL) {
		SDL_DestroyTexture(_texture);
		_texture = NULL;
	}
}

void	AUnit::render(t_settings& settings) {
	SDL_Rect rect = {_x, _y, _width, _height};
	SDL_RenderCopy(settings.renderer, _texture, NULL, &rect);
}

void	AUnit::moveRight(void) {
	if (_x >= WINDOW_WIDTH - PLAYER_WIDTH - 3)
		return;
	_x += 3;
}

void	AUnit::moveLeft(void) {
	if (_x <= 3)
		return;
	_x -= 3;
}

void	AUnit::moveUp(void) {
	if (_y <= 3)
		return;
	_y -= 3;
}
