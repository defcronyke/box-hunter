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
 * ConcavePolygon.hpp
 *
 *  Created on: 2013-03-08
 *      Author: Jeremy Carter
 *     Contact: Jeremy@JeremyCarter.ca
 */

#ifndef CONCAVEPOLYGON_HPP_
#define CONCAVEPOLYGON_HPP_

#include <vector>
#include "GameObject.hpp"

namespace Defcronyke
{

class ConcavePolygon: public Defcronyke::GameObject
{
public:
	ConcavePolygon(float x = 0.f, float y = 0.f, float rot = 0.f,
				   float width = 1.0f, float height = 1.0f,
				   float density = 1.0f, float friction = 0.05f, float restitution = 0.0f);
	virtual ~ConcavePolygon();
};

}
#endif
