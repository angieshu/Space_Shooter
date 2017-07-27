# Space_Shooter

Space Shooter is a simple 2D video game, imlemented in C++ using SDL libraries. Player's space ship can be moved using A, W, S, D and arrow keys.

![game](https://user-images.githubusercontent.com/25576444/28653292-a26cfaae-7241-11e7-9f68-52d9cf0c665e.gif)

## Motivation

I was always curious how video games work: how the design made, how you can control whatever happening on a screen, basicaly, how to make a beautiful interface and what is behind it. That is why I set a goal to build a simple 2D video game to learn how to use graphic APIs.

## Game Description

In this game you can:

• Control player's space ship with A, W, S, D and arrow keys

• Shoot enemies and meteors using space

• Kill and get killed

• Get hit by enemy's space ships (50 hit points) and meteors (20 hit points)

• Collect points by killing enemies and meteors

• Lose life by losing 100 hit points

• Exit pressing ESC

## Getting Started

For those who insterested to create something similar you need to install SDL packages. You can find the ones I used in folder SDL_packages.

To install you just need to copy those three packages to /Library/Frameworks.

Then run following commands in your Terminal:

```
cd /Library/Frameworks/SDL2.framework/
```
```
codesign -f -s - SDL2
```
```
cd /Library/Frameworks/SDL2_image.framework/
```
```
codesign -f -s - SDL2_image
```
```
cd /Library/Frameworks/SDL2_ttf.framework/
```
```
codesign -f -s - SDL2_ttf
```

Thanks to [Open Game Art](https://opengameart.org) you can have a great design and don't spend a lot of time on creating it by yourself. 


