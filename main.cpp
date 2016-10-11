#include <iostream>
#include <vector>
#include "Bot.h"
// interesting
//#include "Map.h"

using namespace std;

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
