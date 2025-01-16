
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID  
MotionID = 2;
LightID = 6;
Time = 10

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 
Motiondetected = 0;


Motion = thingSpeakRead(ChannelID,'Fields',MotionID,'ReadKey',readAPIKey,NumMinutes= Time);

for i = 1:length(Motion)
    if Motion(i) >= 1
        Motiondetected = 1;
    end
end

% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(20);
thingSpeakWrite(ChannelID,'Fields',LightID,'Values',Motiondetected,'WriteKey',writeAPIKey)
