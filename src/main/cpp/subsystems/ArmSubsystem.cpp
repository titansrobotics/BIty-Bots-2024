#include "subsystems/ArmSubsystem.h"

ArmSubsystem::ArmSubsystem() :
    m_motor   {ArmConstants::kMotorId, rev::CANSparkMax::MotorType::kBrushless},
    m_encoder {ArmConstants::kEncoderId[0], ArmConstants::kEncoderId[1]} {
        m_encoder.SetDistancePerPulse(ArmConstants::kAnglePerPulse);
}

void ArmSubsystem::Periodic() {}

void ArmSubsystem::RaiseArm(double speed) {
    if(speed > 0){
        m_motor.Set(-speed);
    } else {
        m_motor.Set(0);
    }
    
}

void ArmSubsystem::ResetEncoder() {
    m_encoder.Reset();
}

double ArmSubsystem::GetEncoderDistance() {
    return m_encoder.GetDistance();
}

frc::Encoder& ArmSubsystem::GetEncoder() {
    return m_encoder;
}