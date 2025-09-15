
/* WARNING: Unknown calling convention */

void set_asic_ticket_mask(uint ticket_mask)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  uVar1 = ticket_mask >> 0x10 & 0xff;
  iVar5 = 0;
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
    while (dev->chain_exist[iVar5] != 1) {
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x10) {
        return;
      }
    }
    if (opt_multi_version == 0) {
      uVar6 = ticket_mask & 0x1f;
      buf[2] = (uchar)uVar6;
      buf[0] = '\0';
      buf[1] = '\x10';
      buf[0] = 0x86;
      bVar2 = CRC5(buf,'\x1b');
      uVar3 = (uint)bVar2;
      buf[3] = bVar2;
      if ((opt_debug == false) ||
         (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
        uVar4 = 0x86100000;
      }
      else {
        snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                 "set_asic_ticket_mask",0x86,0x10,uVar6,uVar3);
        _applog(7,tmp42,false);
        uVar6 = (uint)buf._0_4_ >> 0x10 & 0xff;
        uVar3 = (uint)buf._0_4_ >> 0x18;
        uVar4 = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10;
      }
      cmd_buf[0] = uVar4 | uVar3 | uVar6 << 8;
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
    uVar3 = get_BC_write_command();
    uVar6 = iVar5 << 0x10;
    iVar5 = iVar5 + 1;
    set_BC_write_command(uVar3 & 0xfff0ffff | uVar6 | 0x80800000);
  } while (iVar5 != 0x10);
  return;
}

