
/* WARNING: Unknown calling convention */

void print_usage(void)

{
  puts("eeprom_test help:");
  puts(" -d [chain]                         dump eeprom");
  puts(" -l [chain]                         traverse eeprom friendly");
  puts(" -i [config file path]              init all eeprom with config file");
  puts(" -e [chain]                         erase eeprom");
  puts(" -w [chain] [eeprom addr] [data0 ...]    write eeprom");
  puts(" -r [chain] [eeprom addr] [length]  read eeprom");
  puts(" -p [chain] [pcb_ver] [bom_ver]      update PCB & BOM version");
  return;
}

