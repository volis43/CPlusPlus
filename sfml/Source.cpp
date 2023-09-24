#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Hope C++!");
    
    sf::Texture Pictere;
    Pictere.loadFromFile("G:\\18_fuJZ.jpg");
    sf::Sprite sprite1(Pictere);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(sprite1);
        window.display();
    }

    return 0;
}