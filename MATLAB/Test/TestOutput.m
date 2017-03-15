function TestOutput()
    fid1 = fopen('output1.TXT','r'); 
    while ~feof(fid1)        
        line = fgets(fid1);
        line = line(1:end-1)
        
        %A = sscanf(line,'%*[^,],%f,%f'); %# sscanf can read only numeric 
        % data :(
        %if A(2)<4.185 %# test the values
        %    fprintf(fid2,'%s',line) %# write the line to the new file
        %end
        
    end    
    fclose(fid1);
end