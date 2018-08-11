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

#ifndef MTRNG_HPP
#define MTRNG_HPP

#include <Core/IRNG.hpp>

class MT : public IRNG
{

protected:
    static const u32 LOWERMASK = 0x7FFFFFFF;
    static const int M = 397;
    static const int N = 624;
    static const u32 UPPERMASK = 0x80000000;
    static const u32 TEMPERINGMASKB = 0x9D2C5680;
    static const u32 TEMPERINGMASKC = 0xEFC60000;
    const u32 mag01[2] = { 0x0, 0x9908B0DF };
    u32 *mt = nullptr;
    u32 seed;
    u32 index;

    inline u32 temperingShiftL(u32 y) { return (y >> 18); }
    inline u32 temperingShiftS(u32 y) { return (y << 7); }
    inline u32 temperingShiftT(u32 y) { return (y << 15); }
    inline u32 temperingShiftU(u32 y) { return (y >> 11); }
    virtual void shuffle() = 0;
    virtual void initialize(u32 seed) = 0;

public:
    ~MT() override { delete mt; }
    void advanceFrames(u32 frames) override;

};

class MersenneTwister : public MT
{

private:
    void initialize(u32 seed) override;
    void shuffle() override;

public:
    MersenneTwister(u32 seed);
    u32 nextUInt() override;
    u16 nextUShort() override;
    void setSeed(u32 seed) override;
    u32 getSeed() override;

};

class MersenneTwisterUntempered : public MT
{

private:
    void initialize(u32 seed) override;
    void shuffle() override;

public:
    MersenneTwisterUntempered(u32 seed);
    u32 nextUInt() override;
    u16 nextUShort() override;
    void setSeed(u32 seed) override;
    u32 getSeed() override;

};

class MersenneTwisterFast : public MT
{

private:
    static const u32 TEMPERINGMASKC2 = 0xEF000000;
    u32 max;
    u32 maxCalls;

    void initialize(u32 seed) override;
    void shuffle() override;

public:
    MersenneTwisterFast(u32 seed, u32 calls);
    u32 nextUInt() override;
    u16 nextUShort() override;
    void setSeed(u32 seed) override;
    u32 getSeed() override;

};

#endif //MTRNG_HPP