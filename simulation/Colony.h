//
// Created by g0bel1n on 07/12/2021.
//

#ifndef ANTS_FIGHT_CLUB_WORLD_H
#define ANTS_FIGHT_CLUB_WORLD_H

#include "Elements/Marker.h"


#pragma once

#include <vector>
#include "ants/Ant_.h"
#include "chunks/chunk.h"
#include "Elements/Food.h"


Chunk &get_chunk_ij(std::vector<Chunk> &chunks, int i, int j);

Chunk &get_chunk_xy(std::vector<Chunk> &chunks, float x, float y);

Chunk &get_chunk_pos(std::vector<Chunk> &chunks, sf::Vector2<float> pos);

class Colony {

public:

    Colony(int nb_ants, sf::Color color, sf::Texture hole_text, sf::Font font,
           sf::Vector2f colony_pos = parameters::DEFAULT_COLONY_POSITION,
           float ant_speed = parameters::DEFAULT_ANT_SPEED);

    int get_nb_ants();

    int food_in_colony{};
    int ant_generated = 0;
    float ant_speed{};

    std::vector<Ant_> ants;
    std::vector<Chunk> chunks;

    sf::Vector2f colony_pos;

    void add_ant();

    void delete_ant();

    void apply_texture();


    int get_food_available();


    void update(sf::Time dt, std::vector<Obstacle> &obstacles, std::vector<Food> &foods);

    // Texture of the colony Hole
    sf::Texture colony_hole;


    // Colony Graphic object
    sf::Sprite colony_base;


private:


    int nb_ants;
    int nb_markers{};
    sf::Color color;
    sf::Font font;


};


#endif //ANTS_FIGHT_CLUB_WORLD_H