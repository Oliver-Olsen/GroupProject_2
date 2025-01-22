
% Channel ID to read data from 
ChannelIDRead = 2810501; 
ChannelIDWrite = 2815518;
% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = 'UZG6FLYTIIJSFHSA'; 



TempID = 3;
HeaterID = 7;
Time = 10;



Motorrotation = 0;

DeciTemp = thingSpeakRead(ChannelIDRead,'Fields',TempID,'ReadKey',readAPIKey,NumMinutes= Time);
Temp = mean(DeciTemp)/10;



if (Temp > 24)
    Motorrotation = -1;
elseif (Temp < 20)
     Motorrotation = 1;
else
     Motorrotation = 0;
end



% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

%Motorrotation = 1

pause(5);
thingSpeakWrite(ChannelIDWrite,'Fields',HeaterID,'Values',Motorrotation,'WriteKey',writeAPIKey)
