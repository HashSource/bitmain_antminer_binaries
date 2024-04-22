
void open_core(char param_1)

{
  int iVar1;
  undefined uVar2;
  uint uVar3;
  byte local_160;
  byte local_15f;
  byte local_15e;
  byte local_15d;
  undefined4 local_15c;
  byte local_158 [92];
  uint local_fc;
  uint local_f8;
  byte local_f4;
  byte local_f0 [52];
  uint local_bc [5];
  uint auStack_a8 [8];
  uint auStack_88 [13];
  uint local_54;
  uint local_50;
  int local_4c;
  uint local_48;
  FILE *local_44;
  FILE *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_48 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  memset(auStack_88,0,0x34);
  memset(local_bc,0,0x34);
  memset(local_f0,0,0x34);
  local_f0[0] = 0xff;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_30 = conf._92_4_;
  local_34 = conf._96_4_;
  local_38 = conf._100_4_;
  local_3c = conf._104_4_;
  printf("\n--- %s\n","open_core");
  uVar3 = get_dhash_acc_control();
  set_dhash_acc_control(uVar3 & 0xffffffdf);
  set_hash_counting_number(0);
  local_2c = 0x72;
  if (cgpu._2562268_4_ == 0) {
    local_fc = CONCAT13((char)MISC_CONTROL,0x958);
    local_f8 = CONCAT13(0x80,CONCAT12(cgpu[2562356],0x2040) & 0x1fffff | 0x800000);
    local_f4 = CRC5(&local_fc,0x40);
    local_54 = (local_fc >> 0x10 & 0xff) << 8 | local_fc << 0x18 | (local_fc >> 8 & 0xff) << 0x10 |
               local_fc >> 0x18;
    local_50 = (local_f8 >> 0x10 & 0xff) << 8 | local_f8 << 0x18 | (local_f8 >> 8 & 0xff) << 0x10 |
               local_f8 >> 0x18;
    local_4c = (uint)local_f4 << 0x18;
    printf("%s: gateblk: cmd_buf[0] = 0x%x, cmd_buf[1] = 0x%x, cmd_buf[2] = 0x%x\n","open_core",
           local_54,local_50,local_4c);
    memset(local_bc,0,0xd);
    memset(&local_160,0xaa,0x34);
    local_160 = 1;
    local_15f = 0x80;
    local_15e = 0;
    local_15d = 0;
    local_15c = 0;
    for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) && (testDone[local_c] != '\x01')) {
        uVar3 = get_BC_write_command();
        local_20 = (uVar3 & 0xfff0ffff | local_c << 0x10) & 0xffbfffff | 0x800000;
        set_BC_write_command(local_20);
        usleep(10000);
        set_BC_command_buffer(&local_54);
        local_20 = get_BC_write_command();
        local_24 = local_20 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
        local_20 = local_20 & 0xffbfffff;
        set_BC_write_command(local_24);
        usleep(10000);
        for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
          while( true ) {
            local_28 = get_buffer_space();
            if ((local_28 & 1 << (local_c & 0xff)) != 0) break;
            usleep(1000);
          }
          if (local_18 == 0) {
            local_160 = 0x11;
          }
          else {
            local_160 = 1;
          }
          local_15f = (byte)local_c | 0x80;
          local_bc[0] = (uint)local_15e << 8 | (uint)local_160 << 0x18 | (uint)local_15f << 0x10 |
                        (uint)local_15d;
          local_bc[1] = local_15c;
          for (local_10 = 2; local_10 < 5; local_10 = local_10 + 1) {
            local_bc[local_10] =
                 (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 3] |
                 (uint)local_158[(local_10 + 0x3ffffffe) * 4] << 0x18 |
                 (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 1] << 0x10 |
                 (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 2] << 8;
          }
          for (local_10 = 5; local_10 < 0xd; local_10 = local_10 + 1) {
            local_bc[local_10] = 0;
          }
          set_TW_write_command_vil(local_bc);
          if (((*(int *)(disabled_cores_num + local_c * 4) < 1) && (local_2c - 1 == local_18)) &&
             (param_1 != '\0')) {
            local_20 = get_BC_write_command();
            local_20 = local_20 | 0x400000;
            set_BC_write_command(local_20);
          }
        }
        if (0 < *(int *)(disabled_cores_num + local_c * 4)) {
          for (local_14 = 0; local_14 < *(uint *)(disabled_cores_num + local_c * 4);
              local_14 = local_14 + 1) {
            usleep(0x118c30);
            local_fc = CONCAT13((char)MISC_CONTROL,
                                CONCAT12(disabled_cores_pos[(local_14 + local_c * 8) * 2] << 1,0x948
                                        ));
            local_f8 = 0x80802040;
            local_f4 = CRC5(&local_fc,0x40);
            local_54 = (local_fc >> 0x10 & 0xff) << 8 |
                       local_fc << 0x18 | (local_fc >> 8 & 0xff) << 0x10 | local_fc >> 0x18;
            local_50 = (local_f8 >> 0x10 & 0xff) << 8 |
                       local_f8 << 0x18 | (local_f8 >> 8 & 0xff) << 0x10 | local_f8 >> 0x18;
            local_4c = (uint)local_f4 << 0x18;
            memset(local_bc,0,0xd);
            memset(&local_160,0xaa,0x34);
            local_160 = 1;
            local_15f = (byte)local_c | 0x80;
            local_15e = 0;
            local_15d = 0;
            local_15c = 0;
            set_BC_command_buffer(&local_54);
            local_20 = get_BC_write_command();
            local_24 = local_20 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
            set_BC_write_command(local_24);
            usleep(10000);
            for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
              if ((byte)disabled_cores_pos[(local_14 + local_c * 8) * 2 + 1] == local_18) {
                if (3 < log_level) {
                  local_44 = fopen(log_file,"a+");
                  if (local_44 != (FILE *)0x0) {
                    fprintf(local_44,"%s:%d: Chain[%d]: close chip[%d] core[%d]\n",
                            "driver-bitmain.c",0x112d,local_c,
                            (uint)(byte)disabled_cores_pos[(local_14 + local_c * 8) * 2],
                            (uint)(byte)disabled_cores_pos[(local_14 + local_c * 8) * 2 + 1]);
                  }
                  fclose(local_44);
                }
                for (local_10 = 0; local_10 < 0xc; local_10 = local_10 + 1) {
                  local_158[local_10] = 0;
                }
              }
              else {
                for (local_10 = 0; local_10 < 0xc; local_10 = local_10 + 1) {
                  local_158[local_10] = 0xff;
                }
              }
              while( true ) {
                local_28 = get_buffer_space();
                if ((local_28 & 1 << (local_c & 0xff)) != 0) break;
                usleep(1000);
              }
              if (local_18 == 0) {
                local_160 = 0x11;
              }
              else {
                local_160 = 1;
              }
              local_15f = (byte)local_c | 0x80;
              local_bc[0] = (uint)local_15e << 8 | (uint)local_160 << 0x18 | (uint)local_15f << 0x10
                            | (uint)local_15d;
              local_bc[1] = local_15c;
              for (local_10 = 2; local_10 < 5; local_10 = local_10 + 1) {
                local_bc[local_10] =
                     (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 3] |
                     (uint)local_158[(local_10 + 0x3ffffffe) * 4] << 0x18 |
                     (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 1] << 0x10 |
                     (uint)local_158[(local_10 + 0x3ffffffe) * 4 + 2] << 8;
              }
              for (local_10 = 5; local_10 < 0xd; local_10 = local_10 + 1) {
                local_bc[local_10] = 0;
              }
              set_TW_write_command_vil(local_bc);
            }
          }
          local_20 = get_BC_write_command();
          local_20 = local_20 | 0x400000;
          set_BC_write_command(local_20);
        }
      }
    }
  }
  else {
    local_48._0_3_ = CONCAT12(cgpu[2562356],6) | 0x800000;
    local_48 = CONCAT13(0x80,(uint3)CONCAT31((uint3)local_48 >> 8,6) | 0x80);
    uVar2 = CRC5(&local_48,0x1b);
    local_48 = CONCAT13(uVar2,(uint3)local_48) & 0x1fffffff | 0x80000000;
    if (3 < log_level) {
      local_40 = fopen(log_file,"a+");
      if (local_40 != (FILE *)0x0) {
        fprintf(local_40,
                "%s:%d: %s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",
                "driver-bitmain.c",0xf95,"open_core",local_48 & 0xff,local_48 >> 8 & 0xff,
                local_48 >> 0x10 & 0xff,local_48 >> 0x18);
      }
      fclose(local_40);
    }
    local_54 = (local_48 >> 0x10 & 0xff) << 8 | local_48 << 0x18 | (local_48 >> 8 & 0xff) << 0x10 |
               local_48 >> 0x18;
    memset(local_f0,0,0x34);
    local_f0[51] = 0xff;
    local_f0[40] = 0xff;
    for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) && (testDone[local_c] != '\x01')) {
        set_BC_command_buffer(&local_54);
        local_20 = get_BC_write_command();
        local_24 = local_20 & 0xfff0ffff | local_c << 0x10 | 0x80800000;
        set_BC_write_command(local_24);
        usleep(10000);
        for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
          while (local_28 = get_buffer_space(), (local_28 & 1 << (local_c & 0xff)) == 0) {
            usleep(1000);
          }
          if (local_18 == 0) {
            local_f0[0] = 0x11;
          }
          else {
            local_f0[0] = 1;
          }
          local_f0[1] = (byte)local_c | 0x80;
          if (local_18 == 0) {
            local_20 = get_BC_write_command();
            local_20 = local_20 & 0xffbfffff;
            set_BC_write_command(local_20);
          }
          if ((local_2c - 1 == local_18) && (param_1 != '\0')) {
            local_20 = get_BC_write_command();
            local_20 = local_20 & ((local_c & 0xf) << 0x10 | 0xc00000);
            set_BC_write_command(local_20);
          }
          memset(auStack_88,0,0xd);
          for (local_10 = 0; iVar1 = local_1c, local_10 < 0xd; local_10 = local_10 + 1) {
            auStack_88[local_10] =
                 (uint)local_f0[local_10 * 4 + 2] << 8 |
                 (uint)local_f0[local_10 * 4] << 0x18 | (uint)local_f0[local_10 * 4 + 1] << 0x10 |
                 (uint)local_f0[local_10 * 4 + 3];
            if (local_10 == 9) {
              local_1c = local_1c + 1;
              auStack_88[9] = iVar1;
            }
          }
          set_TW_write_command(auStack_88);
        }
      }
    }
  }
  printf("--- %s end\n","open_core");
  return;
}

