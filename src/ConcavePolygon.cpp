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
 * ConcavePolygon.cpp
 *
 *  Created on: 2013-03-08
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#include "../include/ConcavePolygon.hpp"
#include "../include/GameObject.hpp"

namespace Defcronyke
{

ConcavePolygon::ConcavePolygon(float x, float y, float rot,
							   float width, float height,
							   float density, float friction, float restitution)
{
	this->is_player = false;
	this->is_deadly = false;
	this->is_goal = false;
	this->is_concave = true;

	this->x = x;
	this->y = y;
	this->rot = rot;

	this->width = width;
	this->height = height;

	this->density = density;
	this->friction = friction;
	this->restitution = restitution;

	this->T = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
	this->R = glm::rotate(this->R, this->rot, glm::vec3(0.f, 0.f, 1.0f));

	this->convex_objects.push_back(new GameObject);
	this->convex_objects.push_back(new GameObject); // need two objects because the shape is concave

	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, height));
	this->coords_opengl.push_back(glm::vec2(width, height));
	this->coords_opengl.push_back(glm::vec2(0.f, height));
	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width, 0.f));
	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(width / 2.0f, -height));
	this->coords_opengl.push_back(glm::vec2(0.f, 0.f));
	this->coords_opengl.push_back(glm::vec2(0.f, height));
	this->coords_opengl.push_back(glm::vec2(-width, height / 2.0f));

	this->convex_objects[0]->coords_physics.push_back(glm::vec2(0.f, 0.f));
	this->convex_objects[0]->coords_physics.push_back(glm::vec2(width / 2.0f, -height));
	this->convex_objects[0]->coords_physics.push_back(glm::vec2(width, 0.f));
	this->convex_objects[0]->coords_physics.push_back(glm::vec2(width, height));
	this->convex_objects[0]->coords_physics.push_back(glm::vec2(0.f, height));

	// these coords make the shape concave, so we put them in a new object
	this->convex_objects[1]->coords_physics.push_back(glm::vec2(0.f, 0.f));
	this->convex_objects[1]->coords_physics.push_back(glm::vec2(0.f, height));
	this->convex_objects[1]->coords_physics.push_back(glm::vec2(-width, height / 2.0f));

	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
	this->colors.push_back(glm::vec4(0.6f, 0.6f, 0.6f, 1.0f));
}

ConcavePolygon::~ConcavePolygon()
{
	for (unsigned int i = 0; i < this->convex_objects.size(); i++)
		if (this->convex_objects[i])
			delete this->convex_objects[i];
}

}
