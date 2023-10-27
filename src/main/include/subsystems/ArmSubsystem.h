#ifndef ARM_SUBSYSTEM_H
#define ARM_SUBSYSTEM_H

#include <rev/CANSparkMax.h>
#include <frc/Encoder.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ArmSubsystem : public frc2::SubsystemBase {
    public:

    ArmSubsystem();

    void Periodic() override;

    void RaiseArm(double speed);

    void ResetEncoder();

    double GetEncoderDistance();

    frc::Encoder& GetEncoder();


    private:

    rev::CANSparkMax m_motor;

    frc::Encoder m_encoder;
};

#endif