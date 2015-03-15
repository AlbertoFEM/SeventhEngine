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
 * @author	Alberto Fernández <albertofem@gmail.com>
 */

#include "Core/Common.h"

#ifndef _SCENE_H_
#define _SCENE_H_

namespace Seventh
{
	class SceneManager;
	class Entity;
	class Scene : public AllocatedObject
	{
	public:
		virtual std::string getName() = 0;
		void update();
		virtual void load() = 0;

		void setSceneManager(SceneManager* scene_manager);

		void registerEntity(Entity* entity);
		void removeEntity(Entity* entity);

	protected:
		bool changeScene(std::string name);
		bool changeScene(Scene* scene);

	private:
		SceneManager* mSceneManager;
		std::map<std::string, Entity*> mEntityRegister;
	};
}

#endif