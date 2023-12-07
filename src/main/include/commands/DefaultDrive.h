#ifndef DEFAULT_DRIVE_H
#define DEFAULT_DRIVE_H

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "subsystems/DriveSubsystem.h"

class DefaultDrive
    : public frc2::CommandHelper<frc2::CommandBase, DefaultDrive> {
public:

    DefaultDrive(DriveSubsystem* subsystem,
    std::function<double()> forward,
    std::function<double()> rotation);

    void Execute() override;

private:
    DriveSubsystem* m_drive;
    std::function<double()> m_forward;
    std::function<double()> m_rotation;
};

#endif