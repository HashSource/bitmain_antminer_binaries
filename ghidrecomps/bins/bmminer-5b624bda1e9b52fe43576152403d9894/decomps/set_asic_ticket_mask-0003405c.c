
/* WARNING: Unknown calling convention */

void set_asic_ticket_mask(uint ticket_mask)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  byte bVar4;
  uint uVar5;
  uint ret;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  piVar3 = DAT_000341e4;
  piVar2 = DAT_000341d0;
  uVar1 = ticket_mask >> 0x10 & 0xff;
  iVar7 = 0;
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  do {
    while (*(int *)(*piVar3 + (iVar7 + 2) * 4) != 1) {
      iVar7 = iVar7 + 1;
      if (iVar7 == 0x10) {
        return;
      }
    }
    if (*piVar2 == 0) {
      uVar8 = ticket_mask & 0x1f;
      buf[2] = (uchar)uVar8;
      buf[0] = '\0';
      buf[1] = '\x10';
      buf[0] = 0x86;
      bVar4 = CRC5(buf,'\x1b');
      uVar5 = (uint)bVar4;
      buf[3] = bVar4;
      if ((opt_debug == false) ||
         (((use_syslog == false && (*DAT_000341d4 == '\0')) && (*DAT_000341d8 < 7)))) {
        uVar6 = 0x86100000;
      }
      else {
        snprintf(tmp42,0x800,DAT_000341dc,DAT_000341e0,0x86,0x10,uVar8,uVar5);
        _applog(7,tmp42,false);
        uVar8 = (uint)buf._0_4_ >> 0x10 & 0xff;
        uVar5 = (uint)buf._0_4_ >> 0x18;
        uVar6 = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10;
      }
      cmd_buf[0] = uVar6 | uVar5 | uVar8 << 8;
    }
    else {
      buf._4_4_ = uVar1 << 8;
      buf[6] = (uchar)(ticket_mask >> 8);
      buf[0] = 'X';
      buf[1] = '\t';
      buf[2] = '\0';
      buf[3] = '\x18';
      buf[7] = (uchar)ticket_mask;
      buf._4_3_ = (int3)CONCAT31((uint3)buf._4_3_ >> 8,(char)(ticket_mask >> 0x18));
      buf[8] = CRC5(buf,'@');
      cmd_buf[2] = (uint)buf[8] << 0x18;
      cmd_buf[0] = 0x58090018;
      cmd_buf[1] = ticket_mask & 0xff000000 | uVar1 << 0x10 | (ticket_mask >> 8 & 0xff) << 8 |
                   ticket_mask & 0xff;
    }
    set_BC_command_buffer(cmd_buf);
    uVar5 = get_BC_write_command();
    uVar8 = iVar7 << 0x10;
    iVar7 = iVar7 + 1;
    set_BC_write_command(uVar5 & 0xfff0ffff | uVar8 | 0x80800000);
  } while (iVar7 != 0x10);
  return;
}

