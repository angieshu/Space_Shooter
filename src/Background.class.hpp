/**
 * @Author: Anhelina Shulha <angieshu>
 * @Date:   Jul-26-2017
 * @Email:  anhelina.shulha@gmail.com
 * @Filename: Background.class.hpp
 * @Last modified by:   angieshu
 * @Last modified time: Jul-26-2017
 */

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "SpaceShooter.hpp"
#include "Fireball.class.hpp"
#include "Enemy.class.hpp"
#include "Star.class.hpp"
#include "Meteor.class.hpp"
#include "Player.class.hpp"

class Background {

private:
	Enemy*			_enemies[ENEMY_MAX_QUANTITY];
	Meteor*			_meteors[METEOR_MAX_QUANTITY];
	Star*			_stars[STAR_MAX_QUANTITY];
	SDL_Texture*	_texture;

public:
	Background(void);
	~Background(void);

	void	free(void);
	void	clean(void);
	void	loadGameOver(std::string, t_settings&);
	void	drawInfoBox(Player&, t_settings&, unsigned long);

	void	makeStar(t_settings&);
	void	makeMeteor(t_settings&);
	void	makeEnemy(t_settings&);

	void	displayStar(t_settings&);
	void	displayMeteor(t_settings&, bool);
	void	displayEnemy(t_settings&, bool);

	bool	hitEnemy(Player& player);
	bool	hitMeteor(Player& player);

	void	killEnemy(Player& player);
	void	killMeteor(Player& player);


};

#endif
