import asyncio
import random


class LeakyBucket:
    def __init__(self, bucket_capacity: int, leak_rate: int):
        self.bucket_capacity = bucket_capacity
        self.leak_rate = leak_rate
        self.current_data = 0

    async def add_data(self, data_amount: int):
        print(f"Bucket has {self.current_data} units")
        if self.current_data + data_amount > self.bucket_capacity:
            dropped_data = (self.current_data + data_amount) - self.bucket_capacity
            self.current_data = self.bucket_capacity
            print(f"Overflow! Dropped {dropped_data} units of data.")
        else:
            self.current_data += data_amount
            print(
                f"Added {data_amount} units of data. Bucket has: {self.current_data} units."
            )

    async def leak(self):
        while True:
            if self.current_data > 0:
                print(f"Before leaking: Bucket has {self.current_data} units")
                leak = min(self.current_data, self.leak_rate)
                self.current_data -= leak
                print(
                    f"Leaked {leak} units of data. Bucket has: {self.current_data} units."
                )
            else:
                print("No data to leak, pausing leak.")
                await asyncio.sleep(1)
            await asyncio.sleep(1)

    async def process(self, duration: int):
        start_time = asyncio.get_event_loop().time()
        while True:
            incoming_data = random.randint(0, 5)
            print(f"\nIncoming data: {incoming_data} units.")
            await self.add_data(incoming_data)
            if asyncio.get_event_loop().time() - start_time > duration:
                print(f"\nProcess stopped after {duration} seconds.")
                break
            await asyncio.sleep(1)


async def main():
    bucket_capacity = 10
    leak_rate = 2
    max_duration = 5

    leaky_bucket = LeakyBucket(bucket_capacity, leak_rate)
    leak_task = asyncio.create_task(leaky_bucket.leak())
    await leaky_bucket.process(max_duration)
    leak_task.cancel()


asyncio.run(main())
