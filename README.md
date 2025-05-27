# A Text-Based Role-Playing Game
CO-Authors: [Wesley Wu](https://github.com/xxiyun), [Yubin Zhen](https://github.com/yubinzhen)

## Project Description
In this game, the user can first choose one Pokemon among three to play with, and use their Pokemon to fight and catch other wild Pokemon. Pokemon are associated with different types of types and abilities, and their stats vary by their level. At each step of the game, a narrative is presented and the user can select between different options. The goal of the user is to continually level up their Pokemon through battles with CPUs and eventually catch every Pokemon in this game. 

We are interested in the idea of creating interactive experiences that engage users. An RPG will give us the most creative freedom. We are interested in creating our own turn-based game derived from Pokemon. We will be able to create our own features based on the Pokemon games while also learning how to implement the game mechanics and gameplay experiences that power them. We will also be able to add our own narrative spin on it.

### Language and Tools:
C++\
Visual Studios Code\
Github/Git\
Valgrind\
GDB\
CMake

### Input/Outputs:
Input: All input comes from the user's keyboard, which determines certain actions such as switching between Pokemon, choosing to battle a Pokemon, or selecting options during a battle.\
Output: The output includes updating and displaying the user and CPU Pokemon’s statuses, or the result of a certain action of the user.

### Features:
Battling wild Pokemon with owned Pokemon\
User choice to attack, heal, catch, etc. during battle\
Distinct attack, health, and type stats for each Pokemon\
Experience/leveling and money system\
Able to use/buy items with money earned from battles\
Catch success rate for wild Pokemon varies \
Wild Pokemon appearance/stats scale to the user’s progress\
Wild Pokemon actions are randomized 
Saving and loading game progress

## User Navigation Diagram

![UI Navigation Diagram (2)](https://github.com/user-attachments/assets/2a2a3c0d-61b4-437e-95d1-6f6e06da0a94)


### Screen Layouts

![Screenshot 2024-11-21 233350](https://github.com/user-attachments/assets/57145a91-0331-40ee-b64e-7918ff5ee0f3)

This is the first screen the user will see, which displays the name of the game and two options (1)Load Game and (2)Save Game. If the user inputs "1", the program will load the user's progress if correctly saved. If the user inputs "2", the program will overwrite the user's load file. Either option will lead to the Menu.

![image](https://github.com/user-attachments/assets/b3308e06-a75e-4daa-9ce6-89db5a73f563)

This screen provides the user with 5 main options. The user can choose to (1) go to the Inventory screen, (2) the Store screen, or (3) search for Pokemon which leads to the Battle Menu Screen. The user can also (4) view the Pokemon they own or (5) log the user out by exiting the program and returning to the initial screen.

![image](https://github.com/user-attachments/assets/1fa5dc71-b096-41c7-afb8-48cd5ffc03a7)

This screen displays the user's currently owned items.

![image](https://github.com/user-attachments/assets/6f3df295-fa4c-4a71-8586-01c355172711)

This screen displays the Pokemon they have in storage, and the user can (1) view the stats of a specific pokemon, (2) view or change the pokemon they have in their current battle team, or (3) go back to the previous screen. This screen's options may vary depending on if the user originates from the menu screen or battle menu screen.

![image](https://github.com/user-attachments/assets/7ed50bf1-535c-4d5c-96fa-c85fc2ec29f1)

This screen will show the user all the different items the user can purchase (ex. Pokeball, revive, etc.) and what the user balance is. The user can (1) buy an item, (2) sell an item, (3) view their items, or (4) go back to the previous screen if the user is done shopping.

![Screenshot 2024-11-21 233550](https://github.com/user-attachments/assets/d1a27a7f-b334-4660-91bf-00f8f9ecee57)

This screen will be displayed when the user searches for new Pokemon and enters a battle. The user can (1) view or use any owned Items, (2) view or edit their Pokemon Team, (3) view the Active Pokemon's Moveset, (4) view the Wild Pokemon's stats, or (5) attempt to flee the battle

![Screenshot 2024-11-21 233555](https://github.com/user-attachments/assets/eca046e5-5578-4957-9f06-b3db8b980591)


This screen will display all the moves the Active Pokemon has (attack, defense, etc.) and the trainer can select a move to use in their battle to try to win. There is also an option to go back to the previous menu if the trainer does not want to use a moveset. 

![Screenshot 2024-11-02 210704](https://github.com/user-attachments/assets/d22668c2-161f-40da-8149-4e1f8a1e2349)

This screen will display the result of the user’s decision in the previous screen, such as using an item, attempting to catch the Wild Pokemon, swapping the active Pokemon for another in the team, using an attack/defense move, or attempting to flee. If the Wild Pokemon is alive, it will lead to the Wild Pokemon Move screen, but if it is dead, the program will send the user to the Menu screen.

![Screenshot 2024-11-02 210707](https://github.com/user-attachments/assets/3bbb7508-2343-4223-ad45-54b21c0472c5)

This screen displays the Wild Pokemon’s current status and the decisions it makes, such as attacking/defending or fleeing the battle. If a move kills an Active Pokemon, the user will be prompted to choose an alive one, but if the Active Pokemon lives, the program will continue to the Battle Menu screen. If all user Pokemon are dead, the program will lead the user to the YOU LOST screen.

![Screenshot 2024-11-21 233600](https://github.com/user-attachments/assets/d2191188-06d8-47a9-9871-c389407ce0ce)

This is the screen the user will see if they lost a Pokemon battle. They are given an option (1) to use a revive item to revive their Pokemon or to (2) continue battling or give up on the battle and receive a penalty.


## Class Diagram
![image](https://github.com/user-attachments/assets/4a27e484-17d4-4ddf-9a21-44b580059875)


* Main: Manages the game session, offering a save and load feature. 
* Player: Manages the player's team, money, and experience, as well as interactions with the Inventory and PC.
* Pokemon: Represents basic Pokémon attributes and actions.
* Attack: Represents each attack for Pokemon. Each Pokemon has four abilities. 
* WildPokemon: Extends Pokemon with scaling and random action capabilities.
* Battle: Manages the battle flow, handling player actions and random wild Pokémon responses.
* Inventory: Manages items the player has collected and allows item use as well as purchase and sell items.
* Item: Represents each item in the game, with methods to apply its effect to a Pokemon.
* PokemonSpecies: Represents all Pokemon.
* GrowthRate: Represents how fast the Pokemon level up.
* PokemonType: Represents the Pokemon types.
* moves: Represents the Pokemon moves.

One SOLID principle we applied to the new class diagram was the Single Responsibility. One way we applied it was by removing the feature to access and edit the player’s Pokemon and implementing a separate class, PC, to address that feature. These changes make the code less complex, giving a well-organized, intuitive codebase that allows for better readability.

A second SOLID principle we applied was Liskov Substitution. For example, the StandardBall, GreatBall, and UltraBall subclasses are all coded to be interchangeable as they all have the same functions. These changes allow for code reusability and maintainability along with reducing unexpected bugs caused by inappropriate subclass behavior.

A third SOLID principle we applied to our new class diagram was Interface Segregation Principle (ISP). We applied this principle so users will not be forced to depend on interfaces they don’t use. For example, we created separate interfaces for different concerns. Our inventory class only manages items and money and does not enforce unrelated responsibilities to the class like battling. Our Pokemon class is focused mainly on the Pokemon’s actions and attributes and only our battle class contains battle logic. These changes allowed us to change things easily and made it easier to keep track of things.

 ## Final deliverable
 
 ## Screenshots
 <img width="956" alt="Screenshot 2024-12-06 at 3 13 23 PM" src="https://github.com/user-attachments/assets/88388f27-4028-4a83-a086-971e331f40b4">

 <img width="951" alt="Screenshot 2024-12-06 at 3 15 02 PM" src="https://github.com/user-attachments/assets/29ef32f3-2b5b-4245-85cf-04a840e64c24">

<img width="676" alt="Screenshot 2024-12-06 at 3 16 00 PM" src="https://github.com/user-attachments/assets/36e36e83-6b79-4760-b24e-be132c00f9f7">

<img width="679" alt="Screenshot 2024-12-06 at 3 23 30 PM" src="https://github.com/user-attachments/assets/c3d3e678-97e9-4113-9d9a-844f509121f0">

<img width="945" alt="Screenshot 2024-12-06 at 3 29 38 PM" src="https://github.com/user-attachments/assets/c0eebc42-0911-4a13-be2e-e70b7858d503">

<img width="946" alt="Screenshot 2024-12-06 at 3 47 28 PM" src="https://github.com/user-attachments/assets/e21df977-2c61-49e7-8b59-184458f5f6c4">

<img width="679" alt="Screenshot 2024-12-06 at 3 54 32 PM" src="https://github.com/user-attachments/assets/b8314831-9950-4fb4-8896-6d957c9ce940">

<img width="359" alt="Screenshot 2024-12-06 at 3 54 45 PM" src="https://github.com/user-attachments/assets/81735c48-ba99-4a9c-8169-70bb8bb16459">

 ## Installation/Usage
 Our program is terminal based, therefore to play our Pokemon role-playing game, the user will need to run the executable. Users are free to pick any option displayed on the terminal. 
 ## Testing
To test our program, we made unit tests for each function to make sure all our functions worked correctly. We also used valgrind to check for memory allocation.
 
