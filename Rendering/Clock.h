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

#include "Core/Common.h"

namespace Seventh
{
	class Clock : public EngineComponent<Clock>
	{
	public:
		Clock();
		~Clock();

		void update();
		bool step();
		void reset();
		clock_t tick();

	private:
		uint mTicksPerSecond;
		ufloat mSkipTics;
		uint mMaxFrameSkip;
		uint mLoops;
		uint mLastTick;
	};
}