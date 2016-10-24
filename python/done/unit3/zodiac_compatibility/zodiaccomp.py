'''
Elston Almeida
Checks Compatibility of users based on their zodiac sign
2016/30/05
ICS 3U1
'''

'''Get Date'''
def birthday_day(identifier):
    verified_input = False
    while verified_input is False:
        try:
            birth_date_input = input("Please enter "+identifier+ " date of birth: ")
            if 0 < birth_date_input <= 31:
                verified_input = True
                return(birth_date_input)
            else:
                print "Please enter a valid date"
        except:
            print "Please enter a valid date"

'''Get Month'''
def birthday_month(identifier):
    verified_input = False
    while verified_input is False:
        try:
            '''Enter info and check if can be converted to int'''
            month_birthday = raw_input ("Please enter the month " +identifier+ " born : ")
            if not month_birthday:
                print "Please enter a month"
            else:
                month_birthday_int = int(month_birthday)
                month_int = [1,2,3,4,5,6,7,8,9,10,11,12]
                if month_birthday_int in month_int:
                    verified_input = True
                    return month_birthday_int
                else:
                    print"Please enter a valid int"
        except ValueError:
            str_birthday = (month_birthday[0]).upper()+(month_birthday[1:]).lower()
            month_str = ["January","Febuary","March","April","May","June","July","August","September","October","November","December"]
            month_acc = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
            #print(str_birthday)
            if str_birthday in month_str:
                int_birthday = month_str.index(str_birthday) + 1
                #print int_birthday
                verified_input = True
                return int_birthday
            elif str_birthday in month_acc:
                int_birthday = month_acc.index(str_birthday) + 1
                verified_input = True
                return int_birthday
            else:
                print "Please enter a valid month"
        except:
            print "Please enter a valid input"

'''Cross check data'''
def zodiac_check(month,day):
    if (month == 1 and day >= 21) or (month == 2 and day <= 16):
        return("Capricon")
    elif (month == 2 and day >= 17) or (month == 3  and day <= 11):
        return("Aquarius")
    elif (month == 3 and day >= 12) or (month == 4 and day <= 18):
        return("Pisces")
    elif (month == 4 and day >= 19) or (month == 5 and day <= 13):
        return("Aries")
    elif (month == 5 and day >= 14) or (month == 6 and day <= 21):
        return("Taurus")
    elif (month == 6 and day >= 22) or (month == 7 and day <= 20):
        return("Gemini")
    elif (month == 7 and day >= 21) or (month == 8 and day <= 10):
        return("Cancer")
    elif (month == 8 and day >= 11) or (month == 9 and day <= 16):
        return("Leo")
    elif (month == 9 and day >= 17) or (month == 10 and day <= 30):
        return("Virgo")
    elif (month == 10 and day >= 31) or (month == 11 and day <= 23):
        return("Libra")
    elif (month == 11 and day >= 24) or (month == 11 and day <= 29):
        return("Scorpio")
    elif (month == 11 and day >= 30) or (month == 12 and day <= 17):
        return("Ophiuchus")
    elif (month == 12 and day >= 18) or (month == 1 and day <= 20):
        return("Sagittarius")

'''Checks compatibility'''
def compatible(person,person_two):
    comp_fire = ["Sagittarius","Aries","Leo","Ophiuchus"]
    comp_earth = ["Capricorn","Virgo","Taurus","Ophiuchus"]
    comp_air = ["Aquarius","Libra","Gemini","Ophiuchus"]
    comp_water = ["Pices","Scorpio","Cancer","Ophiuchus"]
    #Runs through if statements to check compatibility
    if person in comp_fire and person_two in comp_fire:
        print "You are compatible"
    elif person in comp_earth and person_two in comp_earth:
        print "You are compatible"
    elif person in comp_air and person_two in comp_air:
        print "You are compatible"
    elif person in comp_water and person_two in comp_water:
        print "You are compatible"
    else:
        print "You are not compatible"

if __name__ == "__main__":
    running = True
    while running is True:
        '''Set variables to compare, by getting user input'''
        user1_month = birthday_month("you were")
        user1_day = birthday_day("you")
        check_new = True
        while check_new is True:
            
            user2_month = birthday_month("your partner")
            user2_day = birthday_day("their")
            
            '''Sets Variables for Function Later'''
            compatibility_user =  zodiac_check(user1_month,user1_day)
            compatibility_partner = zodiac_check(user2_month,user2_day)
            
            '''Runs to check compatibilty'''
            compatible(compatibility_user,compatibility_partner)
            
            run_again = raw_input("Do you want to check compatibily again with another person?\n(y/N) : ")
            
            if run_again in ("y","yes","Y","YES","Dam straight I'm pissed, I'm not compatible"):
                print "Hope tis the one for you this time"
            else:
                check_new = False
                running = False
                
