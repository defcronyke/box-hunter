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
 * Level012.cpp
 *
 *  Created on: 2013-03-12
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../../include/levels/Level012.hpp"
#include <vector>
#include "../../include/Square.hpp"
#include "../../include/Triangle.hpp"
#include "../../include/SquarePlayer.hpp"
#include "../../include/Goal.hpp"

namespace Defcronyke
{

Level012::Level012(std::vector<Defcronyke::GameObject*>& objects_on_screen, Defcronyke::WindowConfig& window_config)
{
	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 1.0f, 1.0f, 0.0f, 1.0f, 24.0f, 1000.0f, 1.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 1.95f, 2.0f, 0.0f, 0.5f, 1.0f, 1000.0f, 1.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 3.95f, 2.0f, 0.0f, 0.5f, 1.0f, 1000.0f, 1.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square((window_config.width * 0.02f) - 3.90f, 4.0f, 0.0f, 2.3f, 0.3f, 0.1f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(0.0f, 1.0f, 0.0f, 1.0f, 24.0f, 1000.0f, 1.0f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(1.25f, 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(1.25f, 1.0f, 0.0f, 2.25f, 0.3f, 0.1f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(3.0f, 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.05f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(3.74f, 1.8f, 180.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(3.24f, 1.84f, 0.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(3.2f, 1.8f, 180.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(2.7f, 1.84f, 0.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(2.65f, 1.8f, 180.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(2.15f, 1.84f, 0.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(2.12f, 1.8f, 180.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(1.62f, 1.84f, 0.0f, 0.5f, 0.5f, 0.01f, 0.05f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle((window_config.width * 0.02f) / 2.0f - 1.0f, 0.0f, 0.0f, 2.0f, 3.0f, 100.0f, 1.0f, 2.0f));

	objects_on_screen.push_back(
		new Defcronyke::Square(6.75f, 3.0f, 0.0f, 2.5f, 0.3f, 0.05f, 0.05f, 1.0f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(7.5f, 4.5f, 180.0f, 1.0f, 1.0f, 0.1f, 1.0f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(6.5f, 4.5f, 0.0f, 1.0f, 1.0f, 0.1f, 1.0f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(9.5f, 4.5f, 180.0f, 1.0f, 1.0f, 0.1f, 1.0f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Triangle(8.5f, 4.5f, 0.0f, 1.0f, 1.0f, 0.1f, 1.0f, 1.5f));

	objects_on_screen.push_back(
		new Defcronyke::Goal((window_config.width * 0.02f) - 3.0f, 3.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.1f, 0.0f));

	objects_on_screen.push_back(
		new Defcronyke::SquarePlayer(2.0f, 0.5f, 0.0f, 0.5f, 0.5f, 1.0f, 0.3f, 0.0f));
}

Level012::~Level012()
{

}

}
