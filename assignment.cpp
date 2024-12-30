#define ASSIGNMENT2_CPP
#include <string>
#include <vector>
#include <iostream>
#include <time.h> 
#include <sstream>

// returns hangman string representing current game 'stage'
// 'stage' refers to how many incorrect guesses have occurred.
int stage = 1; // holds the game stage
std::string getHangmanString(int stage){
    std::string result;
    switch (stage){
    case 0:
        // empty hangman
        result = "\n";
        break;
    case 1:
        // hangman head
        result = "  _\n / \\\n \\ /\n  |\n";
        break;
    case 2:
        // hangman head and body
        result = "  _\n / \\\n \\ /\n  |\n  |\n  |\n";
        break;
    case 3:
        // hangman head, body, left arm
        result = "  _\n / \\\n \\ /\n  |\n/-|\n  |\n";
        break;
    case 4:
        // hangman head, body, left arm, right arm
        result = "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n";
        break;
    case 5:
        // hangman head, body, left arm, right arm, left leg
        result = "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n /\n";
        break; // added break
    case 6:
        // hangman head, body, left arm, right arm, left leg, and right leg
        // completed 'dead' hangman
        result = "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n / \\\n";
        break;
    default:
        result = "\n";
        break;
    }
    return result;
}

// generates and returns a random word from the 'wordlist' using 'seed' to set the pseudo RNG.
std::string generateRandomWord(int seed){
    srand(seed);
    const std::vector<std::string> wordlist{ "test","test2","test3","test4","test5","test6","test7" };
    int n = rand() % wordlist.size();
    return wordlist.at(n); 
}

// pass input and output streams here for testing or cin/cout for playing
void runGame(std::istream &input, std::ostream &output, int seed=-1){
    // if seed left as default ensure each game is a different random word
    if (seed == -1)
        seed = time(0);
    std::string answer {generateRandomWord(seed)};

    // fill attempt with blank guesses the same size as the correct answer
    std::vector<char> attempt(answer.size());
    std::fill(attempt.begin(), attempt.end(), '_');

    // set variables for game
    char guess; // current players guess
    bool deadLetter; // flags if current guess was a dead letter
    std::vector<char> deadLetters; // collection of all dead letters so far
    bool running = true; // repeat game if running is true

    // loop through to allow multiple guesses
    while (running){
        // display current hangman and attempt
        output << getHangmanString(deadLetters.size());
        output << "Attempt: ";
        
        // display current dead letters
        for(char c: attempt)
            output << c << " ";
        output << "\nDead letters: ";

        // display current guess
        for(char d: deadLetters)
            output << d << " ";
        output << "\nGuess a letter: ";
        input >> guess;

        // detect if game over, or letter is dead
        deadLetter = true;
        running = false;
        for(int i = 0; i < 6; i++){
            if(answer[i] == guess){
                attempt[i] = guess;
                deadLetter = false;
            } 
            if(attempt[i] == '_')
                running = true;
        }
        if(deadLetter){
            deadLetters.push_back(guess);
        }
        // display full hangman if game lost and lose text 
        if(deadLetters.size() == 6){
            output << getHangmanString(6);
            output << "You lose!\n";
            running = false;
        }
    }
    // display win text
    if(deadLetters.size() != 6){
        output << "You win!\n";
        running = false;
    }
    // display solution after win or lose
    output << "Solution: " << answer << std::endl;
}

//MUST COMMENT OUT MAIN TO RUN TESTS FILE!
// int main()
// {
//     runGame(std::cin, std::cout);
//     return 0;
// }
