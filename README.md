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
> $ ./gradlew assemble
> ```

## HelloWorld application
A simple publisher/subscriber application can be written by following the guide on [Writing a simple publisher and subscriber application](https://fast-rtps.docs.eprosima.com/en/latest/fastdds/getting_started/simple_app/simple_app.html#prerequisites). The *1.3.4.2.* paragraph has been skipped, since *Colcon* has not been installed.

> **Warning 2**
> </br>
> It was not possible to run the command of *1.3.6.* section:
> ```
> <path/to/Fast DDS-Gen>/scripts/fastrtpsgen HelloWorld.idl
> ```
> since *fastrtpsgen* does not exist at the following path, and seems to be
> deprecated. The following command has been run instead:
> ```
> <path-to-Fast-DDS-Gen>/scripts/fastddsgen HelloWorld.idl
> ```
> following the other guide on [Building a publish/subscribe application](https://fast-rtps.docs.eprosima.com/en/latest/fastddsgen/pubsub_app/pubsub_app.html#fastddsgen-pubsub-app).

There could be the possibility that *fastddsgen* add more files than the ones needed and denoted in the project tree structure at *1.3.3* section. In that case, you can delete the ones in excess (otherwise there will be multiple definitions of main).

> **Warning 3**
> </br>
> Once we run the command from the *build* folder:
> ```
> $ cmake ...
> ```
> there are errors due to the missing *fastcdr*, *fastrtps* e *foonathan_memory*
> libraries. It is possible to run this command instead:
> ```
> $ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/Fast-DDS/install/ ..
> ```

The libraries paths can be found from *$HOME* with:
```
$ find . | grep fastcdr-config.cmake
$ find . | grep fastrtps-config.cmake
$ find . | grep foonathan_memory-config.cmake
```
Now it is possible to follow the last steps to run both the Publisher and Subscriber applications.

## How to run RSWE library
- Clone the **RSWE_library** repository with:
    ```
    $ git clone https://github.com/GianlucaCerilli/RSWE_library.git
    ```
- Build the project by running the following commands in sequence:
    ```
    $ cd RSWE_library/build
    $ cmake -DCMAKE_INSTALL_PREFIX:PATH=~/Fast-DDS/install/ ..
    $ cmake .. && make clean && make
    ```
- It is possible to run the publisher and subscriber by running the following commands in two different terminals:
    ```
    $ ./publisherApp
    $ ./subscriberApp
    ```
- Otherwise, it is possible to run the publisher and subscriber in one single terminal, using threads. By running:
    ```
    $ ./threadSingleMsgApp
    ```
    we run an application in which a subscriber activates the publisher thread when it needs to receive a single message from it.
    </br>
    Instead, with this command:
    ```
    $ ./threadsStreamMsgsApp
    ```
    two different processes (publisher and subscriber threads) are runned together. The publisher streams a series of messages and the subscriber keeps listening.

    There could be the necessity to link the dynamic library *libfastcdr.so.1* when you launch *ThreadSingleMsgApp* or *ThreadSingleMsgApp*. You can do this by running the following commands:
    ```
    $ LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Fast-DDS/install/lib/
    $ export LD_LIBRARY_PATH
    ```
    and then run the executable again.
## RSWE library tasks
The main tasks required for the design of the **RSWE library** are:
- [x] Create custom messages
- [x] Send a single message/response between separate processes
- [x] Stream messages between separate processes
- [x] Display published messages in the terminal
- [x] Display what processes are publishing messages
- [] Stress test system
- [] Measure rate of sent messages
- [] Measure latency of sent messages

## Activities rundown
Here a rundown of the main activities that have been carried on approximately in the time indicated:
| Activity                                 | ~ Time spent (hr) |
| ---------------------------------------- | ----------------- |
| Libraries installation & problems fixing | 2.5               |
| Study of Fast-DDS documentation          | 1                 |
| Making the example application work      | 0.75              |
| Creation of the RSWE library             | 4                 |
| Writing of documentation                 | 1                 |