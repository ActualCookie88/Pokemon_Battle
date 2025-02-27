cmake_minimum_required(VERSION 3.20)

add_executable(testBalls
    test/testBalls.cpp
    src/Item.cpp
    src/Pokeballs/Pokeball.cpp
    src/Pokeballs/StandardBall.cpp
    src/Pokeballs/GreatBall.cpp
    src/Pokeballs/UltraBall.cpp
)

add_executable(testPotions
    test/testPotions.cpp
    src/Item.cpp
    src/Potions/Potion.cpp
    src/Potions/StandardPotion.cpp
    src/Potions/SuperPotion.cpp
    src/Potions/HyperPotion.cpp
)

add_executable(testRevives
    test/testRevives.cpp
    src/Item.cpp
    src/Revives/Revive.cpp
    src/Revives/StandardRevive.cpp
    src/Revives/MaxRevive.cpp
)

add_executable(testDisplays
    test/testDisplays.cpp
    src/Display.cpp
    src/player.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/battle.cpp
    

    src/Pokemon/pokemon.cpp
    src/Pokemon/attack.cpp

    src/Pokeballs/Pokeball.cpp
    src/Pokeballs/StandardBall.cpp
    src/Pokeballs/GreatBall.cpp
    src/Pokeballs/UltraBall.cpp
    src/Potions/StandardPotion.cpp
    src/Potions/SuperPotion.cpp
    src/Potions/HyperPotion.cpp
    src/Revives/Revive.cpp
    src/Revives/StandardRevive.cpp
    src/Revives/MaxRevive.cpp
)