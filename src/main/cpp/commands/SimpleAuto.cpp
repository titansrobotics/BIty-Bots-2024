#include "commands/SimpleAuto.h"

#include <frc/Timer.h>

SimpleAuto::SimpleAuto(DriveSubsystem* subsystem, double time, double speed)
        : m_drive{subsystem}, m_time{time}, m_speed{speed} {
    AddRequirements({subsystem});
}

void SimpleAuto::Initialize() {
    m_drive->ResetEncoders();
}

void SimpleAuto::Execute() {
    m_drive->ArcadeDrive(m_speed, 0);
}

void SimpleAuto::End(bool interrupted) {
    m_drive->ArcadeDrive(0, 0);
}

bool SimpleAuto::IsFinished() {
    return frc::Timer::GetFPGATimestamp().value() >= m_time;
}