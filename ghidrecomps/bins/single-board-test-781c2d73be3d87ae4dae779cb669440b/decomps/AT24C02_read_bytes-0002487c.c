
/* WARNING: Unknown calling convention */

void AT24C02_read_bytes(uchar address,uchar *buf,uchar which_iic,uchar which_chain,uint length)

{
  uchar uVar1;
  uint uVar2;
  uchar *puVar3;
  uchar *puVar4;
  
  uVar2 = (uint)address;
  if (0x100 < uVar2 + length) {
    (*(code *)PTR_printf_00030118)
              ("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n",DAT_000248d4,uVar2 + length,
               0x100);
    return;
  }
  if (length == 0) {
    return;
  }
  puVar3 = buf;
  do {
    uVar1 = AT24C02_read_one_byte((uchar)uVar2,which_iic,which_chain);
    puVar4 = puVar3 + 1;
    *puVar3 = uVar1;
    uVar2 = uVar2 + 1 & 0xff;
    puVar3 = puVar4;
  } while (puVar4 != buf + length);
  return;
}

