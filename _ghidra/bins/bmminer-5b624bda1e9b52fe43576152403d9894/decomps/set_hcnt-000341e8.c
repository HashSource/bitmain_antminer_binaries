
/* WARNING: Unknown calling convention */

void set_hcnt(uint hcnt)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uchar buf [9];
  uint cmd_buf [3];
  
  iVar3 = 0;
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  do {
    while ((dev->chain_exist[iVar3] == 1 && (opt_multi_version != 0))) {
      buf[0] = 'X';
      buf[1] = '\t';
      buf[2] = '\0';
      buf[3] = '\x14';
      buf[5] = (uchar)(hcnt >> 0x10);
      buf[4] = (uchar)(hcnt >> 0x18);
      buf[6] = (uchar)(hcnt >> 8);
      buf[7] = (uchar)hcnt;
      buf[8] = CRC5(buf,'@');
      cmd_buf[2] = (uint)buf[8] << 0x18;
      cmd_buf[0] = 0x58090014;
      cmd_buf[1] = ((hcnt << 8) >> 0x18) << 0x10 | hcnt & 0xff000000 | hcnt & 0xff |
                   ((hcnt << 0x10) >> 0x18) << 8;
      set_BC_command_buffer(cmd_buf);
      uVar1 = get_BC_write_command();
      uVar2 = iVar3 << 0x10;
      iVar3 = iVar3 + 1;
      set_BC_write_command(uVar1 & 0xfff0ffff | uVar2 | 0x80800000);
      if (iVar3 == 0x10) {
        return;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x10);
  return;
}

