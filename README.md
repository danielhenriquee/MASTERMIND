# MASTERMIND
Project for Algorithms and Programming I - 2023/1

This is a terminal-based game developed in C++ as a programming assignment during the first semester of Computer Engineering program. 
The game is inspired by the classic Mastermind game, where the player must guess a secret 4-digit combination using logic and feedback provided by the program after each attempt.

It was created to apply fundamental concepts of programming such as:
- Flow control (loops, conditionals, switch)
- Integer manipulation (digit extraction and validation)
- Random number generation with rand()
- Code structure with do-while and switch
- User input validation and handling
- Logical deduction algorithms for comparing guesses
  
Development Environment:
- Language: C++
- Compiler: g++
- Platform: replit.com – chosen for its collaborative coding features, real-time editing, and ease of access from both university and personal computers.
- Compatible with: Linux, macOS, Windows (UTF-8 support required)

Features:
- Random generation of a 4-digit secret code
- Only digits from 1 to 6 allowed, no repeated digits
- Up to 10 attempts to guess the correct combination
- Feedback after each guess:
  - Digits correct and in the correct position
  - Digits correct but in the wrong position
- Input validation with friendly error messages
- Move counter and win/loss detection
- Simple text-based UI
- Cross-platform compatibility

NOTE: To properly display the game's interface, your terminal must support UTF-8 encoding. 
If you're on Windows, consider using a UTF-8–capable terminal or enabling UTF-8 with 'chcp 65001'.
