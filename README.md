# gazebo-yarp-synchronizer

[![Version](https://img.shields.io/pypi/v/gazebo-yarp-synchronizer.svg)](https://pypi.org/project/gazebo-yarp-synchronizer/)
[![Python versions](https://img.shields.io/pypi/pyversions/gazebo-yarp-synchronizer.svg)](https://pypi.org/project/gazebo-yarp-synchronizer/)
[![Status](https://img.shields.io/pypi/status/gazebo-yarp-synchronizer.svg)](https://pypi.org/project/gazebo-yarp-synchronizer/)
[![Format](https://img.shields.io/pypi/format/gazebo-yarp-synchronizer.svg)](https://pypi.org/project/gazebo-yarp-synchronizer/)
[![License](https://img.shields.io/pypi/l/gazebo-yarp-synchronizer.svg)](https://pypi.org/project/gazebo-yarp-synchronizer/)
[![Python CI/CD](https://github.com/diegoferigo/gazebo-yarp-synchronizer/workflows/Python%20CI/CD/badge.svg)](https://github.com/diegoferigo/gazebo-yarp-synchronizer/actions)

Synchronization with Gazebo Classic via YARP. With Python batteries.

This project is the client side of the [Clock Plugin](https://github.com/robotology/gazebo-yarp-plugins/tree/master/plugins/clock) included in [`robotology/gazebo-yarp-plugins`](https://github.com/robotology/gazebo-yarp-plugins), with some sugar on top.
It provides [`GazeboYarpSynchronizer`](src/gazebo/), a new class that extends the automatically generated resources from the [thrift service](thrift/) and provides initialization and termination helpers.

The main scope of this repository is providing a PyPI package for Python usage, but nothing prevents importing and using it from plain C++. 

## Dependencies

`gazebo-yarp-synchronizer` expects to find installed and configured the following dependencies:

- [`robotology/yarp`](https://github.com/robotology/yarp)
- [`robotology/gazebo-yarp-plugins`](https://github.com/robotology/gazebo-yarp-plugins)
- [`osrf/gazebo`](https://github.com/osrf/gazebo)

## Installation

```bash
pip3 install gazebo-yarp-synchronizer
```

## Usage

In different terminals, execute:


```bash
# 1. Start the YARP server
yarpserver

# 2. Open Gazebo paused
gazebo -u -slibgazebo_yarp_clock.so

# 3. Make sure that YARP is running
yarp detect

# 4. Open the Python interpreter
ipython
```

Then, in the Python interpreter:

```python
# Import the module
>>> from gazebo_yarp_synchronizer import GazeboYarpSynchronizer

# Create the Gazebo synchronizer
>>> gys = GazeboYarpSynchronizer(gazebo_rpc_port_name="/clock/rpc")

# Initialize the Gazebo synchronizer
>>> gys.init()
# [INFO] |yarp.os.Port| Port /tmp/port/1 active at tcp://192.168.8.102:10056/
# [INFO] |yarp.os.impl.PortCoreOutputUnit| Sending output from /tmp/port/1 to /clock/rpc using tcp

# Inspect simulation status
>>> gys.get_step_size(), gys.get_simulation_time()
# (0.001, 0.0)

# Advance the simulation synchronously
>>> gys.step_simulation_and_wait(number_of_steps=250)

# Print time
>>> gys.get_simulation_time()
# 0.25

# Advance the simulation synchronously
>>> gys.run_simulation_and_wait(duration=0.75)

# Print time
>>> gys.get_simulation_time()
# 1.0

# Terminate the synchronizer
>>> gys.fini()
# [INFO] |yarp.os.impl.PortCoreOutputUnit| Removing output from /tmp/port/1 to /clock/rpc
```

## Contributing

Pull requests are welcome. 
For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
