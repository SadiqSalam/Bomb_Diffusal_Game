# ENGG1340_BombDiffuserGame
Group No.: 19

Group members:
Na-siam Sa-nguannam (UID: 3035979406)
Wang Zihan (UID: 3036094540)
Sadiq Salam (UID: 3036087200)
Lakindu (UID: 3036094631)
 
Topic: Bomb Diffuser Game 

*** inspired by "Keep Talking and Nobody Explodes" developed by Canadian studio Steel Crate Games ***


Description:

This is a racing puzzle game about defusing a bomb based on several small puzzle modules, 
including a symbol combination game, a word-finding game, a wire-cutting game, and a memory puzzle game. 

All four games have sophisticated instructions. Players need to follow the instructions to defuse the bomb as soon as possible.
Time for you is limited, only 180 seconds. Besides, you lose 5 seconds for every wrong try, and the number of potential answers
combinations is 6739. Do NOT try to use BRUTE FORCE ATTACK to defuse the bomb, it will only QUICKEN YOUR DEATH.

The less time you use, the higher the final score you get. Each of the puzzle games is randomly composited for every start, 
so you need to be careful about the new situation that you never met.

Compilation and Execution instruction:

$ make game
$ ./game

↓↓↓USE THE INSTRUCTION BELOW ↓↓↓

Game Rules:
180seconds, 5seconds deducted after each incorrect input
![image](https://github.com/PorpanTH/ENGG1340_BombDiffuserGame/blob/main/instru_image/ENGG1340%20Project%20PDF%20Clue_page-0001.jpg)
![image](https://github.com/PorpanTH/ENGG1340_BombDiffuserGame/blob/main/instru_image/ENGG1340%20Project%20PDF%20Clue_page-0002.jpg)
![image](https://github.com/PorpanTH/ENGG1340_BombDiffuserGame/blob/main/instru_image/ENGG1340%20Project%20PDF%20Clue_page-0003.jpg)
![image](https://github.com/PorpanTH/ENGG1340_BombDiffuserGame/blob/main/instru_image/ENGG1340%20Project%20PDF%20Clue_page-0004.jpg)
![image](https://github.com/PorpanTH/ENGG1340_BombDiffuserGame/blob/main/instru_image/ENGG1340%20Project%20PDF%20Clue_page-0005.jpg)
Features Implemented:
1.	**Multiple puzzle modules**: The game includes four different puzzle modules, each with its own set of instructions and rules.
2.	**Randomization**: Each time the game is played, the puzzle modules are randomly composited in a new way, 
    which adds an element of unpredictability and increases replayability.
3. **File input/output**: Players' names and scores are saved into save.txt for ranking. Player can use Makefile to clean the data.
4.	**Time limit**: The game has a time limit of 120 seconds, which adds an element of urgency and encourages players to solve 
    the puzzles as quickly and efficiently as possible.
5.	**Penalty for incorrect guesses**: Incorrect guesses result in a penalty of 5 seconds, 
    which incentivizes players to carefully consider their options before making a guess.
6.	**Scoring system**: The game includes a scoring system that awards points based on
    how quickly and accurately the puzzles are solved.
7.	**Challenging gameplay**: The game is designed to be challenging and engaging, requiring players to use 
    critical thinking, logic, and problem-solving skills to defuse the bomb before time runs out.

