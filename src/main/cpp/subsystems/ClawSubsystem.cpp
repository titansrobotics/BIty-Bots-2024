#include "subsystems/ClawSubsystem.h"

ClawSubsystem::ClawSubsystem() :
    m_leftMotor{ClawConstants::kLeftMotorId, rev::CANSparkMax::MotorType::kBrushless},
    m_rightMotor{ClawConstants::kRightMotorId, rev::CANSparkMax::MotorType::kBrushless} {
        
        m_rightMotor.SetInverted(true);
}

void ClawSubsystem::Periodic() {}

void ClawSubsystem::MoveClaw(double speed) {
    m_leftMotor.Set(speed);
    m_rightMotor.Set(speed);
}