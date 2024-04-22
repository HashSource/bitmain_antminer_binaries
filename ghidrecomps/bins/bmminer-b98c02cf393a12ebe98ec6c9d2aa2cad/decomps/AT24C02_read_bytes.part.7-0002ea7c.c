
void AT24C02_read_bytes_part_7(uint param_1,undefined *param_2,undefined4 param_3,int param_4)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_4 != 0) {
    uVar2 = param_1;
    do {
      uVar3 = uVar2 + 1 & 0xff;
      uVar1 = write_EEPROM_iic(1,1,uVar2,param_3,0);
      *param_2 = uVar1;
      uVar2 = uVar3;
      param_2 = param_2 + 1;
    } while (uVar3 != (param_1 + param_4 & 0xff));
    return;
  }
  return;
}

