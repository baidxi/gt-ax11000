#!/bin/sh

echo "!!! ATE RUN-IN START !!!"

# CPU + MEMORY
echo "start stress..."
stress cpu -e 4 -t 30000 &

# 2G
echo "start eth5 pkteng..."
wl -i eth5 mpc 0
wl -i eth5 down
wl -i eth5 country ALL
wl -i eth5 wsec 0
wl -i eth5 stbc_rx 1
wl -i eth5 scansuppress 1
wl -i eth5 ssid ""
wl -i eth5 txbf 0
wl -i eth5 spect 0
wl -i eth5 mbss 0
wl -i eth5 ampdu 0
wl -i eth5 PM 0
wl -i eth5 stbc_tx 0
wl -i eth5 bi 65535
wl -i eth5 mimo_txbw -1
wl -i eth5 frameburst 1
wl -i eth5 spatial_policy 1
wl -i eth5 txcore  -s 1 -c 3
wl -i eth5 band b
wl -i eth5 bw_cap 2g 0x1
wl -i eth5 chanspec 1/20
wl -i eth5 vht_features 0
wl -i eth5 up
wl -i eth5 phy_forcecal 1
wl -i eth5 phy_watchdog 0
wl -i eth5 2g_rate -h 7 --ldpc -b 20
wl -i eth5 txpwr1 -o -q 76
wl -i eth5 phy_forcecal 1
wl -i eth5 pkteng_start 00:11:22:33:44:55 tx 100 220 0 00:22:44:66:88:00

# 5GL
echo "start eth6 pkteng..."
wl -i eth6 mpc 0
wl -i eth6 down
wl -i eth6 country ALL
wl -i eth6 wsec 0
wl -i eth6 stbc_rx 1
wl -i eth6 scansuppress 1
wl -i eth6 ssid ""
wl -i eth6 txbf 0
wl -i eth6 spect 0
wl -i eth6 mbss 0
wl -i eth6 ampdu 0
wl -i eth6 PM 0
wl -i eth6 stbc_tx 0
wl -i eth6 bi 65535
wl -i eth6 mimo_txbw -1
wl -i eth6 frameburst 1
wl -i eth6 spatial_policy 1
wl -i eth6 txcore  -s 1 -c 3
wl -i eth6 band a
wl -i eth6 bw_cap 5g 0x1
wl -i eth6 chanspec 36/20
wl -i eth6 vht_features 0
wl -i eth6 up
wl -i eth6 phy_forcecal 1
wl -i eth6 phy_watchdog 0
wl -i eth6 5g_rate -v 9x1 --ldpc -b 20
wl -i eth6 txpwr1 -o -q 76
wl -i eth6 phy_forcecal 1
wl -i eth6 pkteng_start 00:11:22:33:44:55 tx 100 293 0 00:22:44:66:88:00

# 5GH
echo "start eth7 pkteng..."
wl -i eth7 mpc 0
wl -i eth7 down
wl -i eth7 country ALL
wl -i eth7 wsec 0
wl -i eth7 stbc_rx 1
wl -i eth7 scansuppress 1
wl -i eth7 ssid ""
wl -i eth7 txbf 0
wl -i eth7 mbss 0
wl -i eth7 ampdu 0
wl -i eth7 PM 0
wl -i eth7 stbc_tx 0
wl -i eth7 bw_cap 5g 7
wl -i eth7 bi 65535
wl -i eth7 mimo_txbw -1
wl -i eth7 frameburst 1
wl -i eth7 spatial_policy 1
wl -i eth7 txcore  -s 1 -c 15
wl -i eth7 band a
wl -i eth7 bw_cap 5g 0x7
wl -i eth7 chanspec 149/80
wl -i eth7 he features 3
wl -i eth7 up
wl -i eth7 phy_forcecal 1
wl -i eth7 phy_watchdog 0
wl -i eth7 5g_rate -e 11 -s 1 -i 0 --ldpc -b 80
wl -i eth7 txpwr1 -o -q 80
wl -i eth7 phy_forcecal 1
wl -i eth7 pkteng_start 00:11:22:33:44:55 tx 100 410 0 00:22:44:66:88:04

# Start temperature polling
touch "tmp/Ate_temp_rec_start"
