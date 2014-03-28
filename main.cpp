/*
  TIC TAC TOE

  Created by Jonathan van der Steege (27.03.2014)

  A simple game of 'Tic Tac Toe' to be played by two human players
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

#define cP1 'X';
#define cP2 'O';

void displayTitle(); // Display game title
void displayBoard(vector <char>& vBoard); // Print the board to the screen
int playerOrCpu();
int cpuMove(vector <char>& vBoard);
int getInput(int& nCount); // Get user input
void changeArray(vector <char>& vBoard, int& nCount, int& nLoc); // Use the input to change contents of the array
bool checkWin(vector <char>& vBoard); // Check if a player has three in a row
bool free(int freeTest, vector <char>& vBoard);

int main()
{
    int nTurn(0); // Counting the turns
    int nHumOrCpu, nTest; // int nTest is for testing the location
    bool GO = true;
    int aBoard[] = {'1','2','3','4','5','6','7','8','9'}; // Initializing the gameboard    
    vector <char> vPlayBoard(aBoard,aBoard+sizeof(aBoard)/sizeof(aBoard[0])); // Put the gameboard into a vector
    srand ( time(NULL) );
    
    displayTitle();
    displayBoard(vPlayBoard);
    nHumOrCpu = playerOrCpu();

    while(GO && nTurn < 9) {
	if(nTurn % 2 == 0 || (nTurn % 2 != 0 && nHumOrCpu==1)){
	    nTest = getInput(nTurn);
	    // Check if chosen position is already taken
	    if(vPlayBoard.at(nTest-1)=='X' || vPlayBoard.at(nTest-1)=='O') {
		cout << "Locatie " << nTest << " is al bezet." << endl;
	    }
	}
	else if(nTurn % 2 != 0 && nHumOrCpu==2){
	    nTest = cpuMove(vPlayBoard);
	}
	
	changeArray(vPlayBoard, nTurn, nTest);
	if(!checkWin(vPlayBoard)) {
	    ++nTurn;
	}
	else {
	    GO = false;
	}
	displayTitle();
	displayBoard(vPlayBoard);
    }

    if(nTurn<9) {
	int speler;
	
	if((nTurn % 2 == 0) || (nTurn % 2 != 0) && (nHumOrCpu == 1)) {
	    if(nTurn % 2 == 0) speler = 1;
	    else if((nTurn % 2 != 0) && (nHumOrCpu == 1)) speler = 2;
	    cout << "De winnaar is speler " << speler << "!\n";
	}
	else
	    cout << "De computer heeft gewonnen!\n";
    }
    
    // When 9 turns are passed without a winner, print this:
    else {
	cout << "Helaas, er is geen winnaar." << endl;
    }
    
    cout << "Bedankt voor het spelen! Tot ziens!" << endl;

    return 0;
}

// Print the name of the game
void displayTitle()
{
    cout << "------------------------------" << endl
	 << "\tTIC TAC TOE" << endl << endl
	 << "Speler 1 = X\tSpeler 2 = O" << endl << endl;
}

// Print the contents of the vector (playing board) to the screen
void displayBoard(vector <char>& vBoard)
{
    cout << "\t " << vBoard.at(0) << " | " << vBoard.at(1) << " | " << vBoard.at(2) << endl
	 << "\t" << "-----------" << endl
	 << "\t " << vBoard.at(3) << " | " << vBoard.at(4) << " | " << vBoard.at(5) << endl
	 << "\t" << "-----------" << endl
	 << "\t " << vBoard.at(6) << " | " << vBoard.at(7) << " | " << vBoard.at(8) << endl << endl;
}

int playerOrCpu()
{
    bool valid=true;
    int choice;

    while(valid) {
	cout << "Kies een tegenstander (1) Persoon (2) CPU: ";
	cin >> choice;
	
	if(choice == 1 || choice == 2) {valid = false;}
	else {
	    cout << "Ongeldige keuze. Kies (1) of (2).\n";
	    valid = false; 
	}
    }
    
    return choice;
}

bool free(int freeTest, vector <char>& vBoard) { 
    if((vBoard[freeTest] != 'X') && (vBoard[freeTest] != 'O')) { return true; }
    else { return false; }
}

// Make the cpu move
int cpuMove(vector <char>& vBoard)
{
    int location, testloc;
    bool done = false;

    while(!done) {
	// Check if it can block the player (or win)
	// Upper row
	if((vBoard[0] == vBoard[1]) && free(2, vBoard)) {testloc = 2; done = true;}
	else if((vBoard[1] == vBoard[2]) && free(0, vBoard)) {testloc = 0; done = true;}
	else if((vBoard[0] == vBoard[2]) && free(1, vBoard)) {testloc = 1; done = true;}
	// Middle row
	else if((vBoard[3] == vBoard[4]) && free(5, vBoard)) {testloc = 5; done = true;}
	else if((vBoard[4] == vBoard[5]) && free(3, vBoard)) {testloc = 3; done = true;}
	else if((vBoard[3] == vBoard[5]) && free(4, vBoard)) {testloc = 4; done = true;}
	// Lower row
	else if((vBoard[6] == vBoard[7]) && free(8, vBoard)) {testloc = 8; done = true;}
	else if((vBoard[7] == vBoard[8]) && free(6, vBoard)) {testloc = 6; done = true;}
	else if((vBoard[6] == vBoard[8]) && free(7, vBoard)) {testloc = 7; done = true;}

	// Left column
	else if((vBoard[0] == vBoard[3]) && free(6, vBoard)) {testloc = 6; done = true;}
	else if((vBoard[3] == vBoard[6]) && free(0, vBoard)) {testloc = 0; done = true;}
	else if((vBoard[0] == vBoard[6]) && free(3, vBoard)) {testloc = 3; done = true;}
	// Middle column
	else if((vBoard[1] == vBoard[4]) && free(7, vBoard)) {testloc = 7; done = true;}
	else if((vBoard[4] == vBoard[7]) && free(1, vBoard)) {testloc = 1; done = true;}
	else if((vBoard[1] == vBoard[7]) && free(4, vBoard)) {testloc = 4; done = true;}
	// Right column
	else if((vBoard[2] == vBoard[5]) && free(8, vBoard)) {testloc = 8; done = true;}
	else if((vBoard[5] == vBoard[8]) && free(2, vBoard)) {testloc = 2; done = true;}
	else if((vBoard[2] == vBoard[8]) && free(5, vBoard)) {testloc = 5; done = true;}

	// Diagonals
	else if((vBoard[0] == vBoard[4]) && free(8, vBoard)) {testloc = 8; done = true;}
	else if((vBoard[4] == vBoard[8]) && free(0, vBoard)) {testloc = 0; done = true;}
	else if((vBoard[0] == vBoard[8]) && free(4, vBoard)) {testloc = 4; done = true;}
	else if((vBoard[2] == vBoard[4]) && free(6, vBoard)) {testloc = 6; done = true;}
	else if((vBoard[4] == vBoard[6]) && free(2, vBoard)) {testloc = 2; done = true;}
	else if((vBoard[2] == vBoard[6]) && free(4, vBoard)) {testloc = 4; done = true;}

	// Choose random position if cpu can't block or win
	else {
	    testloc = rand() % 9;
	    if(vBoard[testloc] != 'X' && vBoard[testloc] != 'O') {
		done = true;
	    }
	    
	}
    }
        
    location = testloc + 1;
    
    cout << "Computer heeft gespeeld op locatie: " << location << endl;

    return location;
}

// Get input from the user and check if it is within valid range (1-9)
int getInput(int& nCount)
{
    bool check=false;
    int nChoice;
    
    while(!check) {
	if(nCount % 2 == 0) {
	    cout << "Speler 1 is aan de beurt." << endl
		 << "Kies een positie (1-9): ";
	}
	else {
	    cout << "Speler 2 is aan de beurt." << endl
		 << "Kies een positie (1-9): ";
	}
	cin >> nChoice;
    
	// Check if input is one of the locations on the board
	if(nChoice < 1 || nChoice > 9) {
	    cout << "Onjuist invoer, probeer het opnieuw. Kies een cijfer tussen 1 en 9." << endl << endl;
	}
	else
	    check = true;
    }
    
    return nChoice;
}

/* Change the contents of the array
   @param vector <char>& vBoard Pass the playing board
   @param int& nCount Pass the turncounter
   @param int& nLoc Pass the chosen location
 */
void changeArray(vector <char>& vBoard, int& nCount, int& nLoc)
{
    if(nCount % 2 == 0) {
	vBoard.at(nLoc-1) = cP1;
    }
    else {
	vBoard.at(nLoc-1) = cP2;
    }
}

// Check winning conditions
bool checkWin(vector <char>& vBoard)
{
    bool win = false;
    // Horizontal
    if (vBoard[0] == vBoard[1] && vBoard[1] == vBoard[2]) win = true;
    if (vBoard[3] == vBoard[4] && vBoard[4] == vBoard[5]) win = true;
    if (vBoard[6] == vBoard[7] && vBoard[7] == vBoard[8]) win = true;
    // Vertical
    if (vBoard[0] == vBoard[3] && vBoard[3] == vBoard[6]) win = true;
    if (vBoard[1] == vBoard[4] && vBoard[4] == vBoard[7]) win = true;
    if (vBoard[2] == vBoard[5] && vBoard[5] == vBoard[8]) win = true;
    // Diagonal
    if (vBoard[0] == vBoard[4] && vBoard[4] == vBoard[8]) win = true;
    if (vBoard[6] == vBoard[4] && vBoard[4] == vBoard[2]) win = true;

    return win;
}
