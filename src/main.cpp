/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-25-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: main.cpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */


#include "SpaceShooter.hpp"
#include "Player.class.hpp"
#include "Background.class.hpp"

bool	init(t_settings& settings) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	settings.window = SDL_CreateWindow("Space Shooter",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										WINDOW_WIDTH,
										WINDOW_HEIGHT + INFOBOX_HEIGHT,
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
	if (TTF_Init() == -1) {
		std::cout << TTF_GetError() << std::endl;
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

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int		main(int ac, char* av[]) {
	Background background;
	t_settings settings;
	srand(time(0));

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
		unsigned long ticks = 0;
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
						case SDLK_SPACE:				player.shoot(settings); break;
						case SDLK_ESCAPE: quit = true;
						default: break;
					}
				}
			}
			if (ticks % (STAR_HEIGHT * 5) == 0)
				background.makeStar(settings);

			if (ticks % (METEOR_HEIGHT * 20) == 0)
				background.makeMeteor(settings);

			if (ticks % (ENEMY_HEIGHT * 24) == 0)
				background.makeEnemy(settings);

			background.killEnemy(player);
			background.killMeteor(player);

			if (background.hitEnemy(player) || background.hitMeteor(player)) {
				SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
				SDL_RenderClear(settings.renderer);
				background.loadGameOver(GAME_OVER, settings);
				SDL_RenderPresent(settings.renderer);
				SDL_Delay(2000);
				break;
			}

			SDL_SetRenderDrawColor(settings.renderer, 0x61, 0x23, 0x7A, 0xFF);
			SDL_RenderClear(settings.renderer);

			background.displayStar(settings);
			background.displayMeteor(settings, (ticks % 2 == 0));
			background.displayEnemy(settings, (ticks % (ENEMY_HEIGHT / 2) == 0));

			player.render(settings);
			player.moveBullets(settings);

			background.drawInfoBox(player, settings, ticks / 100);
			SDL_RenderPresent(settings.renderer);
			ticks++;
		}
	}
	close(settings, player);
}
