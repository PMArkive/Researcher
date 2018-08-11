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

#include "LCRNG64.hpp"

// LCRNG64 constructor that sets a given seed
LCRNG64::LCRNG64(u64 add, u64 mult, u64 seed)
{
    this->add = add;
    this->mult = mult;
    this->seed = seed;
}

// Method for advancing seed by a given number of frames
void LCRNG64::advanceFrames(u32 frames)
{
    for (u32 i = 0; i < frames; i++)
        seed = seed * mult + add;
}

// Method for finding next modified 32 bit seed
u32 LCRNG64::nextUInt(u32 max)
{
    return static_cast<u32>((((nextULong() >> 32) * max) >> 32));
}

// IRNG64 Member
u64 LCRNG64::nextULong()
{
    seed = seed * mult + add;
    return seed;
}

// IRNG64 Memeber
u32 LCRNG64::nextUInt()
{
    return static_cast<u32>((nextULong() >> 32));
}

// IRNG64 Member
void LCRNG64::setSeed(u64 seed)
{
    this->seed = seed;
}

u64 LCRNG64::getSeed()
{
    return seed;
}