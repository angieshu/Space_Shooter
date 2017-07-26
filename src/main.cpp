/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: main.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#include "SpaceShooter.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include "Meteor.class.hpp"

bool	init(t_settings& settings) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	settings.window = SDL_CreateWindow("Space Shooter",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										WINDOW_WIDTH,
										WINDOW_HEIGHT,
										SDL_WINDOW_SHOWN);


	if (settings.window == NULL) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	settings.renderer = SDL_CreateRenderer(settings.window, -1, SDL_RENDERER_ACCELERATED);
	if (settings.renderer == NULL) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cout << IMG_GetError() << std::endl;
		return false;
	}
	return true;
}

void	close(t_settings& settings, Player& player) {
	player.free();

	SDL_DestroyRenderer(settings.renderer);
	SDL_DestroyWindow(settings.window);
	settings.renderer = NULL;
	settings.window = NULL;

	IMG_Quit();
	SDL_Quit();
}

int		main(int ac, char* av[]) {
	int randNum;
	int enemy_quantity = 3;
	Enemy* enemies[ENEMY_MAX_QUANTITY];
	Meteor* meteors[METEOR_MAX_QUANTITY];
	t_settings settings;
	srand(time(0));

	for (int i = 0; i < ENEMY_MAX_QUANTITY; i++)
		enemies[i] = NULL;
	for (int i = 0; i < METEOR_MAX_QUANTITY; i++)
		meteors[i] = NULL;
	settings.window = NULL;
	settings.renderer = NULL;

	if (!init(settings))
		std::cout << "Failed to initialize!" << std::endl;

	Player	player;
	if (!player.load(PLAYER_IMG, settings))
		std::cout << "Failed to load Player image" << std::endl;
	else {
		bool quit = false;
		SDL_Event event;
		int ticks = 0;
		while (!quit) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_QUIT)
					quit = true;
				else if (event.type == SDL_KEYDOWN) {
					switch(event.key.keysym.sym) {
						case SDLK_LEFT: case SDLK_a:	player.moveLeft(); break;
						case SDLK_RIGHT: case SDLK_d:	player.moveRight(); break;
						case SDLK_UP: case SDLK_w:		player.moveUp(); break;
						case SDLK_DOWN: case SDLK_s:	player.moveDown(); break;
						case SDLK_ESCAPE: quit = true;
						default:
							break;
					}
				}
			}
			if (ticks % (METEOR_HEIGHT * 10) == 0) {
				for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
					if (meteors[i]) continue;
					int pos_x = rand() % (WINDOW_WIDTH - METEOR_WIDTH);
					meteors[i] = new Meteor(pos_x);
					meteors[i]->load(METEOR_IMG, settings);
					break;
				}
			}
			if (ticks % (ENEMY_HEIGHT * 32) == 0) {
				for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
					if (enemy_quantity <= 0) break;
					if (enemies[i]) continue;
					randNum = rand() % 2;
					if (randNum) {
						int pos_x = (rand() % (WINDOW_WIDTH / ENEMY_WIDTH) + 1) * ENEMY_WIDTH - ENEMY_WIDTH;
						enemies[i] = new Enemy(pos_x);
						enemies[i]->load(ENEMY_IMG, settings);
						enemy_quantity--;
					}
				}
				enemy_quantity = 3;
			}
			SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
			SDL_RenderClear(settings.renderer);
			for (int i = 0; i < METEOR_MAX_QUANTITY; i++) {
				if (meteors[i]) {
					// std::cout << "here\n";
					if (meteors[i]->getY() >= WINDOW_HEIGHT) {
						delete meteors[i];
						meteors[i] = NULL;
						continue;
					}
					meteors[i]->moveDown();
					meteors[i]->render(settings);
				}
			}
			for (int i = 0; i < ENEMY_MAX_QUANTITY; i++) {
				if (enemies[i]) {
					if (ticks % ENEMY_HEIGHT == 0 && enemies[i]->getY() >= WINDOW_HEIGHT) {
						delete enemies[i];
						enemies[i] = NULL;
						continue;
					}
					if (ticks % ENEMY_HEIGHT == 0) enemies[i]->moveDown();
					enemies[i]->render(settings);
				}
			}
			player.render(settings);
			SDL_RenderPresent(settings.renderer);
			ticks++;
		}
	}
	close(settings, player);
}
