// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/Commands.h>


RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("Simple Auto", m_simpleAuto.get());

    frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

    ConfigureBindings();

    m_drive.SetDefaultCommand(frc2::cmd::Run(
    [this] {
    m_drive.ArcadeDrive(m_driverController.GetRawAxis(OIConstants::kDriveForwardAxisId) * DriveConstants::kDriveForwardPercentage,
                        m_driverController.GetRawAxis(OIConstants::kDriveRotationAxisId) * DriveConstants::kDriveRotationPercentage);
    },
    {&m_drive}));

    m_arm.SetDefaultCommand(frc2::cmd::Run(
    [this] {
    m_arm.RaiseArm(m_armController.GetRawAxis(OIConstants::kArmAxisId) * ArmConstants::kArmPercentage);
    },
    {&m_arm}));
}

void RobotContainer::ConfigureBindings() {
    m_elevatorRaiseButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(ElevatorConstants::kElevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(0); }, {}));

    m_elevatorLowerButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(-ElevatorConstants::kElevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_elevator.LiftElevator(0); }, {}));

    m_clawGrabButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(ClawConstants::kClawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(0); }, {}));

    m_clawEjectButton
    .OnTrue(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(-ClawConstants::kClawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { m_claw.MoveClaw(0); }, {}));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    return m_chooser.GetSelected();
}
