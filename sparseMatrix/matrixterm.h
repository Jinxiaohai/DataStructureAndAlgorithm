/**
 ** This file is part of the spareMatrix project.
 ** Copyright 2018 xiaohai <xiaohaijin@outlook.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef MATRIXTERM_H
#define MATRIXTERM_H

template <class T>
struct matrixTerm {
  int row;
  int col;
  T value;

  /// type conversion from matrixTerm to T
  operator T() const { return value; }
};

#endif  // MATRIXTERM_H
