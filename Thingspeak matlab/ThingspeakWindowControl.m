
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID 
CO2ID = 1; 
HumidityID = 4;
MotorID = 5;
Time = 10;

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 


CO2 = thingSpeakRead(ChannelID,'Fields',CO2ID,'ReadKey',readAPIKey,NumMinutes= Time);
Humidity = thingSpeakRead(ChannelID,'Fields',HumidityID,'ReadKey',readAPIKey,NumMinutes= Time); 


if (mean(CO2) > 600) || (mean(Humidity) > 25)
    Motorvalue = 2;
elseif (mean(CO2) < 400) || (mean(Humidity) < 20)
     Motorvalue = 1;
else
     Motorvalue = 0;
end




% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(15);
thingSpeakWrite(ChannelID,'Fields',MotorID,'Values',Motorvalue,'WriteKey',writeAPIKey)

