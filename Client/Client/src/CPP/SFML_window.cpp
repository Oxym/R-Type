#include "SFML_window.hpp"
//#include "client.hpp"

SFML_win::SFML_win()
{
//	sf::RenderWindow window(sf::VideoMode(this->WindowsX, this->WindowsY), "R-Type");
	std::cout << "JE MARCHE" << std::endl;
}

SFML_win::~SFML_win()
{
}

int		SFML_win::get_win_x()
{
	return (this->WindowsX);
}

int		SFML_win::get_win_y()
{
	return (this->WindowsY);
}

/*void SFML_win::set_win_x()
{
	this->win_x = this->get_win_x();
}

void SFML_win::set_win_y()
{
	this->win_y = this->get_win_y();
}

/*int SFML_test()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
	
    return 0;
}*/