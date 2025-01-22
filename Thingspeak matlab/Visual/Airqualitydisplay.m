
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID 
CO2ID = 1; 

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 

% Gets data
[data,time] = thingSpeakRead(ChannelID, 'Field', CO2ID, 'ReadKey', readAPIKey,NumPoints=100);
CO2 = data./100;

% removes all NAN and replaces replaces it.
for i = 1:length(CO2)
    if isnan(CO2(i))
        CO2(i) = 0;
    end
end

% makes a scatter plot
scatter(time,CO2)
ylim([1,100])

%adds information bar to the right of the plot
cmap = summer(256)  % Blue at bottom, red at top.
colormap(cmap);  % Apply colormap
colorbar;
caxis([0, 100]);
ylabel('Concentration ppm ') 
