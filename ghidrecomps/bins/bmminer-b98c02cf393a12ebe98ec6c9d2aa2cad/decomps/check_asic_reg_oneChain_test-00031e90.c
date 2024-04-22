
/* WARNING: Type propagation algorithm not settling */

undefined4 check_asic_reg_oneChain_test(uint param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  FILE *pFVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  char *__s;
  bool bVar12;
  int local_864;
  uint local_860;
  int iStack_85c;
  uint local_858;
  undefined local_83c [4];
  undefined local_838;
  char acStack_834 [12];
  char acStack_828 [2052];
  
  iVar11 = 0;
  local_83c = (undefined  [4])0x0;
  local_838 = 0;
  while( true ) {
    clear_register_value_buf();
    if (*(int *)(dev + (param_1 + 2) * 4) != 1) {
      return 1;
    }
    if (3 < log_level) {
      pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: do read_asic_register on Chain[%d]...\n","driver-btm-c5.c",0x175a,
                DAT_00032504,param_1);
      }
      fclose(pFVar4);
    }
    read_asic_register(param_1 & 0xff,1,0,param_2 & 0xff);
    if (3 < log_level) {
      pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: Done read_asic_register on Chain[%d]\n","driver-btm-c5.c",0x175e,
                DAT_00032504,param_1);
      }
      fclose(pFVar4);
    }
    if (param_2 == 0) {
      *(char *)(dev + param_1 + 0x53ec) = (char)param_2;
    }
    if (2 < iVar11) break;
    local_864 = 0;
    local_858 = 0;
    local_860 = 0;
    iStack_85c = 0;
    while( true ) {
      cgsleep_ms(300);
      pthread_mutex_lock(DAT_000321d8);
      uVar3 = reg_value_buf._8_4_;
      if ((0x1fe < (uint)reg_value_buf._8_4_) || (0x1fe < (uint)reg_value_buf._4_4_)) break;
      if (reg_value_buf._8_4_ == 0) {
        iVar11 = iVar11 + 1;
        cgsleep_ms(100);
        if (3 < log_level) {
          pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: not_reg_data_time=%d on Chain[%d]\n","driver-btm-c5.c",0x17e3,
                    DAT_00032504,iVar11,param_1);
          }
          fclose(pFVar4);
        }
        pthread_mutex_unlock(DAT_000324fc);
        if (iVar11 == 3) goto LAB_00032202;
      }
      else {
        local_864 = local_864 + reg_value_buf._8_4_;
        if (600 < local_864) {
          if (3 < log_level) {
            pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar4 != (FILE *)0x0) {
              fprintf(pFVar4,
                      "%s:%d:%s: Fatal Error: read asic reg Error on Chain[%d] reg_processed_counter=%d\n"
                      ,"driver-btm-c5.c",0x1782,DAT_00032504,param_1,local_864);
            }
            fclose(pFVar4);
          }
          pthread_mutex_unlock(DAT_000324fc);
          return 0;
        }
        if (3 < log_level) {
          pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: process reg_value_num=%d on Chain[%d]\n","driver-btm-c5.c",
                    0x1788,DAT_00032504,uVar3,param_1);
          }
          fclose(pFVar4);
        }
        iVar11 = 0;
        do {
          while (param_1 != (byte)reg_value_buf[(reg_value_buf._4_4_ + 1) * 8 + 9]) {
            if (3 < log_level) {
              pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
              if (pFVar4 != (FILE *)0x0) {
                fprintf(pFVar4,"%s:%d:%s: Fatal Error: read asic reg chain_number=%d on Chain[%d]\n"
                        ,"driver-btm-c5.c",0x1790,DAT_000321dc,
                        (uint)(byte)reg_value_buf[(reg_value_buf._4_4_ + 1) * 8 + 9],param_1);
              }
              fclose(pFVar4);
            }
            reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
            reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
            if (0x1fe < (uint)reg_value_buf._4_4_) {
              reg_value_buf._4_4_ = 0;
            }
LAB_00031fc4:
            iVar11 = iVar11 + 1;
            if (iVar11 == uVar3) goto LAB_0003204c;
          }
          iVar6 = reg_value_buf._4_4_ + 1;
          iVar7 = reg_value_buf._4_4_ + 1;
          iVar8 = reg_value_buf._4_4_ + 1;
          iVar9 = reg_value_buf._4_4_ + 1;
          reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
          uVar5 = *(uint *)(reg_value_buf + iVar9 * 8 + 4) >> 0x18;
          local_83c = (undefined  [4])
                      CONCAT31(CONCAT21(CONCAT11((char)*(undefined4 *)
                                                        (reg_value_buf + iVar6 * 8 + 4),
                                                 (char)((uint)*(undefined4 *)
                                                               (reg_value_buf + iVar7 * 8 + 4) >> 8)
                                                ),
                                        (char)((uint)*(undefined4 *)(reg_value_buf + iVar8 * 8 + 4)
                                              >> 0x10)),
                               (char)(*(uint *)(reg_value_buf + iVar9 * 8 + 4) >> 0x18));
          reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
          if (0x1fe < (uint)reg_value_buf._4_4_) {
            reg_value_buf._4_4_ = 0;
          }
          if (param_2 != 0) {
            if (param_2 == 0xc) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"%s: the asic freq is 0x%x\n",DAT_000321dc,
                         *(undefined4 *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4));
                _applog(7,acStack_828,0);
              }
            }
            else if (param_2 == 8) {
              puVar10 = (undefined4 *)local_83c;
              __s = acStack_834;
              while( true ) {
                sprintf(__s,"%02x",uVar5);
                __s = __s + 2;
                if (puVar10 == (undefined4 *)((int)local_83c + 3)) break;
                puVar10 = (undefined4 *)((int)puVar10 + 1);
                uVar5 = (uint)*(byte *)puVar10;
              }
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"%s: hashrate is %s\n",DAT_000321dc,acStack_834);
                _applog(7,acStack_828,0);
              }
              local_858 = local_858 + 1;
              uVar5 = strtol(acStack_834,(char **)0x0,0x10);
              bVar12 = CARRY4(uVar5 * 0x1000000,local_860);
              local_860 = uVar5 * 0x1000000 + local_860;
              iStack_85c = (((int)uVar5 >> 0x1f) << 0x18 | uVar5 >> 8) + iStack_85c + (uint)bVar12;
            }
            goto LAB_00031fc4;
          }
          iVar11 = iVar11 + 1;
          *(char *)(dev + param_1 + 0x53ec) = *(char *)(dev + param_1 + 0x53ec) + '\x01';
        } while (iVar11 != uVar3);
LAB_0003204c:
        if ((param_2 == 0) && (*(char *)(dev + param_1 + 0x53ec) == 'T')) {
          pthread_mutex_unlock(DAT_000324fc);
          goto LAB_0003243e;
        }
        if (3 < log_level) {
          pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar4 != (FILE *)0x0) {
            fprintf(pFVar4,"%s:%d:%s: Done reg_value_num=%d on Chain[%d]\n","driver-btm-c5.c",0x17dc
                    ,DAT_00032504,uVar3,param_1);
          }
          fclose(pFVar4);
        }
        iVar11 = 0;
        pthread_mutex_unlock(DAT_000321d8);
      }
    }
    iVar11 = iVar11 + 1;
    if (3 < log_level) {
      pFVar4 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,
                "%s:%d:%s: Need Retry: read asic reg reg_value_num=%d reg_value_buf.p_rd=%d on Chain[%d]\n"
                ,"driver-btm-c5.c",0x176e,DAT_00032504,uVar3,reg_value_buf._4_4_,param_1);
      }
      fclose(pFVar4);
    }
    pthread_mutex_unlock(DAT_000321d8);
  }
  local_860 = 0;
  iStack_85c = 0;
  local_858 = 0;
LAB_00032202:
  if (param_2 == 0) {
LAB_0003243e:
    bVar1 = *(byte *)(dev + param_1 + 0x53ec);
    uVar5 = (uint)bVar1;
    if (*(byte *)(dev + 0x542e) < uVar5) {
      *(byte *)(dev + 0x542e) = bVar1;
    }
  }
  else {
    uVar5 = (uint)*(byte *)(dev + param_1 + 0x53ec);
  }
  if (local_858 == uVar5) {
    *(uint *)(rate + param_1 * 8) = local_860;
    *(int *)(rate + param_1 * 8 + 4) = iStack_85c;
    suffix_string_c5_constprop_16(local_860,iStack_85c,displayed_rate + param_1 * 0x20,0x20,6);
    cVar2 = opt_debug;
    *(undefined4 *)(rate_error + param_1 * 4) = 0;
    if ((cVar2 != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_828,0x800,"%s: chain %d hashrate is %s\n",DAT_00032574,param_1,
               displayed_rate + param_1 * 0x20);
      _applog(7,acStack_828,0);
      goto LAB_0003221e;
    }
    if (local_858 == 0) {
      *(undefined4 *)(rate_error + param_1 * 4) = 1;
      goto LAB_00032240;
    }
LAB_0003240e:
    if (status_error == '\0') goto LAB_00032274;
    *(int *)(rate_error + param_1 * 4) = *(int *)(rate_error + param_1 * 4) + 1;
  }
  else {
LAB_0003221e:
    if (local_858 != 0) goto LAB_0003240e;
    iVar11 = *(int *)(rate_error + param_1 * 4);
    *(int *)(rate_error + param_1 * 4) = iVar11 + 1;
    if (iVar11 + 1 < 4) {
LAB_00032240:
      if (status_error == '\0') goto LAB_00032274;
    }
  }
  puVar10 = (undefined4 *)(DAT_00032500 + param_1 * 8);
  *puVar10 = 0;
  puVar10[1] = 0;
  suffix_string_c5_constprop_16(0,0,displayed_rate + param_1 * 0x20,0x20,6);
LAB_00032274:
  clear_register_value_buf();
  return 1;
}

