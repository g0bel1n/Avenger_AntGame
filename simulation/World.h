//
// Created by g0bel1n on 07/12/2021.
//

#ifndef ANTS_FIGHT_CLUB_WORLD_H
#define ANTS_FIGHT_CLUB_WORLD_H

#include <vector>
#include "ants/Ant_.h"

class World {

public:

    World(int lenght, int width, int nb_ants, int nb_food);

    int get_nb_ants();
    int get_nb_food();

    void AddMarker(sf::Vector2f marker_position);



    int world_lenght;
    int world_width;

    std::vector<Ant_> ants;
    std::vector<Marker> markers;

    void update_ants(sf::Time dt);

    void update_graphics();



private:


    int nb_ants;
    int nb_food;



};


#endif //ANTS_FIGHT_CLUB_WORLD_H
