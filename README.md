#open_ipos

This is the Open iPOS Project (iPOS as in Integrated Point of Sale) with implementations for the Swedbank initiated integration protocol iPOS.

* The iPOS Protocol Specification is Copywright Swedbank AB.
* This open source is restricted to not expose requirements and specificagion details owned by Swedbank AB.
* Swedbank has made the iPOS Specification publicly available at https://ipos.lighthouseapp.com/projects/37410/messages/47344-ipos-32-release
* Please contact Swebank AB if you require a copy of any later release of this specification.

##Project Content

```
C:\Users\kjell-olovhogdahl\Documents\GitHub\open_ipos>tree /F
Folder PATH listing
Volume serial number is D49B-BB89
C:.
│   README.md
│
└───build
    │   CMakeLists.txt
    │   msys2_clang_me.sh
    │   msys2_deafult_me.sh
    │   vs_me.cmd
    │
    └───src
        ├───api
        │   │   APIFiniteStateMachine.cpp
        │   │   APIFiniteStateMachine.h
        │   │   dllmain.cpp
        │   │   iPOSApiImpl.cpp
        │   │   iPOSApiImpl.def
        │   │   iPOSApiImpl.h
        │   │   OpeniPosAPICore.cpp
        │   │   OpeniPosAPICore.h
        │   │
        │   └───.vscode
        │           .BROWSE.VC.DB
        │           .BROWSE.VC.DB-wal
        │
        ├───app
        │       main.cpp
        │       OpeniPosFrontEnd.cpp
        │       OpeniPosFrontEnd.h
        │
        └───external
            └───tris                        // sub-module https://github.com/kjelloh/tris
                │   LICENSE
                │   README.md
                │
                └───build
                    │   CMakeLists.txt
                    │   msys2_clang_me.sh
                    │   msys2_deafult_me.sh
                    │   vs_me.cmd
                    │
                    └───src
                            Active.cpp
                            Active.h
                            BackEnd.cpp
                            BackEnd.h
                            Core.cpp
                            Core.h
                            FrontEnd.cpp
                            FrontEnd.h
                            tris_main_template.cpp


C:\Users\kjell-olovhogdahl\Documents\GitHub\open_ipos>
```
