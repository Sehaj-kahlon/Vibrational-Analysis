import serial
import csv
import time

# Specify the serial port and baud rate
# Replace 'COM3' with the actual port your Arduino is connected to
ser = serial.Serial('COM4', 9600, timeout=1)
time.sleep(2)  # Give some time for the serial connection to initialize

# Open/create a CSV file to save the data
with open('accelerometer_data.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write the header row
    writer.writerow(["Time", "Xa", "Ya", "Za"])
    
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        
        # Split the string to extract Xa, Ya, and Za values
        if line:
            try:
                # Assuming the output format is: "Xa= X_val   Ya= Y_val   Za= Z_val"
                data = line.split()
                Time = float(data[1])
                Xa = float(data[3])
                Ya = float(data[5])
                Za = float(data[7])

                
                # Write the values to the CSV file
                writer.writerow([Time, Xa, Ya, Za])
                
                # Print the data to verify
                print(f"Time={Time}, Xa={Xa}, Ya={Ya}, Za={Za}")
            except (IndexError, ValueError):
                # Handle any errors in parsing or converting to float
                print("Error parsing:", line)

# Don't forget to close the serial connection when done (although this may not be reached in this example)
ser.close()
