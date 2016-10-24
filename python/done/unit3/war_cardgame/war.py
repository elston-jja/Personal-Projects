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
        self.total = ["2 H", "3 H", "4 H", "5 H", "6 H", "7 H", "8 H", "9 H", "10 H", "11 H", "12 H", "13 H", "14 H",\
                      "2 S", "3 S", "4 S", "5 S", "6 S", "7 S", "8 S", "9 S", "10 S", "11 S", "12 S", "13 S", "14 S",\
                      "2 D", "3 D", "4 D", "5 D", "6 D", "7 D", "8 D", "9 D", "10 D", "11 D", "12 D", "13 D", "14 D",\
                      "2 C", "3 C", "4 C", "5 C", "6 C", "7 C", "8 C", "9 C", "10 C", "11 C", "12 C", "13 C", "14 C"]
        self.user1_cards = []
        self.user2_cards = []
        self.user1_winnings = []
        self.user2_winnings = []
        self.card = 0
        self.round_number = 0
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
                    print "Riddle: What has 13 hearts but no other organs?"
                    print "Send a bug report to epeglab@gmail.com "

    '''checks to see which cards being played and who is the winner'''
    def war(self):
        try:
            playing = True
            while playing is True:
                self.play_hand()
                self.shuffle_wins()
                if len(self.user1_cards) == 0 and len(self.user2_cards) == 52:
                    playing = False
                elif len(self.user2_cards) == 0 and len(self.user1_cards) == 52:
                    playing = False
            '''Prints winner based on cards in hand'''
            if len(self.user2_cards) > len(self.user1_cards):
                print "User 2 is the winner"
            elif len(self.user2_cards) < len(self.user1_cards):
                print "User 1 is the winner"
        except:
            print "I knew someone would break it"

wargame()
