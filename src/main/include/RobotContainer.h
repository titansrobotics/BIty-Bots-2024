// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"
#include "commands/Autos.h"
#include "subsystems/ArmSubsystem.h"
#include "subsystems/ClawSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ElevatorSubsystem.h"

class RobotContainer {
    public:
    RobotContainer();

    frc2::CommandPtr GetAutonomousCommand();

    private:
    frc::Joystick m_driverController {OIConstants::kDriverJoystickId};
    frc::Joystick m_armController    {OIConstants::kArmJoystickId};

    frc2::JoystickButton m_elevatorRaiseButton {&m_armController, OIConstants::kElevatorRaiseId};
    frc2::JoystickButton m_elevatorLowerButton {&m_armController, OIConstants::kElevatorLowerId};
    frc2::JoystickButton m_clawGrabButton      {&m_armController, OIConstants::kClawGrabId};
    frc2::JoystickButton m_clawEjectButton     {&m_armController, OIConstants::kClawEjectId};
    
    ArmSubsystem m_arm;
    ClawSubsystem m_claw;
    DriveSubsystem m_drive;
    ElevatorSubsystem m_elevator;

    //setup autos before adding auto selector
    //frc2::CommandPtr m_simpleAuto = autos::SimpleAuto(&m_drive);
    //frc2::CommandPtr m_complexAuto = autos::ComplexAuto(&m_drive, &m_hatch);

    //frc::SendableChooser<frc2::Command*> m_chooser;
 
    void ConfigureBindings();
};

#endif