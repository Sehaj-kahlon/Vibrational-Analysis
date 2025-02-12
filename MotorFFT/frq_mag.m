% Load the data
data = readtable('with load/2-5Load.csv'); % Replace with your file path

% Extract time and signal (e.g., acceleration along the X-axis)
time = data{:, 1} / 1000; % Convert milliseconds to seconds if needed
signal = data{:, 2};      % Example: X-axis acceleration

% Sampling rate and parameters
Fs = 1 / mean(diff(time)); % Sampling frequency (Hz)
N = length(signal);        % Number of samples
T = 1 / Fs;                % Sampling interval (seconds)

% Perform FFT
fft_result = fft(signal);
P2 = abs(fft_result / N);   % Two-sided spectrum
P1 = P2(1:N/2+1);           % Single-sided spectrum
P1(2:end-1) = 2 * P1(2:end-1); % Adjust magnitudes for single-sided spectrum

% Frequency bins
frequencies = Fs * (0:(N/2)) / N;

% Plot Frequency vs Magnitude
figure;
plot(frequencies, P1, 'b');
title('Frequency vs Magnitude');
xlabel('Frequency (Hz)');
ylabel('Magnitude');
grid on;
xlim([0,50]); % Optional: Limit to frequencies below 50 Hz
