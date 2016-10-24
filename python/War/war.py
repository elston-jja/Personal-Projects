#!/usr/bin/python

'''
@Author Elston Almeida
enter info about program here
@Date 2016/04/09
@Course ICS 3U1
'''

from random import randint,shuffle

class  wargame:
    
    '''Sets up the game'''
    def __init__(self):
        self.create_deck()
        self.distribute()
        self.war()
        
    '''Creates the deck and other lists'''
    def create_deck(self):
        self.user1_cards = []
        self.user2_cards = []
        self.user1_winnings = []
        self.user2_winnings = []
        self.card = 0
        self.round_number = 0
        self.deck = []
        self.total = []
        self.type_card = ["H","S","D","C"]
        self.deck_number = 1
        for x in range(self.deck_number): # Create many decks
            for i in range(4):
                self.deck.extend(list(range(2,15)))
                self.total.extend([str(s)+" "+ str(self.type_card[i]) for s in self.deck])
                del self.deck[:]        
        shuffle(self.total)
        
    '''Gives each player half the deck '''
    def distribute(self):
        self.user1_cards = self.total[len(self.total)/2:]
        self.user2_cards = self.total[:len(self.total)/2]

    '''Puts card into winners deck and removes it from playing'''
    def user1_win(self):
        self.user1_winnings.append(self.user2_cards[self.card])
        self.user1_winnings.append(self.user1_cards[self.card])
        self.user2_cards.remove(self.user2_cards[self.card])
        self.user1_cards.remove(self.user1_cards[self.card])
        self.outcome_round()   
    def user2_win(self):
        self.user2_winnings.append(self.user1_cards[self.card])
        self.user2_winnings.append(self.user2_cards[self.card])
        self.user1_cards.remove(self.user1_cards[self.card])
        self.user2_cards.remove(self.user2_cards[self.card])
        self.outcome_round()

    '''Scrambles cards and put them back in hand'''
    def shuffle_wins(self):
        shuffle(self.user1_winnings)
        shuffle(self.user2_winnings)
        self.user1_cards.extend(self.user1_winnings)
        self.user2_cards.extend(self.user2_winnings)
        del self.user1_winnings[:]
        del self.user2_winnings[:]
        print "reshuffling wins back into hand..."
        print "----------------------------------------"
        print "user 1: " + str(len(self.user1_cards))
        print "user 2: " + str(len(self.user2_cards))
        print "----------------------------------------"

    '''Round count and displays all cards on table'''
    def outcome_round(self):
        self.round_number = self.round_number + 1
        print "----------------------------------------"
        print "\nround :"+ str(self.round_number)
        print "========================================"
        print "\nuser 1 has " + str(len(self.user1_cards)) + " cards"
        print   "user 2 has " + str(len(self.user2_cards)) + " cards"
        print "User 1 winnings are " + str(len(self.user1_winnings))
        print "User 2 winnings are " + str(len(self.user2_winnings))
        print "----------------------------------------"

    '''Creates a loop that plays all cards in hand'''
    def play_hand(self):
        while self.user1_cards and self.user2_cards:
            # Changes cards to readable values
            cardplayed_user1 = int((self.user1_cards[self.card])[:2])
            cardplayed_user2 = int((self.user2_cards[self.card])[:2])
            if cardplayed_user1 > cardplayed_user2:
                self.user1_win()
            elif cardplayed_user2 > cardplayed_user1:
                self.user2_win()
                # If their Value was equal in value
            elif cardplayed_user1 == cardplayed_user2:
                cardsvalue = ["C","D","S","H"]
                '''Compares index in list to determine magnitude greater than'''
                if cardsvalue.index(str((self.user1_cards[self.card])[-1])) >\
                   cardsvalue.index(str((self.user2_cards[self.card])[-1])):
                    self.user1_win()
                elif cardsvalue.index(str((self.user1_cards[self.card])[-1])) <\
                     cardsvalue.index(str((self.user2_cards[self.card])[-1])):
                    self.user2_win()
                else:
                    # Testing for failures
                    self.user1_cards.remove(self.user1_cards[self.card])
                    self.user2_cards.remove(self.user2_cards[self.card])
                    #print "Riddle: What has 13 hearts but no other organs?"
                    #print "Send a bug report to epeglab@gmail.com "

    '''checks to see which cards being played and who is the winner'''
    def war(self):
        try:
            playing = True
            while playing is True:
                self.play_hand()
                self.shuffle_wins()
                if len(self.user1_cards) == 0 and len(self.user2_cards) == (52)*self.deck_number:
                    playing = False
                elif len(self.user2_cards) == 0 and len(self.user1_cards) == (52)*self.deck_number:
                    playing = False
            '''Prints winner based on cards in hand'''
            if len(self.user2_cards) > len(self.user1_cards):
                print "User 2 is the winner on round number: " + str(self.round_number)
            elif len(self.user2_cards) < len(self.user1_cards):
                print "User 1 is the winner on round number: " + str(self.round_number)
        except:
            print "I knew someone would break it"

wargame()
