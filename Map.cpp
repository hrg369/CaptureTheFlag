#include<vector>
#include"Map.h"

using namespace std;

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