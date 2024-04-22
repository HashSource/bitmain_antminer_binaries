
/* WARNING: Unknown calling convention */

void read_asic_register(uchar chain,uchar mode,uchar chip_addr,uchar reg_addr)

{
  uint ret;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uchar buf [5];
  uint cmd_buf [3];
  char logstr [256];
  
  uVar6 = (uint)reg_addr;
  uVar5 = (uint)chip_addr;
  buf[3] = '\0';
  buf[4] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (*DAT_000320b4 == 0) {
    buf[0] = '\x04';
    if (mode != '\0') {
      buf[0] = 0x84;
    }
    buf[1] = chip_addr;
    buf[2] = reg_addr;
    buf[3] = CRC5(buf,'\x1b');
    uVar3 = (uint)buf[3];
    if ((*DAT_000320b8 != '\0') &&
       (((*DAT_000320bc != '\0' || (*DAT_000320c0 != '\0')) || (6 < *DAT_000320cc)))) {
      snprintf(logstr,0x800,DAT_000320c8,DAT_000320c4,(uint)buf[0],uVar5,uVar6,uVar3);
      _applog(7,logstr,false);
      uVar5 = (uint)buf[1];
      uVar6 = (uint)buf[2];
      uVar3 = (uint)buf[3];
    }
    cmd_buf[0] = uVar3 | (uint)buf[0] << 0x18 | uVar5 << 0x10 | uVar6 << 8;
  }
  else {
    if (mode == '\0') {
      buf[0] = 'D';
    }
    else {
      buf[0] = 'T';
    }
    buf[1] = '\x05';
    buf[2] = chip_addr;
    buf[3] = reg_addr;
    buf[4] = CRC5(buf,' ');
    uVar3 = (uint)buf[4];
    if ((*DAT_000320b8 == '\0') ||
       (((*DAT_000320bc == '\0' && (*DAT_000320c0 == '\0')) && (*DAT_000320cc < 7)))) {
      uVar2 = 0x50000;
    }
    else {
      snprintf(logstr,0x800,DAT_000320d0,DAT_000320c4,(uint)buf[0],5,uVar5,uVar6,uVar3);
      _applog(7,logstr,false);
      uVar5 = (uint)buf[2];
      uVar6 = (uint)buf[3];
      uVar3 = (uint)buf[4];
      uVar2 = (uint)buf[1] << 0x10;
    }
    cmd_buf[1] = uVar3 << 0x18;
    iVar4 = 0xbb9;
    cmd_buf[0] = uVar6 | uVar2 | (uint)buf[0] << 0x18 | uVar5 << 8;
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) goto LAB_00031fac;
      cgsleep_ms(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = get_hash_on_plug();
    sprintf(logstr,DAT_000320d4,iVar4);
    writeInitLogFile(logstr);
  }
LAB_00031fac:
  set_BC_command_buffer(cmd_buf);
  uVar5 = get_BC_write_command();
  ret = uVar5 & 0xfff0ffff;
  set_BC_write_command((uint)chain << 0x10 | 0x80800000 | ret);
  return;
}

