function dataImporting()
    % List of CSV files to process
    csvFiles = { ...
        'new_readings/4V.csv', ...
        'new_readings/6V.csv', ...
        'new_readings/8V.csv', ...
        'new_readings/12V.csv', ...
        'new_readings/16V.csv', ...
        'new_readings/18V.csv', ...
        'new_readings/20V.csv', ...
    };

    % Loop through each file and call the function
    for i = 1:length(csvFiles)
        try
            main(csvFiles{i});
        catch ME
            % Handle errors (e.g., log and continue to the next file)
            warning('Failed to process file %s: %s', csvFiles{i}, ME.message);
        end
    end
end

function main(csvFileName)
    % Validate file existence
    if ~isfile(csvFileName)
        error('The specified file does not exist: %s', csvFileName);
    end

    % Read data from the CSV file
    data = readtable(csvFileName);

    % Ensure there are at least two columns
    if width(data) < 2
        error('The CSV file must contain at least two columns (time and one data column).');
    end

    % Extract time column (assume it's the first column)
    time = data{:,1};  % First column as time

    % Check if time is monotonically increasing
    if any(diff(time) <= 0)
        error('The time column must be monotonically increasing.');
    end

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

    % Generate a dynamic MAT file name
    [~, name, ~] = fileparts(csvFileName);
    matFileName = ['_', name, '_scenario.mat'];

    % Save the Dataset object as a MAT file
    save(matFileName, 'scenario');

    % Display a message indicating successful conversion
    disp(['Data from ', csvFileName, ' has been saved in a Simulink Dataset scenario in ', matFileName]);
end
