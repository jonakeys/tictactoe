#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define cP1 'X';
#define cP2 'O';

void displayTitle();
void displayBoard(vector <char>& vBoard);
int getInput(int& nCount);
void changeArray(vector <char>& vBoard, int& nCount, int& nLoc);
bool checkWin(vector <char>& vBoard);

int main()
{
    int nTurn(0);
    bool GO = true;
    int aBoard[] = {'1','2','3','4','5','6','7','8','9'};
    vector <char> vPlayBoard(aBoard,aBoard+sizeof(aBoard)/sizeof(aBoard[0]));
    
    displayTitle();
    displayBoard(vPlayBoard);

    while(GO && nTurn < 9) {
	int nTest = getInput(nTurn);
	if(vPlayBoard.at(nTest-1)=='X' || vPlayBoard.at(nTest-1)=='O') {
	    cout << "Locatie " << nTest << " is al bezet." << endl;
	}
	else {
	    changeArray(vPlayBoard ,nTurn, nTest);
	    if(!checkWin(vPlayBoard)) {
		++nTurn;
	    }
	    else {
		GO = false;
	    }
	}
	displayTitle();
	displayBoard(vPlayBoard);
    }
    
    if(nTurn<9) {
	int speler;
	if (nTurn % 2 == 0) speler = 1;
	else speler = 2;
	cout << "De winnaar is speler " << speler << "!\n";
    }
    else {
	cout << "Helaas, er is geen winnaar." << endl;
    }

    cout << "Bedankt voor het spelen! Tot ziens!" << endl;

    return 0;
}

void displayTitle()
{
    cout << "------------------------------" << endl
	 << "\tTIC TAC TOE" << endl << endl
	 << "Speler 1 = X\tSpeler 2 = O" << endl << endl;
}

void displayBoard(vector <char>& vBoard)
{
    cout << "\t " << vBoard.at(0) << " | " << vBoard.at(1) << " | " << vBoard.at(2) << endl
	 << "\t" << "-----------" << endl
	 << "\t " << vBoard.at(3) << " | " << vBoard.at(4) << " | " << vBoard.at(5) << endl
	 << "\t" << "-----------" << endl
	 << "\t " << vBoard.at(6) << " | " << vBoard.at(7) << " | " << vBoard.at(8) << endl << endl;
}

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
    
	if(nChoice < 1 || nChoice > 9) {
	    cout << "Onjuist invoer, probeer het opnieuw. Kies een cijfer tussen 1 en 9." << endl << endl;
	}
	else
	    check = true;
    }
    
    return nChoice;
}

void changeArray(vector <char>& vBoard, int& nCount, int& nLoc)
{
    if(nCount % 2 == 0) {
	vBoard.at(nLoc-1) = cP1;
    }
    else {
	vBoard.at(nLoc-1) = cP2;
    }
}

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
