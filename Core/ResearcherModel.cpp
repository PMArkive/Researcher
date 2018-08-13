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

#include "ResearcherModel.hpp"

ResearcherModel::ResearcherModel(QObject *parent, bool is64Bit) : QAbstractTableModel(parent)
{
    flag = is64Bit;
}

void ResearcherModel::setModel(QVector<ResearcherFrame> frames)
{
    if (frames.empty())
        return;
    int i = rowCount();
    emit beginInsertRows(QModelIndex(), i, i + frames.size() - 1);
    model.append(frames);
    emit endInsertRows();
}

void ResearcherModel::clear()
{
    if (model.empty())
        return;
    emit beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
    model.clear();
    model.squeeze();
    emit endRemoveRows();
}

void ResearcherModel::setFlag(bool is64Bit)
{
    flag = is64Bit;
    emit headerDataChanged(Qt::Horizontal, 0, columnCount());
}

void ResearcherModel::setHex(QVector<bool> hex)
{
    this->hex = hex;
}

int ResearcherModel::rowCount(const QModelIndex &parent) const
{
    (void) parent;
    return model.size();
}

int ResearcherModel::columnCount(const QModelIndex &parent) const
{
    (void) parent;
    return flag ? 22 : 20;
}

QVariant ResearcherModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        ResearcherFrame frame = model[index.row()];
        if (flag)
        {
            switch (index.column())
            {
                case 0:
                    return frame.getFrame();
                case 1:
                    return QString::number(frame.getFull64(), 16).toUpper().rightJustified(16, '0');
                case 2:
                    return QString::number(frame.getHigh32(), 16).toUpper().rightJustified(8, '0');
                case 3:
                    return QString::number(frame.getLow32(), 16).toUpper().rightJustified(8, '0');
                case 4:
                    return QString::number(frame.getHigh16(), 16).toUpper().rightJustified(4, '0');
                case 5:
                    return QString::number(frame.getLow16(), 16).toUpper().rightJustified(4, '0');
                case 6:
                    return QString::number(frame.getCustom(0), hex[0] ? 16 : 10).toUpper();
                case 7:
                    return QString::number(frame.getCustom(1), hex[1] ? 16 : 10).toUpper();
                case 8:
                    return QString::number(frame.getCustom(2), hex[2] ? 16 : 10).toUpper();
                case 9:
                    return QString::number(frame.getCustom(3), hex[3] ? 16 : 10).toUpper();
                case 10:
                    return QString::number(frame.getCustom(4), hex[4] ? 16 : 10).toUpper();
                case 11:
                    return QString::number(frame.getCustom(5), hex[5] ? 16 : 10).toUpper();
                case 12:
                    return QString::number(frame.getCustom(6), hex[6] ? 16 : 10).toUpper();
                case 13:
                    return QString::number(frame.getCustom(7), hex[7] ? 16 : 10).toUpper();
                case 14:
                    return QString::number(frame.getCustom(8), hex[8] ? 16 : 10).toUpper();
                case 15:
                    return QString::number(frame.getCustom(9), hex[9] ? 16 : 10).toUpper();
                case 16:
                    return frame.getMod3();
                case 17:
                    return frame.getMod25();
                case 18:
                    return frame.getMod100();
                case 19:
                    return frame.getDiv656();
                case 20:
                    return frame.getHighBit();
                case 21:
                    return frame.getLowBit();
            }
        }
        else
        {
            switch (index.column())
            {
                case 0:
                    return frame.getFrame();
                case 1:
                    return QString::number(frame.getFull32(), 16).toUpper().rightJustified(8, '0');
                case 2:
                    return QString::number(frame.getHigh16(), 16).toUpper().rightJustified(4, '0');
                case 3:
                    return QString::number(frame.getLow16(), 16).toUpper().rightJustified(4, '0');
                case 4:
                    return QString::number(frame.getCustom(0), hex[0] ? 16 : 10).toUpper();
                case 5:
                    return QString::number(frame.getCustom(1), hex[1] ? 16 : 10).toUpper();
                case 6:
                    return QString::number(frame.getCustom(2), hex[2] ? 16 : 10).toUpper();
                case 7:
                    return QString::number(frame.getCustom(3), hex[3] ? 16 : 10).toUpper();
                case 8:
                    return QString::number(frame.getCustom(4), hex[4] ? 16 : 10).toUpper();
                case 9:
                    return QString::number(frame.getCustom(5), hex[5] ? 16 : 10).toUpper();
                case 10:
                    return QString::number(frame.getCustom(6), hex[6] ? 16 : 10).toUpper();
                case 11:
                    return QString::number(frame.getCustom(7), hex[7] ? 16 : 10).toUpper();
                case 12:
                    return QString::number(frame.getCustom(8), hex[8] ? 16 : 10).toUpper();
                case 13:
                    return QString::number(frame.getCustom(9), hex[9] ? 16 : 10).toUpper();
                case 14:
                    return frame.getMod3();
                case 15:
                    return frame.getMod25();
                case 16:
                    return frame.getMod100();
                case 17:
                    return frame.getDiv656();
                case 18:
                    return frame.getHighBit();
                case 19:
                    return frame.getLowBit();
            }
        }
    }
    return QVariant();
}

QVariant ResearcherModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
            case 0:
                return "Frame";
            case 1:
                return flag ? "64Bit" : "32Bit";
            case 2:
                return flag ? "32Bit High" : "16Bit High";
            case 3:
                return flag ? "32Bit Low" : "16Bit Low";
            case 4:
                return flag ? "16Bit High" : "Custom 1";
            case 5:
                return flag ? "16Bit Low" : "Custom 2";
            case 6:
                return flag ? "Custom 1" : "Custom 3";
            case 7:
                return flag ? "Custom 2" : "Custom 4";
            case 8:
                return flag ? "Custom 3" : "Custom 5";
            case 9:
                return flag ? "Custom 4" : "Custom 6";
            case 10:
                return flag ? "Custom 5" : "Custom 7";
            case 11:
                return flag ? "Custom 6" : "Custom 8";
            case 12:
                return flag ? "Custom 7" : "Custom 9";
            case 13:
                return flag ? "Custom 8" : "Custom 10";
            case 14:
                return flag ? "Custom 9" : "%3";
            case 15:
                return flag ? "Custom 10" : "%25";
            case 16:
                return flag ? "%3" : "%100";
            case 17:
                return flag ? "%25" : "/656";
            case 18:
                return flag ? "%100" : "HBit";
            case 19:
                return flag ? "/656" : "LBit";
            case 20:
                return "HBit";
            case 21:
                return "LBit";
        }
    }
    return QVariant();
}

QModelIndex ResearcherModel::search(QString string, u64 result, int row)
{
    int column = 0;
    u64 (*getResult)(ResearcherFrame) = nullptr;
    if (string == "64Bit")
    {
        column = 1;
        getResult = &ResearcherModel::get64Bit;
    }
    else if (string == "32Bit High")
    {
        column = 2;
        getResult = &ResearcherModel::get32BitHigh;
    }
    else if (string == "32Bit Low")
    {
        column = 3;
        getResult = &ResearcherModel::get32BitLow;
    }
    else if (string == "32Bit")
    {
        column = 1;
        getResult = &ResearcherModel::get32;
    }
    else if (string == "16Bit High")
    {
        column = flag ? 4 : 2;
        getResult = &ResearcherModel::get16BitHigh;
    }
    else if (string == "16Bit Low")
    {
        column = flag ? 5 : 3;
        getResult = &ResearcherModel::get16BitLow;
    }

    int size = rowCount();

    for (; row < size; row++)
    {
        u64 value = getResult(model[row]);
        if (value == result)
            return index(row, column, QModelIndex());
    }

    return QModelIndex();
}
