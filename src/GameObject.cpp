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
 * GameObject.cpp
 *
 *  Created on: 2013-03-05
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../include/GameObject.hpp"

namespace Defcronyke
{

GameObject::GameObject()
	: is_player(false),
	  is_deadly(false),
	  is_goal(false),
	  is_concave(false),
	  x(0.0f),
	  y(0.0f),
	  rot(0.0f),
	  width(1.0f),
	  height(1.0f)
{

}

GameObject::~GameObject()
{

}

float GameObject::get_x()
{
	return this->x;
}

void GameObject::set_x(float x)
{
	this->x = x;
	this->T = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
	return;
}

float GameObject::get_y()
{
	return this->y;
}

void GameObject::set_y(float y)
{
	this->y = y;
	this->T = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
	return;
}

float GameObject::get_rot()
{
	return this->rot;
}

void GameObject::set_rot(float rot)
{
	if (rot >= 360.0f)
		this->rot = 0.0f;

	if (rot < 0.0f)
		this->rot = 360.0f;

	if (rot != this->rot)
	{
		this->rot = rot;
		this->R = glm::rotate(glm::mat4(1.0f), rot, glm::vec3(0.f, 0.f, 1.0f));
	}


	return;
}

}
