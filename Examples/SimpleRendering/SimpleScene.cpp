/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include "SimpleScene.h"
#include "Input/InputManager.h"

SimpleScene::SimpleScene(void)
{
}


SimpleScene::~SimpleScene(void)
{
}

void SimpleScene::load()
{
	LOG_INFO("I'm loaded!")
}

void SimpleScene::update()
{
	if (GameInput.isKeyPressed(32))
	{
		LOG_INFO("Key pressed in scene!");
	}
}

std::string getName()
{
	return "titanic";
}