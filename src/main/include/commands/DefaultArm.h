#ifndef DEFAULT_ARM_H
#define DEFAULT_ARM_H

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "subsystems/ArmSubsystem.h"

class DefaultArm
    : public frc2::CommandHelper<frc2::CommandBase, DefaultArm> {
public:

    DefaultArm(ArmSubsystem* subsystem,
    std::function<double()> move);

    void Execute() override;

private:
    ArmSubsystem* m_arm;
    std::function<double()> m_move;
};

#endif