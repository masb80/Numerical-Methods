% Plot performances for MPI Heat2D %

% Loading input file
x=load('performances.txt');
% Get runtimes and number of processes
for i=1:3
   runTime(1:9,i)=(x((i-1)*9+1:i*9,3));
end
% Sequential time for each size
timeSeq(1:3)=runTime(1,1:3);
% Compute speedup values
for i=1:3
   speedUp(1:8,i)=timeSeq(i)./runTime(2:9,i);
end
% Number of processes on abscissa
y=[2 4 8 16 32 64 128 256];
% Plot histogram
figure(1);
hbar=bar(log2(y),speedUp(1:8,1:3),'b');
set(gca,'Xlim',[0 9]);
set(gca,'YLimMode','Auto');
set(gca,'xticklabel',{'2','4','8','16','32','64','128','256'});
xlabel('Number of Processes');
ylabel('SpeedUp');
title('Benchmark : SpeedUp vs Number of Processes');
% Define colors of bars
set(hbar(1),'facecolor','b');
set(hbar(2),'facecolor','r');
set(hbar(3),'facecolor','g');
% Transparency
set(hbar,'facealpha',0.4);
% Define legend
hlegend=legend('N=512^2','N=1024^2','N=2048^2');
rect=[0.66,0.76,0.1,0.1];
set(hlegend,'Position',rect,'color','none');
