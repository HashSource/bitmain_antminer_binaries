
void save_eeprom_N(undefined1 param_1,undefined1 param_2)

{
  undefined1 local_11 [8];
  undefined1 local_9;
  
  local_11[0] = param_1;
  local_9 = param_2;
  iic_write_reg(e2prom_fd,local_11,1,&local_9,1);
  return;
}

