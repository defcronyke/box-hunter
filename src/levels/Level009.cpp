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
 * Level009.cpp
 *
 *  Created on: 2013-03-11
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../../include/levels/Level009.hpp"
#include <vector>
#include "../../include/Square.hpp"
#include "../../include/SquarePlayer.hpp"
#include "../../include/Goal.hpp"

namespace Defcronyke
{

Level009::Level009(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config)
{
	objects_on_screen.push_back(
		new Defcronyke::Square(2.1f, 3.0f, 0.0f, 0.3f, 1.6f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(5.0f, 3.0f, 0.0f, 0.3f, 1.6f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(2.1f, 5.0f, 0.0f, 3.2f, 0.3f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 2.4f, 0.5f, 0.0f, 0.3f, 1.2f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 0.4f, 0.5f, 0.0f, 0.3f, 1.2f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 2.4f, 2.5f, 0.0f, 2.3f, 0.3f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(1.0f, 2.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.05f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(6.0f, 2.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.05f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Goal(3.0f, 4.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.1f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::SquarePlayer((window_config.width * 0.02f) - 1.5f, 0.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.3f, 0.0f));
}

Level009::~Level009()
{

}

}
