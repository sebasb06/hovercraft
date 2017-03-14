function HovercraftMain()
% HovercraftMain main Hovercraft controller.
% Implementation of system diagram.


SetInitialConditions();
GeneratePath();
 
% Main loop
while condition    
    if HovercraftOnPath()
       PIController_Bearing();
    else 
       GeneratePath(); 
    end 
    
    MoveOneStep();   
end % while


end 