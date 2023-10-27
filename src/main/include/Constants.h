#ifndef CONSTANTS_H
#define CONSTANTS_H


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

}


namespace ElevatorConstants {

    constexpr int kMotorId {8};

}


namespace ArmConstants {

    constexpr int kMotorId {9};

    constexpr int kEncoderId[2] {4, 5};

    constexpr double kCountsPerRevolution {1};
    constexpr double kAnglePerPulse       {2*kPI/kCountsPerRevolution};

}


namespace ClawConstants {

    constexpr int kLeftMotorId  {7};
    constexpr int kRightMotorId {5};

}


namespace SpeedConstants {

    constexpr double kDriveForwardPercentage  {0.6};
    constexpr double kDriveRotationPercentage {0.3};

    constexpr double kArmPercentage {0.5};

    constexpr double kElevatorPercentage {0.3};

    constexpr double kClawPercentage {0.3};

}


namespace OIConstants {
    
    constexpr int kDriverJoystickId    {0}; //console controller
    constexpr int kDriveForwardAxisId  {1};
    constexpr int kDriveRotationAxisId {4};

    constexpr int kArmJoystickId   {1}; //flight stick
    constexpr int kArmAxisId       {1};
    constexpr int kElevatorRaiseId {5};
    constexpr int kElevatorLowerId {3};
    constexpr int kClawGrabId      {1};
    constexpr int kClawEjectId     {2};

}


#endif