
/* WARNING: Unknown calling convention */

void AT24C02_write_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar *puVar4;
  undefined4 unaff_lr;
  
  printf("--- %s\n","AT24C02_write_bytes");
  uVar1 = (uint)address + (uint)length;
  if (0x100 < uVar1) {
    (*(code *)(undefined *)0x0)
              ("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n","AT24C02_write_bytes",uVar1,
               0x100,unaff_lr);
    return;
  }
  if (length == 0) {
    return;
  }
  puVar4 = buf + -1;
  uVar2 = (uint)address;
  do {
    uVar3 = uVar2 + 1 & 0xff;
    puVar4 = puVar4 + 1;
    AT24C02_write_one_byte((uchar)uVar2,*puVar4,which_iic);
    uVar2 = uVar3;
  } while (uVar3 != (uVar1 & 0xff));
  return;
}

