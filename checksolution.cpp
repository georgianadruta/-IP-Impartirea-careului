#include "checksolution.h"



void giveSolution(){
    help=true;
    for(int i = 0; i <size; i++){
        for(int j=0; j< size; j++){
            switch(board_zone[i][j]){
            case 1:
                updateSquareColor(square[i][j], sf::Color::Blue);
                break;
            case 2:
                updateSquareColor(square[i][j], sf::Color::Red);
                break;
            case 3:
                updateSquareColor(square[i][j], sf::Color(153, 0, 76)); // Scarlet
                break;
            case 4:
                updateSquareColor(square[i][j], sf::Color(0, 255, 0)); // Green
                break;
            case 5:
                updateSquareColor(square[i][j], sf::Color(255, 102, 255)); // Pink
                break;
            case 6:
                updateSquareColor(square[i][j], sf::Color(102, 51, 0)); // Brown
                break;
            case 7:
                updateSquareColor(square[i][j], sf::Color(255, 255, 0)); // Yellow
                break;
            case 8:
                updateSquareColor(square[i][j], sf::Color(192, 192, 192)); // Gray
                break;

            }
        }
    }
}


bool checkSolution(){
    for(int i =0 ;i<size; i++){
        for(int j=0; j< size; j++)
            if(getcolor(square[i][j]) == sf::Color::White)
                return false;
    }
    return true;
}

void showWinOrLose(sf::RenderWindow &window, std::string secunde){
    sf::RenderWindow stateWindow(sf::VideoMode(500, 250), "Impartirea Careului", sf::Style::None);
    //gameWindow.setPosition();
    stateWindow.setFramerateLimit(30);

    sf::Text loseMessage, winMessage, helpMessage;

    sf::Font font;
    font.loadFromFile("Commodore PET.TTF");

        loseMessage.setFont(font);
        loseMessage.setCharacterSize(18);
        loseMessage.setColor(sf::Color(239, 207, 0));
        loseMessage.setPosition(sf::Vector2f(45.f, 65.f));
        loseMessage.setString("Tabelul nu este corect! \n     Mai incearca! \n Apasa Escape pentru \n      a corecta!");

        winMessage.setFont(font);
        winMessage.setCharacterSize(18);
        winMessage.setColor(sf::Color(239, 207, 0));
        winMessage.setPosition(sf::Vector2f(55.f, 65.f));
        winMessage.setString("  Avem un castigator!\nAi terminat jocul in \n    " + secunde + "secunde!\n     Felicitari!");

        helpMessage.setFont(font);
        helpMessage.setCharacterSize(18);
        helpMessage.setColor(sf::Color(239, 207, 0));
        helpMessage.setPosition(sf::Vector2f(55.f, 65.f));
        helpMessage.setString("      AI PIERDUT  \n IT WAS NOT YOUR IDEA! ");

    Button backButton;
    setButton(backButton, "res/img/backbutton.png", sf::IntRect(30, 320, 240, 60), 130.f, 160.f);

    //Loading clicking sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/bgm/clicksound.wav");

    sf::Sound clickSound;
    clickSound.setBuffer(buffer);


 //bool isHelped=help;

    while (stateWindow.isOpen()) {

        sf::Event event;

        float Mx = sf::Mouse::getPosition(stateWindow).x;
        float My = sf::Mouse::getPosition(stateWindow).y;

        while (stateWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                stateWindow.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (backButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        Sleep(200);
                        return;
                        std::cout << Mx << "   " << My << std::endl; // debug
                    }
                }
            }else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) //closing game with escape
                    return;
            }
        }

        stateWindow.clear(sf::Color(228,105,178));

        if(help){

            stateWindow.draw(helpMessage);
            window.close();
        }else if(checkSolution() && help==false){
            window.close();
            drawButton(backButton, stateWindow);
            stateWindow.draw(winMessage);
            //cout << "  DEDED:  " << help;

        }
        else{
            stateWindow.draw(loseMessage);
        }

        stateWindow.display();
    }
}
