@startuml

title FaceLocker LifeCycle

start

:Start; 
note left: Load config, check if video input is available ... 

if (Is model available?) then (yes)
note left: Model should be saved on disk, path to model specified in config

  : Load Model ;
else (no)
  : Create Face model ;
  : Save Model to file ;
endif

repeat
    if (User is absent?) then (yes)
        : Wait timeout ;
        
        note left : timeout specified in config
        
        : Lock Screen ; 
        : Wait Screen Unlock ;
    endif
repeat while (until program exit)


@enduml
