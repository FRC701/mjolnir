#include "GameData.h"
#include <DriverStation.h>

namespace robovikes {


GameData::Side GameData::GetOurSwitchSide(){

  Side ourSwitchSide = Left;
  if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[0] == 'L'){
    ourSwitchSide = Left;
  }
  else if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[0] == 'R') {
    ourSwitchSide = Right;
  }
  else{
    ourSwitchSide = Unknown;
   }
  return ourSwitchSide;
}

GameData::Side GameData::GetScaleSide(){

  Side scaleSide = Left;
  if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[1] == 'L'){
    scaleSide = Left;
  }
  else if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[1] == 'R') {
    scaleSide = Right;
  }
  else{
     scaleSide = Unknown;
   }
  return scaleSide;
}

GameData::Side GameData::GetTheirSwitchSide(){

  Side theirSwitchSide = Left;
  if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[2] == 'L'){
    theirSwitchSide = Left;
  }
  else if(frc::DriverStation::GetInstance().GetGameSpecificMessage()[2] == 'R'){
    theirSwitchSide = Right;
  }
  else{
    theirSwitchSide = Unknown;
  }
  return theirSwitchSide;
}


}
