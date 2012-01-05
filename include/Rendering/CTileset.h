/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
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
 * @version	0.1
 *
 */

#include "resources.h"

#include "Rendering/GLtexture.h"

#ifndef STH_TILESET_H_
#define STH_TILESET_H_

namespace Seventh
{
	class CTile;
	class CTileset
	{
	public:
		CTileset(std::string filename);
		~CTileset();

		CTileset(boost::shared_ptr< GLtexture >& texture);

		U64 LoadTile(s_Tile* tile);

		STH_INLINE boost::shared_ptr< GLtexture > GetGLtexture();

	private:
		// counter for internal tiles
		U64 m_CounterTiles;

		// main resource, will be shared by all the tiles
		boost::shared_ptr< GLtexture > m_GLtexture;

		// tiles map
		std::map< U64, SRenderingResource< CTile > > m_Tiles;
		std::map< s_Tile*, U64 > m_LoadedTiles;

	};
}

#endif
