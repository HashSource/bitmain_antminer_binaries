
/* WARNING: Unknown calling convention */

void low_temperature_freq_handler(void)

{
  FILE *__stream;
  FILE *pFile;
  uint32_t inc_freq;
  int asic;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < 0x3c; asic = asic + 1) {
        scan_result[chain].freq_eeprom[asic] = scan_result[chain].freq_eeprom[asic] + 10;
        if (g_sweep_config_eco.sweep_max_freq + 10U < scan_result[chain].freq_eeprom[asic]) {
          scan_result[chain].freq_eeprom[asic] = g_sweep_config_eco.sweep_max_freq + 10;
        }
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: chain[%d] increase [%d] MHz...\n","driver-btm-soc.c",0x151c,
                  "low_temperature_freq_handler",chain,10);
        }
        fclose(__stream);
      }
    }
  }
  return;
}

