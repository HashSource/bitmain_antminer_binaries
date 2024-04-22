
/* WARNING: Unknown calling convention */

_Bool check_asic_reg(uint reg)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int j;
  int ii;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  double dVar12;
  undefined4 in_stack_fffffe6c;
  int local_180;
  uint local_17c;
  int local_178;
  char **local_174;
  char *local_170;
  char *pcStack_16c;
  uchar reg_buf [5];
  uchar rate_buf [10];
  char displayed_rate_asic [32];
  char logstr [256];
  
  iVar1 = DAT_00033328;
  iVar6 = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
rerun_all:
  local_178 = 0;
  uVar10 = 0;
  local_174 = DAT_00033318;
  clear_register_value_buf();
  do {
    if (dev->chain_exist[uVar10] == 1) {
      read_asic_register((uchar)uVar10,'\x01','\0',(uchar)reg);
      if (reg == 0) {
        dev->chain_asic_num[uVar10] = (uchar)reg;
      }
      else if (reg == 8) {
        sprintf(logstr,DAT_00033490,uVar10,0x12);
        writeLogFile(logstr);
      }
      if (iVar6 < 3) {
        local_180 = 0;
        local_17c = 0;
        local_170 = (char *)0x0;
        pcStack_16c = (char *)0x0;
        do {
          while( true ) {
            cgsleep_ms(300);
            pthread_mutex_lock(DAT_0003331c);
            uVar8 = *(uint *)(iVar1 + 8);
            if ((0x1fe < uVar8) || (0x1fe < *(uint *)(iVar1 + 4))) {
              iVar6 = iVar6 + 1;
              pthread_mutex_unlock(DAT_0003331c);
              goto rerun_all;
            }
            if (uVar8 == 0) break;
            local_180 = local_180 + uVar8;
            if (600 < local_180) {
              pthread_mutex_unlock(DAT_00033484);
              return false;
            }
            uVar7 = 0;
LAB_00033170:
            do {
              iVar6 = *(int *)(iVar1 + 4) + 1;
              uVar9 = local_17c;
              if (*(byte *)(iVar1 + (*(int *)(iVar1 + 4) + 1) * 8 + 9) == uVar10) {
                reg_buf[3] = (uchar)*(undefined4 *)(iVar1 + iVar6 * 8 + 4);
                reg_buf[2] = (uchar)((uint)*(undefined4 *)
                                            (iVar1 + (*(int *)(iVar1 + 4) + 1) * 8 + 4) >> 8);
                reg_buf[1] = (uchar)((uint)*(undefined4 *)
                                            (iVar1 + (*(int *)(iVar1 + 4) + 1) * 8 + 4) >> 0x10);
                uVar3 = *(uint *)(iVar1 + (*(int *)(iVar1 + 4) + 1) * 8 + 4);
                uVar4 = uVar3 >> 0x18;
                *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
                reg_buf[0] = (uchar)(uVar3 >> 0x18);
                *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
                uVar5 = *(uint *)(iVar1 + 4);
                uVar3 = uVar5;
                if (0x1fe < uVar5) {
                  uVar3 = 0;
                }
                if (0x1fe < uVar5) {
                  *(uint *)(iVar1 + 4) = uVar3;
                }
                if (reg == 0) {
                  uVar7 = uVar7 + 1;
                  dev->chain_asic_num[uVar10] = dev->chain_asic_num[uVar10] + '\x01';
                  if (uVar7 == uVar8) break;
                  goto LAB_00033170;
                }
                if (reg == 0xc) {
                  iVar6 = *(int *)(iVar1 + 4);
                  pcVar2 = DAT_0003348c;
                }
                else {
                  if (reg != 0x18) {
                    if ((reg == 8) && (uVar9 = local_17c + 1, (int)uVar9 < 0x13)) {
                      iVar6 = 0;
                      while( true ) {
                        sprintf((char *)(rate_buf + iVar6 * 2),DAT_00033320,uVar4);
                        if (iVar6 + 1 == 4) break;
                        uVar4 = (uint)reg_buf[iVar6 + 1];
                        iVar6 = iVar6 + 1;
                      }
                      uVar3 = strtol((char *)rate_buf,(char **)0x0,0x10);
                      uVar4 = ((int)uVar3 >> 0x1f) << 0x18 | uVar3 >> 8;
                      pcVar2 = (char *)(uVar3 * 0x1000000);
                      bVar11 = CARRY4((uint)local_170,(uint)pcVar2);
                      local_170 = local_170 + (int)pcVar2;
                      pcStack_16c = pcStack_16c + uVar4 + bVar11;
                      suffix_string_c5(CONCAT44(in_stack_fffffe6c,6),pcVar2,uVar4,
                                       (int)displayed_rate_asic,true);
                      sprintf(logstr,DAT_00033324,uVar9,displayed_rate_asic);
                      iVar6 = DAT_0003332c;
                      writeLogFile(logstr);
                      dVar12 = strtod(displayed_rate_asic,(char **)0x0);
                      *(double *)(iVar6 + (uVar10 * 0x12 + local_17c) * 8) = dVar12;
                      if (((uVar9 & 7) == 0) || (uVar9 == 0x12)) {
                        logstr[0] = '\n';
                        logstr[1] = '\0';
                        writeLogFile(logstr);
                      }
                    }
                    goto LAB_0003316a;
                  }
                  iVar6 = *(int *)(iVar1 + 4);
                  pcVar2 = DAT_00033488;
                }
                sprintf(logstr,pcVar2,uVar10,*(undefined4 *)(iVar1 + (iVar6 + 1) * 8 + 4));
                writeInitLogFile(logstr);
              }
              else {
                *(int *)(iVar1 + 4) = iVar6;
                *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
                uVar4 = *(uint *)(iVar1 + 4);
                uVar3 = uVar4;
                if (0x1fe < uVar4) {
                  uVar3 = 0;
                }
                if (0x1fe < uVar4) {
                  *(uint *)(iVar1 + 4) = uVar3;
                }
              }
LAB_0003316a:
              local_17c = uVar9;
              uVar7 = uVar7 + 1;
            } while (uVar7 != uVar8);
            if ((reg == 0) && (dev->chain_asic_num[uVar10] == '\x12')) {
              pthread_mutex_unlock(DAT_00033484);
              goto LAB_00033416;
            }
            iVar6 = 0;
            pthread_mutex_unlock(DAT_0003331c);
          }
          iVar6 = iVar6 + 1;
          cgsleep_ms(100);
          pthread_mutex_unlock(DAT_00033484);
        } while (iVar6 != 3);
      }
      else {
        local_170 = (char *)0x0;
        pcStack_16c = (char *)0x0;
        local_17c = 0;
      }
      if (reg == 0) {
LAB_00033416:
        uVar8 = (uint)dev->chain_asic_num[uVar10];
        if (dev->max_asic_num_in_one_chain < uVar8) {
          dev->max_asic_num_in_one_chain = dev->chain_asic_num[uVar10];
        }
      }
      else {
        uVar8 = (uint)dev->chain_asic_num[uVar10];
      }
      if (uVar8 == local_17c) {
        *local_174 = local_170;
        local_174[1] = pcStack_16c;
        suffix_string_c5(CONCAT44(in_stack_fffffe6c,6),local_170,(size_t)pcStack_16c,
                         (int)(displayed_rate + uVar10),true);
        *(undefined4 *)(local_178 + DAT_00033494) = 0;
      }
      if (((local_17c == 0) || (status_error != false)) &&
         ((iVar6 = *(int *)(local_178 + DAT_00033494) + 1,
          *(int *)(local_178 + DAT_00033494) = iVar6, 3 < iVar6 || (status_error != false)))) {
        *local_174 = (char *)0x0;
        local_174[1] = (char *)0x0;
        suffix_string_c5(CONCAT44(in_stack_fffffe6c,6),(char *)0x0,0,(int)(displayed_rate + uVar10),
                         true);
      }
      iVar6 = 0;
      clear_register_value_buf();
    }
    uVar10 = uVar10 + 1;
    local_174 = local_174 + 2;
    local_178 = local_178 + 4;
    if (uVar10 == 0x10) {
      return true;
    }
  } while( true );
}

