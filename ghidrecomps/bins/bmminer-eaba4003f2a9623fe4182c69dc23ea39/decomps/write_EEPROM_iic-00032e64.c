
uchar write_EEPROM_iic(_Bool read,_Bool reg_addr_valid,uchar reg_addr,uchar which_iic,uchar data)

{
  uchar uVar1;
  char cVar2;
  uint uVar3;
  uchar which_iic_local;
  uchar reg_addr_local;
  _Bool reg_addr_valid_local;
  _Bool read_local;
  uchar ret;
  uint counter;
  uint value;
  
  value = 0;
  counter = 0;
  while( true ) {
    get_iic();
    uVar3 = counter;
    if (counter < 4) {
      uVar3 = 0;
    }
    cVar2 = (char)uVar3;
    if (3 < counter) {
      cVar2 = '\x01';
    }
    counter = counter + 1;
    if (cVar2 != '\0') break;
    usleep(1000);
  }
  if (read) {
    value = 0x2000000;
  }
  if (reg_addr_valid) {
    value = (uint)reg_addr << 8 | value | 0x1000000;
  }
  uVar1 = set_iic((uint)data | (which_iic & 7) << 0x10 | value | 0xa00000);
  return uVar1;
}

