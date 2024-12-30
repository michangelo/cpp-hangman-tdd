#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "assignment.cpp"

TEST_CASE("Test getHangmanString")
{
    CHECK( getHangmanString(0) == "\n" );
    CHECK( getHangmanString(1) == "  _\n / \\\n \\ /\n  |\n" );
    CHECK( getHangmanString(2) == "  _\n / \\\n \\ /\n  |\n  |\n  |\n" );
    CHECK( getHangmanString(3) == "  _\n / \\\n \\ /\n  |\n/-|\n  |\n" );
    CHECK( getHangmanString(4) == "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n" );
    CHECK( getHangmanString(5) == "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n /\n" );
    CHECK( getHangmanString(6) == "  _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n / \\\n" );
}

TEST_CASE("Test generateRandomWord")
{
    CHECK( generateRandomWord(2) == "test5" );
    CHECK( generateRandomWord(5) == "test2" );
    CHECK( generateRandomWord(1000) == "test4" );
    CHECK( generateRandomWord(2213) == "test6" );
}

TEST_CASE("Test repeat guesses")
{
    // Enter your input here. <Enter> key is implied after every letter since we use char datatype.
    std::istringstream input{"test2"};
    std::ostringstream output;

    // Pass streams to function to test
    runGame(input, output, 1);

    // Compare output as if it came to std::cout here with output.str()
    CHECK(output.str() == "\nAttempt: _ _ _ _ _ \nDead letters: \nGuess a letter: \nAttempt: t _ _ t _ \nDead letters: \nGuess a letter: \nAttempt: t e _ t _ \nDead letters: \nGuess a letter: \nAttempt: t e s t _ \nDead letters: \nGuess a letter: \nAttempt: t e s t _ \nDead letters: \nGuess a letter: You win!\nSolution: test2\n");
}

TEST_CASE("Test Lose text")
{
    // Enter your input here. <Enter> key is implied after every letter since we use char datatype.
    std::istringstream input{"a b c d e f"};
    std::ostringstream output;

    // Pass streams to function to test
    runGame(input, output, 1);
    CHECK( output.str() == "\nAttempt: _ _ _ _ _ \nDead letters: \nGuess a letter:   _\n / \\\n \\ /\n  |\nAttempt: _ _ _ _ _ \nDead letters: a \nGuess a letter:   _\n / \\\n \\ /\n  |\n  |\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ e _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n /\nAttempt: _ e _ _ _ \nDead letters: a b c d f \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\n / \\\nYou lose!\nSolution: test2\n" );
}

TEST_CASE("Test Win text")
{
    // Enter your input here. <Enter> key is implied after every letter since we use char datatype.
    std::istringstream input{"abcdets2"};
    std::ostringstream output;

    // Pass streams to function to test
    runGame(input, output, 1);
    CHECK( output.str() == "\nAttempt: _ _ _ _ _ \nDead letters: \nGuess a letter:   _\n / \\\n \\ /\n  |\nAttempt: _ _ _ _ _ \nDead letters: a \nGuess a letter:   _\n / \\\n \\ /\n  |\n  |\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ e _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: t e _ t _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: t e s t _ \nDead letters: a b c d \nGuess a letter: You win!\nSolution: test2\n" );
}

TEST_CASE("Test display dead letters")
{
    // Enter your input here. <Enter> key is implied after every letter since we use char datatype.
    std::istringstream input{"abcdets2"};
    std::ostringstream output;
    // Pass streams to function to test
    runGame(input, output, 1);
    CHECK( output.str() == "\nAttempt: _ _ _ _ _ \nDead letters: \nGuess a letter:   _\n / \\\n \\ /\n  |\nAttempt: _ _ _ _ _ \nDead letters: a \nGuess a letter:   _\n / \\\n \\ /\n  |\n  |\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ _ _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: _ e _ _ _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: t e _ t _ \nDead letters: a b c d \nGuess a letter:   _\n / \\\n \\ /\n  |\n/-|-\\\n  |\nAttempt: t e s t _ \nDead letters: a b c d \nGuess a letter: You win!\nSolution: test2\n" );
}
