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