
void set_asic_ticket_mask(uint ticket_mask)

{
  byte bVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  uint ticket_mask_local;
  char tmp42 [2048];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  uint tm;
  uint i;
  
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  bVar1 = (byte)(ticket_mask >> 8);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      if (opt_multi_version == 0) {
        buf._0_4_ = CONCAT13(buf[3],CONCAT12((char)ticket_mask,0x1006)) & 0xff1fffff;
        buf._0_4_ = buf._0_4_ | 0x80;
        bVar3 = CRC5(buf,'\x1b');
        uVar2 = buf._0_4_;
        buf[3] = bVar3;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                   "set_asic_ticket_mask",uVar2 & 0xff,(uint)uVar2 >> 8 & 0xff,
                   (uint)uVar2 >> 0x10 & 0xff,(uint)bVar3);
          _applog(7,tmp42,false);
        }
        cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                     buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                     ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
        set_BC_command_buffer(cmd_buf);
        uVar4 = get_BC_write_command();
        set_BC_write_command(uVar4 & 0xfff0ffff | i << 0x10 | 0x80800000);
      }
      else {
        buf[0] = 'Q';
        buf[1] = '\t';
        buf[2] = '\0';
        buf[3] = '\x14';
        buf._4_2_ = CONCAT11(bit_swap_table[ticket_mask >> 0x10 & 0xff],
                             bit_swap_table
                             [CONCAT12(bVar1,(ushort)(byte)(ticket_mask >> 0x18)) & 0xff]);
        buf._4_3_ = CONCAT12(bit_swap_table[bVar1],buf._4_2_);
        buf[7] = bit_swap_table[ticket_mask & 0xff];
        buf[8] = CRC5(buf,'@');
        cmd_buf[0] = (uint)buf._0_4_ >> 0x18 |
                     buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                     ((uint)buf._0_4_ >> 0x10 & 0xff) << 8;
        cmd_buf[1] = (uint)buf._4_4_ >> 0x18 |
                     buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
                     ((uint)buf._4_4_ >> 0x10 & 0xff) << 8;
        cmd_buf[2] = (uint)buf[8] << 0x18;
        set_BC_command_buffer(cmd_buf);
        uVar4 = get_BC_write_command();
        set_BC_write_command(uVar4 & 0xfff0ffff | i << 0x10 | 0x80800000);
      }
    }
  }
  return;
}

