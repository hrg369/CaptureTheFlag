//
// Created by Gaskin on 11/10/2016.
//

#ifndef CAPTURETHEFLAG_BOT_H
#define CAPTURETHEFLAG_BOT_H
#include <vector>
#include "Map.h"

class Bot
{
public:
    Bot(Map &map);

    void update();
    int getCurrentTile();
    vector<int> getMemory();
    bool hasReachedFlag();
    bool hasReachedBase();

private:
    int visibility;
    int fCurrentTile;
    int fChosenTile;
    vector<int> fMemory;
    vector<int> fSight;
    Map *fMap;

    bool reachedFlag;
    bool reachedBase;

    void fillSight();
    void chooseTile();
    void addToMemory();
    void flushSight();
    void moveToTile();

};

#endif //CAPTURETHEFLAG_BOT_H
