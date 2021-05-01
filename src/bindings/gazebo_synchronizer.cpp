#include "GazeboSynchronizer.h"
#include <pybind11/pybind11.h>
#include <string>

// Create the Python module
PYBIND11_MODULE(bindings, module)
{
    namespace py = ::pybind11;
    module.doc() = "GazeboSynchronizer bindings";

    py::class_<gs::GazeboSynchronizer>(module, "GazeboSynchronizer")
        .def(py::init<const std::string&, const std::string&>(),
             py::arg("gazebo_rpc_port_name"),
             py::arg("client_rpc_port_name") = "")
        .def("init", &gs::GazeboSynchronizer::init)
        .def("fini", &gs::GazeboSynchronizer::fini)
        .def("pause_simulation", &gs::GazeboSynchronizer::pauseSimulation)
        .def("continue_simulation",
             &gs::GazeboSynchronizer::continueSimulation)
        .def("step_simulation",
             &gs::GazeboSynchronizer::stepSimulation,
             py::arg("number_of_steps"))
        .def("step_simulation_and_wait",
             &gs::GazeboSynchronizer::stepSimulationAndWait,
             py::arg("number_of_steps"))
        .def("reset_simulation_time",
             &gs::GazeboSynchronizer::resetSimulationTime)
        .def("get_simulation_time", &gs::GazeboSynchronizer::getSimulationTime)
        .def("get_step_size", &gs::GazeboSynchronizer::getStepSize)
        .def("run_simulation",
             &gs::GazeboSynchronizer::runSimulation,
             py::arg("duration"))
        .def("run_simulation_and_wait",
             &gs::GazeboSynchronizer::runSimulationAndWait,
             py::arg("duration"));
}