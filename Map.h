#ifndef CAPTURETHEFLAG_MAP_H
#define CAPTURETHEFLAG_MAP_H
#include<vector>
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
    vector<int> *fWeights;
    int fFlagTile;
    int fBaseTile;
};

#endif //CAPTURETHEFLAG_MAP_H
