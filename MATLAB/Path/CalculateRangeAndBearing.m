function  [range,bearing] = CalculateRangeAndBearing (point2, point1)
    [range, bearing] = distance(point1(1),point1(2),point2(1),point2(2));
    range = distdim(deg2nm(range),'nm','km');
end % 