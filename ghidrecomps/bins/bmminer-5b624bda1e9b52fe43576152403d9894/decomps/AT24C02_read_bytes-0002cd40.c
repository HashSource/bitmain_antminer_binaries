
/* WARNING: Unknown calling convention */

void AT24C02_read_bytes(uchar address,uchar *buf,uchar which_iic,uchar length)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  
  printf(DAT_0002cd90,DAT_0002cd94);
  uVar2 = (uint)address + (uint)length;
  if (0x100 < uVar2) {
                    /* WARNING: Could not recover jumptable at 0x0000a420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_LAB_0005f294)(DAT_0002cd98,DAT_0002cd94,uVar2,0x100);
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

