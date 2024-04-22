
void open_core_onChain(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte bVar1;
  undefined uVar2;
  byte *pbVar3;
  FILE *__stream;
  undefined4 *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int local_8ec;
  uint local_8e0;
  undefined4 local_8dc;
  undefined4 local_8d8;
  byte local_8d4;
  uint local_8d0;
  uint local_8cc;
  int local_8c8;
  uint local_8c4 [3];
  undefined local_8b8;
  int local_8a0;
  uint local_890;
  uint local_88c;
  uint local_888;
  undefined local_884;
  undefined4 uStack_880;
  undefined4 local_87c [8];
  byte local_85c [40];
  undefined local_834;
  undefined local_829;
  byte local_828;
  undefined local_827;
  undefined local_826;
  undefined local_825;
  uint local_824;
  byte local_820 [2044];
  
  uVar6 = 0;
  local_8e0 = 0;
  local_8d0 = 0;
  local_8cc = 0;
  local_8c8 = 0;
  memset(local_8c4,0,0x34);
  memset(&local_890,0,0x34);
  memset(local_85c,0,0x34);
  local_85c[0] = 0xff;
  local_8dc = 0;
  local_8d8 = 0;
  local_8d4 = 0;
  if (opt_multi_version != 0) {
    uVar7 = get_dhash_acc_control();
    set_dhash_acc_control(uVar7 & 0xffff7fdf | (opt_multi_version & 0xf) << 8 | 0x8000);
    set_hash_counting_number(0);
    iVar9 = dev;
    uVar7 = *(byte *)(dev + 0x542f) & 0x1f | 0x80;
    local_8d8 = CONCAT13(0x80,CONCAT12((char)uVar7,0x2040));
    local_8dc = 0x1c000958;
    local_8d4 = CRC5(&local_8dc,0x40);
    local_8c8 = (uint)local_8d4 << 0x18;
    local_8cc = uVar7 << 8 | 0x40200080;
    local_890 = 0;
    local_88c = 0;
    local_888 = 0;
    local_884 = 0;
    local_8d0 = 0x5809001c;
    memset(&local_828,0xff,0x34);
    if (*(int *)(iVar9 + (param_1 + 2) * 4) == 1) {
      uVar7 = get_BC_write_command();
      set_BC_write_command((uVar7 & 0xfff0ffff | param_1 << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(1000,0);
      local_820[0] = 0xff;
      local_820[11] = 0xff;
      uVar2 = (undefined)(param_1 | 0xffffff80);
      local_828 = 1;
      local_826 = 0;
      local_825 = 0;
      local_824 = 0;
      local_827 = uVar2;
      set_BC_command_buffer(&local_8d0);
      uVar7 = get_BC_write_command();
      set_BC_write_command(uVar7 & 0xfff0ffff | param_1 << 0x10 | 0x80800000);
      cgsleep_us(10000,0);
      if (param_2 != 0) {
        do {
          iVar9 = 0xbb9;
          if (uVar6 < param_3) {
            local_820[0] = 0xff;
            local_820[11] = local_820[0];
          }
          else {
            local_820[0] = 0;
            local_820[11] = local_820[0];
          }
          while (uVar7 = get_buffer_space(), (uVar7 & 1 << (param_1 & 0xff)) == 0) {
            cgsleep_us(1000,0);
            iVar9 = iVar9 + -1;
            if (iVar9 == 0) {
              if (3 < log_level) {
                __stream = fopen(log_file,(char *)&DAT_0005e760);
                if (__stream != (FILE *)0x0) {
                  fprintf(__stream,"%s:%d:%s: Error: send open core work Failed on Chain[%d]!\n",
                          "driver-btm-c5.c",0x2cdc,DAT_00037b64,param_1);
                }
                fclose(__stream);
              }
              goto LAB_00037aae;
            }
          }
          if (uVar6 == 0) {
            local_890 = 0x11000000;
            local_828 = 0x11;
          }
          else {
            local_890 = 0x1000000;
            local_828 = 1;
          }
          puVar8 = &local_88c;
          local_827 = uVar2;
          local_890 = (uint)CONCAT11(local_826,local_825) | ((param_1 | 0xffffff80) & 0xff) << 0x10
                      | local_890;
          local_88c = local_824;
          pbVar3 = &local_828;
          do {
            pbVar5 = pbVar3 + 4;
            puVar8 = puVar8 + 1;
            *puVar8 = (uint)pbVar3[0xb] | (uint)pbVar3[9] << 0x10 | (uint)pbVar3[8] << 0x18 |
                      (uint)pbVar3[10] << 8;
            pbVar3 = pbVar5;
          } while (local_820 + 4 != pbVar5);
          puVar4 = &uStack_880;
          do {
            puVar4 = puVar4 + 1;
            *puVar4 = 0;
          } while (puVar4 != local_87c + 7);
          set_TW_write_command_vil(&local_890);
          if (param_2 - 1 == uVar6) {
            uVar7 = param_4 & 1;
          }
          else {
            uVar7 = 0;
          }
          if ((uVar7 != 0) &&
             (((disabledcore_pos_buf[param_1 * 0x10] != ',' ||
               (disabledcore_pos_buf[param_1 * 0x10 + 1] != 'e')) ||
              (iVar9 = chainHasDisabledCore_part_5(param_1), iVar9 == 0)))) {
            uVar7 = get_BC_write_command();
            set_BC_write_command(uVar7 | 0x400000);
          }
          uVar6 = uVar6 + 1;
        } while (param_2 != uVar6);
      }
LAB_00037aae:
      close_bad_core(param_1,param_4);
    }
    uVar6 = get_dhash_acc_control();
    set_dhash_acc_control(uVar6 | (opt_multi_version & 0xf) << 8 | 0x8000);
    return;
  }
  uVar6 = get_dhash_acc_control();
  set_dhash_acc_control(uVar6 & 0xffffffdf);
  set_hash_counting_number(0);
  iVar9 = dev;
  uVar7 = *(byte *)(dev + 0x542f) | 0x80;
  local_8e0._0_3_ = CONCAT12((char)uVar7,0x86);
  local_8e0 = CONCAT13(0x80,(undefined3)local_8e0);
  uVar6 = CRC5(&local_8e0,0x1b);
  uVar6 = uVar6 & 0x1f | 0x80;
  local_8e0 = CONCAT13((char)uVar6,(undefined3)local_8e0);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf((char *)&local_828,0x800,
             "%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",DAT_000379f4
             ,0x86,0,uVar7,uVar6);
    _applog(7,&local_828,0);
    iVar9 = dev;
  }
  local_8d0 = local_8e0 << 0x18 | (local_8e0 >> 8 & 0xff) << 0x10 | (local_8e0 >> 0x10 & 0xff) << 8
              | local_8e0 >> 0x18;
  memset(local_85c,0,0x34);
  local_829 = 0xff;
  local_834 = 0xff;
  if (*(int *)(iVar9 + (param_1 + 2) * 4) == 1) {
    set_BC_command_buffer(&local_8d0);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | param_1 << 0x10 | 0x80800000);
    cgsleep_us(10000,0);
    if (param_2 != 0) {
      local_8ec = 0;
      uVar6 = 0;
      bVar1 = (byte)param_1 | 0x80;
LAB_000378ca:
      while (uVar7 = get_buffer_space(), (uVar7 & 1 << (param_1 & 0xff)) == 0) {
        cgsleep_us(1000,0);
      }
      if (uVar6 == 0) {
        local_85c[0] = 0x11;
        local_85c[1] = bVar1;
        uVar7 = get_BC_write_command();
        set_BC_write_command(uVar7 & 0xffbfffff);
      }
      else {
        local_85c[0] = 1;
        local_85c[1] = bVar1;
      }
      if (uVar6 == param_2 - 1) {
        uVar7 = param_4 & 1;
      }
      else {
        uVar7 = 0;
      }
      if (uVar7 != 0) {
        uVar7 = get_BC_write_command();
        set_BC_write_command(uVar7 & ((param_1 & 0xf) << 0x10 | 0xc00000));
      }
      pbVar3 = local_85c;
      local_8c4[0] = 0;
      local_8c4[1] = 0;
      iVar9 = 1;
      local_8c4[2] = 0;
      local_8b8 = 0;
      puVar8 = local_8c4;
      do {
        *puVar8 = (uint)pbVar3[3] | (uint)pbVar3[1] << 0x10 | (uint)*pbVar3 << 0x18 |
                  (uint)pbVar3[2] << 8;
        if (iVar9 == 10) {
          local_8a0 = local_8ec;
          local_8ec = local_8ec + 1;
        }
        else if (iVar9 == 0xd) goto code_r0x0003793a;
        pbVar3 = pbVar3 + 4;
        iVar9 = iVar9 + 1;
        puVar8 = puVar8 + 1;
      } while( true );
    }
  }
LAB_00037788:
  uVar6 = get_dhash_acc_control();
  set_dhash_acc_control(uVar6 | 0x20);
  return;
code_r0x0003793a:
  uVar6 = uVar6 + 1;
  set_TW_write_command(local_8c4);
  if (param_2 == uVar6) goto LAB_00037788;
  goto LAB_000378ca;
}

