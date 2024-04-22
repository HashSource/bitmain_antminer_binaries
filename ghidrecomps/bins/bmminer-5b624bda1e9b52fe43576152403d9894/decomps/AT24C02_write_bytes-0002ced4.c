
/* WARNING: Unknown calling convention */

void AT24C02_write_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar *puVar4;
  
  printf(DAT_0002cf24,DAT_0002cf28);
  uVar1 = (uint)address + (uint)length;
  if (0x100 < uVar1) {
                    /* WARNING: Could not recover jumptable at 0x0000a420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f294)(DAT_0002cf2c,DAT_0002cf28,uVar1,0x100);
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

