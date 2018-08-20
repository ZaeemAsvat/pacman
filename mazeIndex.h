//
// Created by zaeem on 2018/02/02.
//

#ifndef PACMAN_MAZEINDEX_H
#define PACMAN_MAZEINDEX_H


struct mazeIndex {
    mazeIndex();
    mazeIndex(int r, int c);

    int row, col;

    bool operator==(const mazeIndex &other);
    void operator=(const mazeIndex &other);
    bool operator!=(const mazeIndex &other);

};


#endif //PACMAN_MAZEINDEX_H
