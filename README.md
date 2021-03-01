# RSWE_library
**Robotics Software Engineer library** - This is a publisher/subscriber library based on *Fast-DDS*.

## Installation process
The [eProsima Fast DDS](https://github.com/eProsima/Fast-DDS) services can be installed in several ways. The installation that has been followed in this project is based on [Linux installation from sources](https://fast-dds.docs.eprosima.com/en/latest/installation/sources/sources_linux.html#fast-dds-gen-installation). The *CMake installation* has been followed, so *Colcon* has not been installed.
</br>
The OS and SW versions used are the following ones:
- Ubuntu **18.04**
- CMake **3.16.5**
- g++ **7.5.0**
- openjdk **11.0.10**
- jdk-**15.0.2**

> **Warning 1**
> </br>
> **Deprecated Gradle features were used in this build, making it incompatible with
> Gradle 7.0.**
> </br>
> This message occurred once compiling *Fast DDS-Gen* both installing *gradle* and
> launching the executable script:
> ```
> ./gradlew assemble
> ```

## HelloWorld application
A simple publisher/subscriber application can be written by following the guide on [Writing a simple publisher and subscriber application](https://fast-rtps.docs.eprosima.com/en/latest/fastdds/getting_started/simple_app/simple_app.html#prerequisites).

> **Warning 2**
> </br>
> The libraries denoted in the *1.3.4.1.* paragraph were not present in the path
> indicated. That is why they have been manually linked further on.

The *1.3.4.2.* paragraph has been skipped, since *Colcon* has not been installed.

> **Warning 3**
> </br>
> It was not possible to run the command of *1.3.6.* section:
> ```
> <path/to/Fast DDS-Gen>/scripts/fastrtpsgen HelloWorld.idl
> ```
> since *fastrtpsgen* does not exist at the following path, and seems to be
> deprecated. The following command has been run instead:
> ```
> <path-to-Fast-DDS-Gen>/scripts/fastddsgen -example CMake HelloWorld.idl
> ```
> following the other guide on [Building a publish/subscribe application](https://fast-rtps.docs.eprosima.com/en/latest/fastddsgen/pubsub_app/pubsub_app.html#fastddsgen-pubsub-app).

With *fastddsgen* it is possible to see that more files than the ones denoted in the project tree structure at *1.3.3* section are created. The ones in excess can be deleted (otherwise there will be multiple definitions of main).

> **Warning 4**
> </br>
> Once we run the command:
> ```
> cmake ...
> ```
> there are errors due to the missing *fastcdr*, *fastrtps* e *foonathan_memory*
> libraries, as anticipated in *Warning 2*. It is possible to run these three commands instead:
> ```
> cmake -DCMAKE_INSTALL_PREFIX:PATH=~/Fast-DDS/install/lib/cmake/fastcdr/ ..
>
> cmake -DCMAKE_INSTALL_PREFIX:PATH=~/Fast-DDS/install/share/fastrtps/cmake/ ..
>
> cmake -DCMAKE_INSTALL_PREFIX:PATH=~/Fast-DDS/foonathan_memory_vendor/build/foo_mem_ext_prj_install/lib/foonathan_memory/cmake/ ..
> ```

The libraries paths can be found from *$HOME* with:
```
find . | grep fastcdr-config.cmake

find . | grep fastrtps-config.cmake

find . | grep foonathan_memory-config.cmake
```
Now it is possible to follow the last steps to run both the Publisher and Subscriber applications.
## RSWE library tasks
The main tasks required for the design of the **RSWE library** are:
- [] Create custom messages
- [] Stream messages between separate processes
- [] Send a single message/response between separate processes
- [] Display published messages in the terminal
- [] Display what processes are publishing messages
- [] Stress test system
- [] Measure rate of sent messages
- [] Measure latency of sent messages

## Activities rundown
Here a rundown of the main activities that have been carried on approximately in the time indicated:
| Activity                                 | ~ Time spent (hr) |
| ---------------------------------------- | ----------------- |
| Libraries installation & problems fixing | 2.5               |
| Documentation analysis                   | 1                 |
| Making the example application work      | 0.75              |
| Creation of the custom RSWE application  | 0.5               |
| Writing of documentation                 | 1                 |