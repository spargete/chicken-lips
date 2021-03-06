#include "Game.hpp"
#include <vector>

Game::Game() : size(15) {
	board = (Point **) malloc (size * sizeof(Point *));
	for (int i = 0; i < size; i++) {
		board[i] = (Point *) malloc(size * sizeof(Point));
		for (int j = 0; j < size; j++) {
			board[i][j] = Point(i, j);
		}
	}

	srand(time(NULL)); // random seed for the randomizer
	int x = rand() % size;
	int y = rand() % size;
	playerList.push_back(new HumanPlayer(x, y)); // human player at random coords

	for (int i = 1; i < 5; i++) { // randomize placement of four other players
		bool done = false;
		bool changed = false;
		do {
			x = rand() % size;
			y = rand() % size;
			for (int j = 0; j < playerList.size(); j++) {
				if (x == playerList[j]->getXPosition() && y == playerList[j]->getYPosition()) {
					changed = true;
				}
			}
			done = !changed;
		} while (!done);
		switch(i % 2) {
			case 0:
				playerList.push_back(new AlienPlayer(x, y));
				break;
			case 1:
				playerList.push_back(new CowboyPlayer(x, y));
				break;
		}
	}
}

Game::~Game() {
	for (int i = 0; i < size; i++) {
		free(board[i]);
	}
	free(board);
}

int Game::getSize() {
	return this->size;
}

std::vector<Player *>* Game::getPlayerList() {
	return &(this->playerList);
}

bool Game::playRound(PlayerMove humanPlayerMove) {
	//loop through player list, calling playMove() on each one
	std::vector<PlayerMove> playerMoves;
	int numPlayers = playerList.size();
	playerList[0]->playMove(humanPlayerMove, &board, size, 0);
	playerMoves.push_back(humanPlayerMove);
	for (int i = 1; i < numPlayers; i++) {
		playerMoves.push_back(playerList[i]->playMove(humanPlayerMove, &board, size, i));
	}
	//shove results into a vector of PlayerMoves
	//loop through this vector and do the specified move to the player, moving players before shooting
	int numMoves = playerMoves.size();
	for (int i = 0; i < numMoves; i++) {
		switch (playerMoves[i].getPlayerMove())  {
			case PlayerMove::SHOOT:
				break;

			case PlayerMove::MOVE:
				playerList[playerMoves[i].getMovingPlayer()]->move(&playerList, size);
				break;

			case PlayerMove::SHIELD:
				playerList[playerMoves[i].getMovingPlayer()]->shield(playerMoves[i].getBulletOrShieldType());
				break;

			case PlayerMove::RELOAD:
				playerList[playerMoves[i].getMovingPlayer()]->reload();
				break;
		}
	}
	//(loop through twice to handle this)
	for (int i = 0; i < numMoves; i++) {
		switch (playerMoves[i].getPlayerMove())  {
			case PlayerMove::SHOOT:
				playerList[playerMoves[i].getMovingPlayer()]->shoot(playerMoves[i].getXOffset(), playerMoves[i].getYOffset(), playerMoves[i].getBulletOrShieldType(), &playerList, size);
				break;
			default: break;
		}
	}
	//marks handled in the player functions
	//kill all players marked for death
	if (playerList[0]->getMarkedForDeath()) {
		return true;
	}

	auto current_position = playerList.begin();
	while (current_position != playerList.end()) {
		if ((*current_position)->getMarkedForDeath()) {
			std::vector<Player*>::iterator new_position = playerList.erase(current_position);
			current_position = new_position;
		} else {
			current_position++;
		}
	}
	//reset shieldType, movingTo at the end

	numPlayers = playerList.size();
	for (int i = 0; i < numPlayers; i++) {
		playerList[i]->resetShieldType();
		playerList[i]->resetMovingTo(&board);
	}
	//if the human player is marked for death, somehow let the main function know. return a value: true if human player died, false if they didn't
	return false;
}

Point* Game::getPoint(int x, int y) {
	return &(board[x][y]);
}
