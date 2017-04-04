function on_path=HovercraftOnPath()
    desired_bearing = NextStepBearing();
    
    difference = abs(CurrentBearing() - desired_bearing) ;
    
    while difference > 180
        difference = difference - 360;
    end % while
      
    on_path = diff < 10;
end %HovercraftOnPath