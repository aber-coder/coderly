window_size = int(input("Enter window size: "))

for frame in range(window_size):
    print(f"Frame {frame} transferred")

lost_frame = int(input("Acknowledgement not recieved for: "))

print(f"Frame {lost_frame} transferred")
