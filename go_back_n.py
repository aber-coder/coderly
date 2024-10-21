window_size = int(input("Enter window size: "))

frames = [f"Frame {frame} transferred" for frame in range(window_size)]

print(*frames, sep="\n")

while (
    last_ack := int(input("Enter the last acknowledgement received: "))
) != window_size - 1:
    print(last_ack)
    print(*frames[last_ack:], sep="\n")

print("Frame transfer done")
