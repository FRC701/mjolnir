#ifndef _GAMEDATA_H
#define _GAMEDATA_H

namespace robovikes{

class GameData {

public:

  enum Side{Left, Right, Unknown};

  static Side GetOurSwitchSide();
  static Side GetScaleSide();
  static Side GetTheirSwitchSide();

};

}
#endif
