#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    m_leftMotors   {DriveConstants::kLeftMotorId},
    m_rightMotors  {DriveConstants::kRightMotorId},
    m_leftEncoder  {DriveConstants::kLeftEncoderId[0], DriveConstants::kLeftEncoderId[1]},
    m_rightEncoder {DriveConstants::kRightEncoderId[0], DriveConstants::kRightEncoderId[1]} {

        m_leftMotors.SetInverted(true);

        m_leftEncoder.SetDistancePerPulse(DriveConstants::kDistancePerPulse);
        m_rightEncoder.SetDistancePerPulse(DriveConstants::kDistancePerPulse);
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot){
    m_leftMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd - rot);
    m_rightMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd + rot);
}

void DriveSubsystem::ResetEncoders() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}

double DriveSubsystem::GetAverageEncoderDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() {
    return m_leftEncoder;
}

frc::Encoder& DriveSubsystem::GetRightEncoder() {
    return m_rightEncoder;
}