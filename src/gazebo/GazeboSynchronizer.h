#ifndef GS_GAZEBO_SYNCHRONIZER_H
#define GS_GAZEBO_SYNCHRONIZER_H

#include "ClockServer.h"

#include <memory>
#include <string>

namespace gs {
    class GazeboSynchronizer;
} // namespace gs

class gs::GazeboSynchronizer : public GazeboYarpPlugins::ClockServer
{
public:
    GazeboSynchronizer(const std::string& gazeboRpcPortName,
                       const std::string& clientRpcPortName = "");
    ~GazeboSynchronizer() override;

    void init();
    void fini();

    void runSimulation(const double duration);
    void runSimulationAndWait(const double duration);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // GS_GAZEBO_SYNCHRONIZER_H
