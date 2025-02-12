% MATLAB script to convert each column in a CSV file to individual timeseries objects within a Simulink Dataset scenario

% Specify the CSV file name (ensure it's in the same directory or provide full path)
csvFileName = '100V.csv';

% Read data from the CSV file
data = readtable(csvFileName);

% Extract time column (assume it's the first column)
time = data{:,1};  % First column as time

% Initialize a Simulink Dataset object for the scenario
scenario = Simulink.SimulationData.Dataset;

% Loop through each column (starting from the second column)
for col = 2:width(data)
    % Get the variable name for the current column
    varName = data.Properties.VariableNames{col};
    
    % Extract data for the current column
    dataValues = data{:,col};
    
    % Create a timeseries object for the current data column
    ts = timeseries(dataValues, time);
    ts.Name = varName;  % Set the name of the timeseries object to the column name
    
    % Add the timeseries object to the Dataset
    scenario = scenario.addElement(ts, varName);
end

% Save the Dataset object as a MAT file
matFileName = 'your_scenario_file.mat';
save(matFileName, 'scenario');

% Display a message indicating successful conversion
disp(['Data from ', csvFileName, ' has been saved in a Simulink Dataset scenario in ', matFileName]);
