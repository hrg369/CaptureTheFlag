#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Map
{
public:
    Map();
    Map(vector<int> freshWeights);
    Map(vector<int> freshWeights, int freshFlagTile, int freshBaseTile);

    vector<int> getTileWeights();
    void setTileWeights(vector<int> freshWeights);

    int getTileWeight(int tile);
    void setTileWeight(int tile, int weight);

    int getFlagTile();
    void setFlagTile(int tile);

    int getBaseTile();
    void setBaseTile(int tile);

private:
    vector<int> *weights;
    int flagTile;
    int baseTile;
};

Map::Map()
{
    //is this line needed?
    weights = new vector<int>;
    baseTile = 00;
    flagTile = 55;
}

Map::Map(vector<int> freshWeights)
{
    weights = &freshWeights;
}

Map::Map(vector<int> freshWeights, int freshFlagTile, int freshBaseTile)
{
    *weights = freshWeights;
    flagTile = freshFlagTile;
    baseTile = freshBaseTile;
}

vector<int> Map::getTileWeights()
{
    return *weights;
}

void Map::setTileWeights(vector<int> freshWeights)
{
    weights = &freshWeights;
}

int Map::getTileWeight(int tile)
{
    return weights->at(tile);
}

void Map::setTileWeight(int tile, int weight)
{
    weights->at(tile) = weight;
}

int Map::getFlagTile()
{
    return flagTile;
}

void Map::setFlagTile(int tile)
{
    flagTile = tile;
}

int Map::getBaseTile()
{
    return baseTile;
}

void Map::setBaseTile(int tile)
{
    baseTile = tile;
}

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
    int currentTile;
    int chosenTile;
    vector<int> memory;
    vector<int> sight;
    Map *map;

    bool reachedFlag;
    bool reachedBase;

    void fillSight();
    void chooseTile();
    void addToMemory();
    void flushSight();
    void moveToTile();

};

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



int main()
{
    std::cout << "Hello, World!" << std::endl;

    //comment out for same result for debug
    srand(time(NULL));

    vector<int> weights = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                           0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
                           0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
                           0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
                           0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
                           0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    Map mapLand(weights);

    mapLand.setTileWeight(10, 1);
    mapLand.setTileWeight(11, 1);
    mapLand.setTileWeight(12, 1);
    mapLand.setTileWeight(13, 1);
    cout << mapLand.getTileWeight(10);
    cout << mapLand.getTileWeight(11);

    Bot *bob = new Bot(mapLand);

    cout << "Bob's location is: " << bob->getCurrentTile() << "\n";

    for(int i = 0; i < 30; i++)
    {
        bob->update();
        cout << "Bob's location is: " << bob->getCurrentTile() << "\n";
    }
    cout << "Memory:";
    for(int i = 0; i < bob->getMemory().size(); i++)
    {
        cout << " " << bob->getMemory()[i];
    }
    cout << "\n";

    return 0;
}
