
% Channel ID to read data from 
ChannelIDRead = 2810501; 
ChannelIDWrite = 2815518;
% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = 'UZG6FLYTIIJSFHSA'; 


% Temperature Field ID 
CO2ID = 1; 
HumidityID = 4;
MotorID = 5;
Time = 10;




CO2 = thingSpeakRead(ChannelIDRead,'Fields',CO2ID,'ReadKey',readAPIKey,NumMinutes= Time)
Humidity = thingSpeakRead(ChannelIDRead,'Fields',HumidityID,'ReadKey',readAPIKey,NumMinutes= Time)

tempCO2 = 0;
temphum = 0;

numCO2 = 0;
numhum = 0;


%finds mean of CO2
for i = 1:length(CO2)
    if ~(isnan(CO2(i)))
        tempCO2 = tempCO2 + CO2(i);
        numCO2 = numCO2 +1;
    end
end


meanCO2 = tempCO2/(numCO2*100)

% finds mean if humidity
for i = 1:length(Humidity)
    if ~(isnan(Humidity(i)))
        temphum = temphum + Humidity(i);
        numhum = numhum +1;
    end
end

meanhum = temphum/(numhum*100)

%logic that controls the window

if (meanCO2 > 100 || meanhum > 60)
    Motorvalue = 1;
elseif (meanCO2 < 40 || meanhum < 35)
     Motorvalue = -1;
else
     Motorvalue = 0;
end
Motorvalue

%test
%should be comented
%Motorvalue = -1

% Learn more about the THINGSPEAKWRITE function by going to the Documentation tab on 
% the right side pane of this page. 

pause(5);
thingSpeakWrite(ChannelIDWrite,'Fields',MotorID,'Values',Motorvalue,'WriteKey',writeAPIKey)
