//
// Created by zaeem on 2018/02/02.
//

#include "mazeIndex.h"

mazeIndex::mazeIndex() {}

mazeIndex::mazeIndex(int r, int c) : row(r), col (c) {}

bool mazeIndex::operator==(const mazeIndex &other) {
    return row == other.row && col == other.col;
}

void mazeIndex::operator=(const mazeIndex &other) {
    row = other.row;
    col = other.col;
}

bool mazeIndex::operator!=(const mazeIndex &other) {
    return row != other.row || col != other.col;
}