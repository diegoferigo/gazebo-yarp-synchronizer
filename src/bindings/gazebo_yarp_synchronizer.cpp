#include "GazeboYarpSynchronizer.h"
#include <pybind11/pybind11.h>
#include <string>

// Create the Python module
PYBIND11_MODULE(bindings, module)
{
    namespace py = ::pybind11;
    module.doc() = "GazeboYarpSynchronizer bindings";

    py::class_<gs::GazeboYarpSynchronizer>(module, "GazeboYarpSynchronizer")
        .def(py::init<const std::string&, const std::string&>(),
             py::arg("gazebo_rpc_port_name"),
             py::arg("client_rpc_port_name") = "")
        .def("init", &gs::GazeboYarpSynchronizer::init)
        .def("fini", &gs::GazeboYarpSynchronizer::fini)
        .def("pause_simulation", &gs::GazeboYarpSynchronizer::pauseSimulation)
        .def("continue_simulation",
             &gs::GazeboYarpSynchronizer::continueSimulation)
        .def("step_simulation",
             &gs::GazeboYarpSynchronizer::stepSimulation,
             py::arg("number_of_steps"))
        .def("step_simulation_and_wait",
             &gs::GazeboYarpSynchronizer::stepSimulationAndWait,
             py::arg("number_of_steps"))
        .def("reset_simulation_time",
             &gs::GazeboYarpSynchronizer::resetSimulationTime)
        .def("get_simulation_time",
             &gs::GazeboYarpSynchronizer::getSimulationTime)
        .def("get_step_size", &gs::GazeboYarpSynchronizer::getStepSize)
        .def("run_simulation",
             &gs::GazeboYarpSynchronizer::runSimulation,
             py::arg("duration"))
        .def("run_simulation_and_wait",
             &gs::GazeboYarpSynchronizer::runSimulationAndWait,
             py::arg("duration"));
}
