function MoveOneStep()

delay(GetStepClearance() / GetSpeed());

if PointSurpassed(GetCurrentPoint())
    
    IncrementPointIndex();
end% PointSurpassed()
end% MoveOneStep()