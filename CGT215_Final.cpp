#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main() {
 
    // COLLECT DAY SKY COLOR
    RenderWindow daySkyInput(VideoMode(400, 200), "pick a daytime sky color");

    // RGB values for the day sky color
    Uint8 dayRed = 255;
    Uint8 dayGreen = 255;
    Uint8 dayBlue = 255;

    // Text to instruct the user
    Font font;
    font.loadFromFile("Valoon.ttf");

    Text dayInstructionText("Pick Daytime Sky Color:", font, 20);
    dayInstructionText.setPosition(10, 10);

    Text daycolorText("", font, 20);
    daycolorText.setPosition(10, 50);

    // Sliders for selecting RGB values
    RectangleShape dayRedSlider(Vector2f(255, 20));
    dayRedSlider.setFillColor(Color::Red);
    dayRedSlider.setPosition(10, 100);

    RectangleShape dayGreenSlider(Vector2f(255, 20));
    dayGreenSlider.setFillColor(Color::Green);
    dayGreenSlider.setPosition(10, 130);

    RectangleShape dayBlueSlider(Vector2f(255, 20));
    dayBlueSlider.setFillColor(Color::Blue);
    dayBlueSlider.setPosition(10, 160);

    // Actual collection of data loop
    while (daySkyInput.isOpen()) {
        Event event;
        while (daySkyInput.pollEvent(event)) {
            if (event.type == Event::Closed) {
                daySkyInput.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                // Check if the user clicked on one of the sliders
                Vector2f mousePos = daySkyInput.mapPixelToCoords(Mouse::getPosition(daySkyInput));

                if (dayRedSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the red component based on the slider position
                    dayRed = static_cast<Uint8>(mousePos.x - dayRedSlider.getPosition().x);
                }
                else if (dayGreenSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the green component based on the slider position
                    dayGreen = static_cast<Uint8>(mousePos.x - dayGreenSlider.getPosition().x);
                }
                else if (dayBlueSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the blue component based on the slider position
                    dayBlue = static_cast<Uint8>(mousePos.x - dayBlueSlider.getPosition().x);
                }

                // Display the selected color
                daycolorText.setString("Selected Color: " + to_string(dayRed) + ", " + to_string(dayGreen) + ", " + to_string(dayBlue));
                Color textColor(dayRed, dayGreen, dayBlue);
                daycolorText.setFillColor(textColor);
            }
        }

        daySkyInput.clear();

        // Draw sliders and text
        daySkyInput.draw(dayInstructionText);
        daySkyInput.draw(daycolorText);
        daySkyInput.draw(dayRedSlider);
        daySkyInput.draw(dayGreenSlider);
        daySkyInput.draw(dayBlueSlider);

        daySkyInput.display();
    }

    // Close the input window after user provides input
    daySkyInput.close();

    // COLLECT NIGHT SKY COLOR
    RenderWindow nightSkyInput(VideoMode(400, 200), "pick a nighttime sky color");

    // RGB values for the background color
    Uint8 nightRed = 255;
    Uint8 nightGreen = 255;
    Uint8 nightBlue = 255;

    //Text to instruct the user
    Text nightInstructionText("Pick Nighttime Sky Color:", font, 20);
    nightInstructionText.setPosition(10, 10);

    Text nightcolorText("", font, 20);
    nightcolorText.setPosition(10, 50);

    // Sliders for selecting RGB values
    RectangleShape nightRedSlider(Vector2f(255, 20));
    nightRedSlider.setFillColor(Color::Red);
    nightRedSlider.setPosition(10, 100);

    RectangleShape nightGreenSlider(Vector2f(255, 20));
    nightGreenSlider.setFillColor(Color::Green);
    nightGreenSlider.setPosition(10, 130);

    RectangleShape nightBlueSlider(Vector2f(255, 20));
    nightBlueSlider.setFillColor(Color::Blue);
    nightBlueSlider.setPosition(10, 160);

    // Actual data collection loop
    while (nightSkyInput.isOpen()) {
        Event event;
        while (nightSkyInput.pollEvent(event)) {
            if (event.type == Event::Closed) {
                nightSkyInput.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                // Check if the user clicked on one of the sliders
                Vector2f mousePos = nightSkyInput.mapPixelToCoords(Mouse::getPosition(nightSkyInput));

                if (nightRedSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the red component based on the slider position
                    nightRed = static_cast<Uint8>(mousePos.x - nightRedSlider.getPosition().x);
                }
                else if (nightGreenSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the green component based on the slider position
                    nightGreen = static_cast<Uint8>(mousePos.x - nightGreenSlider.getPosition().x);
                }
                else if (nightBlueSlider.getGlobalBounds().contains(mousePos)) {
                    // Update the blue component based on the slider position
                    nightBlue = static_cast<Uint8>(mousePos.x - nightBlueSlider.getPosition().x);
                }

                // Display the selected color AND SET "nightColor"
                nightcolorText.setString("Selected Color: " + to_string(nightRed) + ", " + to_string(nightGreen) + ", " + to_string(nightBlue));
                Color nightColor(nightRed, nightGreen, nightBlue);
                nightcolorText.setFillColor(nightColor);
            }
        }
        nightSkyInput.clear();

        // Draw sliders and text
        nightSkyInput.draw(nightInstructionText);
        nightSkyInput.draw(nightcolorText);
        nightSkyInput.draw(nightRedSlider);
        nightSkyInput.draw(nightGreenSlider);
        nightSkyInput.draw(nightBlueSlider);

        nightSkyInput.display();
    }

    // Close the input window after user provides input
    nightSkyInput.close();


    // WINDOW TO PICK BETWEEN SUNRISE AND SUNSET
    RenderWindow window(VideoMode(400, 200), "Sunrise or Sunset");

    // Create button shapes
    RectangleShape button1(Vector2f(150, 50));
    RectangleShape button2(Vector2f(150, 50));

    // Set button positions
    button1.setPosition(10, 75);
    button2.setPosition(240, 75);

    // Set button colors
    Color dayColor(dayRed, dayGreen, dayBlue);
    Color nightColor(nightRed, nightGreen, nightBlue);

    button1.setFillColor(dayColor);
    button2.setFillColor(nightColor);

    // Create button labels
   Text label1("Sunrise", font, 20);
    Text label2("Sunset", font, 20);

    // Set label positions
    label1.setPosition(30, 90);
    label2.setPosition(270, 90);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                // Check if the mouse is over a button when clicked
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

                if (button1.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Button 1 clicked!" << std::endl;
                }
                else if (button2.getGlobalBounds().contains(mousePos)) {
                    std::cout << "Button 2 clicked!" << std::endl;
                }
            }
        }

        window.clear();

        // Draw buttons and labels
        window.draw(button1);
        window.draw(button2);
        window.draw(label1);
        window.draw(label2);

        window.display();
    }

    //ANIMATION
    // Create a window for the animation
    RenderWindow animationWindow(VideoMode(800, 600), "SFML Animation");

    // Main loop for the animation
    while (animationWindow.isOpen()) {
        Event event;
        while (animationWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                animationWindow.close();
            }
        }

        // Update the background color based on user input
        Color backgroundColor(dayRed, dayGreen, dayBlue);
        animationWindow.clear(backgroundColor);

        // Draw your animation or graphics here

        animationWindow.display();
    }

    return 0;
}
//I JUST NEED TO PUSH THIS