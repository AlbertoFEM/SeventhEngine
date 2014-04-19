/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fern�ndez
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
 * @author	Alberto Fern�ndez <albertofem@gmail.com>
 */

#include "Core/Common.h"
#include "Rendering/RenderingResource.h"
#include "Rendering/Vector2.h"

#ifndef _ENTITY_H_
#define _ENTITY_H_

namespace Seventh
{
	class Entity : public AllocatedObject
	{
	public:
		Entity();
		~Entity();

		void setRenderingResource(RenderingResource* resource);

		virtual void update() = 0;

		void setPosition(Vector2 position);


	protected:
		RenderingResource* mRenderingResource;
		Vector2 mPosition;
	};
}

#endif