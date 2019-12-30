#pragma once
#include "Submenu.h"
#include "pacman.h"
#include "Enemy.h"
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

class Test : public subMenu {
public:
	void instructions();
	void testPacMan();
	void testEnemy();
};