#include <iostream>
#include "FBullCowGame.hpp"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;


int main()
{
    PrintIntro();
    
    do {
        PlayGame();
    } while (AskToPlayAgain());
    
    return 0;
}

void PrintIntro()
{
    constexpr int WORD_LENGTH = 5;
    
    std::cout << "\033[0;31mWelcome to the Bulls and Cows game\033[0m" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    
    return;
}

std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";

    std::string Guess = "";
    getline(std::cin, Guess);
    
    return Guess;
}

void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();
    std::string Guess = "";
    
    for (int i = 1; i <= MaxTries; i++) {
        Guess = GetGuess();
        
        // Print the guess back to the user
        std::cout << "You have entered: " << Guess << std::endl;
        std::cout << std::endl;
    }
    
    return;
}

bool AskToPlayAgain()
{
    std::cout << std::endl << "Would you like to play again? (y/n): ";
    
    std::string Response = "";
    getline(std::cin, Response);
    
    return Response[0] == 'y' || Response[0] == 'Y';
}
