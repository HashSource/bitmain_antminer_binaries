
void save_eeprom_N(undefined param_1,undefined param_2)

{
  undefined local_11 [8];
  undefined local_9;
  
  local_11[0] = param_1;
  local_9 = param_2;
  iic_write_reg(e2prom_fd,local_11,1,&local_9,1);
  return;
}

