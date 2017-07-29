#pragma once

#include <iostream>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
void PringGameSummary();

FBullCowGame BCGame;

int main()
{
    PrintIntro();
    
    do {
        BCGame.Reset();
        PlayGame();
    } while (AskToPlayAgain());
    
    return 0;
}

void PrintIntro()
{
    int32 WorldLength = BCGame.GetHiddenWordLength();
    
    std::cout << "\033[0;31mWelcome to the Bulls and Cows game\033[0m" << std::endl;
    std::cout << "Can you guess the " << WorldLength;
    std::cout << " letter isogram I'm thinking of?";
    std::cout << std::endl;
    
    return;
}

FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::INCORRECT_STATUS;
    FText Guess = "";

    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << std::endl;
        std::cout << "Try " << CurrentTry << ". Enter your guess: ";

        getline(std::cin, Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch (Status) {
            case EGuessStatus::INCORRECT_LENGTH:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letters length word" << std::endl;
                break;
            case EGuessStatus::NOT_ALLOWED_CHARACTERS:
                std::cout << "Please enter a lower case letters word without whitespaces" << std::endl;
                break;
            case EGuessStatus::NOT_ISOGRAM:
                std::cout << "Please enter a word without repeating letters" << std::endl;
                break;
        }
        
    } while (Status != EGuessStatus::OK);
    
    return Guess;
}

void PlayGame()
{
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries;
    FText Guess = "";
    
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        Guess = GetValidGuess();
        
        std::cout << "The try # " << BCGame.GetCurrentTry() << " out of " << MaxTries << std::endl;

        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        std::cout << "Bulls: " << BullCowCount.Bulls;
        std::cout << " Cows: " << BullCowCount.Cows;
        std::cout << std::endl;
    }
    
    PringGameSummary();
    
    return;
}

bool AskToPlayAgain()
{
    std::cout << std::endl << "Would you like to play again? (y/n): ";
    
    FText Response = "";
    getline(std::cin, Response);
    
    return Response[0] == 'y' || Response[0] == 'Y';
}

void PringGameSummary()
{
    if (BCGame.IsGameWon()) {
        std::cout << "Congratulations you have won!";
    } else {
        std::cout << "Sorry you've lost :(((";
    }
    
    std::cout << std::endl;
    
    return;
}

