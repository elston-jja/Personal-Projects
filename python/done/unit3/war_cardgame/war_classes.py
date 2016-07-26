#!/usr/bin/python2

import random

''' War Card Game'''

class player:
    def __init__(self):
        print("1. Class || Player\t || Running")

    def create_cards(self):
        deck().create_deck()
    
    def get_hand(self):
        self.hand = self.player.distribute_cards()
        return self.hand

class deck:
    def __init__(self):
        print("2. Class || Deck\t || Running")
        
    def create_deck(self):
        self.fulldeck = []
        self.f_deck = []
        self.suits = ["H","S","D","C"]
        for i in range(4):
            self.f_deck.extend(list(range(2,15)))
            self.fulldeck.extend([str(card)+" "+str(self.suits[i]) for card in self.f_deck])
            del self.f_deck[:]
        random.shuffle(self.fulldeck)
        print("\t-Created and shuffled cards")

    def distribute_cards(self):
        if len(self.fulldeck) == 52:
            self.hand = self.fulldeck[len(self.fulldeck)/2:]
            del self.fulldeck[len(self.fulldeck)/2:]
            print("\t-Cards Distributed for player1")
        else:
            self.hand = self.fulldeck
            print("\t-Cards Distributed for player2")
        return self.hand
            
    
class play:
    def __init__(self):
        print("3. Class || Play\t || Running")

    def play_round(self,hand1,hand2):
        
        self.card_played1 = int((hand1[0])[:2])
        self.card_played2 = int((hand2[0])[:2])

        if self.card_played1 > self.card_played2:
            print "nothing"

            #ERROR CREATES 2 DECKS


elmer = player()
elston = player()
#elston = player_val.get_hand()
#elmer  = player_val.get_hand()
print elmer,elston
