####################
# CISC 454 - W19   #
# Assignment 1     #
# January 31, 2019 #
####################

Students:
------------------------------
Karen Batch
Mitch Mathieu


Additional Functionality:
------------------------------
1) ASTEROID EXPLOSIONS
   When an asteroid that is below the scaling threshold is destroyed by a shell,
   it 'explodes' into four even smaller temporary pieces. These pieces are tagged
   as fragments and only exist in the world for 0.5 seconds. Fragments cannot be
   hit by anything and don't have a score value. We implemented this by adding
   an elapsedTime attribute (similar to the shell object) and an isFragment flag 
   to the asteroid object. We added conditional statements in world.cpp for checking
   the age of the fragments while checking for collisions of asteroids. The explosion
   annimation is created using 4 different velocities using the original velocity of
   the shell.

2) HALT SHIP ON COLLISION
   When the ship collides with an asteroid, resulting in GAME OVER, the ship's
   velocity is set to zero so it stops at the site of collision. The asteroids
   continue moving after the game ends.

