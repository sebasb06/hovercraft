function TestOutput()
    fid1 = fopen('test_output.txt','r'); 
    
    figure;
    all_coords = [];
    all_times = [];
    
    while ~feof(fid1)        
        line = fgets(fid1);
        line = line(1:end-1);
        
        time = line;
        
        line = fgets(fid1);
        line = line(1:end-1);        
        coords = line;
        coords = strsplit(coords,',');
       
        lat = char(coords(1));
        lon = char(coords(2));
       
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
        
        lat = str2num(lat(1:end-1)) * lat_sign;
        lon = str2num(lon(1:end-1)) * lon_sign;
        
               
        line = fgets(fid1);
        line = line(6:end-1);
        
        ypr = line;
        ypr = strsplit(ypr,',');

        time_s = str2num(time) / 1000;
        
        
        all_coords = [all_coords; [lat, lon]];
                
    end    
    fclose(fid1);
    
 
end