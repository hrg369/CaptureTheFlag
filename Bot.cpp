#include <vector>
#include <cstdlib>
#include <ctime>
#include "Bot.h"
#include "Map.h"

using namespace std;

Bot::Bot(Map &freshMap)
{
    reachedBase = false;
    reachedFlag = false;
    visibility = 1;
    //current grid made of 10 by 10
    currentTile = 00;
    memory.push_back(currentTile);
    map = &freshMap;
}

void Bot::update()
{
    fillSight();
    chooseTile();
    addToMemory();
    flushSight();
    moveToTile();
}

int Bot::getCurrentTile()
{
    return currentTile;
}

vector<int> Bot::getMemory()
{
    return memory;
}

void Bot::fillSight()
{
    //take surrounding four tiles and add them to sight
    // conditional statements trim boundaries
    if(visibility == 1)
    {
        if(currentTile < 90)
        {
            sight.push_back(currentTile + 10);
        }
        if(currentTile % 10 < 9)
        {
            sight.push_back(currentTile + 01);
        }
        if(currentTile > 9)
        {
            sight.push_back(currentTile - 10);
        }
        if(currentTile % 10 > 0)
        {
            sight.push_back(currentTile - 01);
        }
    }
}

/*
 * currently only performs unweighted exploration,
 * remaining within the bounds of the grid, and avoiding
 * tiles already walked on.
 * Note: May find no chosenTile if surrounded by tiles already walked (spiral).
 */
void Bot::chooseTile()
{
    vector<int> bestTiles;

    /*
     * first check memory for tiles
     * Note: maybe a good idea to flush memory every now and then
     * or keep to a certain size
     * Note: currently uses dreaded goto, think about alternatives
     */
    /*
    cout << "\nSight:";
    for(int i = 0; i < sight.size(); i++)
    {
        cout << " " << sight[i];
    }
    cout << "\n";
     */

    for(int i = 0; i < sight.size(); i++)
    {
        for (int j = 0; j < memory.size(); j++)
        {
            if (sight[i] == memory[j])
            {
                //cout << sight[i] << " already visited!";
                //remove element as it won't be a choice and is already in memory
                sight.erase(sight.begin() + i);
                i--;

                //if erased element was last element

                if (i == sight.size())
                {
                    goto finishedMemorySearch;
                }
                else
                {
                    //break to check next sight[i]
                    break;
                }

            }
        }
    }
    finishedMemorySearch:

    /*
    cout << "\nSight:";
    for(int i = 0; i < sight.size(); i++)
    {
        cout << " " << sight[i];
    }
    cout << "\n";
     */

    for(int i = 0; i < sight.size(); i++)
    {
        //if the tile seen is not in the grid
        if(sight[i] < 0)
            continue;

        //if no valid candidates to compare with, add tile
        if(bestTiles.size() == 0)
        {
            bestTiles.push_back(sight[i]);
        }
            /*
             * Either replace bestTiles[n] or be added to them.
             * Note: bestTiles[0] will have equal weight to all bestTiles[n].
             */
        else if(map->getTileWeight(sight[i]) < map->getTileWeight(bestTiles[0]))
        {
            bestTiles.clear();
            bestTiles.push_back(sight[i]);
        }
        else
        {
            bestTiles.push_back(sight[i]);
        }

    }
    //if no bestTiles, chosenTile remains the same.
    if(bestTiles.size() == 1)
    {
        chosenTile = bestTiles.front();
    }
        //Note: this statement may work for both cases, as rand() of 1 is 1.
    else if(bestTiles.size() > 1)
    {
        chosenTile = bestTiles[rand() % bestTiles.size()];
    }
}

void Bot::addToMemory()
{
    //this style of memory includes all tiles traversed
    memory.push_back(chosenTile);

    /*
     * This style of memory includes all tiles traversed AND seen
    for(int i = 0; i < sight.size(); i++)
    {
        memory.push_back(sight[i]);
    }
     */
}

/* Note: if sight is filled and flushed within public update method,
 * does it need its own method?
 * Currently thinking Yes.
 */
void Bot::flushSight()
{
    sight.clear();
}

void Bot::moveToTile()
{
    currentTile = chosenTile;
}


