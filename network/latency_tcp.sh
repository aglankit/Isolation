rm -f /home/heemanshu/dumps/network/tcp_latency
mkdir -p /home/heemanshu/dumps/network

for it in {1..30}
do
    ping $1 -i 0.2 -c 10 | grep icmp | rev | cut -d= -f1 | cut -d\  -f2  | rev >> /home/heemanshu/dumps/network/tcp_latency
    echo Iteration $it
done
