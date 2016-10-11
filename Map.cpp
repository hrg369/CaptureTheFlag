#include<vector>
#include"Map.h"

using namespace std;

Map::Map()
{
    //is this line needed?
    fWeights = new vector<int>;
    fBaseTile = 00;
    fFlagTile = 55;
}

Map::Map(vector<int> weights)
{
    fWeights = &weights;
}

Map::Map(vector<int> weights, int flagTile, int baseTile)
{
    *fWeights = weights;
    fFlagTile = flagTile;
    fBaseTile = baseTile;
}

vector<int> Map::getTileWeights()
{
    return *fWeights;
}

void Map::setTileWeights(vector<int> weights)
{
    fWeights = &weights;
}

int Map::getTileWeight(int tile)
{
    return fWeights->at(tile);
}

void Map::setTileWeight(int tile, int weight)
{
    fWeights->at(tile) = weight;
}

int Map::getFlagTile()
{
    return fFlagTile;
}

void Map::setFlagTile(int tile)
{
    fFlagTile = tile;
}

int Map::getBaseTile()
{
    return fBaseTile;
}

void Map::setBaseTile(int tile)
{
    fBaseTile = tile;
}