
% Channel ID to read data from 
ChannelIDRead = 2815518; 
ChannelIDWrite = 2815518;
% Channel Read API Key  
readAPIKey = 'AOZUNN780N8DL3VL'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = 'UZG6FLYTIIJSFHSA'; 



ClimateID = 5;
LightID = 6;
TempID = 7;


Climate = thingSpeakRead(ChannelIDRead,'Fields',ClimateID,'ReadKey',readAPIKey);
Light = thingSpeakRead(ChannelIDRead,'Fields',LightID,'ReadKey',readAPIKey);
Temp = thingSpeakRead(ChannelIDRead,'Fields',TempID,'ReadKey',readAPIKey);

data = [0,0,0] ;


if (Climate == 1) || (Climate == 0)
    data(1) = -1;
else
    data(1) = 1;
end

if (Light == 1)
    data(2) = 0;
else
    data(2) = 1;
end

if (Temp == 1) || (Temp == 0)
    data(3) = -1;
else
    data(3) = 1;
end

%test
%Motiondetected = 1

% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(5);
data
thingSpeakWrite(ChannelIDWrite,'Fields',[ClimateID,LightID,TempID],'Values',data,'WriteKey',writeAPIKey)
