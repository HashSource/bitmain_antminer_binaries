
void close_bad_core(uint param_1,uint param_2)

{
  uint uVar1;
  FILE *pFVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  undefined1 *puVar10;
  uint *puVar11;
  undefined local_8cc;
  undefined4 local_8a8;
  uint local_8a4;
  byte local_8a0;
  uint local_89c;
  uint local_898;
  int local_894;
  uint local_890;
  uint local_88c;
  uint local_888;
  undefined local_884;
  undefined4 uStack_880;
  undefined4 local_87c [8];
  byte local_85c;
  undefined local_85b;
  undefined local_85a;
  undefined local_859;
  uint local_858;
  byte local_854 [44];
  char acStack_828 [2052];
  
  local_89c = 0;
  local_898 = 0;
  local_894 = 0;
  memset(&local_890,0,0x34);
  local_8a8 = 0;
  local_8a4 = 0;
  local_8a0 = 0;
  if ((((*(int *)(dev + (param_1 + 2) * 4) == 1) &&
       (iVar9 = param_1 * 0x10, disabledcore_pos_buf[iVar9] == ',')) &&
      (disabledcore_pos_buf[iVar9 + 1] == 'e')) && ((byte)disabledcore_pos_buf[iVar9 + 2] < 0x54)) {
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 & 0xffff7fdf | (opt_multi_version & 0xf) << 8 | 0x8000);
    set_hash_counting_number(0);
    iVar6 = dev;
    local_8a4._0_3_ = CONCAT12(*(undefined *)(dev + 0x542f),0x2000) & 0x1fffff | 0x800000;
    local_8a4 = CONCAT31((uint3)local_8a4 >> 8,0x40);
    local_8a4 = CONCAT13(0x80,(uint3)local_8a4);
    local_8a8 = 0x1c000948;
    local_8a0 = CRC5(&local_8a8);
    local_890 = 0;
    local_88c = 0;
    local_888 = 0;
    local_884 = 0;
    memset(&local_85c,0xff,0x34);
    if (*(int *)(iVar6 + (param_1 + 2) * 4) == 1) {
      if (((byte)disabledcore_pos_buf[iVar9] == 0x2c) && (disabledcore_pos_buf[iVar9 + 1] == 'e')) {
        if ((byte)disabledcore_pos_buf[iVar9 + 2] < 0x54) {
          puVar10 = disabledcore_pos_buf + iVar9;
          do {
            if (((byte)puVar10[2] < 0x54) && ((byte)puVar10[3] < 0x72)) {
              if ((use_syslog != '\0') || ((opt_log_output != '\0' || (4 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"Close asic %d bad core %d",(uint)(byte)puVar10[2],
                         (uint)(byte)puVar10[3]);
                _applog(5,acStack_828,0);
              }
              uVar1 = get_BC_write_command();
              set_BC_write_command((uVar1 & 0xfff0ffff | param_1 << 0x10) & 0xffbfffff | 0x800000);
              uVar1 = get_dhash_acc_control();
              set_dhash_acc_control(uVar1 | 0x80);
              cgsleep_us(1000,0);
              uVar3 = 0;
              bVar5 = *(char *)(dev + 0x542d) * puVar10[2];
              local_8a0 = CRC5(&local_8a8,0x40);
              local_8cc = (undefined)(param_1 | 0xffffff80);
              local_894 = (uint)local_8a0 << 0x18;
              local_85b = local_8cc;
              local_85a = 0;
              local_858 = 0;
              local_89c = local_8a8 >> 0x18 | (local_8a8 >> 8 & 0xff) << 0x10 | local_8a8 << 0x18 |
                          (uint)bVar5 << 8;
              local_85c = 1;
              local_854[0] = 0xff;
              local_898 = local_8a4 << 0x18 | (local_8a4 >> 8 & 0xff) << 0x10 |
                          (local_8a4 >> 0x10 & 0xff) << 8 | local_8a4 >> 0x18;
              local_854[11] = 0xff;
              local_859 = local_85a;
              set_BC_command_buffer(&local_89c);
              uVar1 = get_BC_write_command();
              set_BC_write_command(uVar1 & 0xfff0ffff | param_1 << 0x10 | 0x80800000);
              cgsleep_us(10000,0);
              do {
                if ((byte)puVar10[3] == uVar3) {
                  if (3 < log_level) {
                    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
                    if (pFVar2 != (FILE *)0x0) {
                      fprintf(pFVar2,"%s:%d:%s: Disable Chain[%d] Chip[%d] Core[%d]!\n",
                              "driver-btm-c5.c",0x2a15,DAT_00036178,param_1,(uint)(byte)puVar10[2],
                              (uint)(byte)puVar10[3]);
                    }
                    fclose(pFVar2);
                  }
                  local_854[0] = 0;
                  local_854[11] = 0;
                }
                else {
                  local_854[0] = 0xff;
                  local_854[11] = 0xff;
                }
                iVar6 = 0xbb9;
                while (uVar1 = get_buffer_space(), (uVar1 & 1 << (param_1 & 0xff)) == 0) {
                  cgsleep_us(1000,0);
                  iVar6 = iVar6 + -1;
                  if (iVar6 == 0) {
                    if (3 < log_level) {
                      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
                      if (pFVar2 != (FILE *)0x0) {
                        fprintf(pFVar2,"%s:%d:%s: Error: send open core work Failed on Chain[%d]!\n"
                                ,"driver-btm-c5.c",0x2a30,DAT_00036178,param_1);
                      }
                      fclose(pFVar2);
                    }
                    goto LAB_000360ba;
                  }
                }
                if (uVar3 == 0) {
                  local_890 = 0x11000000;
                  local_85c = 0x11;
                }
                else {
                  local_890 = 0x1000000;
                  local_85c = 1;
                }
                puVar11 = &local_88c;
                local_85b = local_8cc;
                local_890 = (uint)CONCAT11(local_85a,local_859) |
                            ((param_1 | 0xffffff80) & 0xff) << 0x10 | local_890;
                local_88c = local_858;
                pbVar7 = &local_85c;
                do {
                  pbVar8 = pbVar7 + 4;
                  puVar11 = puVar11 + 1;
                  *puVar11 = (uint)pbVar7[0xb] | (uint)pbVar7[9] << 0x10 | (uint)pbVar7[8] << 0x18 |
                             (uint)pbVar7[10] << 8;
                  pbVar7 = pbVar8;
                } while (pbVar8 != local_854 + 4);
                puVar4 = &uStack_880;
                do {
                  puVar4 = puVar4 + 1;
                  *puVar4 = 0;
                } while (puVar4 != local_87c + 7);
                set_TW_write_command_vil(&local_890);
                if (uVar3 == 0x71) {
                  uVar1 = param_2 & 1;
                }
                else {
                  uVar1 = 0;
                }
                if (uVar1 != 0) {
                  uVar1 = get_BC_write_command();
                  set_BC_write_command(uVar1 | 0x400000);
                }
                uVar3 = uVar3 + 1;
              } while (uVar3 != 0x72);
            }
LAB_000360ba:
            puVar10 = puVar10 + 2;
          } while (puVar10 != (undefined1 *)(iVar9 + 0x7e466));
        }
      }
      else if ((use_syslog != '\0') || ((opt_log_output != '\0' || (4 < opt_log_level)))) {
        snprintf(acStack_828,0x800,"Chain %d disabled core magic num error [0x%x%x] except 0x2C65!!"
                 ,param_1,(uint)(byte)disabledcore_pos_buf[iVar9],
                 (uint)(byte)disabledcore_pos_buf[iVar9 + 1]);
        _applog(5,acStack_828,0);
      }
    }
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 | (opt_multi_version & 0xf) << 8 | 0x8000);
  }
  return;
}

