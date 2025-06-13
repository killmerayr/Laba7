#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>


void drawCantor(sf::RenderWindow& window, float x, float y, float length, int depth){
    if (depth == 0 || length < 2.f) return;

    sf::VertexArray line(sf::PrimitiveType::Lines, 2);
    line[0].position = {x, y};
    line[0].color = sf::Color::Black;
    line[1].position = {x + length, y};
    line[1].color = sf::Color::Black;
    window.draw(line);

    float newY = y + 20.f;

    drawCantor(window, x, newY, length / 3.f, depth - 1);

    drawCantor(window, x + 2 * length / 3.f, newY, length / 3.f, depth - 1);
}

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Fractal");

    while (window.isOpen()) {

        // Инициализируем окно
        std::optional<sf::Event> eventOpt;
        while ((eventOpt = window.pollEvent())) {
            const sf::Event& event = *eventOpt;

            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // Рисуем фрактал
        drawCantor(window, 50.f, 50.f, 700.f, 7);

        window.display();
    }

    return 0;
}


