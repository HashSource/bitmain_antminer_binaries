
void set_baud_onChain(int param_1,byte param_2)

{
  undefined uVar1;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  byte local_20;
  FILE *local_1c;
  uint local_18;
  uint local_14;
  FILE *local_10;
  int local_c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  printf("\n--- %s\n","set_baud_onChain");
  if (param_2 == cgpu[2562356]) {
    if (3 < log_level) {
      local_1c = fopen(log_file,"a+");
      if (local_1c != (FILE *)0x0) {
        fprintf(local_1c,"%s:%d: %s: the setting bauddiv(%d) is the same as before\n",
                "driver-bitmain.c",0xc5c,"set_baud_onChain",(uint)param_2);
      }
      fclose(local_1c);
    }
  }
  else {
    local_c = param_1;
    if ((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) {
      if (cgpu._2562268_4_ == 0) {
        local_28 = CONCAT13((char)MISC_CONTROL,0x958);
        local_24 = (uint)(CONCAT12(param_2,0x2040) & 0x1fffff);
        local_20 = CRC5(&local_28,0x40);
        local_34 = (local_28 >> 0x10 & 0xff) << 8 |
                   local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | local_28 >> 0x18;
        local_30 = (local_24 >> 0x10 & 0xff) << 8 |
                   local_24 << 0x18 | (local_24 >> 8 & 0xff) << 0x10 | local_24 >> 0x18;
        local_2c = (uint)local_20 << 0x18;
        printf("%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x\n","set_baud_onChain",local_34
               ,local_30,local_2c);
        set_BC_command_buffer(&local_34);
        local_14 = get_BC_write_command();
        local_18 = local_14 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
        set_BC_write_command(local_18);
      }
      else {
        local_28 = CONCAT13(local_28._3_1_,CONCAT12(param_2,0x1006)) & 0xff1fffff;
        local_28 = local_28 | 0x80;
        uVar1 = CRC5(&local_28,0x1b);
        local_28 = CONCAT13(uVar1,(undefined3)local_28);
        if (3 < log_level) {
          local_10 = fopen(log_file,"a+");
          if (local_10 != (FILE *)0x0) {
            fprintf(local_10,"%s:%d: %s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
                    "driver-bitmain.c",0xc70,"set_baud_onChain",local_28 & 0xff,local_28 >> 8 & 0xff
                    ,local_28 >> 0x10 & 0xff,local_28 >> 0x18);
          }
          fclose(local_10);
        }
        local_34 = (local_28 >> 0x10 & 0xff) << 8 |
                   local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | local_28 >> 0x18;
        set_BC_command_buffer(&local_34);
        local_14 = get_BC_write_command();
        local_18 = local_14 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
        set_BC_write_command(local_18);
      }
    }
    usleep(50000);
    local_14 = get_BC_write_command();
    local_18 = param_2 & 0x1f | local_14 & 0xffffffe0;
    set_BC_write_command(local_18);
    cgpu[2562356] = param_2;
    printf("%s: system baudrate is: 0x%x\n","set_baud_onChain",(uint)param_2);
  }
  return;
}

