#include<string>
#include<iostream>
#include<array>
#include<algorithm>
#include<random>

//suit enum
enum Suit { Spade, Heart, Club, Diamond };

//classes
class Card
{
    public:

    //data members
    Suit suit;
    int rank;

    //constructors
    Card()
    {
        suit = Spade;
        rank = 1;
    }

    Card(Suit s, int r)
    {
        suit = s;
        rank = r;
    }
    

    //functions
};

class Player
{
    public:

    //data members
    std::string name; //player's name
    Card hand[5]; //to store cards once dealt
    int order; //order of dealing and play (distance from dealer's left, dealer is 4)

    //constructor
    Player(std::string Name, int Order)
    {
        name = Name;
        order = Order;
    }

    //functions
    
};

//declare methods
void deal(Player p1, Player p2, Player p3, Player p4, Card *deck, int dealNum);

//main method
int main()
{
    //create deck of cards
    Card deck[52];

    int i = 0; //will use this to popluate deck in for loops
    for(int s = Spade; s <= Diamond; s++)
    {
        for(int r = 1; r <=13; r++)
        {
            Suit suit = static_cast<Suit>(s);
            deck[i].suit = suit;
            deck[i].rank = r;
            i++;
        }
    }

    //shuffle deck of cards
    unsigned seed = 0;
    std::shuffle(deck[0], deck[51]], std::default_random_engine(seed));
    
    //create players
    Player p1 = new Player("p1", 1);
    Player p2 = new Player("p2", 2);
    Player p3 = new Player("p3", 3);
    Player p4 = new Player("p4", 4);

    //deal cards
    deal(p1, p2, p3, p4, *deck, 2);

    return 0;
}

//methods
void deal(Player p1, Player p2, Player p3, Player p4, Card *deck, int dealNum) 
{
    int currentCard = 0; //used to know which card of the deck has been dealt
    for(int i = 0; i <= 5; i++)
    {
        p1.hand[i] = deck[currentCard];
        currentCard++;
        p2.hand[i] = deck[currentCard];
        currentCard++;
        p3.hand[i] = deck[currentCard];
        currentCard++;
        p4.hand[i] = deck[currentCard];
        currentCard++;
    }
}