
void set_asic_ticket_mask(uint ticket_mask)

{
  byte bVar1;
  uchar uVar2;
  FILE *__stream;
  uint uVar3;
  uint ticket_mask_local;
  uint cmd_buf [3];
  uchar buf [9];
  FILE *pFile;
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
        uVar2 = CRC5(buf,'\x1b');
        buf[3] = uVar2;
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          __stream = fopen(log_file,"a+");
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                    "asic.c",0x503,"set_asic_ticket_mask",buf._0_4_ & 0xff,
                    (uint)buf._0_4_ >> 8 & 0xff,(uint)buf._0_4_ >> 0x10 & 0xff,
                    (uint)buf._0_4_ >> 0x18);
          }
          fclose(__stream);
        }
        cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                     buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                     (uint)buf._0_4_ >> 0x18;
        set_BC_command_buffer(cmd_buf);
        uVar3 = get_BC_write_command();
        set_BC_write_command(uVar3 & 0xfff0ffff | i << 0x10 | 0x80800000);
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
        cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                     buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                     (uint)buf._0_4_ >> 0x18;
        cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
                     buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
                     (uint)buf._4_4_ >> 0x18;
        cmd_buf[2] = (uint)buf[8] << 0x18;
        set_BC_command_buffer(cmd_buf);
        uVar3 = get_BC_write_command();
        set_BC_write_command(uVar3 & 0xfff0ffff | i << 0x10 | 0x80800000);
      }
    }
  }
  return;
}

