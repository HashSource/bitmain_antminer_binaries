
/* WARNING: Unknown calling convention */

void set_hcnt(uint hcnt)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint ret;
  uint uVar4;
  int iVar5;
  uchar buf [9];
  uint cmd_buf [3];
  
  piVar2 = DAT_000342d4;
  piVar1 = DAT_000342d0;
  iVar5 = 0;
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  do {
    while ((*(int *)(*piVar1 + (iVar5 + 2) * 4) == 1 && (*piVar2 != 0))) {
      buf[0] = 'X';
      buf[1] = '\t';
      buf[2] = '\0';
      buf[3] = '\x14';
      buf._4_2_ = CONCAT11((uchar)(hcnt >> 0x10),(uchar)(hcnt >> 0x18));
      buf._4_3_ = CONCAT12((uchar)(hcnt >> 8),buf._4_2_);
      buf[7] = (uchar)hcnt;
      buf[8] = CRC5(buf,'@');
      cmd_buf[2] = (uint)buf[8] << 0x18;
      cmd_buf[0] = 0x58090014;
      cmd_buf[1] = ((hcnt << 8) >> 0x18) << 0x10 | hcnt & 0xff000000 | hcnt & 0xff |
                   ((hcnt << 0x10) >> 0x18) << 8;
      set_BC_command_buffer(cmd_buf);
      uVar3 = get_BC_write_command();
      uVar4 = iVar5 << 0x10;
      iVar5 = iVar5 + 1;
      set_BC_write_command(uVar3 & 0xfff0ffff | uVar4 | 0x80800000);
      if (iVar5 == 0x10) {
        return;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x10);
  return;
}

