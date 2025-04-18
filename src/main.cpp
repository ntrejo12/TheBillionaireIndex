#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    std::cout << "Hello, World!" << std::endl;
    //load window
    sf::RenderWindow window(sf::VideoMode((800), (612)), "The Billionaire Index");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}
