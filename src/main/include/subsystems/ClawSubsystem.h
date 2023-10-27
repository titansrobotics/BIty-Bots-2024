#ifndef CLAW_SUBSYSTEMS_H
#define CLAW_SUBSYSTEMS_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ClawSubsystem : public frc2::SubsystemBase {
    public:

    ClawSubsystem();

    void Periodic() override;

    void MoveClaw(double speed);

    
    private:

    rev::CANSparkMax m_leftMotor;
    rev::CANSparkMax m_rightMotor;
};

#endif