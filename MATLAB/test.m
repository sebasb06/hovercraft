fid= fopen('test_output','r');
data = fread(fid);
chardata=char(data);
fclose(fid);
disp(data)