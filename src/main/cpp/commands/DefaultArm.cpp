#include "commands/DefaultArm.h"

#include <utility>

DefaultArm::DefaultArm(ArmSubsystem* subsystem,
std::function<double()> move)
        : m_arm{subsystem},
        m_move{std::move(move)} {
    AddRequirements({subsystem});
}

void DefaultArm::Execute(){
    m_arm->RaiseArm(m_move());
}