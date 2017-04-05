function p = GetFinalPoint()
    if OnFirstLeg()
        p = [00.00000, 00.00000];
    else
        p = GetInitialPoint();
    end % if

end 