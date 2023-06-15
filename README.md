# PVZ_2023  

## By 方文昊 & 鄭琳玲  

### 2023-OOPL  
### LGF Version: [1.1.3](https://github.com/ntut-xuan/LeistungsstarkesGameFramework/releases/tag/v1.1.3)  

## Release v3.0.0

1. Working main menu and transition screens.
2. Players can pick the 8 plants they want to use through the use of the plant picker.
3. Player can click on the suns falling from the sky by clicking on them.
    - The sun's position is determined by the game's PRNG (Pseudo Random Number Generator), which uses system clock.
4. Once a sun is clicked, the sun is added to the sun counter.
5. Zombies spawn in the right part of the screen and they walk to the left.
6. Plants can be planted on the lane and can attack the zombies.
    - Plants that be planted and used: `Peashooter`, `Sunflower`, `Cherrybomb`, `Wallnut`, `Potatomine`, `Snowpea`, `Repeaterpea`, `Puffshroom`, `Scaredyshroom`, `Squash`, and `Threeshooterpea`, `Iceshroom`.
    - Plants that be planted and can't be used: N/A.
    - WIP Plants: N/A.
7. The plant picker cards have three modes:
    - The plant can't be planted since the accumulated sun isn't enough to plant the plants that the player wants.
    - The plant can be planted since the sun is accumulated and the cooldown has passed.
    - The plant can't be planted since the card needs to pass the cooldown time.
8. The plants will not put out bullets if there are no zombies detected in the lane.
9. The Sunflower can properly put out the sun.
10. The plants and zombies can detect their presence; Hence the zombie will stop and start eating the plants away when they can detect the plants.
11. The game is playable on Fullscreen or minimized screen.
12. Plants Cancelation logic:
    - If the plants chosen are incorrect, then by `clicking right` then it will cancel the chosen plant.
    - If the plants chosen are planted on the square that has plants, then the logic will cancel the chosen plant.
13. Shovel logic: Removes the plants that have been planted on the map.
14. Landmower logic.
15. Progress Bar logic.
16. Zombie Factory logic.
17. If the zombies are attacked by Snowpea, then the zombie animation will turn blue and move slower.
18. The zombies that can be generated are:
    - Normal Zombie
    - Conehead Zombie
    - Buckethead Zombie
    - Newspaper Zombie
    - Flag Zombie
19. In-game menu logic. The in-game menu allows the user to:
  - go back to the previous level by pressing the button if the previous level isn't the main menu.
  - Skip the current level and go to the next one if the next level isn't the main menu.
  - Restart the current map.
  - go back to the main menu.
20. Level ending added
  - If the user loses the game, then a game over screen will be displayed and the user can click anywhere on the screen to restart the level
  - If the user completes the level, then a note will drop from the last zombie and the user can only click that. When clicking it, the note will occupy the full screen to allow the user to read it. After reading it, the user can click anywhere to proceed to the next level.
21. 5 Day map level and 5 Night map level are available to be played.
22. Added key shortcuts.
23. Fixed Icon and About.
24. Added report to the folder.
25. About us page are added.
26. Music and SFX are added.

## Bugs:

No visible bugs were seen.
