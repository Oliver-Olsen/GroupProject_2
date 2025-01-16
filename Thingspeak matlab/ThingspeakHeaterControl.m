
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID  
TempID = 3;
HeaterID = 7;
Time = 10;

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 
Motorrotation = 0;

DeciTemp = thingSpeakRead(ChannelID,'Fields',TempID,'ReadKey',readAPIKey,NumMinutes= Time);
Temp = mean(DeciTemp)/10;



if (Temp > 26)
    Motorrotation = 5;
elseif (Temp < 22)
     Motorrotation = -5;
else
     Motorrotation = 0;
end



% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(20);
thingSpeakWrite(ChannelID,'Fields',HeaterID,'Values',Motorrotation,'WriteKey',writeAPIKey)
