#include "GazeboSynchronizer.h"
#include <pybind11/pybind11.h>
#include <string>

// Create the Python module
PYBIND11_MODULE(bindings, module)
{
    namespace py = ::pybind11;
    module.doc() = "GazeboSynchronizer bindings";

    py::class_<gps::GazeboSynchronizer>(module, "GazeboSynchronizer")
        .def(py::init<const std::string&, const std::string&>(),
             py::arg("gazebo_rpc_port_name"),
             py::arg("client_rpc_port_name") = "")
        .def("init", &gps::GazeboSynchronizer::init)
        .def("fini", &gps::GazeboSynchronizer::fini)
        .def("pause_simulation", &gps::GazeboSynchronizer::pauseSimulation)
        .def("continue_simulation",
             &gps::GazeboSynchronizer::continueSimulation)
        .def("step_simulation",
             &gps::GazeboSynchronizer::stepSimulation,
             py::arg("number_of_steps"))
        .def("step_simulation_and_wait",
             &gps::GazeboSynchronizer::stepSimulationAndWait,
             py::arg("number_of_steps"))
        .def("reset_simulation_time",
             &gps::GazeboSynchronizer::resetSimulationTime)
        .def("get_simulation_time", &gps::GazeboSynchronizer::getSimulationTime)
        .def("get_step_size", &gps::GazeboSynchronizer::getStepSize)
        .def("run_simulation",
             &gps::GazeboSynchronizer::runSimulation,
             py::arg("duration"))
        .def("run_simulation_and_wait",
             &gps::GazeboSynchronizer::runSimulationAndWait,
             py::arg("duration"));
}
