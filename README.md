# So_long

*******************************This project is a 2D game divided into two parts:**********************************

    Mandatory Part: In this section, the map doesn't contain any enemies.

    Bonus Part: This section introduces a surprise enemy. If the player touches the enemy, they lose the game.


**********To compile and run the game, follow these steps:**********

    Execute the make command to compile the game. This will automatically install the MLX42 library repository, and the game will be ready to launch.

    You can control the game using either the arrow keys or the W, A, S, and D buttons.

    To exit the game, simply close the window by clicking the 'x' or pressing the 'esc' button.

**********Compiling mandatory part :**********


```
make

./so_long src/maps/batmap.ber

```

**********Compiling bonus part :**********

```
make bonus

./so_long_bonus bonus/maps/batmap.ber

```

You can replace 'batmap.ber' with another map file of your choice, but it should follow the '.ber' file format.

********Map Requirements**********

Your game map should be constructed using the following elements:

    The map will be built using 3 elements: walls, collectible items, and empty spaces.
    Your map can consist of the following 5 characters:
        '0' for an empty space.
        '1' for a wall.
        'C' for a collectible item (C for collectible).
        'E' for an exit (E for exit).
        'P' for the starting position of the character.
    In the bonus part, you can also use 'M' to represent the enemy.

Please ensure that:

    The map contains at least 1 exit, 1 item, and 1 starting position.
    There are no duplicate elements on the map; if duplicates are found, display an error message.
    The map has a rectangular shape.
    The map is enclosed by walls. If it's not, the program should return an error.
    You validate the existence of a valid path (i.e., one that can be traversed) within the map.
    Your program should be able to parse any type of map as long as it adheres to these rules.
