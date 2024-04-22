
/* WARNING: Unknown calling convention */

void AT24C02_write_bytes(uchar address,uchar *buf,uchar which_iic,uchar which_chain,uint length)

{
  uint uVar1;
  uchar *puVar2;
  uchar *puVar3;
  
  uVar1 = (uint)address;
  if (0x100 < uVar1 + length) {
    (*(code *)PTR_printf_00030118)
              ("\n--- %s: address + length = %d > EEPROM_LENGTH(%d)\n","AT24C02_write_bytes",
               uVar1 + length,0x100);
    return;
  }
  if (length == 0) {
    return;
  }
  puVar3 = buf;
  do {
    puVar2 = puVar3 + 1;
    AT24C02_write_one_byte((uchar)uVar1,*puVar3,which_iic,which_chain);
    uVar1 = uVar1 + 1 & 0xff;
    puVar3 = puVar2;
  } while (puVar2 != buf + length);
  return;
}

