#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <units/time.h>

constexpr double kPI = 3.14159265358979323846;


namespace DriveConstants {

    constexpr int kLeftMotorId  {1};
    constexpr int kRightMotorId {3};

    constexpr int kLeftEncoderId[2]  {0, 1};
    constexpr int kRightEncoderId[2] {2, 3};

    constexpr double kCountsPerRevolution {2048};
    constexpr double kWheelDiameter       {6};
    constexpr double kDistancePerPulse    {kWheelDiameter*kPI/kCountsPerRevolution};
    //Assuming the encoder is mounted directly on the wheel shaft

    constexpr double kDriveForwardPercentage  {0.5};
    constexpr double kDriveRotationPercentage {0.2};
}


namespace ElevatorConstants {

    constexpr int kMotorId {9};

    constexpr double kElevatorPercentage {0.3};
}


namespace ArmConstants {

    constexpr int kMotorId {8};

    constexpr int kEncoderId[2] {4, 5};

    constexpr double kCountsPerRevolution {1};
    constexpr double kAnglePerPulse       {2*kPI/kCountsPerRevolution};

    constexpr double kArmPercentage {0.5};
}


namespace ClawConstants {

    constexpr int kLeftMotorId  {5};
    constexpr int kRightMotorId {6};

    constexpr double kClawPercentage {0.2};
}


namespace OIConstants {
    
    constexpr int kDriverJoystickId    {0}; //console controller
    constexpr int kDriveForwardAxisId  {1};
    constexpr int kDriveRotationAxisId {4};

    constexpr int kArmJoystickId   {1}; //flight stick
    constexpr int kArmAxisId       {1};
    constexpr int kElevatorRaiseId {5};
    constexpr int kElevatorLowerId {3};
    constexpr int kClawGrabId      {2};
    constexpr int kClawEjectId     {1};

}


namespace AutoConstants {
    constexpr double kSimpleAutoSpeed {-0.3};
    constexpr int kSimpleAutoDistance  {3};
}

#endif