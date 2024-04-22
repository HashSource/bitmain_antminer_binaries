
/* WARNING: Unknown calling convention */

void adjust_mostdevs(void)

{
  if (most_devices < total_devices - zombie_devs) {
    most_devices = total_devices - zombie_devs;
  }
  return;
}

