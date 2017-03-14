#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Game.hpp"

#include "Player.hpp"
#include <vector>
#include "PlayerMove.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "Fight or Flight");
	
	sf::Texture movetabletexture;
	if (!movetabletexture.loadFromFile("MoveTable.png", sf::IntRect(0, 0, 120, 120)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture movetablecleartexture;
	if (!movetablecleartexture.loadFromFile("MoveTableClear.png", sf::IntRect(0, 0, 120, 120)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture movetotexture;
	if (!movetotexture.loadFromFile("moveto.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture loadtexture;
	if (!loadtexture.loadFromFile("Load.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture shieldtexture;
	if (!shieldtexture.loadFromFile("Shield.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture movetexture;
	if (!movetexture.loadFromFile("Move.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture shoottexture;
	if (!shoottexture.loadFromFile("Shoot.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}

	sf::Texture tiletexture;
	if (!tiletexture.loadFromFile("purple.jpeg", sf::IntRect(0, 0, 25, 25)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture chartexture;
	if (!chartexture.loadFromFile("char.png", sf::IntRect(0, 0, 25, 25)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture starttexture;
	if (!starttexture.loadFromFile("NewGame.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	sf::Texture diedtexture;
	if (!diedtexture.loadFromFile("Died.png", sf::IntRect(0, 0, 120, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	//////////////////////////////////////////////////////
	sf::Texture bullet0texture;
	if (!bullet0texture.loadFromFile("bullet0.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet1texture;
	if (!bullet1texture.loadFromFile("bullet1.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet2texture;
	if (!bullet2texture.loadFromFile("bullet2.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet3texture;
	if (!bullet3texture.loadFromFile("bullet3.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet4texture;
	if (!bullet4texture.loadFromFile("bullet4.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet5texture;
	if (!bullet5texture.loadFromFile("bullet5.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet6texture;
	if (!bullet6texture.loadFromFile("bullet6.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet7texture;
	if (!bullet7texture.loadFromFile("bullet7.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet8texture;
	if (!bullet8texture.loadFromFile("bullet8.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	
	sf::Texture bullet9texture;
	if (!bullet9texture.loadFromFile("bullet9.png", sf::IntRect(0, 0, 80, 50)))
		{
		std::cout << "Error: image not found" << std::endl;
		}
	

	sf::Sprite loadButton;
	loadButton.setTexture(loadtexture);
	loadButton.move(10, 5);

	sf::Sprite shootButton;
	shootButton.setTexture(shoottexture);
	shootButton.move(10, 60);

	sf::Sprite shieldButton;
	shieldButton.setTexture(shieldtexture);
	shieldButton.move(10, 115);
	
	sf::Sprite moveButton;
	moveButton.setTexture(movetexture);
	moveButton.move(10, 175);

	sf::Sprite start;
	start.setTexture(starttexture);
	start.move(335, 5);

	sf::Sprite died;
	died.setTexture(diedtexture);
	died.move(650, 5);

	sf::Sprite bullet;
	bullet.setTexture(bullet0texture);
	bullet.move(5, 400);

	sf::Sprite movetable;
	//movetable.setTexture();
	movetable.move(5, 250);

	// sf::Sprite plasma;
	// plasma.setTexture(plasma0texture);
	// plasma.move(5, 400);




	// *****board ********
	 
	sf::Sprite map[15][15];
	for(int i = 0; i < 15; i++){   
	    for(int j = 0; j < 15; j++){ 
	    	map[i][j].setTexture(tiletexture); 
	        map[i][j].move(sf::Vector2f(200+(i*26), 60+(j*26)));
	    }  
	} 
	//Important board info, leave alone
	sf::Texture bullets[10];
	bullets[0]=bullet0texture;
	bullets[1]=bullet1texture;
	bullets[2]=bullet2texture;
	bullets[3]=bullet3texture;
	bullets[4]=bullet4texture;
	bullets[5]=bullet5texture;
	bullets[6]=bullet6texture;
	bullets[7]=bullet7texture;
	bullets[8]=bullet8texture;
	bullets[9]=bullet9texture;
	int numBullets=0;
	bool canmove=false;
	bool canshoot=false;
	bool shootplasma=false;
	bool shootbullet=false;
	
	//actual window interactions
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			// *****board logic below**********

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					

					//clear board and redraw all remaining characters
					for(int i = 0; i < 15; i++){   
				    for(int j = 0; j < 15; j++){ 
				    	map[i][j].setTexture(tiletexture); 
				    }
				    //TODO redraw characters
				    std::vector<Player>* players=game.getPlayerList();
 					numberOfPlayers=players.size();
 					for(int i=0; i<numberOfPlayers; i++){
 						thePlayer=players[i];
 						//for each player we need coordinates
 						//x=thePlayer.getx();
 						//y=thePlayer.gety();
 						//map(x,y).settexture(playerTypeImage);

 					}


				    //clear the move table if present
				    movetable.setTexture(movetablecleartexture);

				}
					//now draw all char on board
				
				    //START NEW GAME
				    if (event.mouseButton.x <= 455 && event.mouseButton.y <= 55 && event.mouseButton.x >= 335 && event.mouseButton.y >= 5) {
	 					map[5][5].setTexture(chartexture);
	 					numBullets=0;
	 					bullet.setTexture(bullets[numBullets]);
	 					canmove=false;

						canshoot=false;
						shootplasma=false;
						shootbullet=false;
	 					Game game;
	 					std::vector<Player> players = *(game.getPlayerList());
	 					numberOfPlayers=players.size();
	 					for(int i=0; i<numberOfPlayers; i++){
	 						thePlayer=players[i];
	 						//for each player we need coordinates
	 						int x=thePlayer.getXPosition();
	 						int y=thePlayer.getYPosition();
	 						//map(x,y).settexture(playerTypeImage);

	 					}


	 					

					//LOAD 
				    } else if (event.mouseButton.x <= 120 && event.mouseButton.y <= 50) {
						//map[10][10].setTexture(chartexture);
						//increase player bullets by 1,
						//call players bullet val to get int for below
						// if (i<9)
						// 	i+=1;
						// else
						// 	i=9;
						//playerMove=HumanPlayer.reload()
						PlayerMove playerMove = new PlayerMove(PlayerMove::RELOAD, PlayerMove::NONE, 0, 0, &players[0]);
						game.playRound(playerMove);
						//bullet.setTexture(bullets[players[0].getAmmo()]);
						//run game simulations
					}
					// //SHOOT PLASMA
					 else if (event.mouseButton.x <= 120 && event.mouseButton.y <= 50) {
					 	//find player x and y first
					 	int x=thePlayer.getXPosition();
	 					int y=thePlayer.getYPosition();
					int xvalues[9]={-1,0,1,-1,1,-1,0,1};
						int yvalues[9]={-1,-1,-1,0,0,1,1,1};
						for(int j=0; j<8; j++){

							map[x+(xvalues[j])][y+(yvalues[j])].setTexture(movetotexture);
						}
						//redraw char here
						movetable.setTexture(movetabletexture);
						shootplasma=true;
					 }


					//SHOOT BULLET
					 else if (event.mouseButton.x <= 120 && event.mouseButton.y <= 50) {
					 	//find player x and y first
					int x=thePlayer.getXPosition();
	 					int y=thePlayer.getYPosition();
					int xvalues[9]={-1,0,1,-1,1,-1,0,1};
						int yvalues[9]={-1,-1,-1,0,0,1,1,1};
						for(int j=0; j<8; j++){

							map[x+(xvalues[j])][y+(yvalues[j])].setTexture(movetotexture);
						}
						//redraw char here
						movetable.setTexture(movetabletexture);
						
						shootbullet=true;
						 }


					// //SHIELD PLASMA
					// else if (event.mouseButton.x <= 120 && event.mouseButton.y <= 50) {
					// int xvalues[9]={-1,0,1,-1,1,-1,0,1};
					// 	int yvalues[9]={-1,-1,-1,0,0,1,1,1};
					// 	for(int j=0; j<8; j++){

					// 		map[xcoord+(xvalues[j])][ycoord+(yvalues[j])].setTexture(movetotexture);
					// 	}
					// 	//run board logic for other char
					//  }

					// //SHIELD BULLET
					//  else if (event.mouseButton.x <= 120 && event.mouseButton.y <= 50) {
					// int xvalues[9]={-1,0,1,-1,1,-1,0,1};
					// 	int yvalues[9]={-1,-1,-1,0,0,1,1,1};
					// 	for(int j=0; j<8; j++){

					// 		map[xcoord+(xvalues[j])][ycoord+(yvalues[j])].setTexture(movetotexture);
					// 	}
					// 	 }

					//MOVE
					else if (event.mouseButton.y <= 225 && event.mouseButton.x <= 120 && event.mouseButton.y >= 175 && event.mouseButton.x >= 5) {
						//call to get player corrdinates returns x,y
						int xcoord=5;
						int ycoord=6;
						//below code is logic to show avaible moves on board
						//need to find a way to not draw on bad move
						int xvalues[9]={-1,0,1,-1,1,-1,0,1};
						int yvalues[9]={-1,-1,-1,0,0,1,1,1};
						for(int j=0; j<8; j++){

							map[xcoord+(xvalues[j])][ycoord+(yvalues[j])].setTexture(movetotexture);
						}
						//**redraw characters here**

						//logic for move arrows
						movetable.setTexture(movetabletexture);
						canmove=true;

						
					}
					//Left UP
					else if (event.mouseButton.y <=290  && event.mouseButton.x <= 45 && event.mouseButton.y >= 250 && event.mouseButton.x >= 5) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
					}
						}
						//UP
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 85 && event.mouseButton.y >= 250 && event.mouseButton.x >= 45) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
					}
						}
						//Right Up
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 125 && event.mouseButton.y >= 250 && event.mouseButton.x >= 85) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
						}
						//LEFT 
						else if (event.mouseButton.y <=330  && event.mouseButton.x <= 45 && event.mouseButton.y >= 290 && event.mouseButton.x >= 5) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
						}
						//Right
						else if (event.mouseButton.y <=330  && event.mouseButton.x <= 125 && event.mouseButton.y >= 290 && event.mouseButton.x >= 85) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//LEFT Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 45 && event.mouseButton.y >= 330 && event.mouseButton.x >= 5) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 85 && event.mouseButton.y >= 330 && event.mouseButton.x >= 45) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//Right Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 125 && event.mouseButton.y >= 330 && event.mouseButton.x >= 85) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//Left UP
					else if (event.mouseButton.y <=290  && event.mouseButton.x <= 45 && event.mouseButton.y >= 250 && event.mouseButton.x >= 5) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//UP
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 85 && event.mouseButton.y >= 250 && event.mouseButton.x >= 45) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//Right Up
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 125 && event.mouseButton.y >= 250 && event.mouseButton.x >= 85) {
						if (canmove==true){
							map[4][5].setTexture(chartexture);
						
						canmove=false;
						}
				}
						//*****************
						//Shoot logic
						//*****************
						//Left UP
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 45 && event.mouseButton.y >= 250 && event.mouseButton.x >= 5) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
				}
						//UP
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 85 && event.mouseButton.y >= 250 && event.mouseButton.x >= 45) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
				}
						//Right Up
						else if (event.mouseButton.y <=290  && event.mouseButton.x <= 125 && event.mouseButton.y >= 250 && event.mouseButton.x >= 85) {
					
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
						//LEFT 
						else if (event.mouseButton.y <=330  && event.mouseButton.x <= 45 && event.mouseButton.y >= 290 && event.mouseButton.x >= 5) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
						//Right
						else if (event.mouseButton.y <=330  && event.mouseButton.x <= 125 && event.mouseButton.y >= 290 && event.mouseButton.x >= 85) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
						//LEFT Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 45 && event.mouseButton.y >= 330 && event.mouseButton.x >= 5) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
						//Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 85 && event.mouseButton.y >= 330 && event.mouseButton.x >= 45) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
						//Right Down
						else if (event.mouseButton.y <=370  && event.mouseButton.x <= 125 && event.mouseButton.y >= 330 && event.mouseButton.x >= 85) {
						if (canshoot==true){
							if(shootplasma==true){
								shootplasma=false;
							}
							else if(shootbullet==true){
								shootbullet=false;
							}

							
						canshoot=false;
					}
						}
				}
				break;

			default:
				break;
			}
		}
		
		window.clear();

		//**right column*
		window.draw(movetable);
		window.draw(bullet);
		//window.draw(died);
		window.draw(start);
		window.draw(shootButton);
		window.draw(loadButton);
		window.draw(shieldButton);
		window.draw(moveButton);

		
		//**board**
		for(int i = 0; i < 15; i++){   
	    for(int j = 0; j < 15; j++){  
	       window.draw(map[i][j]);
	       	    }  
	}
		
		window.display();
	}
	
	return 0;
}
