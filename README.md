# A Text-Based Role-Playing Game
Co-Authors: [Wesley Wu](https://github.com/xxiyun), [Yubin Zhen](https://github.com/yubinzhen)

## Project Description

In this game, the user uses their Pokemon to fight and catch other wild Pokemon, which the user can also use if successfully caught. Pokemon are associated with different types of types and abilities, and their stats depend on their level. At each step/screen of the game, the user can select between different options. The goal of the user is to continually level up their Pokemon through battles with CPUs and eventually catch every Pokemon in this game. 

### Language and Tools:
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/VSCode-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white)
![GDB](https://img.shields.io/badge/GDB-900C3F?style=for-the-badge&logo=gnu&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-6C3483?style=for-the-badge&logo=valgrind&logoColor=white)
### Version Control & Collaboration
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/GitHub_Actions-2088FF?style=for-the-badge&logo=github-actions&logoColor=white)


### Input/Outputs:
Input: All input comes from the user's keyboard in the form of numbers, which determines certain actions such as selecting options during a battle or deciding on an item to purchase.\

Output: The output includes updating and displaying the user and CPU Pokemon’s statuses and the result of a certain action of the user.

### Features:
Battle wild Pokémon using owned Pokémon

Player actions: attack, heal, catch, etc.

Distinct health, attack, and type stats for each Pokémon

Leveling, experience, and in-game currency system

Shop system to buy/use items

Ability to catch and add new Pokémon to team

Wild Pokémon difficulty scales with player progress

Randomized enemy actions

Save and load game progress

## User Navigation Diagram

![UI Navigation Diagram (2)](https://github.com/user-attachments/assets/2a2a3c0d-61b4-437e-95d1-6f6e06da0a94)


### Screen Layouts

![Main Screen](assets/ss1.png)
![Menu](assets/ss2.png)
![Inventory](assets/ss3.png)
![PC](assets/ss4.png)
![Items](assets/ss5.png)
![Store](assets/ss6.png)
![Battle Menu](assets/ss7.png)
![Moves](assets/ss8.png)
![Lose Screen](assets/ss9.png)
![Team](assets/ss10.png)


 ## Installation/Usage

Git clone the repo

Make sure you have a C++ compiler installed, such as MinGW or MSVC

Navigate to the build directory ( cd build )

Run the executable in the terminal
```bash
./Pokemon_Battle.exe
```
 
 ## Testing
To test our program, we made unit tests for each function to make sure all our functions worked correctly. We also used valgrind to check for memory allocation.
 
