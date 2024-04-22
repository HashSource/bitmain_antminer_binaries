
/* WARNING: Type propagation algorithm not settling */

undefined4 check_asic_reg_oneChain(uint param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  char *__s;
  bool bVar11;
  int local_864;
  uint local_860;
  int iStack_85c;
  uint local_858;
  undefined local_83c [4];
  undefined local_838;
  char acStack_834 [12];
  char acStack_828 [2052];
  
  iVar10 = 0;
  local_83c = (undefined  [4])0x0;
  local_838 = 0;
  while( true ) {
    clear_register_value_buf();
    if (*(int *)(dev + (param_1 + 2) * 4) != 1) {
      return 1;
    }
    read_asic_register(param_1 & 0xff,1,0,param_2 & 0xff);
    if (param_2 == 0) {
      *(char *)(dev + param_1 + 0x53ec) = (char)param_2;
    }
    if (2 < iVar10) break;
    local_864 = 0;
    local_858 = 0;
    local_860 = 0;
    iStack_85c = 0;
    while( true ) {
      cgsleep_ms(300);
      pthread_mutex_lock(DAT_00031d70);
      uVar3 = reg_value_buf._8_4_;
      if ((0x1fe < (uint)reg_value_buf._8_4_) || (0x1fe < (uint)reg_value_buf._4_4_)) break;
      if (reg_value_buf._8_4_ == 0) {
        iVar10 = iVar10 + 1;
        cgsleep_ms(100);
        pthread_mutex_unlock(DAT_00031d70);
        if (iVar10 == 3) goto LAB_00031cf4;
      }
      else {
        local_864 = local_864 + reg_value_buf._8_4_;
        if (600 < local_864) {
          pthread_mutex_unlock(DAT_00031e88);
          return 0;
        }
        iVar10 = 0;
        do {
          while (uVar5 = reg_value_buf._4_4_ + 1,
                param_1 != (byte)reg_value_buf[(reg_value_buf._4_4_ + 1) * 8 + 9]) {
            reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
            reg_value_buf._4_4_ = uVar5;
            if (0x1fe < uVar5) {
              reg_value_buf._4_4_ = 0;
            }
LAB_00031b32:
            iVar10 = iVar10 + 1;
            if (iVar10 == uVar3) goto LAB_00031bbc;
          }
          iVar6 = reg_value_buf._4_4_ + 1;
          iVar7 = reg_value_buf._4_4_ + 1;
          iVar8 = reg_value_buf._4_4_ + 1;
          reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
          uVar4 = *(uint *)(reg_value_buf + iVar8 * 8 + 4) >> 0x18;
          local_83c = (undefined  [4])
                      CONCAT31(CONCAT21(CONCAT11((char)*(undefined4 *)
                                                        (reg_value_buf + uVar5 * 8 + 4),
                                                 (char)((uint)*(undefined4 *)
                                                               (reg_value_buf + iVar6 * 8 + 4) >> 8)
                                                ),
                                        (char)((uint)*(undefined4 *)(reg_value_buf + iVar7 * 8 + 4)
                                              >> 0x10)),
                               (char)(*(uint *)(reg_value_buf + iVar8 * 8 + 4) >> 0x18));
          reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
          if (0x1fe < (uint)reg_value_buf._4_4_) {
            reg_value_buf._4_4_ = 0;
          }
          if (param_2 != 0) {
            if (param_2 == 0xc) {
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"%s: the asic freq is 0x%x\n",DAT_00031d74,
                         *(undefined4 *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4));
                _applog(7,acStack_828,0);
              }
            }
            else if (param_2 == 8) {
              puVar9 = (undefined4 *)local_83c;
              __s = acStack_834;
              while( true ) {
                sprintf(__s,"%02x",uVar4);
                __s = __s + 2;
                if (puVar9 == (undefined4 *)((int)local_83c + 3)) break;
                puVar9 = (undefined4 *)((int)puVar9 + 1);
                uVar4 = (uint)*(byte *)puVar9;
              }
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_828,0x800,"%s: hashrate is %s\n",DAT_00031d74,acStack_834);
                _applog(7,acStack_828,0);
              }
              local_858 = local_858 + 1;
              uVar5 = strtol(acStack_834,(char **)0x0,0x10);
              bVar11 = CARRY4(uVar5 * 0x1000000,local_860);
              local_860 = uVar5 * 0x1000000 + local_860;
              iStack_85c = (((int)uVar5 >> 0x1f) << 0x18 | uVar5 >> 8) + iStack_85c + (uint)bVar11;
            }
            goto LAB_00031b32;
          }
          iVar10 = iVar10 + 1;
          *(char *)(dev + param_1 + 0x53ec) = *(char *)(dev + param_1 + 0x53ec) + '\x01';
        } while (iVar10 != uVar3);
LAB_00031bbc:
        if ((param_2 == 0) && (*(char *)(dev + param_1 + 0x53ec) == 'T')) {
          pthread_mutex_unlock(DAT_00031d70);
          goto LAB_00031df6;
        }
        iVar10 = 0;
        pthread_mutex_unlock(DAT_00031d70);
      }
    }
    iVar10 = iVar10 + 1;
    pthread_mutex_unlock(DAT_00031d70);
  }
  local_858 = 0;
  local_860 = 0;
  iStack_85c = 0;
LAB_00031cf4:
  if (param_2 == 0) {
LAB_00031df6:
    bVar1 = *(byte *)(dev + param_1 + 0x53ec);
    uVar5 = (uint)bVar1;
    if (*(byte *)(dev + 0x542e) < uVar5) {
      *(byte *)(dev + 0x542e) = bVar1;
    }
  }
  else {
    uVar5 = (uint)*(byte *)(dev + param_1 + 0x53ec);
  }
  if (uVar5 == local_858) {
    *(uint *)(rate + param_1 * 8) = local_860;
    *(int *)(rate + param_1 * 8 + 4) = iStack_85c;
    suffix_string_c5_constprop_16(local_860,iStack_85c,displayed_rate + param_1 * 0x20,0x20,6);
    cVar2 = opt_debug;
    *(undefined4 *)(rate_error + param_1 * 4) = 0;
    if ((cVar2 != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_828,0x800,"%s: chain %d hashrate is %s\n",DAT_00031e8c,param_1,
               displayed_rate + param_1 * 0x20);
      _applog(7,acStack_828,0);
      goto LAB_00031d0c;
    }
    if (uVar5 == 0) {
      *(undefined4 *)(rate_error + param_1 * 4) = 1;
      goto LAB_00031d2c;
    }
LAB_00031dcc:
    if (status_error == '\0') goto LAB_00031d60;
    *(int *)(rate_error + param_1 * 4) = *(int *)(rate_error + param_1 * 4) + 1;
  }
  else {
LAB_00031d0c:
    if (local_858 != 0) goto LAB_00031dcc;
    iVar10 = *(int *)(rate_error + param_1 * 4);
    *(int *)(rate_error + param_1 * 4) = iVar10 + 1;
    if (iVar10 + 1 < 4) {
LAB_00031d2c:
      if (status_error == '\0') goto LAB_00031d60;
    }
  }
  puVar9 = (undefined4 *)(DAT_00031d78 + param_1 * 8);
  *puVar9 = 0;
  puVar9[1] = 0;
  suffix_string_c5_constprop_16(0,0,displayed_rate + param_1 * 0x20,0x20,6);
LAB_00031d60:
  clear_register_value_buf();
  return 1;
}

