import serial
import csv
import time

# Specify the serial port and baud rate
ser = serial.Serial('/dev/tty.usbmodem1101', 9600, timeout=1)
time.sleep(2)  # Allow serial connection to initialize

# Open/create a CSV file to save the data
with open('accelerometer_data.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    
    # Write the header row
    writer.writerow(["Time", "Xa", "Ya", "Za"])
    
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()

        if line:
            try:
                # Ensure the line has expected keywords
                if "Time_Stamp=" in line and "Xa=" in line and "Ya=" in line and "Za=" in line:
                    # Split using '=' and extract values
                    parts = line.replace("=", "").split()
                    if len(parts) >= 8:  # Ensure all values are present
                        Time = float(parts[1])
                        Xa = float(parts[3])
                        Ya = float(parts[5])
                        Za = float(parts[7])
                        
                        # Write the values to the CSV file
                        writer.writerow([Time, Xa, Ya, Za])

                        # Print the data to verify
                        print(f"Time={Time}, Xa={Xa}, Ya={Ya}, Za={Za}")
                else:
                    print("Unexpected format:", line)

            except (IndexError, ValueError) as e:
                print(f"Error parsing line: {line} | Error: {e}")

# Close the serial connection (this line is never reached in the loop)
ser.close()
