//
// Created by g0bel1n on 09/12/2021.
//

#include <iostream>
#include "Renderer.h"
#define PI 3.14159265

void Renderer::update(World& world) {

    int delta = markers_graphic.size() - world.markers.size();

    if (delta > 0) {

        std::cout << "\n" << "erased in markers graphic" << "\n";

        markers_graphic.erase(markers_graphic.begin() + world.get_nb_food(),
                              markers_graphic.begin() + world.get_nb_food() + delta);
    } else {
        for (int i = 0; i < -delta; i++) {
            sf::CircleShape graph_marker = sf::CircleShape(world.markers[0].radius);
            if (world.markers[world.markers.size() + delta + i].marker_type == 3) {
                graph_marker.setFillColor(sf::Color::Blue);
            } else { graph_marker.setFillColor(sf::Color::Green); }
            graph_marker.setPosition(world.markers[world.markers.size() + delta + i].position);
            markers_graphic.push_back(graph_marker);
        }}


        for (int i = 0; i < world.get_nb_food(); i++) {
            if (world.markers[i].marker_type == -1) {
                markers_graphic[i].setFillColor(sf::Color(104, 157, 113));
            }
            if (world.markers[i].marker_type == 2) {
                markers_graphic[i].setFillColor(sf::Color::Yellow);
            }
            if (world.markers[i].marker_type == 1) {
                markers_graphic[i].setFillColor(sf::Color::Red);
            }
            markers_graphic[i].setPosition(world.markers[i].position);
        }
        for (int i = world.get_nb_food(); i < markers_graphic.size(); i++) {

            markers_graphic[i].setRadius(world.markers[i].get_intensity() / 3.);

        }

        for (int i = 0; i < world.get_nb_ants(); i++) {
            ants_graphics[i].setPosition(world.ants[i].get_position());
            ants_graphics[i].setRotation(world.ants[i].get_angle() * 180 / PI);

            if (world.ants[i].switchSkin && world.ants[i].have_food) {
                texture_with_food.loadFromFile("../ressources/ant_with_food.png");

                ants_graphics[i].setTexture(texture_with_food);
                world.ants[i].switchSkin = false;
            } else if (world.ants[i].switchSkin && !world.ants[i].have_food) {
                texture.loadFromFile("../ressources/ant.png");

                ants_graphics[i].setTexture(texture);
                world.ants[i].switchSkin = false;
            }
        }
    }
Renderer::Renderer(World& world) {


    texture.loadFromFile("../ressources/ant.png");

    for (int i = 0; i < world.get_nb_food(); i++) {
        sf::CircleShape graph_marker = sf::CircleShape(world.markers[0].radius);
        graph_marker.setFillColor(sf::Color(231, 62, 1));
        graph_marker.setPosition(world.markers[i].position);
        markers_graphic.push_back(graph_marker);
    }


    for (int i = 0; i < world.get_nb_ants(); i++) {
        sf::Sprite ant_graphics = sf::Sprite();
        ant_graphics.setColor(sf::Color::White);
        ant_graphics.setOrigin(300.,300.f);
        ant_graphics.setTexture(texture);
        ant_graphics.setScale(0.05f, 0.05f);
        ants_graphics.push_back(ant_graphics);
    }

}