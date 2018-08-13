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

#ifndef RESEARCHER_HPP
#define RESEARCHER_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QVector>
#include <Core/LCRNG.hpp>
#include <Core/LCRNG64.hpp>
#include <Core/MTRNG.hpp>
#include <Core/SFMT.hpp>
#include <Core/TinyMT.hpp>
#include <Core/ResearcherModel.hpp>
#include <Core/ResearcherFrame.hpp>

typedef uint64_t u64;
typedef uint32_t u32;
typedef u64 (*func)(u64, u64);
typedef QHash<QString, func> Calculator;

namespace Ui
{
    class Researcher;
}

class Researcher : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Researcher *ui;
    ResearcherModel *model = new ResearcherModel(this, false);
    QHash<QString, int> keys;

    u64 getCustom(QString text, ResearcherFrame frame, QVector<ResearcherFrame> frames);
    void setupModels();
    void resizeHeader();
    QVector<bool> getHexCheck();
    static inline u64 divide(u64 x, u64 y) { return y == 0 ? 0 : x / y; }
    static inline u64 modulo(u64 x, u64 y) { return x % y; }
    static inline u64 shiftRight(u64 x, u64 y) { return x >> y; }
    static inline u64 shiftLeft(u64 x, u64 y) { return x << y; }
    static inline u64 bitAnd(u64 x, u64 y) { return x & y; }
    static inline u64 bitOr(u64 x, u64 y) { return x | y; }
    static inline u64 bitXor(u64 x, u64 y) { return x ^ y; }
    static inline u64 add(u64 x, u64 y) { return x + y; }
    static inline u64 subtract(u64 x, u64 y) { return x - y; }
    static inline u64 multiply(u64 x, u64 y) { return x * y; }

private slots:
    void on_pushButtonGenerate32Bit_clicked();
    void on_rngSelection_currentChanged(int index);
    void on_pushButtonSearch_clicked();
    void on_pushButtonNext_clicked();

public:
    explicit Researcher(QWidget *parent = nullptr);
    ~Researcher();

};

#endif // RESEARCHER_HPP
