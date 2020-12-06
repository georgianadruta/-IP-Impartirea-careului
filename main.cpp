#include <SFML/Audio.hpp>
#include <vector>
#include "square.h"




void initGameMenu(sf::RenderWindow & window) {
    GameDificulty dificulty;

    sf::Texture background;
    sf::Sprite backgroundImage;

    background.loadFromFile("res/img/background1.jpg");
    backgroundImage.setTexture(background);

    //loading screen
    sf::Texture loading;
    sf::Sprite loadingImage;


    loading.loadFromFile("res/img/loading.png");
    loadingImage.setTexture(loading);

    //Loading Easy Button
    Button easyButton;
    setButton(easyButton, "res/img/easybutton.png", sf::IntRect(30, 100, 240, 60), 30.f, 100.f);

    //Loading Medium Button
    Button mediumButton;
    setButton(mediumButton, "res/img/mediumbutton.png", sf::IntRect(30, 180, 240, 60), 30.f, 190.f);

    //Loading hard Button
    Button hardButton;
    setButton(hardButton, "res/img/hardbutton.png", sf::IntRect(30, 320, 240, 60), 30.f, 280.f);

    //Loading back Button
    Button backButton;
    setButton(backButton, "res/img/backbutton.png", sf::IntRect(30, 320, 240, 60), 30.f, 380.f);

    //Loading clicking sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/bgm/clicksound.wav");

    sf::Sound clickSound;
    clickSound.setBuffer(buffer);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            //get mouse coordinates
            float Mx = sf::Mouse::getPosition(window).x;
            float My = sf::Mouse::getPosition(window).y;

            //std::cout<< Mx << "   " << My << std::endl;

            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) //closing game with escape
                    return;
            }
            // #####TO DO : Delete unnecessary pieces of code ######### PS: To many events!!!! //
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (easyButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        dificulty = Easy;
                        window.setVisible(false);
                        runGame(window, dificulty);
                        std::cout << Mx << "   " << My << std::endl; // debug
                    }

                    if (mediumButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        dificulty = Medium;
                        window.setVisible(false);
                        runGame(window, dificulty);
                        std::cout << Mx << "   " << My << std::endl; //debug
                    }

                    if (hardButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        dificulty = Hard;
                        window.setVisible(false);
                        runGame(window, dificulty);
                    }

                    if (backButton.sprite.getGlobalBounds().contains(Mx, My)){
                        clickSound.play();
                        Sleep(200);
                        return;
                    }
                }
            }
        }


        window.clear();
        window.draw(backgroundImage);
        drawButton(easyButton, window);
        drawButton(mediumButton, window);
        drawButton(hardButton, window);
        drawButton(backButton, window);

        window.display();
    }

}

void runInstructions(sf::RenderWindow & window) {
    //string str = "Apasand tasta PLAY GAME, \nse va afisa meniul cu nivele. \nDin acesta se va selecta dificultatea \njocului care consta in numarul \n de buline ce trebuie incadrat in zone de arii egale si continuie. Formarea grupelor se face prin selectarea unei culori din partea dreapta a ferestrei jocului. Dupa selectarea culorii, formarea grupei va incepe de la o bulina. Jocul va lua sfarsit in momentul in care se vor forma grupe cu acelasi numar de buline de culori diferite si de aceeasi dimensiune.";



    sf::Texture background;
    sf::Sprite backgroundImage;


    background.loadFromFile("res/img/instructionsU.jpg");
    backgroundImage.setTexture(background);


    Button backButton;
    setButton(backButton, "res/img/backbutton.png", sf::IntRect(30, 320, 240, 60), 30.f, 400.f);

    //Loading clicking sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/bgm/clicksound.wav");

    sf::Sound clickSound;
    clickSound.setBuffer(buffer);

    while (window.isOpen()) {

        sf::Event event;

        float Mx = sf::Mouse::getPosition(window).x;
        float My = sf::Mouse::getPosition(window).y;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (backButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        Sleep(200);
                        return;
                        std::cout << Mx << "   " << My << std::endl; // debug
                    }
                }
            }
        }

        window.clear();

        window.draw(backgroundImage);
        drawButton(backButton, window);
       // window.draw(instructionsText);

        window.display();
    }
}

int main() {

    sf::RenderWindow mainWindow(sf::VideoMode(300, 500), "Impartirea Careului", sf::Style::Titlebar | sf::Style::Close);
    mainWindow.setPosition(sf::Vector2i(50, 50));
    mainWindow.setFramerateLimit(10);

    mainWindow.clear();
    mainWindow.display();

    sf::Music music;
    music.openFromFile("res/bgm/bgm_action_5.ogg");

    music.setLoop(true);
    music.setVolume(65.0);
    music.play();

    sf::Texture background;
    sf::Sprite backgroundImage;

    system("dir"); //debugging purposes

    background.loadFromFile("res/img/background1.jpg");
    backgroundImage.setTexture(background);

    //Loading Play Button
    Button soundButton;
    setButton(soundButton, "res/img/playedsoundbutton.png", sf::IntRect(30, 100, 240, 60), 20.f, 20.f);

    //Loading Play Button
    Button playGameButton;
    setButton(playGameButton, "res/img/playbutton.png", sf::IntRect(30, 100, 240, 60), 30.f, 100.f);

    //Loading Instruction Button
    Button instructionButton;
    setButton(instructionButton, "res/img/instructions.png", sf::IntRect(30, 180, 240, 60), 30.f, 180.f);

    //Loading Exit Button
    Button exitButton;
    setButton(exitButton, "res/img/exit.png", sf::IntRect(30, 320, 240, 60), 30.f, 320.f);

    //Loading clicking sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/bgm/clicksound.wav");

    sf::Sound clickSound;
    clickSound.setBuffer(buffer);


    while (mainWindow.isOpen()) {
        sf::Event event;
        while (mainWindow.pollEvent(event)) {
            //get mouse coordinates
            float Mx = sf::Mouse::getPosition(mainWindow).x;
            float My = sf::Mouse::getPosition(mainWindow).y;

            //std::cout<< Mx << "   " << My << std::endl;

            if (event.type == sf::Event::Closed)
                mainWindow.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) //closing game with escape
                    mainWindow.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (playGameButton.sprite.getGlobalBounds().contains(Mx, My)) {

                        clickSound.play();
                        initGameMenu(mainWindow);
                        std::cout << Mx << "   " << My << std::endl; // debug
                    }

                    if (instructionButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        //instructionButton.sprite.setColor(sf::Color(255, 255, 255, 128)); // button effect
                        //addHover(instructionButton, mainWindow);
                        clickSound.play();
                        runInstructions(mainWindow);
                        std::cout << Mx << "   " << My << std::endl; //debug
                    }

                    if (exitButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        clickSound.play();
                        Sleep(250);
                        mainWindow.close();
                    }

                    if (soundButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        if(music.getStatus()==sf::Music::Playing){
                            music.pause();
                            setButton(soundButton, "res/img/pausedsoundbutton.png", sf::IntRect(30, 100, 240, 60), 20.f, 20.f);
                        }else{
                            music.play();
                            setButton(soundButton, "res/img/playedsoundbutton.png", sf::IntRect(30, 100, 240, 60), 20.f, 20.f);
                        }
                        clickSound.play();

                    }
                }
            }
        }
        mainWindow.clear();

        mainWindow.draw(backgroundImage);
        //playGameButton.drawButton1(mainWindow);
        drawButton(playGameButton, mainWindow);
        drawButton(instructionButton, mainWindow);
        drawButton(soundButton, mainWindow);

        drawButton(exitButton, mainWindow);
        mainWindow.display();
    }

    return 0;
}
