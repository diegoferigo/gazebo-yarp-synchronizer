#include "gys/GazeboYarpSynchronizer.h"
#include <pybind11/pybind11.h>
#include <string>

// Create the Python module
PYBIND11_MODULE(bindings, module)
{
    namespace py = ::pybind11;
    module.doc() = "GazeboYarpSynchronizer bindings";

    py::class_<gys::GazeboYarpSynchronizer>(module, "GazeboYarpSynchronizer")
        .def(py::init<const std::string&, const std::string&>(),
             py::arg("gazebo_rpc_port_name"),
             py::arg("client_rpc_port_name") = "")
        .def("init", &gys::GazeboYarpSynchronizer::init)
        .def("fini", &gys::GazeboYarpSynchronizer::fini)
        .def("pause_simulation", &gys::GazeboYarpSynchronizer::pauseSimulation)
        .def("continue_simulation",
             &gys::GazeboYarpSynchronizer::continueSimulation)
        .def("step_simulation",
             &gys::GazeboYarpSynchronizer::stepSimulation,
             py::arg("number_of_steps"))
        .def("step_simulation_and_wait",
             &gys::GazeboYarpSynchronizer::stepSimulationAndWait,
             py::arg("number_of_steps"))
        .def("reset_simulation_time",
             &gys::GazeboYarpSynchronizer::resetSimulationTime)
        .def("get_simulation_time",
             &gys::GazeboYarpSynchronizer::getSimulationTime)
        .def("get_step_size", &gys::GazeboYarpSynchronizer::getStepSize)
        .def("run_simulation",
             &gys::GazeboYarpSynchronizer::runSimulation,
             py::arg("duration"))
        .def("run_simulation_and_wait",
             &gys::GazeboYarpSynchronizer::runSimulationAndWait,
             py::arg("duration"));
}
