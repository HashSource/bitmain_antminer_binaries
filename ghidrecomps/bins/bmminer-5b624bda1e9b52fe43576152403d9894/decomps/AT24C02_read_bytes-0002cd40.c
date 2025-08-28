
/* WARNING: Unknown calling convention */

void AT24C02_read_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  undefined4 unaff_lr;
  
  printf("--- %s\n","AT24C02_read_bytes");
  uVar2 = (uint)address + (uint)length;
  if (0x100 < uVar2) {
    (*(code *)(undefined *)0x0)
              ("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n","AT24C02_read_bytes",uVar2,
               0x100,unaff_lr);
    return;
  }
  if (length == 0) {
    return;
  }
  puVar5 = buf + -1;
  uVar3 = (uint)address;
  do {
    uVar4 = uVar3 + 1 & 0xff;
    uVar1 = AT24C02_read_one_byte((uchar)uVar3,which_iic);
    puVar5 = puVar5 + 1;
    *puVar5 = uVar1;
    uVar3 = uVar4;
  } while (uVar4 != (uVar2 & 0xff));
  return;
}

