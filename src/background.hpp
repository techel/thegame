#pragma once

#include <sfml/Graphics/RectangleShape.hpp>
#include <sfml/Graphics/RenderTarget.hpp>

class App;

class Background
{
public:
    Background(App &app);

    void render(sf::RenderTarget &target) const;

    //between 0 (bottom) and 1 (top)
    void setScroll(float amount);

private:
    App *MyApp;
    
    sf::RectangleShape Shape;
    sf::View View;
};