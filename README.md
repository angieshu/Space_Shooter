# Space_Shooter

Space Shooter is a simple 2D video game, imlemented in C++ using SDL libraries. The user's space ship is controlled by A, W, S, D buttons and arrow keys.

![game](https://user-images.githubusercontent.com/25576444/28653292-a26cfaae-7241-11e7-9f68-52d9cf0c665e.gif)

## Motivation

I was always curious how video games work: how the design is made and how the game characters are controlled, basicaly, how to make a beautiful interface and what is behind it. That is why I set a goal to build a simple 2D video game to learn how to use graphic APIs.

## Game Description

You have 3 lives, and each life consists of 100 hit points.

In this game you can:

• Control player's space ship with A, W, S, D and arrow keys

• Shoot enemies and meteors using space button

• Destroy and get destroyed

• Get hit by enemy's space ships (-50 hit points) and meteors (-20 hit points)

• Collect points by destroying enemy's ships and meteors

• Exit by pressing ESC button

## Getting Started

For those who insterested to create something similar you need to install SDL packages. You can find the ones I used in folder SDL_packages.

To install you just need to copy those three packages to /Library/Frameworks.

Then run following commands in your Terminal:

```
cd /Library/Frameworks/SDL2.framework/

codesign -f -s - SDL2

cd /Library/Frameworks/SDL2_image.framework/

codesign -f -s - SDL2_image

cd /Library/Frameworks/SDL2_ttf.framework/

codesign -f -s - SDL2_ttf
```

Thanks to [Open Game Art](https://opengameart.org) you can have a great design and don't spend a lot of time on creating it by yourself.

## Code Overview

In this program I made several classes: Background, AUnit, and its inheritors Player, Enemy, Meteor, Star and Fireball.


#### Background class

Probably, the biggest class in this program. Here I control background (obviously): create enemies, stars, meteors, make them move down and check collisions with player's bullets.

<img width="446" alt="screen shot 2017-07-26 at 10 26 08 pm" src="https://user-images.githubusercontent.com/25576444/28655571-9a50186e-7251-11e7-9ada-8b87072eb118.png">

Enemies, meteors and stars are stored in arrays. This way easier manage creation, movements and collisions. All of them created at the top of the game window at random X position.
For example, that is how meteors generated:

<img width="395" alt="screen shot 2017-07-26 at 10 36 13 pm" src="https://user-images.githubusercontent.com/25576444/28655797-ee994f2a-7252-11e7-99b1-7745c8c9141f.png">

In display*() functions objects get rended to the screen.
s
In hit*() functions I check if the player got hit by enemy or meteor, and if he/she did, reduce his/her Hit Points. If there is not enough points, player loses life. If that was the last life function returns true meaning that the player died and game over : 

<img width="343" alt="screen shot 2017-07-26 at 10 47 06 pm" src="https://user-images.githubusercontent.com/25576444/28656040-74c52c08-7254-11e7-9295-de1b6f4b265d.png">

drawInfoBox() function creates a box at the bottom of the game screen with info about current score, time spent in the game, lives left and Hit Points.


#### AUnit class

AUnit is an abstract class for all units you could find in the game: Player, Enemy, Meteor, Star and even Fireball.

<img width="420" alt="screen shot 2017-07-26 at 10 59 06 pm" src="https://user-images.githubusercontent.com/25576444/28656316-1e980bd2-7256-11e7-9c13-3dabbaea3b57.png">

Here we have widht and height of an object, its position on a screen and its image. Also getter- and setter- along with movement-functions are present. load() and render() load and render object's image to the screen respectively:

<img width="589" alt="screen shot 2017-07-26 at 11 10 41 pm" src="https://user-images.githubusercontent.com/25576444/28656608-c899a57c-7257-11e7-91f6-cc309f40c90e.png">


#### Player class

Inherit from AUnit class. Stores info about bullets used, current score, lives left, Hit Points, and colliders. Beside getter- and setter-functions has its own moveDown() function. Also has unique functions: moveBullets,() shoot(), containes(), kill().    

<img width="389" alt="screen shot 2017-07-26 at 11 18 27 pm" src="https://user-images.githubusercontent.com/25576444/28656815-dbcf6d24-7258-11e7-9367-5f521076affa.png">

containes() functions check for collision with Enemy and Meteor:

<img width="392" alt="screen shot 2017-07-26 at 11 26 08 pm" src="https://user-images.githubusercontent.com/25576444/28657017-e629dd94-7259-11e7-8a98-d581ccb3e8ce.png">

kill() function checks if Enemy or Meteor got killed by bullets:

<img width="380" alt="screen shot 2017-07-26 at 11 28 40 pm" src="https://user-images.githubusercontent.com/25576444/28657090-3af28f56-725a-11e7-9295-db2f71d621b3.png">


#### Fireball class

Inherit from AUnit class. Called only from Player class. Has its own moveDown() and two unique functions contains() that check for collisions with Enemy and Meteor.

<img width="300" alt="screen shot 2017-07-26 at 11 37 01 pm" src="https://user-images.githubusercontent.com/25576444/28657338-771adb2c-725b-11e7-9f29-3d255ccc2551.png">

<img width="331" alt="screen shot 2017-07-26 at 11 37 16 pm" src="https://user-images.githubusercontent.com/25576444/28657352-8fe28ede-725b-11e7-960a-e5f93edb70c8.png">


#### Enemy, Meteor and Star classes

Inherit from AUnit class. Have their own moveDown() and no unique functions. Built more or less in the same way :

<img width="241" alt="screen shot 2017-07-26 at 11 42 16 pm" src="https://user-images.githubusercontent.com/25576444/28657476-2f929014-725c-11e7-88ef-a0b4d502fdad.png">


#### main.cpp

After initiazing a game window and a player there is a game loop created. Here we can shoot, move player, render enemies and obsctacles, quit and even die:

<img width="473" alt="screen shot 2017-07-26 at 11 55 53 pm" src="https://user-images.githubusercontent.com/25576444/28657979-0f7dc4ea-725e-11e7-9e49-6ef034ed2009.png">

## Installation and Usage

1. Clone repository
2. Run next command in your terminal :

```
./Space_Shooter
```

### Limitations

The game will only run on MacOs machine.

## Author

Anhelina Shulha


