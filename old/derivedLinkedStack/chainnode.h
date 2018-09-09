/**
 ** This file is part of the chain project.
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

#ifndef CHAINNODE_H
#define CHAINNODE_H

template <class T>
struct chainNode {
  chainNode() {}
  chainNode(const T& element) { this->element = element; }
  chainNode(const T& element, chainNode<T>* next) {
    this->element = element;
    this->next = next;
  }

  /// save data
  T element;
  /// save pointer to point the next chain node
  chainNode<T>* next;
};

#endif  // CHAINNODE_H
