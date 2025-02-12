import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq
from scipy.interpolate import interp1d

# Load the dataset
file_path = 'readings/100V.csv'
data = pd.read_csv(file_path)

# Convert Time to seconds
data['Time'] = data['Time'] / 1000  # Convert milliseconds to seconds

# Filter data for the first 10 seconds
# data10s = data[data['Time'] <= 10]

# Define the interpolation function for uniform sampling
def resample_data(time, values, target_rate=1000):
    # Generate uniformly spaced time points
    uniform_time = np.linspace(time.min(), time.max(), int((time.max() - time.min()) * target_rate))
    # Interpolate the values
    interpolator = interp1d(time, values, kind='linear', fill_value='extrapolate')
    uniform_values = interpolator(uniform_time)
    return uniform_time, uniform_values

# Resample data for uniform sampling
target_rate = 1000  # Target sampling rate in Hz
time_uniform, Xa_uniform = resample_data(data['Time'], data['Xa'], target_rate)
_, Ya_uniform = resample_data(data['Time'], data['Ya'], target_rate)
_, Za_uniform = resample_data(data['Time'], data['Za'], target_rate)

# Perform FFT for each axis
def compute_fft(time, values, sampling_rate):
    N = len(values)  # Number of samples
    T = 1 / sampling_rate  # Sampling interval
    fft_result = fft(values)
    fft_magnitude = 2.0 / N * np.abs(fft_result[:N // 2])  # Magnitude
    fft_freqs = fftfreq(N, T)[:N // 2]  # Frequencies
    return fft_freqs, fft_magnitude

# Compute FFT for each axis
freqs_X, mag_X = compute_fft(time_uniform, Xa_uniform, target_rate)
freqs_Y, mag_Y = compute_fft(time_uniform, Ya_uniform, target_rate)
freqs_Z, mag_Z = compute_fft(time_uniform, Za_uniform, target_rate)

# Plot frequency vs. magnitude for each axis
plt.figure(figsize=(12, 8))

plt.subplot(3, 1, 1)
plt.plot(freqs_X, mag_X, label='X-axis', color='r')
plt.title('Frequency vs. Magnitude (X-axis)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid()
plt.legend()

plt.subplot(3, 1, 2)
plt.plot(freqs_Y, mag_Y, label='Y-axis', color='g')
plt.title('Frequency vs. Magnitude (Y-axis)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid()
plt.legend()

plt.subplot(3, 1, 3)
plt.plot(freqs_Z, mag_Z, label='Z-axis', color='b')
plt.title('Frequency vs. Magnitude (Z-axis)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid()
plt.legend()

plt.tight_layout()
plt.show()

