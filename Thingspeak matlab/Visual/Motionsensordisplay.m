
% Channel ID to read data from 
ChannelID = 2810501; 
% Temperature Field ID 
MotionID = 2; 

% Channel Read API Key  
readAPIKey = 'AMPXQDNAKUDP9COD'; 
% Enter the Write API Key between the '' below: 
writeAPIKey = '6475AR5ZBC5ZU3A7'; 

% Reads data
data = thingSpeakRead(ChannelID, 'Field', MotionID, 'ReadKey', readAPIKey, NumMinutes=30)
check = 0;

for i = 1:length(data)
    if data(i) >= 1
        check = 1;
    end
end

%adds a red or green box to show if there is movement.

if check == 1 
    plot(1,1)
    set(gca,'Color','g')
    xlim([0,2])
    ylim([0,2])
    txt = 'Motion';
    set(gca,'XTick',[], 'YTick', []);
    text(1,1,txt,'FontSize',20,'HorizontalAlignment','center');
else
    plot(1,1)
    set(gca,'Color','r')
    xlim([0,2])
    ylim([0,2])
    txt = 'No Motion';
    set(gca,'XTick',[], 'YTick', []);
    text(1,1,txt,'FontSize',20,'HorizontalAlignment','center');
end



