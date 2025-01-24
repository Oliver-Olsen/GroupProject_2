% Author Emil
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID 
TempID = 3; 

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 

%reads data
[data,time] = thingSpeakRead(ChannelID, 'Field', TempID, 'ReadKey', readAPIKey,NumPoints=100);
temp = data./100;

%finds NAN and replaces it
for i = 1:length(temp)
    if isnan(temp(i))
        temp(i) = -256;
    end
end

%shows time 
scatter(time,temp)
ylim([0,40])
%Adds info bar
cmap = parula(256)  % Blue at bottom, red at top.
colormap((cmap));  % Apply colormap
colorbar;
caxis([0, 40]);
ylabel('Degrees \circC') 
