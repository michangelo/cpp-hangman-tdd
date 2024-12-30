# C++ Exercise - Hangman TDD

## TDD

Test Driven Development (TDD) is a software development practice that focuses on understanding the software requirements before writing the relevant code. It also emphasizes writing tests, specifically unit tests which are important for any software project, particularly larger software systems with multiple contributors that will be used by end-users that expect it to satisfy certain requirments.

The process for employing TDD is as follows:

1. Write a test based on requirements for the project feature. The actual coding implementation of this feature should not be implemented yet. The test should pass if, and only if, the new feature is implemented correctly.
2. Ensure that the test fails, since the feature does not exist yet. This ensures the test is not flawed to always pass.
3. Write the simplest code to pass the test. Rough code is acceptable for now as long as the requirements are satisfied.
4. Re-run all tests to ensure they all pass.
5. Refactor and clean up code to ensure code is maintainable and readable still. Ensure all tests still pass after this step.
6. Repeat this process with the next feature!

This technique is used to fix bugs, not just add new features. Treat a bug fix as if it is addding a new feature, that feature just happens to restore the program to its expected behavior.

![TDD Flow](./TDD.svg)

## Unit testing

We will be utilizing unit testing to implement TDD in this assignment. Unit testing is a method of software testing where individual 'units' of source code are tested to ensure they satisfy project requirements. Units are loosely defined as "sets of one or more computer program modules together with associated control data, usage procedures, and operating procedures". When unit testing, you should always try to test the smallest functional piece of code you can, breaking the requirements into as many meaningful units as possible.

Unit testing is one of the most popular testing methods implemented directly by the development team because its relatively easy to tie into existing source code and is beneficial towards detecting bugs early in the development cycle. Unit tests also serve as 'living documentation' of a system, as all of the project specifications should be laid out in code through the unit tests, and must remain up to date to ensure all of the tests pass.

## Doctest

Before starting this assignment you must include the unit testing framework header file. We will be using the [C++ Doctest Library](https://github.com/doctest/doctest). It should already be present in your repo and included in the skeleton tests file. Do not delete it!

In this directory you will need:

1. `doctest.h` library file
2. `assignment.cpp` This file will contain the code you will be testing. This runs the hangman game.
3. `assignment-unittests.cpp` This file will contain the unit tests you must write for the hangman game.

Your `assignment-unittests.cpp` file should begin with:

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "hangman.cpp" // Insert name of your code file here
```

This will configure this file to run the Doctest Test cases.

**NOTE**: Your code file should have its `main()` function commented out when running tests, as this file creates its own main. Simply uncomment the hangman `main()` function when you'd like to run the game in your console instead of test it.

Tests are written as follows:

```cpp
TEST_CASE("Basic test"){
    CHECK(1 + 1 == 2);
}
```

Test cases can have any name and any number of 'CHECKS' inside of them. Checks use basic C++ comparisons and also support more complex assertions. More information can be found in the [C++ Doctest Library Documentation](https://github.com/doctest/doctest).

## Directions

Your assignment is to write unit tests to test the provided (incomplete) hangman game.

You can find the starter code in `assignment.cpp`.

### Objective

Your objective is to fix 2 bugs and add 3 features by employing TDD.

1. Bug in `getHangmanString`
2. Bug in `generateRandomWord`
3. Feature in `runGame` to allow multiple guesses.
4. Feature in `runGame` to display all letters already used ("Dead Letters").
5. Feature in `runGame` to display Win/Lose text when the end of the game is reached.

**You should have _at least_ 5 successful unit tests and a functional complete hangman game upon completion of this assignment**

Ensure you write the unit test _before_ implementing the feature or bug fix.

### Testing

In order to play this game it will use `std::cin` and `std::cout` like you are familiar with, but in order to test we will use input streams. You will notice the `runGame` function accepts a `std::istream &input` and a `std::ostream &output`. When playing the game these are `std::cin` and `std::cout` respectively.

When testing you should create custom `std::istringstream` and `std::istringstream` and pass those instead.
Here is an example

```cpp
TEST_CASE("Test using streams"){
    // Enter your input here. <Enter> key is implied after every letter since we use char datatype.
    std::istringstream input{"GUESS"};
    std::ostringstream output;

    // Pass streams to function to test
    runGame(input, output, 1);

    // Compare output as if it came to std::cout here with output.str()
    CHECK(output.str() == "EXPECTED OUTPUT");
}
```

**NOTE: Ensure everywhere in `runGame()` uses `input` and `output` _NOT_ `std::cin` and `std::cout` since the unit tests will not test this behavior.**

### Example output

```txt

Attempt: _ _ _ _ _
Dead letters:
Guess a letter: a
  _
 / \
 \ /
  |
Attempt: _ _ _ _ _
Dead letters: a
Guess a letter: t
  _
 / \
 \ /
  |
Attempt: t _ _ t _
Dead letters: a
Guess a letter: b
  _
 / \
 \ /
  |
  |
  |
Attempt: t _ _ t _
Dead letters: a b
Guess a letter: e
  _
 / \
 \ /
  |
  |
  |
Attempt: t e _ t _
Dead letters: a b
Guess a letter: c
  _
 / \
 \ /
  |
/-|
  |
Attempt: t e _ t _
Dead letters: a b c
Guess a letter: s
  _
 / \
 \ /
  |
/-|
  |
Attempt: t e s t _
Dead letters: a b c
Guess a letter: d
  _
 / \
 \ /
  |
/-|-\
  |
Attempt: t e s t _
Dead letters: a b c d
Guess a letter: g
  _
 / \
 \ /
  |
/-|-\
  |
 /
Attempt: t e s t _
Dead letters: a b c d g
Guess a letter: 2
You win!
Solution: test2
```

## Autograding

### Files

You **_MUST NOT:_** **DELETE** or **RENAME** `assignment.cpp`, `autograder.gpg`, or `assignment-unittests.cpp`.

You **_MUST_**: remove or comment out the `main()` function from your submission before submitting or the autograder will not work!

Executing `assignment-unittests.cpp` should satisfy the requirements above. You are allowed to add as many other `.cpp`, `.h`, or subdirectories you need to organize your solution, but these filenames should remain unchanged in the project root. Ensure you edit `assignment.cpp` with your solution.

Additionally, `.devcontainer`, `.gitignore`, and `README.md` can be edited at your own risk, but they are not required to be edited to complete the assignment. Focus on adding your own implementation to `assignment.cpp` and `assignment-unittests.cpp`.

### Github Testing

When you commit any changes Github Classroom will autograde your submission, but you will not be able to view any of the reasons you fail a test. Github will tell you when you have passed all tests successfully.

_Therefore, you are responsible to thoroughly test your assignment and consider all edge cases_

## Repo Setup

### Option 1: Github Codespaces

This will allow you to work on this assignment remotely from the web in the cloud using Github Codespaces.

1. Click the green "Code" button in the top right of the repo
2. Click the "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the codespace to be created

You can now edit the code in the browser.

You can "commit" your code by opening a terminal and running:

```bash
git add .
git commit -m "My commit message"
git push
```

This will save your code to GitHub so you can access it later. And also will submit it for **autograding**.

### Option 2: VS Code Dev Container

If you have _VS Code_ and _Docker_ installed ([see getting started steps](https://aka.ms/vscode-remote/containers/getting-started)), you can follow these steps:

1. Clone the repo to your computer using [HTTPS](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories#cloning-with-https-urls) or [SSH](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories#cloning-with-ssh-urls).
2. Open VS Code
3. Press `F1` and select the **Dev Containers: Open Folder in Container...** command.
4. Select the cloned copy of this folder, wait for the container to start, and try things out!

### Option 3: Local Development Environment

1. Clone the repo to your computer using [HTTPS](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories#cloning-with-https-urls) or [SSH](https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories#cloning-with-ssh-urls).
2. Open the repo in your favorite editor/IDE.
3. If you haven't already, install a compiler. See `Chapter 0` of [LearnCPP](https://www.learncpp.com/).
4. Edit, compile, run, and test your code.
5. You can "commit" your code by opening a terminal and running:

```bash
git add .
git commit -m "My commit message"
git push
```

This will save your code to GitHub so you can access it later. And also will submit it for **autograding**.

## Compiling

Compiling is covered in depth in [Learncpp Chapter 0.7](https://www.learncpp.com/cpp-tutorial/compiling-your-first-program/), but a brief example for **Linux** is as follows:

### Install

```console
$ sudo apt install g++
```

### Compile

```console
$ g++ -o assignment assignment.cpp
```

### Execute

```console
$ ./assignment
```
