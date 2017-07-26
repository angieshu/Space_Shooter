/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-24-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: SpaceShooter.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-25-2017
 */


#ifndef SPACESHOOTER_HPP
#define SPACESHOOTER_HPP

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

#define ENEMY_MAX_QUANTITY 500

#define ENEMY_WIDTH 33
#define ENEMY_HEIGHT 17
#define PLAYER_WIDTH 33
#define PLAYER_HEIGHT 25

#define PLAYER_START_X ((WINDOW_WIDTH / 2) - (PLAYER_WIDTH / 2))
#define PLAYER_START_Y (WINDOW_HEIGHT - PLAYER_HEIGHT - 1)

#define PLAYER_IMG ("img/player.png")
#define ENEMY_IMG ("img/enemyShip.png")


class AUnit;
class Player;

// typedef enum {
// 	PLAYER,
// 	ENEMY,
// 	OBSTACLE
// };

typedef struct	s_settings {

	SDL_Window* window;
	SDL_Renderer* renderer;
	// SDL_Texture* background;

}				t_settings;

// typedef struct	s_units {
//
// 	Player player;
// }				t_units;

#endif
