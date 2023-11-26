#include "Graphics.h"

Graphics::Graphics() {}

Graphics::~Graphics() {}

void Graphics::initialize() {
    // Additional graphics setup can be done here
}

void Graphics::update(Entity& player) {
    Window::getInstance().clear();

    // Update player physics state
    player.update();

    // Draw player
    player.draw(Window::getInstance().getWindow());

    // Draw other entities
    for (const auto& entity : entities) {
        entity.draw(Window::getInstance().getWindow());
    }

    Window::getInstance().display();
}

sf::RenderWindow& Graphics::getWindow() {
    return Window::getInstance().getWindow();
}

void Graphics::handleResize() {
    // Handle resizing-related adjustments if needed
    // For example, update the view to maintain the scale of elements
    sf::Vector2u newSize = Window::getInstance().getWindow().getSize();
    sf::View view = Window::getInstance().getWindow().getView();
    view.setSize(static_cast<float>(newSize.x), static_cast<float>(newSize.y));
    Window::getInstance().getWindow().setView(view);
}