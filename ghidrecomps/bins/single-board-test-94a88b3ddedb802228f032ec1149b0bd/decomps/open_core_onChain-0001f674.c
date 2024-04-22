
void open_core_onChain(uint param_1,uint param_2,uint param_3,char param_4)

{
  int iVar1;
  undefined uVar2;
  uint uVar3;
  byte local_168;
  byte local_167;
  byte local_166;
  byte local_165;
  undefined4 local_164;
  byte local_160 [92];
  uint local_104;
  uint local_100;
  byte local_fc;
  byte local_f8 [52];
  uint local_c4 [5];
  uint auStack_b0 [8];
  uint auStack_90 [13];
  uint local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  FILE *local_4c;
  uint local_48;
  FILE *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_50 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  memset(auStack_90,0,0x34);
  memset(local_c4,0,0x34);
  memset(local_f8,0,0x34);
  local_f8[0] = 0xff;
  local_104 = 0;
  local_100 = 0;
  local_fc = 0;
  local_34 = conf._92_4_;
  local_38 = conf._96_4_;
  local_3c = conf._100_4_;
  local_40 = conf._104_4_;
  printf("\n--- %s\n","open_core_onChain");
  uVar3 = get_dhash_acc_control();
  set_dhash_acc_control(uVar3 & 0xffffffdf);
  set_hash_counting_number(0);
  local_48 = param_1;
  local_30 = param_2;
  if (cgpu._2562268_4_ == 0) {
    local_104 = CONCAT13((char)MISC_CONTROL,0x958);
    local_100 = CONCAT13(0x80,CONCAT12(cgpu[2562356],0x2040) & 0x1fffff | 0x800000);
    local_fc = CRC5(&local_104,0x40);
    local_5c = (local_104 >> 0x10 & 0xff) << 8 | local_104 << 0x18 | (local_104 >> 8 & 0xff) << 0x10
               | local_104 >> 0x18;
    local_58 = (local_100 >> 0x10 & 0xff) << 8 | local_100 << 0x18 | (local_100 >> 8 & 0xff) << 0x10
               | local_100 >> 0x18;
    local_54 = (uint)local_fc << 0x18;
    printf("%s: gateblk: cmd_buf[0] = 0x%x, cmd_buf[1] = 0x%x, cmd_buf[2] = 0x%x\n",
           "open_core_onChain",local_5c,local_58,local_54);
    memset(local_c4,0,0xd);
    memset(&local_168,0xff,0x34);
    local_168 = 1;
    local_167 = 0x80;
    local_166 = 0;
    local_165 = 0;
    local_164 = 0;
    if ((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) {
      uVar3 = get_BC_write_command();
      local_24 = (uVar3 & 0xfff0ffff | local_48 << 0x10) & 0xffbfffff | 0x800000;
      set_BC_write_command(local_24);
      usleep(10000);
      set_BC_command_buffer(&local_5c);
      local_24 = get_BC_write_command();
      local_28 = local_24 & 0xfff0ffff | local_48 << 0x10 | 0x80800000;
      local_24 = local_24 & 0xffbfffff;
      set_BC_write_command(local_28);
      usleep(10000);
      for (local_1c = 0; local_1c < local_30; local_1c = local_1c + 1) {
        if (local_1c < param_3) {
          local_160[0] = 0xff;
          local_160[11] = 0xff;
        }
        else {
          local_160[0] = 0;
          local_160[11] = 0;
        }
        while( true ) {
          local_2c = get_buffer_space();
          if ((local_2c & 1 << (local_48 & 0xff)) != 0) break;
          usleep(1000);
        }
        if (local_1c == 0) {
          local_168 = 0x11;
        }
        else {
          local_168 = 1;
        }
        local_167 = (byte)local_48 | 0x80;
        local_c4[0] = (uint)local_166 << 8 | (uint)local_168 << 0x18 | (uint)local_167 << 0x10 |
                      (uint)local_165;
        local_c4[1] = local_164;
        for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
          local_c4[local_14] =
               (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 3] |
               (uint)local_160[(local_14 + 0x3ffffffe) * 4] << 0x18 |
               (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 1] << 0x10 |
               (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 2] << 8;
        }
        for (local_14 = 5; local_14 < 0xd; local_14 = local_14 + 1) {
          local_c4[local_14] = 0;
        }
        set_TW_write_command_vil(local_c4);
        if (((*(int *)(disabled_cores_num + local_48 * 4) < 1) && (local_30 - 1 == local_1c)) &&
           (param_4 != '\0')) {
          local_24 = get_BC_write_command();
          local_24 = local_24 | 0x400000;
          set_BC_write_command(local_24);
        }
      }
      if (0 < *(int *)(disabled_cores_num + local_48 * 4)) {
        for (local_18 = 0; local_18 < *(uint *)(disabled_cores_num + local_48 * 4);
            local_18 = local_18 + 1) {
          usleep(0x118c30);
          local_104 = CONCAT13((char)MISC_CONTROL,
                               CONCAT12(disabled_cores_pos[(local_18 + local_48 * 8) * 2] << 1,0x948
                                       ));
          local_100 = 0x80802040;
          local_fc = CRC5(&local_104,0x40);
          local_5c = (local_104 >> 0x10 & 0xff) << 8 |
                     local_104 << 0x18 | (local_104 >> 8 & 0xff) << 0x10 | local_104 >> 0x18;
          local_58 = (local_100 >> 0x10 & 0xff) << 8 |
                     local_100 << 0x18 | (local_100 >> 8 & 0xff) << 0x10 | local_100 >> 0x18;
          local_54 = (uint)local_fc << 0x18;
          memset(local_c4,0,0xd);
          memset(&local_168,0xaa,0x34);
          local_168 = 1;
          local_167 = (byte)local_48 | 0x80;
          local_166 = 0;
          local_165 = 0;
          local_164 = 0;
          set_BC_command_buffer(&local_5c);
          local_24 = get_BC_write_command();
          local_28 = local_24 & 0xfff0ffff | local_48 << 0x10 | 0x80800000;
          set_BC_write_command(local_28);
          usleep(10000);
          for (local_1c = 0; local_1c < local_30; local_1c = local_1c + 1) {
            if ((byte)disabled_cores_pos[(local_18 + local_48 * 8) * 2 + 1] == local_1c) {
              if (3 < log_level) {
                local_4c = fopen(log_file,"a+");
                if (local_4c != (FILE *)0x0) {
                  fprintf(local_4c,"%s:%d: Chain[%d]: close chip[%d] core[%d]\n","driver-bitmain.c",
                          0xe77,local_48,
                          (uint)(byte)disabled_cores_pos[(local_18 + local_48 * 8) * 2],
                          (uint)(byte)disabled_cores_pos[(local_18 + local_48 * 8) * 2 + 1]);
                }
                fclose(local_4c);
              }
              for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
                local_160[local_14] = 0;
              }
            }
            else {
              for (local_14 = 0; local_14 < 0xc; local_14 = local_14 + 1) {
                local_160[local_14] = 0xff;
              }
            }
            while( true ) {
              local_2c = get_buffer_space();
              if ((local_2c & 1 << (local_48 & 0xff)) != 0) break;
              usleep(1000);
            }
            if (local_1c == 0) {
              local_168 = 0x11;
            }
            else {
              local_168 = 1;
            }
            local_167 = (byte)local_48 | 0x80;
            local_c4[0] = (uint)local_166 << 8 | (uint)local_168 << 0x18 | (uint)local_167 << 0x10 |
                          (uint)local_165;
            local_c4[1] = local_164;
            for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
              local_c4[local_14] =
                   (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 3] |
                   (uint)local_160[(local_14 + 0x3ffffffe) * 4] << 0x18 |
                   (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 1] << 0x10 |
                   (uint)local_160[(local_14 + 0x3ffffffe) * 4 + 2] << 8;
            }
            for (local_14 = 5; local_14 < 0xd; local_14 = local_14 + 1) {
              local_c4[local_14] = 0;
            }
            set_TW_write_command_vil(local_c4);
          }
        }
        local_24 = get_BC_write_command();
        local_24 = local_24 | 0x400000;
        set_BC_write_command(local_24);
      }
    }
  }
  else {
    local_50._0_3_ = CONCAT12(cgpu[2562356],6) | 0x800000;
    local_50 = CONCAT13(0x80,(uint3)CONCAT31((uint3)local_50 >> 8,6) | 0x80);
    uVar2 = CRC5(&local_50,0x1b);
    local_50 = CONCAT13(uVar2,(uint3)local_50) & 0x1fffffff | 0x80000000;
    if (3 < log_level) {
      local_44 = fopen(log_file,"a+");
      if (local_44 != (FILE *)0x0) {
        fprintf(local_44,
                "%s:%d: %s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",
                "driver-bitmain.c",0xd1f,"open_core_onChain",local_50 & 0xff,local_50 >> 8 & 0xff,
                local_50 >> 0x10 & 0xff,local_50 >> 0x18);
      }
      fclose(local_44);
    }
    local_5c = (local_50 >> 0x10 & 0xff) << 8 | local_50 << 0x18 | (local_50 >> 8 & 0xff) << 0x10 |
               local_50 >> 0x18;
    memset(local_f8,0,0x34);
    local_f8[51] = 0xff;
    local_f8[40] = 0xff;
    if ((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) {
      set_BC_command_buffer(&local_5c);
      local_24 = get_BC_write_command();
      local_28 = local_24 & 0xfff0ffff | local_48 << 0x10 | 0x80800000;
      set_BC_write_command(local_28);
      usleep(10000);
      for (local_1c = 0; local_1c < local_30; local_1c = local_1c + 1) {
        while (local_2c = get_buffer_space(), (local_2c & 1 << (local_48 & 0xff)) == 0) {
          usleep(1000);
        }
        if (local_1c == 0) {
          local_f8[0] = 0x11;
        }
        else {
          local_f8[0] = 1;
        }
        local_f8[1] = (byte)local_48 | 0x80;
        if (local_1c == 0) {
          local_24 = get_BC_write_command();
          local_24 = local_24 & 0xffbfffff;
          set_BC_write_command(local_24);
        }
        if ((local_30 - 1 == local_1c) && (param_4 != '\0')) {
          local_24 = get_BC_write_command();
          local_24 = local_24 & ((local_48 & 0xf) << 0x10 | 0xc00000);
          set_BC_write_command(local_24);
        }
        memset(auStack_90,0,0xd);
        for (local_14 = 0; iVar1 = local_20, local_14 < 0xd; local_14 = local_14 + 1) {
          auStack_90[local_14] =
               (uint)local_f8[local_14 * 4 + 2] << 8 |
               (uint)local_f8[local_14 * 4] << 0x18 | (uint)local_f8[local_14 * 4 + 1] << 0x10 |
               (uint)local_f8[local_14 * 4 + 3];
          if (local_14 == 9) {
            local_20 = local_20 + 1;
            auStack_90[9] = iVar1;
          }
        }
        set_TW_write_command(auStack_90);
      }
    }
  }
  printf("--- %s end\n","open_core_onChain");
  return;
}

