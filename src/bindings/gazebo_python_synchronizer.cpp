#include "ClockServer.h"
#include <pybind11/pybind11.h>

// Create the Python module
PYBIND11_MODULE(bindings, module)
{
    namespace py = ::pybind11;
    module.doc() = "ClockServer bindings";

    using namespace GazeboYarpPlugins;

    py::class_<ClockServer>(module, "ClockServer")
        .def(py::init())
        .def("pause_simulation", &ClockServer::pauseSimulation)
        .def("continue_simulation", &ClockServer::continueSimulation)
        .def("step_simulation",
             &ClockServer::stepSimulation,
             py::arg("number_of_steps"))
        .def("step_simulation_and_wait",
             &ClockServer::stepSimulationAndWait,
             py::arg("number_of_steps"))
        .def("reset_simulation_time", &ClockServer::resetSimulationTime)
        .def("get_simulation_time", &ClockServer::getSimulationTime)
        .def("get_step_size", &ClockServer::getStepSize);
}
