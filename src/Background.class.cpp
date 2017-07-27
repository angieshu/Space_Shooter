/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-26-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Background.class.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#include "Background.class.hpp"

Background::Background(void) {
	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++)
		_enemies[i] = NULL;
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++)
		_meteors[i] = NULL;
	for (int i = 0; i < STAR_MAX_QUANTITY; i++)
		_stars[i] = NULL;
	_texture = 0;
}

Background::~Background(void) {
	free();
	clean();
}

void	Background::free(void) {
	if (_texture != NULL) {
		SDL_DestroyTexture(_texture);
		_texture = NULL;
	}
}

void	Background::clean(void) {
	free();
	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
		if (_enemies[i]) {
			delete _enemies[i];
			_enemies[i] = NULL;
		}
	}
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
		if (_meteors[i]) {
			delete _meteors[i];
			_meteors[i] = NULL;
		}
	}
	for (int i = 0; i < STAR_MAX_QUANTITY; i++) {
		if (_stars[i]) {
			delete _stars[i];
			_stars[i] = NULL;
		}
	}
}

void	Background::loadGameOver(std::string path, t_settings& settings) {
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
		SDL_FreeSurface(surface);
	}
	_texture = newTexture;
	SDL_Rect rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT + INFOBOX_HEIGHT};
	SDL_RenderCopy(settings.renderer, _texture, NULL, &rect);
}

void	Background::drawInfoBox(Player& player, t_settings& settings, unsigned long tick) {
	SDL_Rect infoBox = {0, WINDOW_HEIGHT, WINDOW_WIDTH, INFOBOX_HEIGHT};
	SDL_SetRenderDrawColor(settings.renderer, 0x37, 0x30, 0x38, 0xFF);
	SDL_RenderFillRect(settings.renderer, &infoBox);
	SDL_SetRenderDrawColor(settings.renderer, 0xF9, 0xF8, 0xAE, 0xFF);
	for (int i = 0; i < WINDOW_WIDTH; i += 4)
		SDL_RenderDrawPoint(settings.renderer, i, WINDOW_HEIGHT + 1);
	int pos_x = WINDOW_WIDTH / 25;
	int pos_y = WINDOW_HEIGHT + (INFOBOX_HEIGHT / 5);
	TTF_Font* font = TTF_OpenFont(FONT_TTF, 15);
	SDL_Color fontColor = {0xE2, 0xE0, 0xE7};

	std::string s = "SCORE:  " + std::to_string(player.getPoints());
	SDL_Surface* score = TTF_RenderText_Solid(font, s.c_str(), fontColor);
	SDL_Texture* messageScore = SDL_CreateTextureFromSurface(settings.renderer, score);
	SDL_Rect rect = {pos_x, pos_y, score->w, score->h};
	SDL_RenderCopy(settings.renderer, messageScore, NULL, &rect);
	SDL_FreeSurface(score);
	score = NULL;
	SDL_DestroyTexture(messageScore);
	messageScore = NULL;

	s = "TIME:    " + std::to_string(tick);
	SDL_Surface* ticks = TTF_RenderText_Solid(font, s.c_str(), fontColor);
	SDL_Texture* messageTicks = SDL_CreateTextureFromSurface(settings.renderer, ticks);
	rect = {pos_x, pos_y + (2 * INFOBOX_HEIGHT / 5), ticks->w, ticks->h};
	SDL_RenderCopy(settings.renderer, messageTicks, NULL,  &rect);
	SDL_FreeSurface(ticks);
	ticks = NULL;
	SDL_DestroyTexture(messageTicks);
	messageTicks = NULL;

	int x = WINDOW_WIDTH - (WINDOW_WIDTH / 25) - 3 * (PLAYER_WIDTH / 2 + 10);
	for (int i = player.getLives(); i > 0; i--) {
		rect = {x, pos_y, PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2};
		SDL_RenderCopy(settings.renderer, player.getTexture(), NULL, &rect);
		x += (PLAYER_WIDTH / 2 + 10);
	}

	s = "HIT POINTS: " + std::to_string(player.getHitPoints());
	SDL_Surface* hitPoints = TTF_RenderText_Solid(font, s.c_str(), fontColor);
	SDL_Texture* messagePoints = SDL_CreateTextureFromSurface(settings.renderer, hitPoints);
	x = WINDOW_WIDTH - (WINDOW_WIDTH / 25) - hitPoints->w;
	rect = {x, pos_y + (2 * INFOBOX_HEIGHT / 5), hitPoints->w, hitPoints->h};
	SDL_RenderCopy(settings.renderer, messagePoints, NULL,  &rect);
	SDL_FreeSurface(hitPoints);
	hitPoints = NULL;
	SDL_DestroyTexture(messagePoints);
	messagePoints = NULL;

	TTF_CloseFont(font);
	font = NULL;
}

void	Background::makeStar(t_settings& settings) {
	for (int i = 0; i < STAR_MAX_QUANTITY; i++) {
		if (_stars[i]) continue;
		int pos_x = rand() % (WINDOW_WIDTH - STAR_WIDTH);
		_stars[i] = new Star(pos_x);
		_stars[i]->load(STAR_IMG, settings);
		break;
	}
}
void	Background::makeMeteor(t_settings& settings) {
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
		if (_meteors[i]) continue;
		int pos_x = rand() % (WINDOW_WIDTH - METEOR_WIDTH);
		_meteors[i] = new Meteor(pos_x);
		_meteors[i]->load(METEOR_IMG, settings);
		break;
	}
}
void	Background::makeEnemy(t_settings& settings) {
	int quantity = 2;
	int randNum;

	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
		if (quantity <= 0) break;
		if (_enemies[i]) continue;
		randNum = rand() % 2;
		if (randNum) {
			int pos_x = (rand() % (WINDOW_WIDTH / ENEMY_WIDTH) + 1) * ENEMY_WIDTH - ENEMY_WIDTH;
			_enemies[i] = new Enemy(pos_x);
			_enemies[i]->load(ENEMY_IMG, settings);
			quantity--;
		}
	}
}

void	Background::displayStar(t_settings& settings) {
	for (int i = 0; i < STAR_MAX_QUANTITY; i++) {
		if (_stars[i]) {
			if (_stars[i]->getY() >= WINDOW_HEIGHT) {
				delete _stars[i];
				_stars[i]= NULL;
				continue;
			}
			_stars[i]->moveDown();
			_stars[i]->render(settings);
		}
	}
}

void	Background::displayMeteor(t_settings& settings, bool itsTime) {
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
		if (_meteors[i]) {
			if (itsTime && _meteors[i]->getY() >= WINDOW_HEIGHT) {
				delete _meteors[i];
				_meteors[i] = NULL;
				continue;
			}
			if (itsTime) _meteors[i]->moveDown();
			_meteors[i]->render(settings);
		}
	}
}

void	Background::displayEnemy(t_settings& settings, bool itsTime) {
	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
		if (_enemies[i]) {
			if (itsTime && _enemies[i]->getY() >= WINDOW_HEIGHT) {
				delete _enemies[i];
				_enemies[i] = NULL;
				continue;
			}
			if (itsTime) _enemies[i]->moveDown();
			_enemies[i]->render(settings);
		}
	}
}

bool	Background::hitEnemy(Player& player) {
	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
		if (_enemies[i]) {
			if (player.containes(_enemies[i])) {
				if (player.getKilled(ENEMY_HIT))
					return true;
				delete _enemies[i];
				_enemies[i] = NULL;
			}
		}
	}
	return false;
}

bool	Background::hitMeteor(Player& player) {
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
		if (_meteors[i]) {
			if (player.containes(_meteors[i])) {
				if (player.getKilled(METEOR_HIT))
					return true;
				delete _meteors[i];
				_meteors[i] = NULL;
			}
		}
	}
	return false;
}

void	Background::killEnemy(Player& player) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		for (int j = 0; j < ENEMY_MAX_QUANTITY; j++) {
			if (_enemies[j] && player.kill(i, _enemies[j])) {
				delete _enemies[j];
				_enemies[j] = NULL;
				player.setPoints(ENEMY_POINTS);
			}
		}
	}
}

void	Background::killMeteor(Player& player) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		for (int j = 0; j < METEOR_MAX_QUANTITY; j++) {
			if (_meteors[j] && player.kill(i, _meteors[j])) {
				delete _meteors[j];
				_meteors[j] = NULL;
				player.setPoints(METEOR_POINTS);
			}
		}
	}
}
