/*
 * This file is part of Researcher
 * Copyright (C) 2018 by Admiral_Fish
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef IRNG_HPP
#define IRNG_HPP

#include <Core/Global.hpp>

class IRNG
{

public:
    virtual u32 nextUInt() = 0;
    virtual u16 nextUShort() = 0;
    virtual void setSeed(u32 seed) = 0;
    virtual void setSeed(u32 seed, u32 frames) = 0;
    virtual u32 getSeed() = 0;
    virtual void advanceFrames(u32 frames) = 0;
    virtual ~IRNG() = default;

};

#endif // IRNG_HPP
