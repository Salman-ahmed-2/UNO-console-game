// se c
//salman ahmed khan (i243004)
//usman azhar (i243105)





#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<fstream>

using namespace std;
#define  n_clr 4   // 4 color: Red Blue Green Yellow
#define  n_card_type 15  // 0 to 9, Skip, Reverse, Draw Two, Wild, Wild Draw Four
#define card_in_hand 7 // Cards a player will  starts 

const int DECK_SIZE = 108;  //calculatr uno deck size
int play_2_win= 0;
int play_1_win=0;
int play_2_wins;
int play_1_wins;

// Color and card type 
const string clr[]= { "Red","Green","Blue", "Yellow", "Wild" };
const string cardtypeed[] ={ "0", "1", "2", "3", "4",  "5","6", "7", "8","9", "Skip", "Reverse","Draw Two", "Wild","Wild Draw Four" };

// The deck, player's hands, and discard pile
int deck[DECK_SIZE][2]; 
int play_hand_one[DECK_SIZE][2];
int play_hand_two[DECK_SIZE][2];

int topCard[2]= {-1,-1};  // Top card on the discardd pile

int deckSize =DECK_SIZE;  // remaining number 



int w_clr;
int c_player;
const int MAGENTA= 5;
const int YELLOW= 6;
const int WHITE =7;
const int CYAN = 3;
const int RED = 4;
const int BLACK   = 0;
const int BLUE =  1;
const int GREEN= 2;
// Function prototypes
void clearScreen();
void updateDiscardPile(int playerCard[2]);
void printPlayerHand(int player);
void printTopCard();
void initializeDeck(int decko[][15]);
void shuffleDeck(int decko[][15]);
void dealCards(int playerHands[][DECK_SIZE][2]);
bool isValidPlay(int playerCard[2], int topCard[2]);
bool checkWinner();
void drawCard(int player);
void r_cardffromplayer(int player, int cardi_ndex);
void setColor(int textColor, int bgColor);
void printCardRow(int bgColor, int textColor, const string &content);
void playTurn(bool& mainmenu);
void handleSpecialCard(int specialCardType);

// Clear the console screen
void clearScreen() {
    system("CLS"); // Windows ke liye
}

// Set the color for the console output
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor <<4) | textColor);
}
void setConsoleColor(int textColor, int bgColor) {
    HANDLE hConsole =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor <<4) | textColor);
}



void printRemainingDeck() {
    //print the cards which are not valid and are not in the hand of the player

    for (int i = 0; i < DECK_SIZE; i++) {
        if (deck[i][0] != -1) {
            cout << (i + 1) << ". ";  // Show 1-based i_ndex for user
            printCardRow((deck[i][0]), WHITE, cardtypeed[deck[i][1]]);
            cout << " ";
        }
    }
}

void printCardsp(int player) {
    int player2[DECK_SIZE][2];
    if(player==0){
        for(int i=0; i<DECK_SIZE; i++){
        player2[i][0] =play_hand_two[i][0];
        player2[i][1]= play_hand_two[i][1];
    }
    }
    else if(player==1){
    for(int i=0; i<DECK_SIZE; i++){
        player2[i][0]= play_hand_one[i][0];
        player2[i][1] = play_hand_one[i][1];
    }
    }
for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
  int numCards = 0 ;  // Assuming numCards is the number of cards
  for (int i = 0 ; i<DECK_SIZE ;i++ )
      if (player2[i][0]!= -1)
          numCards++;

    // Print the top border of all cards


    int clr[DECK_SIZE];
    int ttiles[DECK_SIZE];



    int i=0;  
     while(i<numCards){
	 switch(player2[i][0]){
	 
       case 0:
            clr[i] = RED;
        break;
        case 1:
            clr[i]= GREEN;
break;
	     case 2:
            clr[i] = BLUE;
       break;
       case 3:
    
            clr[i]= YELLOW;
         break;
         case 4:
        
            clr[i]= 0;
        break;
}
        ttiles[i] =player2[i][1]; 
		 // Assigning the title value
		 i++;
    }
    for (int i= 0; i<numCards; i++) {
        printCardRow(clr[i], WHITE, "-------");
    }
    cout << endl;

    // Print the firstt content row of all cards
    for (int i = 0; i < numCards; i++)
     {
        printCardRow(clr[i], WHITE, "|     |");
    }
    for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    cout <<endl;

    // Print the seciond content row of all cards (Title)
   for (int i= 0; i< numCards; i++) {
    string title =to_string(ttiles[i]);
switch(ttiles[i]){

        case 13:
            title="W";
        
        break;
        case 10:
          title="S";	
       
        break;
        case 11:
        title="R";	
        break;
        case 12:
        title="D";
        break;
        case 14:
		title="X";
        break;
    }
        // Add an extra spamce for single-digit numbers
        title = " "+title;

    
    printCardRow(clr[i], WHITE,"|  " + title + " |");
}
    cout << endl;

 


    // Print the third content row of all cards
    for (int i = 0; i < numCards; i++) {
        printCardRow(clr[i],WHITE, "|     |");
    }
    cout << endl;

    // Print the bottom border of all cards
    for (int i = 0; i< numCards;i++) {
        printCardRow(clr[i], WHITE, "-------");
    }

 
    cout << endl;

}


// for(int playycard=0;playycard<108;playycard++){
//     for ( int cardnum=0;cardnum<15;cardnum++)
//     {
//         for (int ccard=0; ccard<=7;ccard++)
//         {
//             int playcarduno;
//              playcarduno++;
//         }
//     }
// }

bool callUno(){


    char uno;
    cout<<"Enter 'U' to call Uno: ";
    cin>>uno;
    while(cin.fail() )
{ cin.clear();
	cin.ignore(10,'\n');
	cout<<"INVALID!!!"<<endl;
	cout<<"enter again: "<<endl;
	cin>>uno;
}
    if(uno=='U' || uno=='u'){
        return true;
    }
    return false;
}
int playerCards(int player){
    int count=0;
    for(int i=0; i<DECK_SIZE; i++){
        if(player==0 && play_hand_two[i][0]!=-1){
            count++;
        }
        else
        if(play_hand_one[i][0]!=-1 && player==1){
            count++;
        }
    }
    return count;
}

//void saveLoadGameResult(bool save) {
//    if (save) {
//        ofstream file("gameResults.txt");
//        file << "Player 1 Wins: 0" << endl;
//        file << "Player 2 Wins: 0" << endl;
//        file.close();
//    } else {
//        ifstream file("gameResults.txt");
//        string line;
//        while (getline(file, line)) {
//            cout << line << endl;
//        }
//        file.close();
//    }
//}
// Print a row of a card with its color
void saveLoadGameResult(int play_1_wins, int play_2_wins) {
    // Save game results to a file
    ofstream out("game_history.txt"); // Opein file in append mode
    if (out.is_open()) {
        out << "Game Result:\n";
        out << "Player 1's wins: " << play_1_wins << endl;
        out << "Player 2's wins: " << play_2_wins << endl;
        out << "--------------------------------\n";
        out.close();
        cout << "Game history saved successfully.\n";
    } else {
        cerr << "Error: Unable to save game history.\n";
        return;
    }
for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    // Load and display goame history
    ifstream in("game_history.txt");
    if (in.is_open()) {
        cout << "\nGame History:\n";
        string line;
        while (getline(in, line)) {
            cout << line << endl; // Display each line from the file
        }
        in.close();
    } else {
        cerr << "Error: Unable to load game history.\n";
    }
}

void printCardRow(int bgColor, int textColor, const string &content) {
    setColor(textColor,bgColor);
    cout<< " " <<content <<" ";
    setColor(WHITE, BLACK); // Rejset for spacing
    cout << "  "; // Space between cards
}
//FUNCTION NO 1 STUDENT 1
void initializeDeck(int decko[][15]) {
    int i_ndex =0;

    // Red, Green, Blue, Yekllow color cards (numbers, skip, reverse, draw two)
    for (int color = 0; color < n_clr; color++) {
        // Number cards (1-9), 2 copies of each
        for (int num = 0; num < 10; num++) {
            if (num == 0) {  // 1 "0" card for each color
                deck[i_ndex][0] = color;
                deck[i_ndex][1] = num;
                i_ndex++;
            } else {  // 2 copies of each number card (1-9)
                deck[i_ndex][0] =color;
                deck[i_ndex][1]= num;
                i_ndex++;

                deck[i_ndex][0] = color;
                deck[i_ndex][1] = num;
                i_ndex++;
            }
        }
        for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
        // Special cards: Skip, Reverse, Draw Two (2 copies each)
        for (int type = 10; type <= 12; type++) {
            deck[i_ndex][0] = color;
            deck[i_ndex][1] = type;
            i_ndex++;
            deck[i_ndex][0] = color;
            deck[i_ndex][1] = type;
            i_ndex++;
        }
    }

    // Wild cards and Wild Draw Four cards
    for (int i = 0; i < 4; i++) {
        deck[i_ndex][0] = 4;  // Wild
        deck[i_ndex][1] = 13;  // Wild
        i_ndex++;
        deck[i_ndex][0] = 4;
        deck[i_ndex][1] = 14;  // Wild Draw Four
        i_ndex++;
    }
}
// FUNCTION NO 1 STUDENT 2
void shuffleDeck(int decko[][15]) {
    srand(time(0));
  for (int i = 0; i < DECK_SIZE; i++) {

        int randindex = rand() % DECK_SIZE;


        for (int j = 0; j < 2; j++) {
            int temp = deck[i][j];
            deck[i][j] = deck[randindex][j];
            deck[randindex][j] = temp;
}
}
}
// FUNCTION NO 2 STUDENT 1
void dealCards() {
    int cardi_ndex = 0;

    for (int player = 0; player < 2; player++) {
        for (int card = 0; card < DECK_SIZE; card++) {
            if (card < card_in_hand) {
                // Assign cards from the deck to the player's hand
                if (player == 0) {
                    play_hand_two[card][0] = deck[cardi_ndex][0]; // Color
                    play_hand_two[card][1] = deck[cardi_ndex][1]; // Type
                } else {
                    play_hand_one[card][0] = deck[cardi_ndex][0]; // Color
                    play_hand_one[card][1] = deck[cardi_ndex][1]; // Type
                }
                cardi_ndex++;
            } else {
                // Initialize the reist of the cards as empty (-1)
                if (player == 0) {
                    play_hand_two[card][0] = -1; // Color
                    play_hand_two[card][1] = -1; // Type
                } else {
                    play_hand_one[card][0] = -1; // Color
                    play_hand_one[card][1] = -1; // Type
                }
            }
        }
    }
    for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
}
// for(int playycard=0;playycard<108;playycard++){
//     for ( int cardnum=0;cardnum<15;cardnum++)
//     {
//         for (int ccard=0; ccard<=7;ccard++)
//         {
//             int playcarduno;
//              playcarduno++;
//         }
//     }
// }
// FUNCTION NO 2 STUDENT 2
bool isValidPlay(int playerCard[2],int topCard[2]) {

    if (topCard[0] == -1) {  // No card on top, any card is valid
        return true;
    }

    // If the player card is a Wild card (13 or 14), it can be played on any card
    if (playerCard[1] ==13 || playerCard[1] == 14) {
        return true;  //5 Wild cards can be played on any card
    }

    // If the top card is a Wild card, oonly color should match
    if (topCard[1] ==13 || topCard[1] == 14) {
        return playerCard[0] == w_clr;  // Only color should match the selected wild color
    }
for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    // If the top card is not Wiuld, the card must match the color or number
    return (playerCard[0] ==topCard[0] || playerCard[1] ==topCard[1]);
}
// FUNCTION NO 3 STUDENT 2
void playTurn(bool& mainmenu) {
    cout << "Player " << c_player + 1 << "'s turn!" << endl;
    int cchoice;
    bool validPlay = false;

    printCardsp(c_player);

    while (!validPlay) {
        cout << "Choose a card to play (enter the card number) or choose 99 to draw a card (1-based i_ndex) and (E or e to EXIT GAME): ";
        bool uno = true;

        // Check if the player musti call Uno
        if (playerCards(c_player) == 2) {
            uno = callUno();
            if (!uno) {
                cout << "You must call Uno before playing the second last card!" << endl;
                cout << "Player " << c_player + 1 << " must draw 2 cards!" << endl;
                drawCard(c_player);
                drawCard(c_player);
                printCardsp(c_player);
                cout << "Now select a card to play!" << endl;
            }
        }
string  ans,ans1;
        cin >> ans;
            if (playerCards(c_player) > 2 && (ans == "U" || ans == "u")) {
        cout << "You called Uno too early! You must draw 2 cards!" << endl;
        drawCard(c_player);
        drawCard(c_player);
        printCardsp(c_player);  // Display updated hand
        cout << "Now select a card to play!" << endl;
        continue;  // Continue to ask for valid inpuot after drawing cards
    }
        int cchoice=0;
    if(ans=="e" || ans=="E"){
    	cout<<"DO YOU WANT TO EXIT GAME?"<<endl;
    	cin>>ans1;
    	if(ans1=="Y"){
    		 mainmenu=true;
    		return;
    		
		}
	}
else	if(ans1=="N"||ans1=="n")	{
	
		cout<<"CONTINUING THE GAME FROM WHERE YOU LEFT......."<<endl;
		 cout << "Choose a card to play (enter the card number) or choose 99 to draw a card (1-based i_ndex): ";
		 cin>>ans;
		
		
		}
		
		
		
		
    	
    
	
 

   else  { // ariund string
   cchoice=0;
    for (char c : ans) {
        // Checking if the element is number
        if (c >= '0' && c <= '9') {
        	
            cchoice = cchoice * 10 + (c - '0');
        }
        else {
            cout << "Bad Input";
            return  ;
        }
        
    
	}

	}

//        while(cin.fail())
//{ cin.clear();
//	cin.ignore(10,'\n');
//	cout<<"INVALID!!!"<<endl;
//	cout<<"enter again: "<<endl;
//	cin>>cchoice;
//}

        // Convert cchoice from 1-based to 0-based i_ndex
        cchoice -= 1;

        if (cchoice == 98) {  // For drawing a card (since 99 will be used for drawing)
            drawCard(c_player);
            validPlay = true;
        }  if (cchoice >= 0 && cchoice < DECK_SIZE) {
            // Use the appropriate player's hand based on the current player
            if (c_player == 0 && play_hand_two[cchoice][0] != -1 && isValidPlay(play_hand_two[cchoice], topCard)) {
                validPlay = true;
                int cardType = play_hand_two[cchoice][1];
                updateDiscardPile(play_hand_two[cchoice]);
                r_cardffromplayer(c_player, cchoice);  // Remove the played card from the hand
                handleSpecialCard(cardType);  // Handle special cards
            } else if (c_player == 1 && play_hand_one[cchoice][0] != -1 && isValidPlay(play_hand_one[cchoice], topCard)) {
                validPlay = true;
                int cardType = play_hand_one[cchoice][1];
                updateDiscardPile(play_hand_one[cchoice]);
                r_cardffromplayer(c_player, cchoice);  // Remove the played card from the hand
                handleSpecialCard(cardType);  // Handle special cards
            } 
			else {
                cout << "Invalid cchoice! Try again." << endl;
            }
    }
           
        
//        else {
//            cout << "Invalid cchoice! Try again." << endl;
//        }
        for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    }
}




void r_cardffromplayer(int player, int cardi_ndex){
    // Shift all card6s after the played card to the left
    for (int i =cardi_ndex; i<DECK_SIZE - 1; i++) {
        
        if(player==0){
        play_hand_two[i][0]=play_hand_two[i +1][0];
        play_hand_two[i][1] =play_hand_two[i+ 1][1];
        }
        else if(player==1){

        play_hand_one[i][0] =play_hand_one[i+ 1][0];

        play_hand_one[i][1]= play_hand_one[i +1][1];
        }

    }
    for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    // Set the last ca9rd in the hand to an empty card
    if(player==0)
    {
    play_hand_two[DECK_SIZE-1][0] =-1;

    play_hand_two[DECK_SIZE- 1][1]= -1;
    }
    else if(player==1)
    {
    play_hand_one[DECK_SIZE -1][0]= -1;

    play_hand_one[DECK_SIZE-1][1]= -1;
    }

}
void printCardstop() {

  int numCards=1;


int clr[1];
int ttiles[1];
int i=0;
while(i<numCards){
	 switch(topCard[0]){
	 
       case 0:
            clr[i] = RED;
        break;
        case 1:
            clr[i]= GREEN;
break;
	     case 2:
            clr[i] = BLUE;
       break;
       case 3:
    
            clr[i]= YELLOW;
         break;
         case 4:
        
            clr[i]= 0;
        break;
}
	  
    ttiles[i] =topCard[1];
	  // Assigning thei title value
	  i++;
}
   for (int i =0;i <numCards; i++) {
          cout<<"                                ";  printCardRow(clr[i], WHITE, "-------");
    }

    cout << endl;
for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
        for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    }
}
    // Print the firstt content row of all cards
    for (int i = 0; i < numCards; i++) {
              cout<<"                                ";printCardRow(clr[i], WHITE, "|     |");
    }
    cout << endl;

    // Print the second content row of all cards
    for (int i =0; i<numCards; i++) {
    
    string title = to_string(ttiles[i]);
    
switch(ttiles[i]){

        case 13:
            title="W";
        
        break;
        case 10:
          title="S";	
       
        break;
        case 11:
        title="R";	
        break;
        case 12:
        title="D";
        break;
        case 14:
		title="X";
        break;
    }

        // Add an extraa space for single-digit numbers
        title = " "+title;
    
          cout<<"                                ";printCardRow(clr[i], WHITE, "|  " + title + " |");
}
    cout << endl;

    // Print the third content row of all cards
    for (int i = 0; i < numCards; i++)
     {
              cout<<"                                ";printCardRow(clr[i], WHITE, "|     |");
    }
    cout << endl;

    // Print the bottom b0order of all cards
    for (int i = 0; i < numCards; i++)
     {
        cout<<"                                "; printCardRow(clr[i], WHITE, "-------");
    }
    cout << endl;
}

void drawCard(int player) {
    if (deckSize > 0) {
        int randCard = rand() % deckSize;

        // Use the appropriiate player's hand array directly
        if (player == 0) {
            for (int i = 0; i < DECK_SIZE; i++) {
                if (play_hand_two[i][0]==-1) {  // Find an empty spot for the card
                    play_hand_two[i][0]=deck[randCard][0];
                    play_hand_two[i][1]= deck[randCard][1];
                    break;
                }
            }
        } else if (player == 1) {
            for (int i = 0; i < DECK_SIZE; i++) {
                if (play_hand_one[i][0] == -1) {  // Find an empty spot for the card
                    play_hand_one[i][0] = deck[randCard][0];
                    play_hand_one[i][1] = deck[randCard][1];
                    break;
                }

            }
            for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
        }

        deckSize--;  // Decrease the number of cards in the deck
        cout << "Player " << player + 1 << " drew a card from the deck." << endl;
    } else {
        cout << "No more cards in the deck!" << endl;
    }
    for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
}

void handleSpecialCard(int specialCardType) {
cout<<"Special card type: "<<specialCardType<<endl;


    switch (specialCardType) {
        case 10:  // Skip
          //  c_player = (c_player + 1) % 2;
            cout << "Player " << c_player + 1 << " is skipped!" << endl;
            c_player = (c_player + 1) % 2;
            //c_player = (c_player + 1) % 2;
           // cout<<"Player "<<c_player+1<<"'s turn!"<<endl;
            
            break;
        case 11:  // Reverse
             c_player = (c_player + 1) % 2;
            cout << "Reversed turn order!" << endl;
            break;
        case 12:  // Draw Two
            c_player = (c_player + 1) % 2; // Skip their turn
            cout << "Player " << c_player + 1 << " must draw 2 cards!" << endl;
            drawCard(c_player);
            drawCard(c_player);
            
            break;
        case 13:  // Wild
            cout << "Wild card played!" << endl;
            cout << "Choose the color to play next (0: Red, 1: Green, 2: Blue, 3: Yellow): ";
            cin >> w_clr;
            while(cin.fail()|| w_clr<0|| w_clr>3)
{ cin.clear();
	cin.ignore(10,'\n');
	cout<<"INVALID!!!"<<endl;
	cout<<"enter again: "<<endl;
	cin>>w_clr;
            for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
            
}
            break;
        case 14:  // Wild Draw Four
        a:
            cout << "Wild Draw Four card played!" << endl;
            cout << "Choose the color to play next (0: Red, 1: Green, 2: Blue, 3: Yellow): ";
            cin >> w_clr;
            while(cin.fail() || w_clr<0|| w_clr>3)
{ cin.clear();
	cin.ignore(10,'\n');
	cout<<"INVALID!!!"<<endl;
	cout<<"enter again: "<<endl;
	goto a;
}
            c_player = (c_player + 1) % 2; // Skip their turn
            cout << "Player " << c_player + 1 << " must draw 4 cards!" << endl;
            drawCard(c_player);
            drawCard(c_player);
            drawCard(c_player);
            drawCard(c_player);
            c_player = (c_player + 1) % 2; // Return the opposite turn
            

            break;
        default:
          //  c_player = (c_player + 1) % 2;
            break;
    }
}

void updateDiscardPile(int playerCard[2]) {
    topCard[0] = playerCard[0];  // Set the color of the top card
    topCard[1] = playerCard[1];  // Set the type of the top card
    cout << "Top card: ";
    printCardRow(topCard[0], WHITE, cardtypeed[topCard[1]]);
    cout << endl;
    
    
}

void printPlayerHand(int player) {
    cout << "Player " << player + 1 << "'s cards: ";

    // Use the appropriate player's hand directly
    if (player==0) { for (int i=0;i <DECK_SIZE; i++) {
            if (play_hand_two[i][0]!=-1) {  // Only print valid cards
                cout << (i+1)<<". ";  // Show 1-based i_ndex for user
                printCardRow(play_hand_two[i][0], WHITE, cardtypeed[play_hand_two[i][1]]);
                cout<<" ";
            }
        }
    } else if (player==1) {
        for (int i=0; i< DECK_SIZE; i++) {
            if (play_hand_one[i][0]!=-1) {  // Only print valid cards
                cout <<(i+1)<<". ";  // Show 1-based i_ndex for user
                printCardRow(play_hand_one[i][0], WHITE, cardtypeed[play_hand_one[i][1]]);
                cout <<" ";}}}

    cout << endl;
}


void printTopCard() 
{ srand(time(0));

    if (topCard[0] == -1)
     { cout<<"                "<<endl;
       cout<<"Top card: ";
        cout<<endl;
	 int color=rand()%3;
	 int value=rand()%12;
	   topCard[0]=color;
         topCard[1]=value;
          printCardstop();
    } else {
        cout<<"Top card: ";
        cout<<endl;

        printCardstop();
        cout << endl;
    }
}
bool checkWinner() {

    for (int i = 0; i < 2; i++) {

        bool hasCardsLeft=false;

        if (i==0) 
        { // Check play_hand_two
            for (int j =0; j< DECK_SIZE; j++) 
            {
                if (play_hand_two[j][0] != -1) {  // If the player has at least one card left
                    hasCardsLeft = true;
                    break;
                }
            }
            for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
        } else { // Check play_hand_one
            for (int j = 0; j < DECK_SIZE; j++) {
                if (play_hand_one[j][0] != -1) { 
                     // If the player has at least one card left
                    hasCardsLeft = true;
                    break;
                }
            }
        }

        if (!hasCardsLeft) { // If the player has no cards left
            cout << "Player " << i + 1 << " wins!" << endl;
            return true; // A player has won
        }
        for(int playycard=0;playycard<108;playycard++){
    for ( int cardnum=0;cardnum<15;cardnum++)
    {
        for (int ccard=0; ccard<=7;ccard++)
        {
            int playcarduno;
             playcarduno++;
        }
    }
}
    }
    
    return false;  // If both players still have cards left, no winner yet

}




int main() {
	cout<<endl<<endl<<endl<<endl;
	
	 a:
	 	b:
	 	clearScreen();
cout<<"                                    ###############################################"<<endl;
cout<<"                                    #####                                     #####"<<endl;
cout<<"                                    #####            WELCOME TO UNO           #####"<<endl;
cout<<"                                    #####                                     #####"<<endl;
cout<<"                                    ###############################################"<<endl;

cout<<endl;
cout<<" MENU "<<endl;
cout<<"1. START GAME "<<endl;
cout<<"2. EXIT "<<endl;
cout<<"3. SHOW GAME POINTS "<<endl;
int cchoice;
cin>>cchoice;
while(cin.fail()|| cchoice==0 || cchoice<0 || cchoice>3)
{ cin.clear();
	cin.ignore(10,'\n');
		cout<<"INVALID!!!"<<endl;
	cout<<"ENTER YOUR CHOICE AGAIN:  "<<endl;
	cin>>cchoice;
}
switch(cchoice){
	case 1:
{ 
cout<<" loading .... ";
clearScreen();
    bool gamegoing=true;
     c_player= 0;
     w_clr =-1;
    int deck [DECK_SIZE][15];
    initializeDeck(deck);



    shuffleDeck(deck);
    dealCards();
    int turn=0;
    while (gamegoing) 
    {
    	turn++;
    	 bool mainmenu=false;
    	clearScreen();
        printTopCard();
        playTurn(mainmenu);
       
        if(mainmenu==true)
        {
        goto a;
		}
		
        c_player= (c_player +1) % 2;
        
      string ans2;

if(checkWinner()==true){
	if (turn%2!=0){
		cout<<"CONGRAJULATIONS !!!"<<endl;
	cout<<"PLAYER 1 wins"<<endl;
	cout<<"enter back to exit"<<endl;
	cin>>ans2;
	goto b;
}
else if(turn%2==0)
{  cout<<"CONGRADULATIONS!!!!!"<<endl;
	cout<<"PLAYER 2 wins"<<endl;
	cout<<"enter back(b) to exit"<<endl;
	cin>>ans2;
	goto b;
}
        // Check for winner
//        if (checkwin==true) {
//            cout << "Player " << c_player + 1 << " wins!" << endl;
//            break
 }
        //cout<<"Remaining cards in the deck: ";
       // printRemainingDeck();
          
    
    }
     play_1_wins= play_1_win;
 play_2_wins=play_2_win;
}
break;
case 2: 
cout<<"exiting.....";
return 0;

case 3:
	   saveLoadGameResult(play_1_wins, play_2_wins);

    
}
}


