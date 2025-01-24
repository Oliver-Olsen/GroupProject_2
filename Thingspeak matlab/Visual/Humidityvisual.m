% Author Emil
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID 
humiID = 4; 

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 

%reads data
[data,time] = thingSpeakRead(ChannelID, 'Field', humiID, 'ReadKey', readAPIKey,NumPoints=100);
humi = data./100;

%replaces NAN with -256
for i = 1:length(humi)
    if isnan(humi(i))
        humi(i) = -256;
    end
end
%makes scatter plot
scatter(time,humi)
ylim([0,100])

cmap = winter(256)  % Blue at bottom, red at top.
colormap(flipud(cmap));  % Apply colormap
colorbar;
caxis([0, 100]);
ylabel('Humidity %') 
