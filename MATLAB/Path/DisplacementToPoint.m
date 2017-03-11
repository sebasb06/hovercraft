function  pt = DisplacementToPoint (location, distance_km, bearing)
latd = location(1);
lond = location(2);
distIn = distance_km;
dist = nm2deg(distdim(distIn,'km','nm'));
pt = reckon(latd,lond,dist,bearing);
end % DisplacementToPoint