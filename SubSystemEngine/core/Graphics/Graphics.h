#pragma once
#include <SFML/Graphics.hpp>
#include "Display/Window.h"
#include "../SubSystem.h"

class Graphics : public SubSystem {
public:
    Graphics();
    ~Graphics();

    void initialize() override;
    void update() override;

    void render();
    void clear();
    void display();

    sf::RenderWindow& getWindow();

    void setView(const sf::View& view);
    void resetView();

    void handleResize();

    void addDrawable(sf::Drawable& drawable);
    void removeDrawable(sf::Drawable& drawable);

    void drawText(const sf::Text& text);
    void drawSprite(const sf::Sprite& sprite);
    void drawShape(const sf::Shape& shape);


    void enableDebugDrawing(bool enable);

private:
    sf::RenderWindow window;
    sf::View view;
    std::vector<sf::Drawable*> drawables;
    bool debugDrawingEnabled;
    sf::RectangleShape square;
};
