'''
Elston Almeida
War Card Game
2016/49/24
ICS 3U1
'''

# Imports the two fuctions from the random class
from random import randint,shuffle

'''Create Deck'''
def create_deck_gen():
    # Create a deck with 52 cards with 4 suits
    # Creates the varible deck to just add lists to be maniplated
    deck = []
    # Creates the actual deck that will contain all cards
    complete_deck = []
    # List with all the card values that are going to be in the complete deck
    cards = ["H", "S", "D", "C"]
    # Loop four times for four suits
    for i in range(4):
        # Creates the variables 1 - 14 inside deck
        deck.extend(list(range(2,15)))
        # Takes the deck 1) Changes it to a string
        #                2) Adds the space and the suit of the card for each value in the list
        #                3) Appends the new deck to the complete deck
        complete_deck.extend([str(s)+" "+str(cards[i]) for s in deck])
        # delete the deck each time to get rid of duplicates
        del deck[:]
    # Suffles the whole deck to be distributed
    shuffle(complete_deck)
    # Return the whole deck of 52 cards with the 4 suits
    return complete_deck

'''Player wins round'''
def player_win(winner,loser,winner_cards,loser_cards):
    # Add the played cards to the winners winnings
    # Removes the cards that are played from the players deck
    #
    # Adds the played card of the winner to the winners winnings
    winner_cards.append(winner[0])
    # Adds the played card of the loser to the winners winnings
    winner_cards.append(loser[0])
    # Remove the card played from the loser
    loser.remove(loser[0])
    # Removes the card played from the winner
    winner.remove(winner[0])
    
    
'''Shuffle the winnings of both players'''
def shuffle_wins(p1c,p2c,p1w,p2w):
    # Uses the shuffle from random
    # Randomize the winnings of each player
    shuffle(p1w)
    shuffle(p2w)
    # Adds the shuffled winnings
    # back to the main deck
    p1c.extend(p1w)
    p2c.extend(p2w)
    # Remove the winnings
    # As they are now in the playing cards
    del p1w[:]
    del p2w[:]
    # Print statements to show how much cards each player has
    print "========================================"
    print "reshuffling wins back into hand..."
    print "----------------------------------------"
    print "player 1 cards: " + str(len(p1c))
    print "player 2 cards: " + str(len(p2c))

def outcome_round(cp1,cp2,p1c,p2c,rn):
    print "----------------------------------------"
    print "round number :" + str(rn)
    print "----------------------------------------"
    print "player1 played: " + str(cp1)
    print "player2 played: " + str(cp2)
    print "player1 cards left: " + str(len(p1c))
    print "player2 cards left: " + str(len(p2c))

def print_winner(winner,round_number):
    print "----------------------------------------"
    print "The winner is " + winner + " on round number " + str(round_number)
    print "congrats!!!"
    
# main(){
if __name__ == '__main__':
    # Creates Variables
    playing = True
    player2_wins = []
    player1_wins = []
    round_number = 0
    
    # Creates the deck with all 4 suits
    complete_deck = create_deck_gen()
    
    # Splits up the deck into two parts
    # Gives a part to each player
    player1_cards = complete_deck[len(complete_deck)/2:]
    player2_cards = complete_deck[:len(complete_deck)/2]
    
    # Starts a loop for repeating the card playing process
    while playing is True:
        
        # If both players have cards keep playing until one has run out
        while player1_cards and player2_cards:
            
            # Calls the first card in the deck with only the first two characters
            # The first two characters contain the magnitude
            cardplayed1 = int((player1_cards[0])[:2])
            cardplayed2 = int((player2_cards[0])[:2])
            # Player 1 wins the round if he has a higher value
            if cardplayed1 > cardplayed2:
                # Removes the players cards that have been played
                # Adds them to player1 winnings
                player_win(player1_cards,player2_cards,player1_wins,player2_wins)
                # Output statment to be more verbose about round wins
                outcome_round(cardplayed1,cardplayed2,player1_cards,player2_cards,round_number)
                # Loop for rounds played
                round_number = round_number + 1
                # Player 2 wins the round if he has a higher value
            elif cardplayed2 > cardplayed1:
                # Removes the players cards that has been played
                # Adds them to player2 winnings
                player_win(player2_cards,player1_cards,player2_wins,player1_wins)
                # Output statment to be more verbose about round wins
                outcome_round(cardplayed1,cardplayed2,player1_cards,player2_cards,round_number)
                # Loop for rounds played
                round_number = round_number + 1
                # Player 1 and player 2 has the cards with the same value
            elif cardplayed1 == cardplayed2:
                # List with the cards index ranked from lowest to highest
                cardsvalue = ["C","D","S","H"]
                # Takes the last character on card
                # Checks if index is higher
                if cardsvalue.index(str((player1_cards[0])[-1])) > cardsvalue.index((str(player2_cards[0])[-1])):
                    player_win(player1_cards,player2_cards,player1_wins,player2_wins)
                    outcome_round(cardplayed1,cardplayed2,player1_cards,player2_cards,round_number)
                    round_number = round_number + 1
                    # Player2 card index is higher than player1 card
                elif cardsvalue.index(str((player1_cards[0])[-1])) < cardsvalue.index((str(player2_cards[0])[-1])):
                    player_win(player2_cards,player1_cards,player2_wins,player1_wins)
                    outcome_round(cardplayed1,cardplayed2,player1_cards,player2_cards,round_number)
                    round_number = round_number + 1
                else:
                    # Debugging for cards that pop errors on screen or...
                    # Cards are not being put in any pile
                    print "error 1.2"
                    print cardplayed_player1
                    print cardplayed_player2
                    
        # Takes the players wins and reshuffle
        # Adds it back to the players cards
        shuffle_wins(player1_cards,player2_cards,player1_wins,player2_wins)
        
        # Winner is only done when one player has all the cards
        # If the players do not have all the cards then it will loop until one does
        if len(player1_cards) == 0 and len(player2_cards) == 52:
            playing =  False
        elif len(player2_cards) == 0 and len(player1_cards) == 52:
            playing = False

            # Prints the winner based on who has more cards at the end
            # of the game, and then should ask to replay
    if len(player2_cards) > len(player1_cards):
        winner = "player 2"
    else:
        winner = "player 1"
    print_winner(winner,round_number)
#}
