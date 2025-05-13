set(CMAKE_VERBOSE_MAKEFILE OFF)

cmake_minimum_required(VERSION 3.10)
project(Pokemon_Battle)

# Common sources for player-related tests
set(COMMON_PLAYER_SOURCES
    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp
    src/Display.cpp
    src/items/Item.cpp
    src/items/Pokeballs/Pokeball.cpp
    src/items/Pokeballs/StandardBall.cpp
    src/items/Pokeballs/GreatBall.cpp
    src/items/Pokeballs/UltraBall.cpp
    src/items/Potions/Potion.cpp
    src/items/Potions/StandardPotion.cpp
    src/items/Potions/SuperPotion.cpp
    src/items/Potions/HyperPotion.cpp
    src/items/Revives/Revive.cpp
    src/items/Revives/StandardRevive.cpp
    src/items/Revives/MaxRevive.cpp
    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp
)

# Grouped sources by item type
set(BALL_SOURCES
    src/items/Item.cpp
    src/items/Pokeballs/Pokeball.cpp
    src/items/Pokeballs/StandardBall.cpp
    src/items/Pokeballs/GreatBall.cpp
    src/items/Pokeballs/UltraBall.cpp
)

set(POTION_SOURCES
    src/items/Item.cpp
    src/items/Potions/Potion.cpp
    src/items/Potions/StandardPotion.cpp
    src/items/Potions/SuperPotion.cpp
    src/items/Potions/HyperPotion.cpp
)

set(REVIVE_SOURCES
    src/items/Item.cpp
    src/items/Revives/Revive.cpp
    src/items/Revives/StandardRevive.cpp
    src/items/Revives/MaxRevive.cpp
)

# Test Balls
add_executable(testBalls test/testBalls.cpp ${BALL_SOURCES})

# Test Potions
add_executable(testPotions test/testPotions.cpp ${POTION_SOURCES})

# Test Revives
add_executable(testRevives test/testRevives.cpp ${REVIVE_SOURCES})

# Test Displays
add_executable(testDisplays test/testDisplays.cpp src/Display.cpp)

# Test Store
add_executable(testStore test/testStore.cpp ${COMMON_PLAYER_SOURCES})

# Test PC
add_executable(testPC test/testPC.cpp ${COMMON_PLAYER_SOURCES})

# Test Attack
add_executable(testAttack test/testAttack.cpp src/Pokemon/attack.cpp)

# Test Pokemon
add_executable(testPokemon test/testPokemon.cpp ${COMMON_PLAYER_SOURCES})

# Test Wild Pokemon
add_executable(testWild test/testWildPokemon.cpp ${COMMON_PLAYER_SOURCES})

# Test Player
add_executable(testPlayer test/testPlayer.cpp ${COMMON_PLAYER_SOURCES})

# Test Battle
add_executable(testBattle
    test/testBattle.cpp
    src/battle.cpp
    ${COMMON_PLAYER_SOURCES}
)

# Test Main
add_executable(testMain
    src/maintest2.cpp
    src/battle.cpp
    ${COMMON_PLAYER_SOURCES}
)
