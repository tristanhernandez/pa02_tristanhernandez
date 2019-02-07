int main(){

    //test arguments, create a line object, all that
    

    Cards player1;
    Cards player2;

    Cards deck;  //starts with 52 cards, 
    deck.shuffle;//loads the deck with 52 cards.

    while (player1.cardCount()<5) //cardCount checks the number of cards in the hand
    {
        player1.takeCardfromTop(player1, deck);
        //Player1 takes 5 cards from top of deck;
    }

    while (player2.cardCount()<5)
    {
        player2.takeCardfromTop(player1, deck);         
        //Player2 takes 5 cards from top of deck;
    }

    /* Player1 and 2 each choose a number to decide who goes first
     * The first one seeks a card SeekCard(source, target, num)
     * If the other player has that number, the first player takes
       that card
     * Then, if one player has 4 of one number, they get a point and empty
       that number from their hand
     * Player with the most points, or to empty their hand first, wins
     * Else the player draws a card
     * Next player repeats every step beside the first
     * Repeat again with other player until there is a winner.
     */

}
