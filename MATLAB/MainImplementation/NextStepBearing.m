function bearing = NextStepBearing()
[range,bearing] = CalculateRangeAndBearing (GetNextPoint(), GetCurrentPoint());
end % NextStepBearing