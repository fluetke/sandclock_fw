# sandclock_fw
Firmware for the Sandclock I designed for the Prusaprinters "Timekeepers" contest

You can download the required 3d-print parts for the Sandclock at https://www.prusaprinters.org/prints/68560-prusadusa-and-the-sands-of-time-clock

This firmware is currently very basic, it serves just 2 purposes:
- driving the stepper motor at 1 rpm without being killed by the ESPs Watchdog
- enabling later firmware-updates OTA as the controller is hidden behind a layer of sand deep inside the housing of the clock
