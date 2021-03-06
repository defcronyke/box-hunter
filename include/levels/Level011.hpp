/* Ⓒ Copyright 2013 Jeremy Carter
 *
 * This file is part of Box Hunter.
 *
 * Box Hunter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Box Hunter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Box Hunter.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Level011.hpp
 *
 *  Created on: 2013-03-12
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef LEVEL011_HPP_
#define LEVEL011_HPP_

#include <vector>
#include "../Window.hpp"

namespace Defcronyke
{

class GameObject;

class Level011
{
public:
	Level011(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config);
	virtual ~Level011();
};

}
#endif
