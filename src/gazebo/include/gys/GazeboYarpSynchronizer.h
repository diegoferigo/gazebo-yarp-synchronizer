#ifndef GYS_GAZEBO_YARP_SYNCHRONIZER_H
#define GYS_GAZEBO_YARP_SYNCHRONIZER_H

#include "ClockServer.h"

#include <memory>
#include <string>

namespace gys {
    class GazeboYarpSynchronizer;
} // namespace gys

class gys::GazeboYarpSynchronizer : public GazeboYarpPlugins::ClockServer
{
public:
    GazeboYarpSynchronizer(const std::string& gazeboRpcPortName,
                           const std::string& clientRpcPortName = "");
    ~GazeboYarpSynchronizer() override;

    void init();
    void fini();

    void runSimulation(const double duration);
    void runSimulationAndWait(const double duration);

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

#endif // GYS_GAZEBO_YARP_SYNCHRONIZER_H
