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
 * Polygon.cpp
 *
 *  Created on: 2013-03-06
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../include/Polygon.hpp"

namespace Defcronyke
{

Polygon::Polygon(float x, float y, float rot, float width, float height)
{
	this->is_player = false;
	this->is_deadly = false;
	this->is_goal = false;
	this->is_concave = false;

	this->x = x;
	this->y = y;
	this->rot = rot;

	this->width = width;
	this->height = height;

	this->T = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
	this->R = glm::rotate(this->R, this->rot, glm::vec3(0.f, 0.f, 1.0f));

	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, height));
	this->coords_opengl.push_back(glm::vec2(width, height));
	this->coords_opengl.push_back(glm::vec2(0.f, height));
	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, 0.f));
	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width / 2.0f, -height));
	this->coords_opengl.push_back(glm::vec2(0.f, height));
	this->coords_opengl.push_back(glm::vec2(width, height));
	this->coords_opengl.push_back(glm::vec2(width / 2.0f, height * 2));

	this->coords_physics.push_back(glm::vec2(0.f, 0.f));
	this->coords_physics.push_back(glm::vec2(width / 2.0f, -height));
	this->coords_physics.push_back(glm::vec2(width, 0.f));
	this->coords_physics.push_back(glm::vec2(width, height));
	this->coords_physics.push_back(glm::vec2(width / 2.0f, height * 2));
	this->coords_physics.push_back(glm::vec2(0.f, height));

	this->colors.push_back(glm::vec4(0.1f, 0.5f, 0.5f, 1.0f));
	this->colors.push_back(glm::vec4(0.5f, 0.1f, 0.5f, 1.0f));
	this->colors.push_back(glm::vec4(0.5f, 0.5f, 0.1f, 1.0f));
	this->colors.push_back(glm::vec4(0.5f, 0.5f, 0.1f, 1.0f));
	this->colors.push_back(glm::vec4(0.5f, 0.1f, 0.5f, 1.0f));
	this->colors.push_back(glm::vec4(0.1f, 0.5f, 0.5f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.9f, 0.9f, 0.9f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.9f, 0.9f, 0.9f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.9f, 0.9f, 0.9f, 1.0f));
}

Polygon::~Polygon()
{

}

}
