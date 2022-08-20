import re
import string
from collections import Counter

# Function that counts the frequency of and sorts(alphebetically) every line in a file
def PrintAllItemFrequencies(fileName):
    txtFile = open(fileName) #opens fileName and sets it to a variable
    dailySalesList = {} #creates a blank dictionary

    print() # prints a blank line for aesthetic reasons

    for tempKey in txtFile: # for loop that reads each line and sets it to the dictionary keys
        if tempKey.strip('\n') in dailySalesList: # checks if the current line is already in the dictionary. Strip newline so it'll print properly
            dailySalesList[tempKey.strip('\n')] += 1 # increments existing keys
        else: # runs if tempKey is not already in the dicitonary
            dailySalesList[tempKey.strip('\n')] = 1 # initializes the key with a value of 1

    txtFile.close() # closes the file

    for tempKey, tempValue in sorted(dailySalesList.items()): #for loop that iterates through the dictionary and prints its contents
        print("{0: >17}: {1}".format(tempKey, tempValue)) # prints current key's key to the right of a 17 space field, then the key's value

    return 100;  # returns 100

# Function that counts the frequency of lines in a file and returns the quantity of a specific line
# Uses a parameter format such as: fileName%searchTerm, to be split in the program.
# EXAMPLE:
#     SingleItemFrequency(helloWorld.txt%World)
#       fileName = helloWorld.txt%
#       searchTerm = World
def SingleItemFrequency(fileNameAndSearchTerm):
    tempHolderList = fileNameAndSearchTerm.split('%') # creates a list with 2 elements, splitting the string at the %
    fileName = tempHolderList[0] # declares fileName and sets it to the first element of tempHolderList
    searchTerm = tempHolderList[1] # declares searchTerm and sets it to the second element of tempHolderList

    txtFile = open(fileName.strip('%')) # opens a the file (minus the %) and stores it as txtFile
    dailySalesList = {} # declares an empty dictionary

    for tempKey in txtFile: # for loop that counts lines of txtFile
        if tempKey.strip('\n') in dailySalesList: # checks if the current line is already in the dictionary. Strip newline so it'll print properly
            dailySalesList[tempKey.strip('\n')] += 1 # increments existing keys
        else: # runs if tempKey is not already in the dicitonary
            dailySalesList[tempKey.strip('\n')] = 1 # initializes the key with a value of 1

    txtFile.close() # closes the file

    if searchTerm in dailySalesList: # if statment that looks through dailySalesList's keys for searchTerm
        return dailySalesList[searchTerm]; # returns the value for searchTerm is the key is found
    else:
        return 0; # returns 0 if the searchTerm is not found as a key

# Function that iterates through and counts frequency of the lines of a file and saves it as a .dat file titled frequency.dat
def CreateFrequencyDat(fileName):
    txtFile = open(fileName) # opens fileName as txtFile
    dailySalesList = {} # declares a blank dicitonary

    for tempKey in txtFile: # for loop that counts lines of txtFile
        if tempKey.strip('\n') in dailySalesList: # checks if the current line is already in the dictionary. Strip newline so it'll print properly
            dailySalesList[tempKey.strip('\n')] += 1 # increments existing keys
        else: # runs if tempKey is not already in the dicitonary
            dailySalesList[tempKey.strip('\n')] = 1 # initializes the key with a value of 1
            
    txtFile.close() # closes file

    newFile = open('frequency.dat', 'w') # declares newFile, and creates or overwrites frequency.dat

    for tempKey in sorted(dailySalesList): # iterates through the dictionary dailySalesList
        newFile.write('{} {}\n'.format(tempKey.strip('\n'), dailySalesList[tempKey])) # writes each key/value pair as item quantity newline such as: Potato 5\n

    newFile.close() # closes the file

    return 0;




    
