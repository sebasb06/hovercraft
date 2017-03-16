function TestOutput()
    fid1 = fopen('test_output.txt','r'); 
    
    figure;
    all_coords = [];
    all_times = [];
    
    nline = 1;
    
    while ~feof(fid1)        
        line = fgets(fid1);
        line = line(1:end-1);
        
        nline = nline + 1;
        
        time = line;
        
        line = fgets(fid1);
        line = line(1:end-1);        
        
        nline = nline + 1;
        
        coords = line;
        coords = strsplit(coords,',');
       
      
        
        lat = char(coords(1));
        lon = char(coords(2));

        nline = nline + 1;

        if strcmp (lat(end), 'S')
            lat_sign = -1;
        else
            lat_sign = 1;
        end % if
        
        if strcmp (lon(end), 'W')
            lon_sign = -1;
        else
            lon_sign = 1;
        end % if 
        
        lat = str2num(lat(1:end-1)) * lat_sign / 100;
        lon = str2num(lon(1:end-1)) * lon_sign / 100;
        
               
        line = fgets(fid1);
        line = line(6:end-1);
        
        ypr = line;
        ypr = strsplit(ypr,',');

        time_s = str2num(time) / 1000;
        
        
        all_coords = [all_coords; [lat, lon]];
        all_times = [all_times, time_s];        
    end    
    fclose(fid1);

    
    all_speeds = [];
    all_bearings = [];

    for i=1:size(all_coords) - 1
        
        [range, bearing] = CalculateRangeAndBearing (all_coords(i + 1,:), all_coords(i,:));
        range_metres = range * 1000;     
        dt = all_times(i+1) - all_times (i);
                 
        all_speeds = [all_speeds; range_metres / dt];
        
        if bearing > 180
            bearing = bearing - 360;
        end % if
        
        all_bearings = [all_bearings; bearing];
        
    end % for
    
    figure;
    hold on;
    for i=1:size(all_coords) - 1
        plot ([all_coords(i,2),all_coords(i+1,2)], [all_coords(i,1),all_coords(i+1,1)])
    end % for
    
    
end