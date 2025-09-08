# A Text-Based Role-Playing Game
Contributors: [Wesley Wu](https://github.com/xxiyun), [Yubin Zhen](https://github.com/yubinzhen)

## Project Description

In this game, the user battles wild Pokémon using their own Pokémon, which they can catch and add to their team. Each Pokémon has unique types, abilities, and stats that scale with level. Players navigate through different game screens, make strategic choices, and aim to level up and eventually catch all Pokémon in the game.

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
Input: User interacts via numeric keyboard entries to select actions like attacking, using items, or catching Pokémon.

Output: Updates the Pokémon stats, battle results, and menu states in the terminal.


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

1. Git clone the repo, ex:
```bash
git clone https://github.com/ActualCookie88/Pokemon_Battle.git
```

2. Make sure a C++ compiler is installed (MinGW, MSVC, etc.)

3. Navigate to the build directory:
```bash
cd build
```

4. Build the project (if not using prebuilt executable):
```bash
cmake ..
make
```

5. Run the game:
```bash
./Pokemon_Battle.exe
```

 ## GitHub Release
The precompiled .exe is available in the Releases section for convenience. This allows users to play without compiling the source code.
 
 ## Testing
Unit tests are implemented for all major functions.

Valgrind was used to check memory allocation and ensure there are no leaks.
 
