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
 * Level007.cpp
 *
 *  Created on: 2013-03-10
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../../include/levels/Level007.hpp"
#include <vector>
#include "../../include/Triangle.hpp"
#include "../../include/Square.hpp"
#include "../../include/SquarePlayer.hpp"
#include "../../include/Goal.hpp"

namespace Defcronyke
{

Level007::Level007(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config)
{
	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 3.0f, 3.0f, 0.0f, 0.5f, ((window_config.height * 0.02f) - 0.5f) / 2.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 3.0f, ((window_config.height * 0.02f) - 0.5f) / 2.0f + 4.0f, 0.0f, 0.5f, ((window_config.height * 0.02f) - 0.5f) / 2.0f + 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 2.0f, 3.0f, 0.0f, 0.5f, (window_config.height * 0.02f) - 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(2.0f, 9.0f, 0.0f, 0.25f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(3.0f, 9.0f, 0.0f, 0.25f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(4.0f, 9.0f, 0.0f, 0.25f, 2.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(5.0f, 9.0f, 0.0f, 0.25f, 3.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(6.0f, 9.0f, 0.0f, 0.25f, 4.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(7.0f, 9.0f, 0.0f, 0.25f, 4.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(8.0f, 9.0f, 0.0f, 0.25f, 5.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(9.0f, 9.0f, 0.0f, 0.25f, 6.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(10.0f, 9.0f, 0.0f, 0.25f, 7.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(11.0f, 9.0f, 0.0f, 0.25f, 7.5f));

	objects_on_screen.push_back(
		new Defcronyke::Goal((window_config.width * 0.02f) - 2.0f, (window_config.height * 0.02f) - 1.0f + 10.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.1f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::SquarePlayer(0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.3f, 0.0f));
}

Level007::~Level007()
{

}

}
