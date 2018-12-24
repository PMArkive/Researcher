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

#ifndef SFMT_HPP
#define SFMT_HPP

#include <Core/IRNG64.hpp>

class SFMT : public IRNG64
{

public:
    SFMT(u32 seed, u32 frames = 0);
    void advanceFrames(u32 frames) override;
    u32 nextUInt() override;
    u64 nextULong() override;
    void setSeed(u64 seed) override;
    void setSeed(u64 seed, u32 frames) override;
    u64 getSeed() override;

private:
    const u32 parity[4] = { 0x1, 0x0, 0x0, 0x13c9e684 };
    u32 sfmt[624];
    u32 seed;
    u32 index;

    void initialize(u32 seed);
    void periodCertificaion();
    void shuffle();

};

#endif // SFMT_HPP
