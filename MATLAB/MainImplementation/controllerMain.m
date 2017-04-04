function HovercraftMain()
% HovercraftMain main Hovercraft controller.
% Implementation of system diagram.

SetInitialConditions();
GeneratePath(GetInitialPoint());
 
% Main loop
while condition    
    if HovercraftOnPath()
       PIController_Bearing();
    else 
       GeneratePath(GetCurrentPoint()); 
    end % if
    
    MoveOneStep();   
end % while


end 