
#include "square.h"
#include "solution.h"


square1 square[8][8];
bool help = false;
void initSquare1(square1& square, float posx, float posy, bool piece, int pieceNumber){
    square.posx = posx;
    square.posy=posy;
    square.rec = sf::RectangleShape(sf::Vector2f(75.f, 75.f));
    //square.rec.setOutlineColor(sf::Color::White);
    square.outlineColor=sf::Color::White;
    square.rec.setOutlineThickness(5.f);
    square.rec.setPosition(posx, posy);
    square.hasPiece = piece;
    square.pieceNumber=pieceNumber;
    //square.pieceColor=pieceColor;
}

void updateSquareColor(square1& csquare, sf::Color color){
    csquare.outlineColor=color;
    csquare.rec.setOutlineColor(color);

}

sf::Color getcolor(square1& csquare){
    return csquare.outlineColor;
}

bool isSquareAvailable(square1 square){
    if(getcolor(square)==sf::Color::White)
        return true;

    return false;
}



void checkSquare(square1& square, sf::Color color, int o, int p){
    int colorCount=0;
    bool isNeighbor=false;
    bool blackFlag = false;
    bool whiteFlag=false;
    bool brownFlag = false;
    bool grayFlag = false;
    if(getcolor(::square[o-1][p])==color || getcolor(::square[o][p-1])==color || getcolor(::square[o+1][p])==color || getcolor(::square[o][p+1])==color)
                    isNeighbor=true;
    if(isSquareAvailable(square)){
            for(int i=0; i<size; i++){ //looping trough tiles to see the number of squares with a specific color
                for(int j=0; j<size; j++){
                    if(getcolor(::square[i][j])==color){
                        colorCount++;
                        if(::square[i][j].hasPiece)
                            if(::square[i][j].pieceNumber >= (-1 * size))
                                blackFlag=true;
                            else if(::square[i][j].pieceNumber >= (-2 * size))
                                whiteFlag=true; // white pieces
                            else if(::square[i][j].pieceNumber >= (-3 * size))
                                brownFlag=true; // brown pieces
                            else if(::square[i][j].pieceNumber >= (-4 * size))
                                grayFlag = true;
                    }
                }
            }


            if(colorCount<size && (square.hasPiece || isNeighbor)){
               if(square.hasPiece && !isNeighbor && colorCount !=0)
                    return;
                if((square.pieceColor==1 && blackFlag) || (square.pieceColor==2 && whiteFlag) || (square.pieceColor==3 && brownFlag) || (square.pieceColor==4 && grayFlag)){
                       // cout << "PieceColor :    " << square.pieceColor <<endl;
                    return;
                }
               updateSquareColor(square, color);

            } else
            {
            std::cout << "colorCount: " <<"  "<<colorCount << std::endl;;
            std::cout << "PieceColor :    " << square.pieceColor <<std::endl;
            return;
            }

    }else if(getcolor(square) == color)
        updateSquareColor(square, sf::Color::White); //undo square color
}

void initTable(){
    float posx=10, posy=10;
    bool bulina;
    int pieceNumber;
    int pieceColor=0;
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if(board_buline[i][j] < 0){
                bulina= true;
                std::cout << bulina << "  " << board_buline[i][j]; //debug

                if(board_buline[i][j] >= (-1 * size))
                    square[i][j].pieceColor=1;
                else if(board_buline[i][j] >= (-2 * size))
                    square[i][j].pieceColor=2; // white pieces
                else if(board_buline[i][j] >= (-3 * size))
                    square[i][j].pieceColor=3; // brown pieces
                else if(board_buline[i][j] >= (-4 * size))
                    square[i][j].pieceColor=4;
            }
            else
                square[i][j].pieceColor=0;

            pieceNumber=board_buline[i][j];

            initSquare1(square[i][j], posx, posy, bulina, pieceNumber);
            bulina = false;
            posx = posx + 86;

        }

        posx = 10;
        posy = posy + 86;

    }
}

void drawTable(sf::RenderWindow& target){
    sf::CircleShape shape(30, 30);
    // define a 120x50 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

// change the size to 100x100
    rectangle.setSize(sf::Vector2f(700.f, 700.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(0.0, 0.0);
    target.draw(rectangle);

    for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    target.draw(square[i][j].rec);
                    if(square[i][j].hasPiece){
                            if(square[i][j].pieceNumber >= (-1 * size)){
                                shape.setFillColor(sf::Color::Black);

                            }
                            else if(square[i][j].pieceNumber >= (-2 * size)){
                                shape.setFillColor(sf::Color(204,0,153)); // white pieces

                            }
                            else if(square[i][j].pieceNumber >= (-3 * size)){
                                shape.setFillColor(sf::Color(230, 0, 0)); // brown pieces

                            }
                            else if(square[i][j].pieceNumber >= (-4 * size)){
                                shape.setFillColor(sf::Color(153, 153, 132)); // gray pieces

                            }



                        shape.setPosition(square[i][j].posx+6, square[i][j].posy+7);
                        target.draw(shape);

                    }

                }
            }
}

void runGame(sf::RenderWindow & window, GameDificulty dificulty) {
 ///// TIMER
 help=false;
    sf::Clock clock;

    sf::Time time;
    sf::Text timp, loadingText;

    sf::Font font;
    font.loadFromFile("dibble.TTF");

        timp.setFont(font);
        timp.setCharacterSize(40);
        timp.setColor(sf::Color(239, 207, 0));
        timp.setPosition(780.f, 10.f);

        loadingText.setFont(font);
        loadingText.setString("Loading...");
        loadingText.setCharacterSize(80);
        loadingText.setColor(sf::Color(239, 207, 0));
        loadingText.setPosition(270.f, 270.f);

   //BACKGROUND image processing
    sf::Texture background;
    sf::Sprite backgroundImage;

    background.loadFromFile("res/img/runbackground.jpg");
    backgroundImage.setTexture(background);


    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //Draw Game window!
    sf::RenderWindow gameWindow(sf::VideoMode(1000, 695), "Impartirea Careului", sf::Style::Titlebar | sf::Style::Close , settings);
    gameWindow.setFramerateLimit(30);

    //Showing Loading Screen
        gameWindow.clear();
        gameWindow.draw(backgroundImage);
        gameWindow.draw(loadingText);
        gameWindow.display();


    //Loading paint sound
    sf::SoundBuffer buffer;
    buffer.loadFromFile("res/bgm/waterblurp.wav");

    sf::Sound paintSound;
    paintSound.setBuffer(buffer);

    sf::Color color(sf::Color::White);


    //Loading Blue Bucket
    Button blueBucket;
    setButton(blueBucket, "res/img/bluebucket.png", sf::IntRect(30, 100, 240, 60), 900.f, 30.f);

    //Loading Red Button
    Button redBucket;
    setButton(redBucket, "res/img/redbucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 110.f);

    //Loading Scarlet Button
    Button scarletBucket;
    setButton(scarletBucket, "res/img/scarletbucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 190.f);

    //Loading Green Button
    Button greenBucket;
    setButton(greenBucket, "res/img/greenbucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 270.f);

    //Loading Pink Button
    Button pinkBucket;
    setButton(pinkBucket, "res/img/pinkbucket.png", sf::IntRect(255, 102, 178, 60), 900.f, 350.f);

    //Loading Brown Button
    Button brownBucket;
    setButton(brownBucket, "res/img/brownbucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 430.f);

    //Loading Yellow Button
    Button yellowBucket;
    setButton(yellowBucket, "res/img/yellowbucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 510.f);

    //Loading Gray Button
    Button grayBucket;
    setButton(grayBucket, "res/img/graybucket.png", sf::IntRect(30, 180, 240, 60), 900.f, 590.f);

    //Loading Gray Button
    Button helpButton;
    setButton(helpButton, "res/img/helpbutton.png", sf::IntRect(30, 180, 240, 60), 720.f, 60.f);

    Button doneButton;
    setButton(doneButton, "res/img/donebutton.png", sf::IntRect(30, 180, 240, 60), 710.f,620.f);



    switch (dificulty) {
    case Easy:
        generare_grupa1();
        break;
    case Medium:
        generare_grupa1();
        generare_grupa2();
        break;
    case Hard:
        generare_grupa1();
        generare_grupa2();
        generare_grupa4();
        break;

    }

    //Getting squares ready to be drawn
    initTable();


    while (gameWindow.isOpen()) {
        time=clock.getElapsedTime();
        std::string s = std::to_string((int)time.asSeconds());
        timp.setString(s);

        sf::Event event;


        while (gameWindow.pollEvent(event)) {

            //get mouse coordinates
            float Mx = sf::Mouse::getPosition(gameWindow).x;
            float My = sf::Mouse::getPosition(gameWindow).y;

            if (event.type == sf::Event::Closed) {
                clock.restart();
                gameWindow.close();
                window.setVisible(true);

            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    if (blueBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(0, 0, 255);
                        paintSound.play();

                        std::cout << color.toInteger() << std::endl;
                    }
                    if (redBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(255, 0, 0);
                        paintSound.play();
                    }
                    if (scarletBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(153, 0, 76);
                        paintSound.play();
                    }
                    if (greenBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(0, 255, 0);
                        paintSound.play();
                    }
                    if (pinkBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(255, 102, 255);
                        paintSound.play();
                    }
                    if (brownBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(102, 51, 0);
                        paintSound.play();

                    }
                    if (yellowBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(255, 255, 0);
                        paintSound.play();
                    }
                    if (grayBucket.sprite.getGlobalBounds().contains(Mx, My)) {
                        color = sf::Color(192, 192, 192);
                        paintSound.play();
                    }
                    if (helpButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        giveSolution();
                    }
                    if (doneButton.sprite.getGlobalBounds().contains(Mx, My)) {
                        showWinOrLose(gameWindow, s);
                        if(checkSolution())
                            window.setVisible(true);
                    }

                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            if (square[i][j].rec.getGlobalBounds().contains(Mx, My)){
                                    checkSquare(square[i][j], color, i, j);
                                }
                        }

                            }

                        }
                    }

                }

                ///


            gameWindow.clear(sf::Color(0, 196, 255));
            gameWindow.draw(backgroundImage);
            // #### Table Drawing####


            drawTable(gameWindow);



                gameWindow.draw(blueBucket.sprite);
                gameWindow.draw(redBucket.sprite);
                gameWindow.draw(scarletBucket.sprite);
                gameWindow.draw(greenBucket.sprite);
                gameWindow.draw(pinkBucket.sprite);
                gameWindow.draw(brownBucket.sprite);
                gameWindow.draw(yellowBucket.sprite);
                gameWindow.draw(grayBucket.sprite);
                gameWindow.draw(helpButton.sprite);
                gameWindow.draw(doneButton.sprite);


                gameWindow.draw(timp);
                gameWindow.display();

    }
}


