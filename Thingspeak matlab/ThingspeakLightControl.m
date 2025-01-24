% Author Emil
% Channel ID to read data from 
ChannelIDRead = 2810501; 
ChannelIDWrite = 2815518;
% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = 'UZG6FLYTIIJSFHSA'; 



MotionID = 2;
LightID = 6;
Time = 30;
Motiondetected = 0;


Motion = thingSpeakRead(ChannelIDRead,'Fields',MotionID,'ReadKey',readAPIKey,NumMinutes= Time);

for i = 1:length(Motion)
    if Motion(i) >= 1
        Motiondetected = 1;
    end
end


%test
%Motiondetected = 1

% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(5);
thingSpeakWrite(ChannelIDWrite,'Fields',LightID,'Values',Motiondetected,'WriteKey',writeAPIKey)
