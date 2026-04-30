#include <GAME_LIBRARIES>
#include <GAME_DEPENDENCIES>
#include <GAME_SYSTEM>  // Essentially includes all the systems that the game contains (e.g. Attacks, Enemies, Player, etc.)

// Description of Pseudocode:
// This should contain the miscellanous code for the Enemy system, but this will focus entirely-
// on the attacks and modification of the player state for the sake of scope.

/* Game objects / variables:
  Game.GUARD_BREAK_HP_DAMAGE_MULT type: double
    default value: 1.5
    Contains the game multiplier for hp damage when guard broken.

  Game.HP_TO_POSTURE_DAMAGE_MULT type: double
    default value: 0.25
    Contains the game multiplier for the ratio of hp to posture damage during blocking.

  Player.status_effect_list Type: vector<status_effect>
    Contains the current conditions and status effects of the player have

  Player.cooldown_list type: vector<Status_effects>
    Contains the current cooldowns of the player.

  Player.health type: double
  Player.posture type: double
  Player.status_effect.is_parrying type: bool
  Player.status_effect.is_blocking type: bool
    Generic stats from the Player object.
  
  Enemy.is_attacking type: bool
  Enemy.attack_hp_damage type: double
  Enemy.attack_posture_damage type: double
  Enemy.attack_strength type: enum {unstoppable, strong, normal, weak}
    Generic stats from the Enemy object.
*/

class Enemy {
public:
  /*
  . . . . . . . . . . . . . .
  . Miscellanous enemy code .
  . . . . . . . . . . . . . .
  */

  void attack(int attackUID) {
  /*
  . . . . . . . . . . . . . .
  . Miscellanous attack code .
  . . . . . . . . . . . . . .
  */
  switch (Player.parry.attack_outcome(Enemy)) {
  case 3:
    Game.parry_fx(Player);
    Player.posture += Player.parry_posture_healing;
    break;
  case 2:
    Game.blocked_fx(Player);
    Player.posture -= Enemy.attack_posture_damage;
    break;
  case 1:
    Game.guard_break_fx(Player);
    Player.health -= Enemy.attack_hp_damage*Game.GUARD_BREAK_HP_DAMAGE_MULT;
    break;
  case 0:
    Game.damage_fx(Player);
    Player.heatlh -= Enemy.attack_hp_damage;
    break;
  default:
    Game.debug.error_log("Invalid parry outcome inside an attack event.");
  }
}
};
