
void AT24C02_write_bytes(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (((int)(param_1 + param_4) < 0x101) && (param_4 != 0)) {
    puVar3 = (undefined *)(param_2 + -1);
    uVar1 = param_1;
    do {
      puVar3 = puVar3 + 1;
      uVar2 = uVar1 + 1 & 0xff;
      write_EEPROM_iic(0,1,uVar1,param_3,*puVar3);
      uVar1 = uVar2;
    } while (uVar2 != (param_1 + param_4 & 0xff));
  }
  return;
}

