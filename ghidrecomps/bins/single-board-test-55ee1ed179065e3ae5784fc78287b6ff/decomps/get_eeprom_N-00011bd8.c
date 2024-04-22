
bool get_eeprom_N(undefined param_1,undefined4 param_2)

{
  int iVar1;
  undefined local_11 [5];
  undefined4 local_c;
  
  local_c = 0;
  local_11[0] = param_1;
  iVar1 = iic_read_reg(e2prom_fd,local_11,1,param_2,1);
  return iVar1 == 1;
}

