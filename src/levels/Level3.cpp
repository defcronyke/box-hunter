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
 * Level3.cpp
 *
 *  Created on: 2013-03-10
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../../include/levels/Level3.hpp"
#include <vector>
#include "../../include/Triangle.hpp"
#include "../../include/Square.hpp"
#include "../../include/Polygon.hpp"
#include "../../include/ConcavePolygon.hpp"
#include "../../include/SquarePlayer.hpp"
#include "../../include/Goal.hpp"

namespace Defcronyke
{

Level3::Level3(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config)
{
	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 3.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 5.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 7.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 9.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 11.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 13.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) / 2.0f - 0.5f, 15.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Goal((window_config.width * 0.02f) / 2.0f - 0.25f, 17.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.1f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::SquarePlayer(0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.3f, 0.0f));
}

Level3::~Level3()
{

}

}
