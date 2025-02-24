cmake_minimum_required(VERSION 3.20)

add_executable(testBalls
    src/main.cpp
    src/Item.cpp
    src/Pokeballs/Pokeball.cpp
    src/Pokeballs/StandardBall.cpp
    src/Pokeballs/GreatBall.cpp
    src/Pokeballs/UltraBall.cpp
)