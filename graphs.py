import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq

def plot_acceleration_graphs(file_path):
    # Load the CSV file
    df = pd.read_csv(file_path)
    
    # Convert Time from milliseconds to seconds
    df['Time'] = df['Time'] / 1000.0
    
    # Plot Time vs Acceleration for X, Y, and Z
    plt.figure(figsize=(10, 5))
    plt.plot(df['Time'], df['Xa'], label='X-Axis')
    plt.plot(df['Time'], df['Ya'], label='Y-Axis')
    plt.plot(df['Time'], df['Za'], label='Z-Axis')
    plt.xlabel('Time (seconds)')
    plt.ylabel('Acceleration')
    plt.title('Time vs Acceleration')
    plt.legend()
    plt.grid()
    plt.show()
    
    # Compute FFT for each acceleration axis
    sampling_rate = 1 / df['Time'].diff().mean()
    n = len(df['Time'])
    freq = fftfreq(n, d=1/sampling_rate)
    
    fft_x = np.abs(fft(df['Xa']))[:n//2]
    fft_y = np.abs(fft(df['Ya']))[:n//2]
    fft_z = np.abs(fft(df['Za']))[:n//2]
    freq = freq[:n//2]
    
    # Plot Frequency vs Acceleration
    plt.figure(figsize=(10, 5))
    plt.plot(freq, fft_x, label='X-Axis')
    plt.plot(freq, fft_y, label='Y-Axis')
    plt.plot(freq, fft_z, label='Z-Axis')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Acceleration Magnitude')
    plt.title('Frequency vs Acceleration')
    plt.legend()
    plt.grid()
    plt.show()

# Get file path from user
file_path = input("Enter the path to the CSV file: ")
plot_acceleration_graphs(file_path)
