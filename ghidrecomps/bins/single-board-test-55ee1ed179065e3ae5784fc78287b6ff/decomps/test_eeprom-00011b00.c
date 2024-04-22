
undefined4 test_eeprom(void)

{
  undefined4 uVar1;
  byte local_f;
  byte local_e;
  undefined local_d;
  int local_c;
  
  local_d = 0x90;
  local_e = 0x5a;
  local_f = 0xa5;
  local_c = 0;
  printf("test_set_eeprom_val = %x\n",0x5a);
  iic_write_reg(e2prom_fd,&local_d,1,&local_e,1);
  usleep(100000);
  local_c = iic_read_reg(e2prom_fd,&local_d,1,&local_f,1);
  if (local_c == 1) {
    printf("test_get_eeprom_val = %x\n",(uint)local_f);
    if (local_f == local_e) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

