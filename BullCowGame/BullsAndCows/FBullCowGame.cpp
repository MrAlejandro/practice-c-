#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {
    return bIsGameWon;
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 2;
    const FString HIDDEN_WORD = "slope";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bIsGameWon = false;
    
    return;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
    if (false) {
        return EGuessStatus::NOT_ISOGRAM;
    } else if (false) {
        return EGuessStatus::NOT_ALLOWED_CHARACTERS;
    } else if (GetHiddenWordLength() != Guess.length()) {
        return EGuessStatus::INCORRECT_LENGTH;
    } else {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment try number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    int32 HiddenWordLength = GetHiddenWordLength();
    
    for (int32 i = 0; i < HiddenWordLength; i++) {
        
        for (int32 j = 0; j < HiddenWordLength; j++) {
            if (MyHiddenWord[i] == Guess[j]) {
                if (i == j) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    if (BullCowCount.Bulls == HiddenWordLength) {
        bIsGameWon = true;
    } else {
        bIsGameWon = false;
    }
    
    return BullCowCount;
}
