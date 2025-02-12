import pandas as pd

def calculate_sampling_frequency(file_path):
    df = pd.read_csv(file_path)
    
    if 'Time' not in df.columns:
        raise ValueError("The CSV file must contain a 'Time' column.")
    
    time_diffs = df['Time'].diff().dropna()
    
    # Calculate the average sampling period (in milliseconds)
    avg_sampling_period_ms = time_diffs.mean()
    max_sampling_period_ms = time_diffs.min()
    
    # Convert to seconds
    avg_sampling_period_s = avg_sampling_period_ms / 1000
    max_sampling_period_s = max_sampling_period_ms / 1000
    
    # Compute the sampling frequency (Hz)
    sampling_frequency_hz = 1 / avg_sampling_period_s
    max_frequency_hz = 1 / max_sampling_period_s
    
    return sampling_frequency_hz, max_frequency_hz
file_path = input("Enter the path to the CSV file: ")
sampling_freq, max_freq = calculate_sampling_frequency(file_path)
print(f"Sampling Frequency: {sampling_freq:.2f} Hz")
print(f"Max Frequency: {max_freq:.2f} Hz")
