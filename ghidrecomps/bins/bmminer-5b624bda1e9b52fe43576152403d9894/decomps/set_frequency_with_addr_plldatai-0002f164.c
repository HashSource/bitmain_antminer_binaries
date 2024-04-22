
/* WARNING: Variable defined which should be unmapped: buf */
/* WARNING: Unknown calling convention */

void set_frequency_with_addr_plldatai(int pllindex,uchar mode,uchar addr,uchar chain)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  int i;
  uint uVar5;
  uint ret;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uchar buf [9];
  uint cmd_buf [3];
  
  uVar5 = *DAT_0002f2e4;
  uVar6 = *(uint *)(DAT_0002f2e0 + pllindex * 0x10 + 0x44);
  if (uVar5 == 0) {
    buf[1] = '\0';
    uVar1 = buf[1];
    buf[2] = '\0';
    uVar2 = buf[2];
    buf[3] = '\0';
    uVar3 = buf[3];
    buf[4] = '\0';
    uVar4 = buf[4];
    buf[0] = '\a';
    uVar7 = (uint)chain << 0x10 | 0x80800000;
    buf[8] = '\0';
    buf[5] = buf[1];
    buf[6] = buf[2];
    buf[7] = buf[3];
    cmd_buf[0] = uVar5;
    cmd_buf[1] = uVar5;
    cmd_buf[2] = uVar5;
    buf[3] = CRC5(buf,'\x1b');
    cmd_buf[0] = buf[3] | 0x7000000;
    set_BC_command_buffer(cmd_buf);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | uVar7);
    cgsleep_us(CONCAT17(buf[7],CONCAT16(buf[6],CONCAT15(buf[5],CONCAT14(buf[4],CONCAT13(buf[3],
                                                  CONCAT12(buf[2],CONCAT11(buf[1],buf[0]))))))));
    buf[0] = 0x82;
    buf[8] = '\0';
    buf[1] = uVar1;
    buf[2] = uVar2;
    buf[3] = uVar3;
    buf[4] = uVar4;
    buf[5] = uVar1;
    buf[6] = uVar2;
    buf[7] = uVar3;
    cmd_buf[0] = uVar5;
    cmd_buf[1] = uVar5;
    cmd_buf[2] = uVar5;
    buf[3] = CRC5(buf,'\x1b');
    cmd_buf[0] = buf[3] | 0x82000000;
    set_BC_command_buffer(cmd_buf);
    uVar5 = get_BC_write_command();
    set_BC_write_command(uVar5 & 0xfff0ffff | uVar7);
    cgsleep_us(CONCAT17(buf[7],CONCAT16(buf[6],CONCAT15(buf[5],CONCAT14(buf[4],CONCAT13(buf[3],
                                                  CONCAT12(buf[2],CONCAT11(buf[1],buf[0]))))))));
  }
  else {
    buf[8] = '\0';
    cmd_buf[0] = 0;
    cmd_buf[1] = 0;
    cmd_buf[2] = 0;
    if (mode == '\0') {
      uVar5 = 0x4809000c;
      buf[0] = 'H';
    }
    else {
      buf[0] = 'X';
      uVar5 = 0x5809000c;
    }
    buf[7] = (uchar)uVar6;
    buf[5] = (uchar)(uVar6 >> 0x10);
    uVar8 = (uint)buf[5];
    buf[4] = (uchar)(uVar6 >> 0x18);
    buf[6] = (uchar)(uVar6 >> 8);
    uVar7 = (uint)buf[6];
    buf[3] = '\f';
    buf[1] = '\t';
    buf[2] = addr;
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[0] = uVar5 | (uint)addr << 8;
    cmd_buf[1] = uVar8 << 0x10 | uVar6 & 0xff000000 | uVar6 & 0xff | uVar7 << 8;
    while (uVar5 = get_BC_write_command(), (int)uVar5 < 0) {
      cgsleep_us(CONCAT17(buf[7],CONCAT16(buf[6],CONCAT15(buf[5],CONCAT14(buf[4],CONCAT13(buf[3],
                                                  CONCAT12(buf[2],CONCAT11(buf[1],buf[0]))))))));
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command((uint)chain << 0x10 | 0x80800000 | uVar5 & 0xfff0ffff);
    cgsleep_us(CONCAT17(buf[7],CONCAT16(buf[6],CONCAT15(buf[5],CONCAT14(buf[4],CONCAT13(buf[3],
                                                  CONCAT12(buf[2],CONCAT11(buf[1],buf[0]))))))));
  }
  return;
}

