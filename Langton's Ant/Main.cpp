#include "Main.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), SCREEN_TITLE);



    array<array<sf::Color, MAP_HEIGHT>, MAP_WIDTH> buffer;

    std::vector<Ant> ants;

    for (int x = 0; x < MAP_WIDTH; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            buffer[x][y] = sf::Color::Black;
        }
    }

    for (int n = 0; n < NUM_ANTS; n++)
    {
        int rx = rand() % MAP_WIDTH;
        int ry = rand() % MAP_HEIGHT;
        Ant ant;
        ant.setLocation(rx, ry);
        ants.push_back(ant);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // draw world state
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            for (int y = 0; y < MAP_HEIGHT; y++)
            {
                sf::RectangleShape pixel(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                pixel.setPosition(sf::Vector2f(x * CELL_SIZE, y * CELL_SIZE));
                pixel.setFillColor(buffer[x][y]);
                window.draw(pixel);
            }
        }

        window.display();

        // update world state
        for (auto& ant : ants)
        {
            ant.update(buffer);
        }
    }

    return 0;
}