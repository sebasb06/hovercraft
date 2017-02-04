function resulting_points=Cal0culatePoints (a, b, distance_meters)
% CalculatePoints Calculates points along a path.

bearing_ba = CalculateBearing (b,a);
resulting_points = [];
c = a;
x = a;
while CalculateRange (x,a) < CalculateRange (b,a)
    x = DisplacementToPoint (c, distance_meters, bearing_ba);
    c = x;
    resulting_points = [resulting_points; x];    
end

end
