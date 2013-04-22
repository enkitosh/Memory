Memory
=====

Playing around with virtual memory translation

To build:
    
    git clone https://github.com/enkitosh/Memory.git
    cd Memory
    make clean && make
    
Usage:
    
    ./memory [-virtual/physical] [-page size] [-set-associative] [-bits]
    
Example:

    ./memory virtual 4096 4 20

or:
    
    ./memory physical 4096 4 16
    
The program simply shows which fields would be used to determine the following:
    
    Virtual/
    VPO  : The virtual page offset
    VPN  : The virtual page number
    TLBI : The TLB index
    TLBT : The TLB tag
    
    Physical/
    PPO  : The physical page offset
    PPN  : The physical page number


Your output should then look something like this:
    
https://www.dropbox.com/s/jo61pnd4099226r/cache.png
    
Todo:

Show translation between virtual and physical addresses

sleep......
