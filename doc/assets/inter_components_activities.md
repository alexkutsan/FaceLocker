
@startuml
(Face choose) as FC
(Model creating) as MC
(Face recognition) as FR
(UserWatchdog) as UW
(OS) as OS

FC -> MC : FaceCoosed(Frame with face box)
MC -> FC : Reset()
MC -> FR : ModelCreated(model)
FR -> FC : Reset()
FR -> UW : IsUserPresent(boolean)
UW -> OS : Lock

@enduml
