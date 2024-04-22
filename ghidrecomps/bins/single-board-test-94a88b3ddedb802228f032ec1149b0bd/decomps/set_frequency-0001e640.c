
void set_frequency(int param_1,ushort param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 local_40;
  undefined2 local_3a;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  byte local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  FILE *local_10;
  FILE *local_c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_38 = 0;
  local_3a = 0;
  local_40 = 0;
  if (3 < log_level) {
    local_c = fopen(log_file,"a+");
    if (local_c != (FILE *)0x0) {
      fprintf(local_c,"%s:%d: \n--- %s\n","driver-bitmain.c",0xb2b,"set_frequency");
    }
    fclose(local_c);
  }
  get_plldata(0x56b,param_2,&local_38,&local_3a,&local_40);
  if (3 < log_level) {
    local_10 = fopen(log_file,"a+");
    if (local_10 != (FILE *)0x0) {
      fprintf(local_10,"%s:%d: %s: frequency = %d\n","driver-bitmain.c",0xb2e,"set_frequency",
              (uint)param_2);
    }
    fclose(local_10);
  }
  if (*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) {
    local_14 = param_1;
    if (cgpu._2562268_4_ == 0) {
      memset(&local_28,0,9);
      memset(&local_34,0,0xc);
      local_28 = CONCAT13((char)PLL_PARAMETER,0x958);
      local_24 = CONCAT13((char)local_40,
                          CONCAT12((char)((uint)local_40 >> 8),
                                   CONCAT11((char)((uint)local_40 >> 0x10),
                                            (char)((uint)local_40 >> 0x18))));
      local_20 = CRC5(&local_28,0x40);
      local_34 = (local_28 >> 0x10 & 0xff) << 8 | local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10
                 | local_28 >> 0x18;
      local_30 = (local_24 >> 0x10 & 0xff) << 8 | local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10
                 | local_24 >> 0x18;
      local_2c = (uint)local_20 << 0x18;
      printf("%s: cmd_buf[0] = 0x%x, cmd_buf[1] = 0x%x, cmd_buf[2] = 0x%x\n","set_frequency",
             local_34,local_30,local_2c);
      set_BC_command_buffer(&local_34);
      local_18 = get_BC_write_command();
      local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
      set_BC_write_command(local_1c);
      *(ushort *)(cgpu + (int)("SOCKS5: no connection here" + local_14 + 0xc) * 2 + 6) = param_2;
      usleep(10000);
    }
    else {
      memset(&local_28,0,9);
      memset(&local_34,0,0xc);
      local_28._0_3_ =
           CONCAT12((char)((uint)local_38 >> 8),CONCAT11((char)((uint)local_38 >> 0x10),7));
      local_28._3_1_ = (byte)local_38;
      bVar2 = CRC5(&local_28,0x1b);
      local_28._3_1_ = local_28._3_1_ | bVar2;
      uVar1 = local_28;
      local_34 = (uint)local_28._2_1_ << 8 |
                 (uint)(uint3)local_28 << 0x18 | (uint)local_28._1_1_ << 0x10 | (uint)local_28._3_1_
      ;
      local_28 = uVar1;
      set_BC_command_buffer(&local_34);
      local_18 = get_BC_write_command();
      local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
      set_BC_write_command(local_1c);
      usleep(3000);
      memset(&local_28,0,9);
      memset(&local_34,0,0xc);
      local_28._0_3_ = CONCAT12((char)((ushort)local_3a >> 8),0x82);
      local_28._3_1_ = (byte)local_3a;
      bVar2 = CRC5(&local_28,0x1b);
      local_28._3_1_ = local_28._3_1_ | bVar2;
      uVar1 = local_28;
      local_34 = (uint)local_28._2_1_ << 8 |
                 (uint)(uint3)local_28 << 0x18 | (uint)local_28._1_1_ << 0x10 | (uint)local_28._3_1_
      ;
      local_28 = uVar1;
      set_BC_command_buffer(&local_34);
      local_18 = get_BC_write_command();
      local_1c = local_18 & 0xfff0ffff | local_14 << 0x10 | 0x80800000;
      set_BC_write_command(local_1c);
      *(ushort *)(cgpu + (int)("SOCKS5: no connection here" + local_14 + 0xc) * 2 + 6) = param_2;
      usleep(5000);
    }
  }
  return;
}

