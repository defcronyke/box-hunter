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
 * Level011.cpp
 *
 *  Created on: 2013-03-12
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../../include/levels/Level011.hpp"
#include <vector>
#include "../../include/Square.hpp"
#include "../../include/Triangle.hpp"
#include "../../include/SquarePlayer.hpp"
#include "../../include/Goal.hpp"

namespace Defcronyke
{

Level011::Level011(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config)
{
	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 1.5f, 0.5f, 180.0f, 1.0f, 0.5f, 3.0f, 1.0f, 2.4f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 3.5f, 2.0f, 180.0f, 1.0f, 2.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 4.5f, 2.0f, 0.0f, 1.0f, 1.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 5.5f, 0.5f, 180.0f, 1.0f, 0.5f, 3.0f, 1.0f, 1.8f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 7.5f, 4.0f, 180.0f, 1.0f, 4.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 8.5f, 4.0f, 0.0f, 1.0f, 2.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 9.5f, 0.5f, 180.0f, 1.0f, 0.5f, 3.0f, 1.0f, 1.2f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 11.5f, 6.0f, 180.0f, 1.0f, 6.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 12.5f, 6.0f, 0.0f, 1.0f, 3.0f, 0.01f, 0.5f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02) - 13.5f, 0.5f, 180.0f, 1.0f, 0.5f, 3.0f, 1.0f, 2.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(0.5f, 0.1f, 0.0f, 0.5f, 5.0f, 0.01f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(0.5f, 5.1f, 0.0f, 0.5f, 5.0f, 0.01f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Goal(0.5f, 10.6f, 0.0f, 0.5f, 0.5f, 0.01f, 0.1f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(0.5f, 11.6f, 0.0f, 0.5f, 1.0f, 0.01f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::SquarePlayer((window_config.width * 0.02) - 0.5f, 1.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.3f, 0.0f));
}

Level011::~Level011()
{

}

}
