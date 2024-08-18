# Overview


This is a physics simulation of the radiation dose delivered by photons. It consists of one detector made out of NaI, and one particle gun that shoots changable gamma particles. 

I edited this software to become familiar with Geant4 and it's organization. 
# How to run

To run this project, you must have [CMake](https://cmake.org/) installed for compiling. You also need to have the [Geant4](https://geant4.web.cern.ch/) source code installed.

Once you have the prerequisites, compile this example with CMake, then click on the executable it creates. It should automatically create a viewer and you should be able to see the square detector displayed. Then you can run the `test_run.mac` file and it will shoot some photons at the detector. It will display the dose given on the terminal window. 

 

# Useful Websites

- [MinGLE Mini Geant4 Learning Example](https://github.com/jintonic/mingle)
- [Geant4 website](https://geant4.web.cern.ch/)
- [Geant4 help for application developers](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/index.html)
- [Geant4 forum](https://geant4-forum.web.cern.ch/)
- [CMake website](https://cmake.org/)
- [Qt website](https://www.qt.io/)


