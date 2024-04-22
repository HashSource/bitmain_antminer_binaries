
/* WARNING: Unknown calling convention */

void store_max_min_temperature(void)

{
  if (last_testpatten_lowest_pcb_temp < min_temperature) {
    min_temperature = last_testpatten_lowest_pcb_temp;
  }
  if (max_temperature < last_testpatten_highest_pcb_temp) {
    max_temperature = last_testpatten_highest_pcb_temp;
  }
  if (max_chip_temperature < last_testpatten_highest_chip_temp) {
    max_chip_temperature = last_testpatten_highest_chip_temp;
  }
  if (last_testpatten_lowest_chip_temp < min_chip_temperature) {
    min_chip_temperature = last_testpatten_lowest_chip_temp;
  }
  return;
}

