rm -f /home/heemanshu/dumps/cpu/sysbench_4
mkdir -p /home/heemanshu/dumps/cpu

# Running 12 iterations and taking the middle 10 for analysis
for it in {1..12}
do
    echo Iteration $it
    sysbench --test=cpu --cpu-max-prime=10000 run | grep "event execution:" | rev | cut -d\  -f1 | rev >> /home/heemanshu/dumps/cpu/sysbench_4
done
