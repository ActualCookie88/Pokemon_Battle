cmake_minimum_required(VERSION 3.20)
project(Pokemon_Battle)

add_executable(testBalls
    test/testBalls.cpp
    src/items/Item.cpp
    src/items/Pokeballs/Pokeball.cpp
    src/items/Pokeballs/StandardBall.cpp
    src/items/Pokeballs/GreatBall.cpp
    src/items/Pokeballs/UltraBall.cpp
)

add_executable(testPotions
    test/testPotions.cpp
    src/items/Item.cpp
    src/items/Potions/Potion.cpp
    src/items/Potions/StandardPotion.cpp
    src/items/Potions/SuperPotion.cpp
    src/items/Potions/HyperPotion.cpp
)

add_executable(testRevives
    test/testRevives.cpp
    src/items/Item.cpp
    src/items/Revives/Revive.cpp
    src/items/Revives/StandardRevive.cpp
    src/items/Revives/MaxRevive.cpp
)

add_executable(testDisplays
    test/testDisplays.cpp
    src/Display.cpp
)

add_executable(testStore
    test/testStore.cpp
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
)

add_executable(testPC
    test/testPC.cpp
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
)

add_executable(testAttack
    test/testAttack.cpp
    src/Pokemon/attack.cpp
)

add_executable(testPokemon
    test/testPokemon.cpp
    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp

    src/Display.cpp

    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp

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
)

add_executable(testWild
    test/testWildPokemon.cpp
    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp

    src/Display.cpp

    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp

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
)

add_executable(testPlayer
    test/testPlayer.cpp
    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp

    src/Display.cpp

    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp

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
)

add_executable(testBattle
    test/testBattle.cpp
    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp

    src/Display.cpp
    src/battle.cpp

    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp

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
)

add_executable( testMain
    src/maintest2.cpp
    src/Display.cpp
    src/battle.cpp

    src/player/Player.cpp
    src/player/Store.cpp
    src/player/PC.cpp

    src/Pokemon/attack.cpp
    src/Pokemon/pokemon.cpp
    src/Pokemon/moves.cpp
    src/Pokemon/wildPokemon.cpp

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

)