
/* WARNING: Unknown calling convention */

void set_baud(uchar bauddiv,int no_use)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  uint ret;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint i;
  undefined4 in_stack_fffff7b0;
  uint in_stack_fffff7b4;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  pcVar3 = DAT_000344ec;
  piVar2 = DAT_000344e8;
  piVar1 = DAT_000344e4;
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  iVar7 = *DAT_000344e4;
  buf[8] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if ((uint)*(byte *)(iVar7 + 0x2fea) == (uint)bauddiv) {
    if ((*DAT_000344ec != '\0') &&
       (((*DAT_00034504 != '\0' || (*DAT_000344f0 != '\0')) || (6 < *DAT_00034500)))) {
      snprintf(tmp42,0x800,DAT_00034508,DAT_000344f8,(uint)*(byte *)(iVar7 + 0x2fea));
      _applog(7,tmp42,false);
    }
  }
  else {
    uVar9 = bauddiv & 0x1f;
    iVar11 = 0;
    uVar10 = uVar9 << 8 | 0x200000;
    while( true ) {
      if (*(int *)(iVar7 + (iVar11 + 2) * 4) == 1) {
        if (*piVar2 == 0) {
          buf[2] = (uchar)uVar9;
          buf[0] = 0x86;
          buf[1] = '\x10';
          bVar4 = CRC5(buf,'\x1b');
          uVar5 = (uint)bVar4;
          buf[3] = bVar4;
          if ((*pcVar3 == '\0') ||
             (((use_syslog == false && (*DAT_000344f0 == '\0')) && (*DAT_00034500 < 7)))) {
            uVar8 = 0x86100000;
            uVar6 = uVar9;
          }
          else {
            in_stack_fffff7b0 = 0x86;
            in_stack_fffff7b4 = 0x10;
            snprintf(tmp42,0x800,DAT_000344f4,DAT_000344f8,0x86,0x10,uVar9,uVar5);
            _applog(7,tmp42,false);
            uVar5 = (uint)buf._0_4_ >> 0x18;
            uVar8 = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10;
            uVar6 = (uint)buf._0_4_ >> 0x10 & 0xff;
          }
          cmd_buf[0] = uVar8 | uVar5 | uVar6 << 8;
        }
        else {
          buf._4_3_ = CONCAT12((uchar)uVar9,0x2000);
          buf[7] = '\0';
          buf[0] = 'X';
          buf[1] = '\t';
          buf[2] = '\0';
          buf[3] = '\x1c';
          buf[8] = CRC5(buf,'@');
          cmd_buf[2] = (uint)buf[8] << 0x18;
          cmd_buf[0] = 0x5809001c;
          cmd_buf[1] = uVar10;
          if ((*pcVar3 != '\0') &&
             (((use_syslog != false || (*DAT_000344f0 != '\0')) || (6 < *DAT_00034500)))) {
            in_stack_fffff7b0 = 0x5809001c;
            in_stack_fffff7b4 = uVar10;
            snprintf(tmp42,0x800,DAT_000344fc,DAT_000344f8,0x5809001c,uVar10,cmd_buf[2]);
            _applog(7,tmp42,false);
          }
        }
        set_BC_command_buffer(cmd_buf);
        uVar5 = get_BC_write_command();
        set_BC_write_command(uVar5 & 0xfff0ffff | iVar11 << 0x10 | 0x80800000U);
      }
      if (iVar11 == 0xf) break;
      iVar11 = iVar11 + 1;
      iVar7 = *piVar1;
    }
    cgsleep_us(CONCAT44(in_stack_fffff7b4,in_stack_fffff7b0));
    uVar10 = get_BC_write_command();
    set_BC_write_command(uVar10 & 0xffffffe0 | uVar9);
    *(uchar *)(*piVar1 + 0x2fea) = bauddiv;
  }
  return;
}

