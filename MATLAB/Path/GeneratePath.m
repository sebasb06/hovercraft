function GeneratePath(initial_point)
    global path_points
    if OnFirstLeg()
        path_points = CalculatePoints(initial_point, GetNeckPoint(), GetPointSpacing());
        path_points = [path_points; CalculateSemicircularPath(GetNeckPoint(), GetFinalPoint())]; 
    else
        path_points = CalculatePoints(initial_point, GetFinalPoint(), GetPointSpacing());        
    end


end % GeneratePath