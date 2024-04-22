
undefined4 check_asic_reg(uint param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  double dVar17;
  int local_488;
  uint *local_480;
  uint *local_47c;
  undefined1 *local_478;
  uint local_470;
  uint uStack_46c;
  undefined4 local_45c;
  undefined local_458;
  char acStack_454 [12];
  char acStack_448 [32];
  undefined2 local_428 [514];
  undefined4 *puVar11;
  
  iVar12 = 0;
  local_45c = 0;
  local_458 = 0;
LAB_00033804:
  local_480 = DAT_00033abc;
  uVar13 = 0;
  local_47c = DAT_00033abc;
  local_478 = displayed_rate;
  clear_register_value_buf();
  local_480 = local_480 + 0x20;
  do {
    if (*(int *)(dev + (uVar13 + 2) * 4) == 1) {
      read_asic_register(uVar13 & 0xff,1,0,param_1 & 0xff);
      if (param_1 == 0) {
        *(char *)(dev + uVar13 + 0x53ec) = (char)param_1;
joined_r0x00033c06:
        if (2 < iVar12) goto LAB_00033bac;
LAB_00033882:
        local_488 = 0;
        local_470 = 0;
        uStack_46c = 0;
        uVar14 = 0;
        do {
          while( true ) {
            cgsleep_ms(300);
            pthread_mutex_lock(DAT_00033ac0);
            uVar3 = reg_value_buf._8_4_;
            if ((0x1fe < (uint)reg_value_buf._8_4_) || (0x1fe < (uint)reg_value_buf._4_4_)) {
              iVar12 = iVar12 + 1;
              pthread_mutex_unlock(DAT_00033ac0);
              goto LAB_00033804;
            }
            if (reg_value_buf._8_4_ == 0) break;
            local_488 = local_488 + reg_value_buf._8_4_;
            if (600 < local_488) {
              pthread_mutex_unlock(DAT_00033c3c);
              return 0;
            }
            iVar12 = 0;
            uVar15 = uVar14;
            do {
              while (uVar5 = reg_value_buf._4_4_ + 1, uVar14 = uVar15,
                    (byte)reg_value_buf[(reg_value_buf._4_4_ + 1) * 8 + 9] != uVar13) {
                reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
                reg_value_buf._4_4_ = uVar5;
                if (0x1fe < uVar5) {
                  reg_value_buf._4_4_ = 0;
                }
LAB_00033904:
                iVar12 = iVar12 + 1;
                uVar15 = uVar14;
                if (iVar12 == uVar3) goto LAB_0003398a;
              }
              iVar6 = reg_value_buf._4_4_ + 1;
              iVar7 = reg_value_buf._4_4_ + 1;
              iVar8 = reg_value_buf._4_4_ + 1;
              reg_value_buf._4_4_ = reg_value_buf._4_4_ + 1;
              local_45c = CONCAT31(CONCAT21(CONCAT11((char)*(undefined4 *)
                                                            (reg_value_buf + uVar5 * 8 + 4),
                                                     (char)((uint)*(undefined4 *)
                                                                   (reg_value_buf + iVar6 * 8 + 4)
                                                           >> 8)),
                                            (char)((uint)*(undefined4 *)
                                                          (reg_value_buf + iVar7 * 8 + 4) >> 0x10)),
                                   (char)((uint)*(undefined4 *)(reg_value_buf + iVar8 * 8 + 4) >>
                                         0x18));
              reg_value_buf._8_4_ = reg_value_buf._8_4_ + -1;
              if (0x1fe < (uint)reg_value_buf._4_4_) {
                reg_value_buf._4_4_ = 0;
              }
              if (param_1 != 0) {
                if (param_1 == 0xc) {
                  sprintf((char *)local_428,"chain[%d]: the asic freq is 0x%x\n",uVar13,
                          *(undefined4 *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4));
                  writeInitLogFile(local_428);
                }
                else {
                  if (param_1 == 0x18) {
                    pcVar4 = "chain[%02d] chip[%02d]: the asic TICKET_MASK is 0x%08x\n";
                  }
                  else if (param_1 == 0x14) {
                    pcVar4 = "chain[%02d] chip[%02d]: the asic HASH_COUNTING_NUMBER is 0x%08x\n";
                  }
                  else {
                    if (param_1 != 0x10) {
                      if ((param_1 == 8) && (uVar14 = uVar15 + 1, (int)uVar14 < 0x55)) {
                        puVar11 = &local_45c;
                        pcVar4 = acStack_454;
                        do {
                          puVar10 = (undefined4 *)((int)puVar11 + 1);
                          sprintf(pcVar4,"%02x",(uint)*(byte *)puVar11);
                          puVar11 = puVar10;
                          pcVar4 = pcVar4 + 2;
                        } while (puVar10 != (undefined4 *)&local_458);
                        uVar5 = strtol(acStack_454,(char **)0x0,0x10);
                        uVar9 = ((int)uVar5 >> 0x1f) << 0x18 | uVar5 >> 8;
                        uVar5 = uVar5 * 0x1000000;
                        bVar16 = uVar9 <= DAT_00033c44;
                        if (DAT_00033c44 == uVar9) {
                          bVar16 = uVar5 <= DAT_00033c40;
                        }
                        if (bVar16) {
                          bVar16 = CARRY4(uVar5,local_470);
                          local_470 = uVar5 + local_470;
                          uStack_46c = uVar9 + uStack_46c + (uint)bVar16;
                        }
                        suffix_string_c5_constprop_16(uVar5,uVar9,acStack_448,0x20,6);
                        sprintf((char *)local_428,"Asic[%02d]=%s ",uVar14,acStack_448);
                        writeLogFile(local_428);
                        dVar17 = strtod(acStack_448,(char **)0x0);
                        *(double *)(DAT_00033c38 + (uVar13 * 0x54 + uVar15) * 8) = dVar17;
                        if ((uVar14 & 7) == 0 || uVar14 == 0x54) {
                          local_428[0] = 10;
                          writeLogFile(local_428);
                        }
                      }
                      goto LAB_00033904;
                    }
                    pcVar4 = "chain[%02d] chip[%02d]: the asic START_NONCE_OFFSET is 0x%08x\n";
                  }
                  sprintf((char *)local_428,pcVar4,uVar13,uVar15 + 1,
                          *(undefined4 *)(reg_value_buf + (reg_value_buf._4_4_ + 1) * 8 + 4));
                  writeInitLogFile(local_428);
                  uVar14 = uVar15 + 1;
                }
                goto LAB_00033904;
              }
              iVar12 = iVar12 + 1;
              *(char *)(dev + uVar13 + 0x53ec) = *(char *)(dev + uVar13 + 0x53ec) + '\x01';
            } while (iVar12 != uVar3);
LAB_0003398a:
            if ((param_1 == 0) && (*(char *)(dev + uVar13 + 0x53ec) == 'T')) {
              pthread_mutex_unlock(DAT_00033c3c);
              goto LAB_00033c1a;
            }
            iVar12 = 0;
            pthread_mutex_unlock(DAT_00033ac0);
          }
          iVar12 = iVar12 + 1;
          cgsleep_ms(100);
          pthread_mutex_unlock(DAT_00033ac0);
        } while (iVar12 != 3);
        if (param_1 == 0) {
LAB_00033c1a:
          bVar1 = *(byte *)(dev + uVar13 + 0x53ec);
          if (*(byte *)(dev + 0x542e) < bVar1) {
            *(byte *)(dev + 0x542e) = bVar1;
          }
        }
        if (uVar14 == 0) goto LAB_00033bac;
        *local_47c = local_470;
        local_47c[1] = uStack_46c;
        suffix_string_c5_constprop_16(local_470,uStack_46c,local_478,0x20,6);
        cVar2 = status_error;
        *local_480 = 0;
        if (cVar2 != '\0') {
          *local_480 = 1;
          goto LAB_00033a44;
        }
      }
      else {
        if (param_1 == 8) {
          sprintf((char *)local_428,
                  "\nget RT hashrate from Chain[%d]: (asic index start from 1-%d)\n",uVar13,0x54);
          writeLogFile(local_428);
          goto joined_r0x00033c06;
        }
        if (iVar12 < 3) goto LAB_00033882;
LAB_00033bac:
        uVar14 = *local_480;
        *local_480 = uVar14 + 1;
        if (((int)(uVar14 + 1) < 4) && (status_error == '\0')) {
          iVar12 = 0;
          clear_register_value_buf();
          goto LAB_00033824;
        }
LAB_00033a44:
        *local_47c = 0;
        local_47c[1] = 0;
        suffix_string_c5_constprop_16(0,0,local_478,0x20,6);
      }
      iVar12 = 0;
      clear_register_value_buf();
    }
LAB_00033824:
    uVar13 = uVar13 + 1;
    local_47c = local_47c + 2;
    local_478 = local_478 + 0x20;
    local_480 = local_480 + 1;
    if (uVar13 == 0x10) {
      return 1;
    }
  } while( true );
}

