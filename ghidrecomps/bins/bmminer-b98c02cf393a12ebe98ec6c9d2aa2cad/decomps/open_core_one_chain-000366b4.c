
void open_core_one_chain(uint param_1,uint param_2)

{
  undefined uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  FILE *__stream;
  byte *pbVar6;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
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
  byte local_85c;
  byte local_85b;
  byte local_85a [38];
  undefined local_834;
  undefined local_829;
  byte local_828;
  undefined local_827;
  undefined local_826;
  undefined local_825;
  uint local_824;
  byte local_820 [2044];
  
  local_8e0 = 0;
  local_8d0 = 0;
  local_8cc = 0;
  local_8c8 = 0;
  memset(local_8c4,0,0x34);
  memset(&local_890,0,0x34);
  memset(&local_85c,0,0x34);
  local_85c = 0xff;
  local_8dc = 0;
  local_8d8 = 0;
  local_8d4 = 0;
  if (opt_multi_version != 0) {
    uVar4 = get_dhash_acc_control();
    set_dhash_acc_control(uVar4 & 0xffff7fdf | (opt_multi_version & 0xf) << 8 | 0x8000);
    set_hash_counting_number(0);
    iVar11 = dev;
    uVar4 = *(byte *)(dev + 0x542f) & 0x1f | 0x80;
    local_8d8 = CONCAT13(0x80,CONCAT12((char)uVar4,0x2040));
    local_8dc = 0x1c000958;
    local_8d4 = CRC5(&local_8dc,0x40);
    local_8c8 = (uint)local_8d4 << 0x18;
    local_8cc = uVar4 << 8 | 0x40200080;
    local_890 = 0;
    local_88c = 0;
    local_888 = 0;
    local_884 = 0;
    local_8d0 = 0x5809001c;
    memset(&local_828,0xff,0x34);
    if (*(int *)(iVar11 + (param_1 + 2) * 4) == 1) {
      uVar4 = get_BC_write_command();
      set_BC_write_command((uVar4 & 0xfff0ffff | param_1 << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(1000,0);
      local_820[0] = 0xff;
      local_820[11] = 0xff;
      local_828 = 1;
      iVar11 = 0;
      local_826 = 0;
      local_825 = 0;
      local_824 = 0;
      uVar1 = (undefined)(param_1 | 0xffffff80);
      local_827 = uVar1;
      set_BC_command_buffer(&local_8d0);
      uVar4 = get_BC_write_command();
      set_BC_write_command(uVar4 & 0xfff0ffff | param_1 << 0x10 | 0x80800000);
      cgsleep_us(10000,0);
      do {
        iVar12 = 0xbb9;
        while (uVar4 = get_buffer_space(), (uVar4 & 1 << (param_1 & 0xff)) == 0) {
          cgsleep_us(1000,0);
          iVar12 = iVar12 + -1;
          if (iVar12 == 0) {
            if (3 < log_level) {
              __stream = fopen(log_file,(char *)&DAT_0005e760);
              if (__stream != (FILE *)0x0) {
                fprintf(__stream,"%s:%d:%s: Error: send open core work Failed on Chain[%d]!\n",
                        "driver-btm-c5.c",0x2bf3,DAT_00036ba0,param_1);
              }
              fclose(__stream);
            }
            goto LAB_00036ae8;
          }
        }
        if (iVar11 == 0) {
          local_890 = 0x11000000;
          local_828 = 0x11;
        }
        else {
          local_890 = 0x1000000;
          local_828 = 1;
        }
        puVar13 = &local_88c;
        local_827 = uVar1;
        local_890 = (uint)CONCAT11(local_826,local_825) | ((param_1 | 0xffffff80) & 0xff) << 0x10 |
                    local_890;
        local_88c = local_824;
        pbVar6 = &local_828;
        do {
          pbVar9 = pbVar6 + 4;
          puVar13 = puVar13 + 1;
          *puVar13 = (uint)pbVar6[0xb] | (uint)pbVar6[9] << 0x10 | (uint)pbVar6[8] << 0x18 |
                     (uint)pbVar6[10] << 8;
          pbVar6 = pbVar9;
        } while (pbVar9 != local_820 + 4);
        puVar8 = &uStack_880;
        do {
          puVar8 = puVar8 + 1;
          *puVar8 = 0;
        } while (local_87c + 7 != puVar8);
        set_TW_write_command_vil(&local_890);
        if (iVar11 == 0x71) {
          uVar4 = param_2 & 1;
        }
        else {
          uVar4 = 0;
        }
        if ((uVar4 != 0) &&
           (((disabledcore_pos_buf[param_1 * 0x10] != ',' ||
             (disabledcore_pos_buf[param_1 * 0x10 + 1] != 'e')) ||
            (iVar12 = chainHasDisabledCore_part_5(param_1), iVar12 == 0)))) {
          uVar4 = get_BC_write_command();
          set_BC_write_command(uVar4 | 0x400000);
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 != 0x72);
LAB_00036ae8:
      close_bad_core(param_1,param_2);
    }
    uVar4 = get_dhash_acc_control();
    set_dhash_acc_control(uVar4 | (opt_multi_version & 0xf) << 8 | 0x8000);
    return;
  }
  uVar4 = get_dhash_acc_control();
  set_dhash_acc_control(uVar4 & 0xffffffdf);
  set_hash_counting_number(0);
  iVar11 = dev;
  uVar10 = *(byte *)(dev + 0x542f) | 0x80;
  local_8e0._0_3_ = CONCAT12((char)uVar10,0x86);
  local_8e0 = CONCAT13(0x80,(undefined3)local_8e0);
  uVar4 = CRC5(&local_8e0,0x1b);
  uVar4 = uVar4 & 0x1f | 0x80;
  local_8e0 = CONCAT13((char)uVar4,(undefined3)local_8e0);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf((char *)&local_828,0x800,
             "%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",DAT_00036af4
             ,0x86,0,uVar10,uVar4);
    _applog(7,&local_828,0);
    iVar11 = dev;
  }
  local_8d0 = local_8e0 << 0x18 | (local_8e0 >> 8 & 0xff) << 0x10 | (local_8e0 >> 0x10 & 0xff) << 8
              | local_8e0 >> 0x18;
  memset(&local_85c,0,0x34);
  local_829 = 0xff;
  local_834 = 0xff;
  if (*(int *)(iVar11 + (param_1 + 2) * 4) != 1) {
LAB_000367dc:
    uVar4 = get_dhash_acc_control();
    set_dhash_acc_control(uVar4 | 0x20);
    return;
  }
  bVar2 = (byte)param_1 | 0x80;
  set_BC_command_buffer(&local_8d0);
  uVar4 = get_BC_write_command();
  iVar11 = 0;
  set_BC_write_command(uVar4 & 0xfff0ffff | param_1 << 0x10 | 0x80800000);
  cgsleep_us(10000,0);
  iVar12 = 0;
LAB_00036914:
  while (uVar4 = get_buffer_space(), (uVar4 & 1 << (param_1 & 0xff)) == 0) {
    cgsleep_us(1000,0);
  }
  local_85b = bVar2;
  if (iVar12 == 0) {
    local_85c = 0x11;
    uVar4 = get_BC_write_command();
    set_BC_write_command(uVar4 & 0xffbfffff);
    uVar10 = (uint)local_85c;
    uVar4 = (uint)local_85b;
  }
  else {
    if (iVar12 == 0x71) {
      uVar7 = param_2 & 1;
    }
    else {
      uVar7 = 0;
    }
    local_85c = 1;
    uVar10 = 1;
    uVar4 = (uint)bVar2;
    if (uVar7 != 0) {
      uVar4 = get_BC_write_command();
      set_BC_write_command(uVar4 & ((param_1 & 0xf) << 0x10 | 0xc00000));
      uVar10 = (uint)local_85c;
      uVar4 = (uint)local_85b;
    }
  }
  pbVar6 = &local_85c;
  local_8c4[0] = 0;
  local_8c4[1] = 0;
  iVar5 = 1;
  local_8c4[2] = 0;
  local_8b8 = 0;
  puVar13 = local_8c4;
  do {
    *puVar13 = uVar4 << 0x10 | uVar10 << 0x18 | (uint)pbVar6[3] | (uint)pbVar6[2] << 8;
    if (iVar5 == 10) {
      iVar3 = iVar11 + 1;
      local_8a0 = iVar11;
    }
    else {
      iVar3 = iVar11;
      if (iVar5 == 0xd) break;
    }
    iVar11 = iVar3;
    uVar10 = (uint)pbVar6[4];
    iVar5 = iVar5 + 1;
    uVar4 = (uint)pbVar6[5];
    pbVar6 = pbVar6 + 4;
    puVar13 = puVar13 + 1;
  } while( true );
  iVar12 = iVar12 + 1;
  set_TW_write_command(local_8c4);
  if (iVar12 == 0x72) goto LAB_000367dc;
  goto LAB_00036914;
}

