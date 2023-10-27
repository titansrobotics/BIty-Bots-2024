#include "subsystems/ElevatorSubsystem.h"

ElevatorSubsystem::ElevatorSubsystem() : 
    m_motors{ElevatorConstants::kMotorId, rev::CANSparkMax::MotorType::kBrushless} {}

void ElevatorSubsystem::Periodic() {}

void ElevatorSubsystem::LiftElevator(double speed) {
    m_motors.Set(speed);
}