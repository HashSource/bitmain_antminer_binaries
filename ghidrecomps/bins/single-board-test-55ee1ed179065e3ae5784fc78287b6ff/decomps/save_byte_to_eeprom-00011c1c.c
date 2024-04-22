
undefined save_byte_to_eeprom(undefined param_1,byte param_2)

{
  int iVar1;
  byte local_a;
  undefined local_9;
  
  local_9 = 1;
  save_eeprom_N(param_1,param_2);
  usleep(500000);
  iVar1 = get_eeprom_N(param_1,&local_a);
  if (iVar1 == 0) {
    puts("Get value from eeprom Error");
    local_9 = 0;
  }
  else {
    printf("The value write to eeprom : 0x%02X\n",(uint)param_2);
    printf("The value get from eeprom : 0x%02X\n",(uint)local_a);
    if (param_2 != local_a) {
      puts("Save eeprom Error");
      local_9 = 0;
    }
  }
  return local_9;
}

