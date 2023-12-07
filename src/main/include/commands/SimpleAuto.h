#ifndef SIMPLE_AUTO_H
#define SIMPLE_AUTO_H

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "subsystems/DriveSubsystem.h"

class SimpleAuto
    : public frc2::CommandHelper<frc2::CommandBase, SimpleAuto> {
public:

    SimpleAuto(DriveSubsystem* subsystem, double time, double speed);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

private:
    DriveSubsystem* m_drive;
    double m_time;
    double m_speed;
};

#endif