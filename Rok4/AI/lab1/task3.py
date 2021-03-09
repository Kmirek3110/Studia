import random
from collections import defaultdict


suites = ["S", "C", "D", "H"]
figurants_figures = ["A", "K", "Q", "J"]
card_order_dict = {"2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "T":10,"J":11, "Q":12, "K":13, "A":14}

def check_flush(hand):
    suits = [h[1] for h in hand]
    if len(set(suits)) == 1:
      return True
    else:
      return False

def check_straight(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v] += 1
    rank_values = [card_order_dict[i] for i in values]
    value_range = max(rank_values) - min(rank_values)
    if len(set(value_counts.values())) == 1 and (value_range==4):
        return True
    return False

def check_straight_flush(hand):
    if check_flush(hand) and check_straight(hand):
        return True
    else:
        return False

def check_four_of_a_kind(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v]+=1
    if sorted(value_counts.values()) == [1,4]:
        return True
    return False

def check_full_house(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v]+=1
    if sorted(value_counts.values()) == [2,3]:
        return True
    return False


def check_three_of_a_kind(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v]+=1
    if set(value_counts.values()) == set([3,1,1]):
        return True
    else:
        return False

def check_two_pairs(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v]+=1
    if sorted(value_counts.values())==[1,2,2]:
        return True
    else:
        return False

def check_one_pairs(hand):
    values = [i[0] for i in hand]
    value_counts = defaultdict(lambda:0)
    for v in values:
        value_counts[v]+=1
    if 2 in value_counts.values():
        return True
    else:
        return False 

def eval(hand):
    if check_straight_flush(hand):
        return 9
    if check_four_of_a_kind(hand):
        return 8
    if check_full_house(hand):
        return 7
    if check_flush(hand):
        return 6
    if check_straight(hand):
        return 5
    if check_three_of_a_kind(hand):
        return 4
    if check_two_pairs(hand):
        return 3
    if check_one_pairs(hand):
        return 2
    return 1



def figurant_draw_cards():
    hand = []
    needed = 5
    while True:
        suite = random.choice(suites)
        figure = random.choice(figurants_figures)
        if figure+suite not in hand:
            hand.append(figure+suite)
            needed -= 1
        if needed == 0:
            break
    val = eval(hand)
    return val

def blotkarz_draw_cards(numbers, colors):
    hand = []
    needed = 5
    while True:
        number = random.choice(numbers)
        color = random.choice(colors)
        if number+color not in hand:
            hand.append(number+color)
            needed -=1 
        if needed == 0:
            break
    val = eval(hand)
    return val


number_of_games = 100000

counters = [0 for _ in range(5)]
for _ in range(number_of_games):
    f_pow = figurant_draw_cards()
    b_pow = blotkarz_draw_cards(["2", "3", "4", "5", "6", "7", "8", "9", "T"], ["S", "C", "D", "H"])
    b1_pow = blotkarz_draw_cards(["2", "3", "4", "5", "6", "7", "8", "9", "T"], ["S", "C"])
    b2_pow = blotkarz_draw_cards(["7", "8", "9", "T"], ["S", "C", "D", "H"])
    b3_pow = blotkarz_draw_cards(["2", "3", "4", "5", "6"], ["S", "C", "D"])
    b4_pow = blotkarz_draw_cards([ "3", "4", "5", "6", "7", "8", "9", "T"], ["S", "C"])
    if f_pow > b_pow:
        counters[0] += 1
    if f_pow > b1_pow:
        counters[1] += 1
    if f_pow > b2_pow:
        counters[2] += 1
    if f_pow > b3_pow:
        counters[3] += 1
    if f_pow > b4_pow:
        counters[4] += 1


print(counters[0]/number_of_games)
print(counters[1]/number_of_games)
print(counters[2]/number_of_games)
print(counters[3]/number_of_games)
print(counters[4]/number_of_games)









# def blotkarz_draw_cards(choices):





