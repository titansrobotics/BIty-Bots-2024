#ifndef ELEVATOR_SUBSYSTEM_H
#define ELEVATOR_SUBSYSTEM_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ElevatorSubsystem : public frc2::SubsystemBase {
    public:

    ElevatorSubsystem();

    void Periodic() override;

    void LiftElevator(double speed);


    private:

    rev::CANSparkMax m_motors;
};

#endif