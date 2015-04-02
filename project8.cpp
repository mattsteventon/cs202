/***************************************************************/
/* PROGRAM: */
/* Project8*/
/* AUTHOR: */
/* Matt Steventon */
/* DATE: */
/* 3/31/2015 */
/* REVISIONS: */
/* PURPOSE: */
/* Read in the deck of cards and players in the game. Create a class of cards and a class of players. Amongst the read in cards, they must be shuffled and then dealt amongst the players. Must also print the unshuffled cards, the shuffled cards, the players, the stock pile, and the discard pile. */
/**************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "cards.h"

using namespace std;

/**************************************************************/
/* FUNCTION: */
/* input */
/* PURPOSE: */
/* Read in the cards from the given file. */
/**************************************************************/
void input(card *ptr);

/**************************************************************/
/* FUNCTION: */
/* printorig */
/* PURPOSE: */
/* Print the unshuffled deck. */
/**************************************************************/
void printorig(card *ptr);

/**************************************************************/
/* FUNCTION: */
/* shuffle */
/* PURPOSE: */
/* Shuffle the cards. */
/**************************************************************/
void shuffle(card* ptr, card *shuf);

/**************************************************************/
/* FUNCTION: */
/* printshuff */
/* PURPOSE: */
/* Print the shuffled cards */
/**************************************************************/
void printshuff(card*);

/**************************************************************/
/* FUNCTION: */
/* nameinput */
/* PURPOSE: */
/* Input the player names */
/**************************************************************/
void nameinput(player *pptr, int num);

/**************************************************************/
/* FUNCTION: */
/* nameoutput */
/* PURPOSE: */
/* print the players of the game */
/**************************************************************/
void nameoutput(player *pptr, int num);

/**************************************************************/
/* FUNCTION: */
/* deal */
/* PURPOSE: */
/* Deal the cards amongst the specified number of players */
/**************************************************************/
int deal(player *pptr,int num, card *shuf, card *discard, card *stock);

/**************************************************************/
/* FUNCTION: */
/* outdiscard */
/* PURPOSE: */
/* Print the discard pile */
/**************************************************************/
void outdiscard(card *discard);

/**************************************************************/
/* FUNCTION: */
/* outstock */
/* PURPOSE: */
/* Print the remaining cards. */
/**************************************************************/
void outstock(card *stock, int k);

int main()
{
	int num = 0;
	card *ptr = NULL;
	ptr = new card[52];
	card *shuf = NULL;
	shuf = new card[52];
	card *discard = NULL;
	discard = new card[52];
	card *stock = NULL;
	stock = new card[52];
	int k = 0;
	char selection;

	cout << endl << "Enter Number of Players (2-8 players): ";
	cin >> num;
	cout << endl;
	player *pptr = NULL;
	pptr = new player[num];

	input(ptr);
	nameinput(pptr, num);

	do {
        	cout << "  Computer Science Registration Menu" << endl;
        	cout << "  ================================== " << endl;
			cout << "  1. Print the Unshuffled Deck of Cards " << endl;
			cout << "  2. Shuffle the Cards " << endl;
			cout << "  3. Print the Shuffled Cards " << endl;
			cout << "  4. Deal the Cards " << endl;
			cout << "  5. Print the Player Information " << endl;
			cout << "  6. Print the Discard Pile " << endl;
			cout << "  7. Print the Stock Pile " << endl;
			cout << "  8. Test the remaining overloaded operators. " << endl;
			cout << "  9. Exit " << endl;
        	cout << "  Enter your selection: ";
        	cin >> selection;
			cout << endl;

        	switch (selection)
        	{
            	case '1':
				printorig(ptr);
                	break;

	            case '2':
				shuffle(ptr, shuf);
                	break;

	            case '3':
				printshuff(shuf);
                	break;

	            case '4':
				k = deal(pptr, num, shuf, discard, stock);
                	break;

	            case '5':
				nameoutput(pptr, num);
                	break;

	            case '6':
				outdiscard(discard);
                	break;

	            case '7':
				outstock(stock, k);
                	break;

				case '8':
				if(shuf[0]>shuf[1])
					cout << "Card one is greater than card two, of the shuffled deck." << endl << endl;
				else
					cout << "Card one is lesser than card two, of the shuffled deck." << endl << endl;;

				if(shuf[2]<shuf[3])
					cout << "Card three is lesser than card four, of the shuffled deck." << endl << endl;
				else
					cout << "Card three is greater than card four, of the shuffled deck." << endl << endl;
					break;
			
			//user option to exit menu
				case '9':
					cout << "Goodbye." << endl << endl;
					selection=0;
					break;
	        }
	    }while (selection != 0 );

return 0;
}

void input(card* ptr)
{
	char *filename = new char[20];
	char *fptr = filename;
	cout << "Enter filename for Cards: ";
	cin >> fptr;
	cout  << endl;
	ifstream fin;
	fin.open(fptr);
	for(int i = 0; i<52; i++)
	{
		fin >> ptr[i];
		ptr[i].setlocation("unshuffled");
	}
}

void printorig(card *ptr)
{
	for( int i = 0; i<52; i++)
	cout << ptr[i];
	cout << endl;
}

void shuffle(card* ptr, card *shuf)
{
	srand ( time(NULL) );
	card temp;
	for(int i = 0; i < 52; i++)
	{
		shuf[i] = ptr[i];
		shuf[i].setlocation("shuffled");
	}
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        temp = shuf[j];
		shuf[j] = shuf[i];
		shuf[i] = temp;
    }
}

void printshuff(card *shuf)
{
	cout << endl << endl;
	for( int i = 0; i<52; i++)
	cout << shuf[i];
	cout << endl;
}

void nameinput(player *pptr, int num)
{
	char *filename = new char[20];
	char *fptr = filename;
	cout << "Enter filename for Players: ";
	cin >> fptr;
	cout  << endl;
	ifstream fin;
	fin.open(fptr);
	for(int i=0; i < num; i++)
	{
		fin >> pptr[i];
	}
}

void nameoutput(player *pptr, int num)
{
	for(int i=0; i < num; i++)
	{
		cout << pptr[i];
	}
}

int deal(player *pptr, int num, card *shuf, card *discard, card *stock)
{
	int tem;
	card* temp;
	int k = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j<num; j++)
		{
			temp = pptr[j].gethand();
			//use a variable (k) to keep track of what has been dealt
			temp[i] = shuf[k];
			temp[i].setlocation(pptr[j].getname());
			k++;
		}
		discard[i] = shuf[k];
		discard[i].setlocation("discard");
		k++;
	}
	tem = k;
	for(int i=tem; i<52; i++)
	{
		stock[i] = shuf[tem];
		stock[i].setlocation("stock");
		tem++;
	}
	return k;
}

void outstock(card *stock, int k)
{
	//Use k to print remaining cards
	for(int i = k; i<52; i++)
	{
		cout << stock[i];
	}
	cout << endl; 
}

void outdiscard(card *discard)
{
	for(int i=0; i<5; i++)
		cout << discard[i];
		cout << endl;
}
