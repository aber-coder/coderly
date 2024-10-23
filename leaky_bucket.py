
from random import randint
from time import sleep, time


class LeakyBucket:
    def __init__(self, cap, rate, duration=4):
        self.cap = cap
        self.rate = rate
        self.curr = 0
        self.duration = duration

    def add(self):
        incoming_data = randint(0, self.cap + 5)
        self.curr += incoming_data
        print(f"Incoming data: {incoming_data}, Current level: {self.curr}")
        self.overflow()

    def leak(self):
        if self.curr == 0:
            print("Not leaking, currently paused")
        else:
            leak = min(self.curr, self.rate)
            print(f"Leaking: {leak}, Current level: {self.curr}")
            self.curr -= leak

    def overflow(self):
        if self.curr > self.cap:
            overflow_amount = self.curr - self.cap
            print(f"Overflowing: {overflow_amount}, Reducing to capacity")
            self.curr = self.cap

    def run_simulation(self):
        start_time = time()

        while time() - start_time < self.duration:
            self.add()
            self.leak()
            sleep(1)

        print("Simulation complete")


if __name__ == "__main__":
    leaky_bucket = LeakyBucket(10, 4)

    leaky_bucket.run_simulation()
