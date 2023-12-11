#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>

#include <frc/Timer.h>

#include "Constants.h"

frc2::CommandPtr autos::SimpleAuto(DriveSubsystem* drive){
    return frc2::FunctionalCommand(
        [drive]() { drive->ResetEncoders(); },
        [drive]() { drive->ArcadeDrive(AutoConstants::kSimpleAutoSpeed, 0); },
        [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
        [drive]() {
            return frc::Timer::GetFPGATimestamp().value() >= 
                    AutoConstants::kSimpleAutoTime;
        },
        {drive})
    .ToPtr();
}

// frc2::CommandPtr autos::ComplexAuto(DriveSubsystem* drive){
// write this later
// }