# PVZ_2023  

## By 方文昊 & 鄭琳玲  

### 2023-OOPL  
### LGF Version: [1.1.3](https://github.com/ntut-xuan/LeistungsstarkesGameFramework/releases/tag/v1.1.3)  


## Release v1.0.0

### Features & Progress:

1. Working main menu and transition screens.
2. Player can pick the 8 plants they want to use through the use of the plant picker.
3. Player can click on the suns falling from the sky by clicking on them.
    - The suns' position is determined by the game's PRNG (Pseudo Random Number Generator), which uses system clock.
4. Once a sun is clicked, the sun is added to the sun counter.
5. Zombies spawn in the right part of the screen and they walk to the left.
    - The lane they walk in is determined by the game's PRNG for now.

### Bugs:

1. The suns falling from the sky don't seem to despawn after a period of time. They can only be despawned when the player clicks on them.
2. Memory Leak: TBD.

## Release v2.0.0 [WIP]

1. Working main menu and transition screens.
2. Player can pick the 8 plants they want to use through the use of the plant picker.
3. Player can click on the suns falling from the sky by clicking on them.
    - The suns' position is determined by the game's PRNG (Pseudo Random Number Generator), which uses system clock.
4. Once a sun is clicked, the sun is added to the sun counter.
5. Zombies spawn in the right part of the screen and they walk to the left.
    - The lane they walk in is determined by the game's PRNG for now.
6. Plants can be planted on the lane and can attack the zombies.
    - Plants that be planted and used: Peashooter, Snowpea.
    - Plants that be planted and can't be used: Potatomine, Squash, wallnut, Cherrybomb, puffshroom.
    - Plants that is in WIP: Jalapeno, Hypnoshroom, Iceshroom, Chomper, Repeaterpea, Threeshooterpea.
7. The plant picker cards has three modes:
    - The plant can't be planted since the accumulated sun isn't enough to plant the plants that the player wants.
    - The plant can be planted since the sun is accumulated and the cooldown has passed.
    - The plant can't be planted since the card needs to pass the cooldown time.
8. The plants will not put out bullets if there are not zombies detected in the lane.
9. The Sunflower can properly put out sun.
10. The plants and zombies can detect their presence; Hence the zombie will stop and start eating the plants away when they can detect the plants.


### Bugs:

1. Once the wallnuts are placed, it will protect the upper lane and the lower lane.
2. When the zombie is in `isAttacking` state, it shows the `attacking` animation, but not really `attacking`, Plants HP isn't decreasing.

2. Memory Leak: TBD.



#### Links  
[GitLab: TA files](http://140.124.183.78/gitlab/109000000/oopl2023s/-/tree/master)  
[GitHub: TA files](https://github.com/ntut-xuan/OOPL2023s)  
[Toggl](https://toggl.com/track)  

