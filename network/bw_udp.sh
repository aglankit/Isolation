rm -f /home/heemanshu/dumps/network/udp_bw
mkdir -p /home/heemanshu/dumps/network

# Running 12 iterations and taking the middle 10 for analysis
for it in {1..12}
do
    # Extracting throughput data from iperf
    iperf -t 30 -c $1 -u -b 1G | grep \/sec | rev | cut -d\  -f2 | rev | sed '1q;d' >> /home/heemanshu/dumps/network/udp_bw
    echo Iteration $it
done
