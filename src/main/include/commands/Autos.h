#ifndef AUTOS_H
#define AUTOS_H

#include <frc2/command/CommandPtr.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/ArmSubsystem.h"
#include "subsystems/ClawSubsystem.h"

namespace autos {

frc2::CommandPtr SimpleAuto(DriveSubsystem* drive);

//frc2::CommandPtr ComplexAuto(DriveSubsystem* drive);

}

#endif