#ifndef GPS_GAZEBO_SYNCHRONIZER_H
#define GPS_GAZEBO_SYNCHRONIZER_H

#include "ClockServer.h"

#include <memory>
#include <string>

namespace gps {
    class GazeboSynchronizer;
} // namespace gps

class gps::GazeboSynchronizer : public GazeboYarpPlugins::ClockServer
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

#endif // GPS_GAZEBO_SYNCHRONIZER_H
