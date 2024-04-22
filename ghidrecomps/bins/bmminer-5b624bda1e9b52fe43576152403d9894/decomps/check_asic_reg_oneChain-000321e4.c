
/* WARNING: Unknown calling convention */

_Bool check_asic_reg_oneChain(int chainIndex,uint reg)

{
  byte bVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 *puVar9;
  int iVar10;
  int i;
  uint uVar11;
  uint uVar12;
  int j;
  bool bVar13;
  int in_stack_fffff794;
  int local_854;
  char *local_850;
  char *pcStack_84c;
  uint local_848;
  uchar reg_buf [5];
  uchar rate_buf [10];
  char tmp42 [2048];
  
  piVar3 = DAT_000324ac;
  iVar7 = DAT_0003248c;
  iVar10 = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
  while( true ) {
    clear_register_value_buf();
    if (*(int *)(*piVar3 + (chainIndex + 2) * 4) != 1) {
      return true;
    }
    read_asic_register((uchar)chainIndex,'\x01','\0',(uchar)reg);
    if (reg == 0) {
      dev->chain_asic_num[chainIndex] = (uchar)reg;
    }
    if (2 < iVar10) break;
    local_854 = 0;
    local_850 = (char *)0x0;
    pcStack_84c = (char *)0x0;
    local_848 = 0;
    while( true ) {
      cgsleep_ms(300);
      pthread_mutex_lock(DAT_00032490);
      uVar11 = *(uint *)(iVar7 + 8);
      if ((0x1fe < uVar11) || (0x1fe < *(uint *)(iVar7 + 4))) break;
      if (uVar11 == 0) {
        iVar10 = iVar10 + 1;
        cgsleep_ms(100);
        pthread_mutex_unlock(DAT_000325e8);
        if (iVar10 == 3) goto LAB_000324c8;
      }
      else {
        local_854 = local_854 + uVar11;
        if (600 < local_854) {
          pthread_mutex_unlock(DAT_000325e8);
          return false;
        }
        uVar12 = 0;
LAB_000322d0:
        do {
          iVar10 = *(int *)(iVar7 + 4) + 1;
          if (chainIndex == (uint)*(byte *)(iVar7 + (*(int *)(iVar7 + 4) + 1) * 8 + 9)) {
            reg_buf[3] = (uchar)*(undefined4 *)(iVar7 + iVar10 * 8 + 4);
            reg_buf[2] = (uchar)((uint)*(undefined4 *)(iVar7 + (*(int *)(iVar7 + 4) + 1) * 8 + 4) >>
                                8);
            reg_buf[1] = (uchar)((uint)*(undefined4 *)(iVar7 + (*(int *)(iVar7 + 4) + 1) * 8 + 4) >>
                                0x10);
            uVar4 = *(uint *)(iVar7 + (*(int *)(iVar7 + 4) + 1) * 8 + 4);
            uVar5 = uVar4 >> 0x18;
            *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
            reg_buf[0] = (uchar)(uVar4 >> 0x18);
            *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + -1;
            uVar6 = *(uint *)(iVar7 + 4);
            uVar4 = uVar6;
            if (0x1fe < uVar6) {
              uVar4 = 0;
            }
            if (0x1fe < uVar6) {
              *(uint *)(iVar7 + 4) = uVar4;
            }
            if (reg == 0) {
              uVar12 = uVar12 + 1;
              *(char *)(*piVar3 + chainIndex + 0x2faa) =
                   *(char *)(*piVar3 + chainIndex + 0x2faa) + '\x01';
              if (uVar12 == uVar11) break;
              goto LAB_000322d0;
            }
            if (reg == 0xc) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (*DAT_00032494 != '\0')) || (6 < *DAT_00032498)))) {
                snprintf(tmp42,0x800,DAT_0003249c,DAT_000324a0,
                         *(undefined4 *)(iVar7 + (*(int *)(iVar7 + 4) + 1) * 8 + 4));
                _applog(7,tmp42,false);
              }
            }
            else if (reg == 8) {
              iVar10 = 0;
              while( true ) {
                sprintf((char *)(rate_buf + iVar10 * 2),DAT_000324a4,uVar5);
                if (iVar10 + 1 == 4) break;
                uVar5 = (uint)reg_buf[iVar10 + 1];
                iVar10 = iVar10 + 1;
              }
              if ((opt_debug != false) &&
                 (((use_syslog != false || (*DAT_00032494 != '\0')) || (6 < *DAT_00032498)))) {
                snprintf(tmp42,0x800,DAT_000324a8,DAT_000324a0,rate_buf);
                _applog(7,tmp42,false);
              }
              local_848 = local_848 + 1;
              uVar4 = strtol((char *)rate_buf,(char **)0x0,0x10);
              bVar13 = CARRY4((uint)local_850,uVar4 * 0x1000000);
              local_850 = local_850 + uVar4 * 0x1000000;
              pcStack_84c = pcStack_84c + (((int)uVar4 >> 0x1f) << 0x18 | uVar4 >> 8) + (uint)bVar13
              ;
            }
          }
          else {
            *(int *)(iVar7 + 4) = iVar10;
            *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + -1;
            uVar5 = *(uint *)(iVar7 + 4);
            uVar4 = uVar5;
            if (0x1fe < uVar5) {
              uVar4 = 0;
            }
            if (0x1fe < uVar5) {
              *(uint *)(iVar7 + 4) = uVar4;
            }
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 != uVar11);
        if ((reg == 0) && (*(char *)(*piVar3 + chainIndex + 0x2faa) == '\x12')) {
          pthread_mutex_unlock(DAT_00032490);
          goto LAB_0003253c;
        }
        iVar10 = 0;
        pthread_mutex_unlock(DAT_00032490);
      }
    }
    iVar10 = iVar10 + 1;
    pthread_mutex_unlock(DAT_00032490);
  }
  local_850 = (char *)0x0;
  pcStack_84c = (char *)0x0;
  local_848 = 0;
LAB_000324c8:
  if (reg == 0) {
LAB_0003253c:
    iVar10 = *piVar3;
    bVar1 = *(byte *)(iVar10 + chainIndex + 0x2faa);
    uVar11 = (uint)bVar1;
    if (*(byte *)(iVar10 + 0x2fe9) < uVar11) {
      *(byte *)(iVar10 + 0x2fe9) = bVar1;
    }
  }
  else {
    uVar11 = (uint)*(byte *)(*piVar3 + chainIndex + 0x2faa);
  }
  if (uVar11 == local_848) {
    iVar10 = DAT_000325f8 + chainIndex * 0x20;
    ppcVar8 = (char **)(DAT_000325f4 + chainIndex * 8);
    *ppcVar8 = local_850;
    ppcVar8[1] = pcStack_84c;
    suffix_string_c5(CONCAT44(in_stack_fffff794,6),local_850,(size_t)pcStack_84c,iVar10,true);
    cVar2 = *DAT_000325fc;
    *(undefined4 *)(DAT_000325f0 + chainIndex * 4 + 0xdd8) = 0;
    if ((cVar2 != '\0') &&
       (((*DAT_00032600 != '\0' || (*DAT_00032604 != '\0')) || (6 < *DAT_00032608)))) {
      snprintf(tmp42,0x800,DAT_0003260c,DAT_00032610,chainIndex);
      _applog(7,tmp42,false);
      in_stack_fffff794 = iVar10;
    }
  }
  if (((local_848 == 0) || (*(char *)(DAT_000325ec + 8) != '\0')) &&
     ((iVar10 = DAT_000325f0 + chainIndex * 4, iVar7 = *(int *)(iVar10 + 0xdd8) + 1,
      *(int *)(iVar10 + 0xdd8) = iVar7, 3 < iVar7 || (*(char *)(DAT_000325ec + 8) != '\0')))) {
    puVar9 = (undefined4 *)(DAT_000325f4 + chainIndex * 8);
    iVar10 = DAT_000325f8 + chainIndex * 0x20;
    *puVar9 = 0;
    puVar9[1] = 0;
    suffix_string_c5(CONCAT44(in_stack_fffff794,6),(char *)0x0,0,iVar10,true);
  }
  clear_register_value_buf();
  return true;
}

