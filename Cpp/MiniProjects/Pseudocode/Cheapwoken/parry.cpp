#include <GAME_LIBRARIES>
#include <GAME_DEPENDENCIES>
#include <GAME_SYSTEM>  // Essentially includes all the systems that the game contains (e.g. Attacks, Enemies, Player, etc.)

// Description of Pseudocode:
//  This is a "close enough" handler of Deepwoken's parrying system.
//  This pseudocode describes a posture / parry handler of the Player class when an attack event occurs.
//  This assumes that the namespace and functions are already defined in the <GAME_SYSTEM> library.
// The modification of player HP / Posture is handled inside the Enemy system. See: Enemy.cpp

/* Game objects / variables:
  Game.STRONG_ATTACK_GUARD_BREAK_THRESH_MULT type: double
    Default value: 2
  Game.NORMAL_ATTACK_GUARD_BREAK_THRESH_MULT type: double
    Default value: 1
  Game.WEAK_ATTACK_GUARD_BREAK_THRESH_MULT type: double
    Default value: 0.5
    The multiplier for posture damage thresholds on guard breaks on each attack type.

  Contains(vector<auto>, vector<string>) type: bool
    Checks if the vector contains a string.

  Player.status_effect_list type: vector<status_effect>
    Contains the current conditions and status effects of the player have.

  Player.cooldown_list type: vector<Status_effects>
    Contains the current cooldowns of the player.

  Player.health type: double
  Player.posture type: double
    Generic stats from the Player object.
  
  Enemy.is_attacking type: bool
  Enemy.attack_hp_damage type: double
  Enemy.attack_posture_damage type: double
  Enemy.attack_strength type: enum {unstoppable = 3, strong = 2, normal = 1, weak = 0}
    Generic stats from the Enemy object.
*/

class Player: public parry {
public:
  enum parry_outcome {
    success = 3,
    blocked = 2,
    guard_break = 1,
    failure = 0
  };
  
  enum parry_outcome guard_break_outcome(double posture_break_threshold_mult) {
    if (Player.posture <= Enemy.attack_posture_damage*posture_break_threshold_mult) {
      return parry_outcome::guard_break;
    } else {
      return parry_outcome::blocked;
    }
  }

  enum parry_outcome attack_outcome(Enemy Enemy) {
    if (!Enemy.is_attacking) {
      return parry_outcome::failure;
    }
    if (contains(Player.status_effect_list, {"Immobilized", "Stunned", "Guard Broken"})) {
      return parry_outcome::failure;
    }

    if (contains(Player.status_effect_list, {"Parrying"})) {
      switch (Enemy.attack_strength) {
      case 3:
        return parry_outcome::guard_break;
      case 2:
        return parry_outcome::blocked;
      case 1:
        return parry_outcome::success;
      case 0:
        return parry_outcome::success;
      default:
        Game.debug.error_log("Invalid enemy attack strength in a parrying event.");
      }
    } else if (contains(Player.status_effect_list, {"Blocking"})) {
      switch (Enemy.attack_strength) {
      case 3:
        return parry_outcome::guard_break;
      case 2:
        return guard_break_outcome(Game.STRONG_ATTACK_GUARD_BREAK_THRESH_MULT);
      case 1:
        return guard_break_outcome(Game.NORMAL_ATTACK_GUARD_BREAK_THRESH_MULT);
      case 0:
        return guard_break_outcome(Game.WEAK_ATTACK_GUARD_BREAK_THRESH_MULT);
      default:
        Game.debug.error_log("Unrecognized enemy attack strength in a blocking event.");
      }
    } else {
      return parry_outcome::failure;
    }
    }
  }
};
