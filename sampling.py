import pandas as pd

def calculate_sampling_frequency(file_path):
    # Load the CSV file
    df = pd.read_csv(file_path)
    
    # Check if 'Time' column exists
    if 'Time' not in df.columns:
        raise ValueError("The CSV file must contain a 'Time' column.")
    
    # Compute time differences (in seconds)
    time_diffs_s = df['Time'].diff().dropna()
    
    # Calculate the average and minimum sampling periods (in seconds)
    avg_sampling_period_s = time_diffs_s.mean()
    min_sampling_period_s = time_diffs_s.min()
    
    # Compute the sampling frequencies (Hz)
    avg_sampling_frequency_hz = 1 / avg_sampling_period_s
    max_frequency_hz = 1 / min_sampling_period_s  # Max frequency is based on the min time gap
    
    return avg_sampling_frequency_hz, max_frequency_hz

# Get file path from user
file_path = input("Enter the path to the CSV file: ")
sampling_freq, max_freq = calculate_sampling_frequency(file_path)
print(f"Sampling Frequency: {sampling_freq:.2f} Hz")
print(f"Max Frequency: {max_freq:.2f} Hz")