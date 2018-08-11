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

#include "LCRNG.hpp"

// Default constructor for LCRNG
LCRNG::LCRNG(u32 add, u32 mult, u32 seed)
{
    this->add = add;
    this->mult = mult;
    this->seed = seed;
}

// Method for advancing seed by a given number of frames
void LCRNG::advanceFrames(u32 frames)
{
    for (u32 i = 0; i < frames; i++)
        seed = seed * mult + add;
}

// Method for finding next 16 bit seed
u16 LCRNG::nextUShort()
{
    return static_cast<u16>((nextUInt() >> 16));
}

// IRNG Member
u32 LCRNG::nextUInt()
{
    seed = seed * mult + add;
    return seed;
}

// IRNG Member
void LCRNG::setSeed(u32 seed)
{
    this->seed = seed;
}

u32 LCRNG::getSeed()
{
    return seed;
}