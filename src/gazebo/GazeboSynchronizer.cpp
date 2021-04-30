#include "GazeboSynchronizer.h"

#include <iostream>
#include <stdexcept>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>

class gps::GazeboSynchronizer::Impl
{
public:
    std::string clientRpcPortName;
    std::string gazeboRpcPortName;

    yarp::os::Port clientPort;
    std::unique_ptr<yarp::os::Network> network;
};

gps::GazeboSynchronizer::GazeboSynchronizer(
    const std::string& gazeboRpcPortName,
    const std::string& clientRpcPortName)
    : GazeboYarpPlugins::ClockServer()
    , pImpl{std::make_unique<Impl>()}
{
    if (clientRpcPortName.empty()) {
        pImpl->clientRpcPortName = "...";
    }
    else {
        pImpl->clientRpcPortName = clientRpcPortName;
    }

    pImpl->gazeboRpcPortName = gazeboRpcPortName;
    pImpl->network = std::make_unique<yarp::os::Network>();
}

gps::GazeboSynchronizer::~GazeboSynchronizer()
{
    this->fini();
}

void gps::GazeboSynchronizer::init()
{
    // Check if the network is initialized
    if (!yarp::os::Network::initialized()
        || !yarp::os::Network::checkNetwork(5.0)) {
        throw std::runtime_error("YARP network not initialized");
    }

    // Open the local port
    if (!pImpl->clientPort.isOpen()) {
        pImpl->clientPort.open(pImpl->clientRpcPortName);
    }

    // Connect client and server ports
    if (!pImpl->network->isConnected(pImpl->clientPort.getName(),
                                     pImpl->gazeboRpcPortName)
        && !yarp::os::Network::connect(pImpl->clientPort.getName(),
                                       pImpl->gazeboRpcPortName)) {
        pImpl->clientPort.close();
        throw std::runtime_error("Failed to connect to remote RPC port");
    }

    // Attach the local port to the RPC service
    this->yarp().attachAsClient(pImpl->clientPort);
}

void gps::GazeboSynchronizer::fini()
{
    // Disconnect the ports
    if (pImpl->clientPort.isOpen()
        && pImpl->network->isConnected(pImpl->clientPort.getName(),
                                       pImpl->gazeboRpcPortName)
        && !pImpl->network->disconnect(pImpl->clientPort.getName(),
                                       pImpl->gazeboRpcPortName)) {
        std::cerr << "Failed to disconnect from the simulator" << std::endl;
    }

    // Close the local port
    pImpl->clientPort.close();
}

void gps::GazeboSynchronizer::runSimulation(const double duration)
{
    const std::int32_t numberOfSteps = duration / this->getStepSize();
    this->stepSimulation(numberOfSteps);
}

void gps::GazeboSynchronizer::runSimulationAndWait(const double duration)
{
    const std::int32_t numberOfSteps = duration / this->getStepSize();
    this->stepSimulationAndWait(numberOfSteps);
}
