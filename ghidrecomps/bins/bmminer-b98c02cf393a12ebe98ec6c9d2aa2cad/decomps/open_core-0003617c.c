
void open_core(uint param_1)

{
  undefined uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  FILE *__stream;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char *local_8f4;
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
    uVar2 = get_dhash_acc_control();
    local_8f4 = DAT_00036510;
    set_dhash_acc_control(uVar2 & 0xffff7fdf | (opt_multi_version & 0xf) << 8 | 0x8000);
    set_hash_counting_number(0);
    iVar10 = dev;
    uVar2 = *(byte *)(dev + 0x542f) & 0x1f | 0x80;
    local_8d8 = CONCAT13(0x80,CONCAT12((char)uVar2,0x2040));
    local_8dc = 0x1c000958;
    local_8d4 = CRC5(&local_8dc);
    local_8c8 = (uint)local_8d4 << 0x18;
    local_8cc = uVar2 << 8 | 0x40200080;
    local_8d0 = 0x5809001c;
    local_890 = 0;
    uVar2 = 0;
    local_88c = 0;
    local_888 = 0;
    local_884 = 0;
    memset(&local_828,0xff,0x34);
    do {
      if (*(int *)(iVar10 + (uVar2 + 2) * 4) == 1) {
        iVar10 = 0;
        uVar9 = get_BC_write_command();
        set_BC_write_command((uVar9 & 0xfff0ffff | uVar2 << 0x10) & 0xffbfffff | 0x800000);
        cgsleep_us(1000,0);
        local_828 = 1;
        local_826 = 0;
        local_824 = 0;
        local_820[0] = 0xff;
        local_820[11] = 0xff;
        uVar1 = (undefined)(uVar2 | 0xffffff80);
        local_827 = uVar1;
        local_825 = local_826;
        set_BC_command_buffer(&local_8d0);
        uVar9 = get_BC_write_command();
        set_BC_write_command(uVar9 & 0xfff0ffff | uVar2 << 0x10 | 0x80800000);
        cgsleep_us(10000,0);
        do {
          while( true ) {
            iVar3 = 0xbb9;
            while (uVar9 = get_buffer_space(), (uVar9 & 1 << (uVar2 & 0xff)) == 0) {
              cgsleep_us(1000,0);
              iVar3 = iVar3 + -1;
              if (iVar3 == 0) {
                if (log_level < 4) goto LAB_000365c4;
                __stream = fopen(log_file,(char *)&DAT_0005e760);
                if (__stream != (FILE *)0x0) {
                  fprintf(__stream,"%s:%d:%s: Error: send open core work Failed on Chain[%d]!\n",
                          "driver-btm-c5.c",0x2b10,DAT_000366b0,uVar2);
                }
                fclose(__stream);
                close_bad_core(uVar2,param_1);
                goto LAB_00036464;
              }
            }
            if (iVar10 == 0) {
              local_890 = 0x11000000;
              local_828 = 0x11;
            }
            else {
              local_890 = 0x1000000;
              local_828 = 1;
            }
            puVar8 = &local_88c;
            local_827 = uVar1;
            local_890 = (uint)CONCAT11(local_826,local_825) | ((uVar2 | 0xffffff80) & 0xff) << 0x10
                        | local_890;
            local_88c = local_824;
            pbVar5 = &local_828;
            do {
              pbVar4 = pbVar5 + 4;
              puVar8 = puVar8 + 1;
              *puVar8 = (uint)pbVar5[0xb] | (uint)pbVar5[9] << 0x10 | (uint)pbVar5[8] << 0x18 |
                        (uint)pbVar5[10] << 8;
              pbVar5 = pbVar4;
            } while (pbVar4 != local_820 + 4);
            puVar7 = &uStack_880;
            do {
              puVar7 = puVar7 + 1;
              *puVar7 = 0;
            } while (local_87c + 7 != puVar7);
            set_TW_write_command_vil(&local_890);
            if (iVar10 == 0x71) {
              uVar9 = param_1 & 1;
            }
            else {
              uVar9 = 0;
            }
            if (uVar9 != 0) break;
LAB_000365be:
            iVar10 = iVar10 + 1;
            if (iVar10 == 0x72) goto LAB_000365c4;
          }
          if (((*local_8f4 != ',') || (local_8f4[1] != 'e')) ||
             (iVar3 = chainHasDisabledCore_part_5(uVar2), iVar3 == 0)) {
            uVar9 = get_BC_write_command();
            set_BC_write_command(uVar9 | 0x400000);
            goto LAB_000365be;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 != 0x72);
LAB_000365c4:
        close_bad_core(uVar2,param_1);
      }
LAB_00036464:
      uVar2 = uVar2 + 1;
      local_8f4 = local_8f4 + 0x10;
      iVar10 = dev;
      if (uVar2 == 0x10) {
        uVar2 = get_dhash_acc_control();
        set_dhash_acc_control(uVar2 | (opt_multi_version & 0xf) << 8 | 0x8000);
        return;
      }
    } while( true );
  }
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 & 0xffffffdf);
  set_hash_counting_number(0);
  iVar10 = dev;
  uVar9 = *(byte *)(dev + 0x542f) | 0x80;
  local_8e0._0_3_ = CONCAT12((char)uVar9,0x86);
  local_8e0 = CONCAT13(0x80,(undefined3)local_8e0);
  uVar2 = CRC5(&local_8e0,0x1b);
  uVar2 = uVar2 & 0x1f | 0x80;
  local_8e0 = CONCAT13((char)uVar2,(undefined3)local_8e0);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf((char *)&local_828,0x800,
             "%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",DAT_0003650c
             ,0x86,0,uVar9,uVar2);
    _applog(7,&local_828,0);
    iVar10 = dev;
  }
  local_8f4 = (char *)0x0;
  local_8d0 = local_8e0 << 0x18 | (local_8e0 >> 8 & 0xff) << 0x10 | (local_8e0 >> 0x10 & 0xff) << 8
              | local_8e0 >> 0x18;
  memset(&local_85c,0,0x34);
  uVar2 = 0;
  local_829 = 0xff;
  local_834 = 0xff;
LAB_000362b8:
  if (*(int *)(iVar10 + (uVar2 + 2) * 4) == 1) {
    set_BC_command_buffer(&local_8d0);
    uVar9 = get_BC_write_command();
    iVar10 = 0;
    set_BC_write_command(uVar9 & 0xfff0ffff | uVar2 << 0x10 | 0x80800000);
    cgsleep_us(10000,0);
LAB_0003630a:
    while (uVar9 = get_buffer_space(), (uVar9 & 1 << (uVar2 & 0xff)) == 0) {
      cgsleep_us(1000,0);
    }
    local_85b = (byte)(uVar2 | 0xffffff80);
    if (iVar10 == 0) {
      local_85c = 0x11;
      uVar9 = get_BC_write_command();
      set_BC_write_command(uVar9 & 0xffbfffff);
      uVar11 = (uint)local_85c;
      uVar9 = (uint)local_85b;
    }
    else {
      if (iVar10 == 0x71) {
        uVar6 = param_1 & 1;
      }
      else {
        uVar6 = 0;
      }
      local_85c = 1;
      uVar11 = 1;
      uVar9 = (uVar2 | 0xffffff80) & 0xff;
      if (uVar6 != 0) {
        uVar9 = get_BC_write_command();
        set_BC_write_command(uVar9 & (uVar2 << 0x10 | 0xc00000));
        uVar11 = (uint)local_85c;
        uVar9 = (uint)local_85b;
      }
    }
    pbVar5 = &local_85c;
    local_8c4[0] = 0;
    local_8c4[1] = 0;
    iVar3 = 1;
    local_8c4[2] = 0;
    local_8b8 = 0;
    puVar8 = local_8c4;
    do {
      *puVar8 = uVar9 << 0x10 | uVar11 << 0x18 | (uint)pbVar5[3] | (uint)pbVar5[2] << 8;
      if (iVar3 == 10) {
        local_8a0 = (int)local_8f4;
        local_8f4 = (char *)((int)local_8f4 + 1);
      }
      else if (iVar3 == 0xd) goto code_r0x0003637e;
      uVar11 = (uint)pbVar5[4];
      iVar3 = iVar3 + 1;
      uVar9 = (uint)pbVar5[5];
      pbVar5 = pbVar5 + 4;
      puVar8 = puVar8 + 1;
    } while( true );
  }
  if (uVar2 != 0xf) goto LAB_000362b4;
LAB_00036394:
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 | 0x20);
  return;
code_r0x0003637e:
  iVar10 = iVar10 + 1;
  set_TW_write_command(local_8c4);
  if (iVar10 == 0x72) goto code_r0x0003638a;
  goto LAB_0003630a;
code_r0x0003638a:
  if (uVar2 == 0xf) goto LAB_00036394;
LAB_000362b4:
  uVar2 = uVar2 + 1;
  iVar10 = dev;
  goto LAB_000362b8;
}

