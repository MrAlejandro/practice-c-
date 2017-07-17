#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    INCORRECT_STATUS,
    OK,
    NOT_ISOGRAM,
    INCORRECT_LENGTH,
    NOT_ALLOWED_CHARACTERS
};

class FBullCowGame
{
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString);
    
    void Reset();
    FBullCowCount SubmitGuess(FString);

private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bIsGameWon;
};
