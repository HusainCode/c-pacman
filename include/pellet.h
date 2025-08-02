#pragma once


struct pellet
{
    int location = 0;

};


void spwan_pellet(int x, int y);

int isPelletAt(int x, int y);

void collect_pellet(int x, int y);
