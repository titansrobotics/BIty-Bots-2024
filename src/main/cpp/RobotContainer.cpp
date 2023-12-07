// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/Commands.h>

#include <commands/DefaultDrive.h>
#include <commands/DefaultArm.h>


RobotContainer::RobotContainer() {

  m_chooser.SetDefaultOption("Simple Auto", &m_simpleAuto);

  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

  ConfigureBindings();

  m_drive.SetDefaultCommand(DefaultDrive(
    &m_drive,
    [this] {return m_driverController.GetRawAxis(OIConstants::kDriveForwardAxisId) * SpeedConstants::kDriveForwardPercentage;},
    [this] {return m_driverController.GetRawAxis(OIConstants::kDriveRotationAxisId) * SpeedConstants::kDriveRotationPercentage;}));

  m_arm.SetDefaultCommand(DefaultArm(
    &m_arm,
    [this] {return m_armController.GetRawAxis(OIConstants::kArmAxisId) * SpeedConstants::kArmPercentage;}));
}

void RobotContainer::ConfigureBindings() {
    m_elevatorRaiseButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(SpeedConstants::kElevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(0); }, {}));

    m_elevatorLowerButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(-SpeedConstants::kElevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(0); }, {}));

    m_clawGrabButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(SpeedConstants::kClawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(0); }, {}));

    m_clawEjectButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(-SpeedConstants::kClawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(0); }, {}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return m_chooser.GetSelected();
}
