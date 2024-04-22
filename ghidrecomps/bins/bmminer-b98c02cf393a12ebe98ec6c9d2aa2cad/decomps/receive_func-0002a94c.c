
undefined4 receive_func(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint local_40;
  uint local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = 0;
  uVar14 = 0;
  memset(DAT_0002ac68,0xff,0x4000);
  memset(DAT_0002ac6c,0,0x40);
  memset(DAT_0002ac70,0,0x40);
  memset(DAT_0002ac74,0,0x40);
  local_40 = 0;
  memset(m_nonce,0,0x40);
  iVar1 = DAT_0002ac78;
  do {
    while( true ) {
      while( true ) {
        if (ExitFlag != '\0') {
          return 0;
        }
        uVar5 = (uint)start_receive;
        if (uVar5 != 0) break;
        local_30 = uVar5;
        local_2c = uVar5;
        memset(DAT_0002ac68,0xff,0x4000);
        memset(DAT_0002ac6c,0,0x40);
        memset(DAT_0002ac70,0,0x40);
        memset(DAT_0002ac74,0,0x40);
        memset(DAT_0002ac7c,0,0x40);
        usleep(100000);
        uVar14 = 0;
        local_40 = 0;
      }
      uVar2 = get_nonce_number_in_fifo();
      uVar5 = 0;
      if ((uVar2 & 0x1ff) != 0) break;
      usleep(1000);
    }
    do {
      get_return_nonce(&local_30);
      if ((int)local_30 < 0) {
        if ((gBegin_get_nonce != '\0') && ((int)(local_30 << 0x18) < 0)) {
          uVar12 = local_30 & 0xf;
          iVar10 = uVar12 * 4;
          uVar3 = *(uint *)(last_nonce + iVar10);
          *(uint *)(work_id + iVar10) = (local_30 << 1) >> 0x11;
          if ((local_2c == uVar3) || (local_2c == *(uint *)(llast_nonce + iVar10))) {
            *(int *)(last_nonce_num + iVar10) = *(int *)(last_nonce_num + iVar10) + 1;
          }
          else {
            if (*DAT_0002ac80 == 1) {
              if ((int)conf._16_4_ < 0x41) {
                local_40 = local_2c & 0x3f;
                uVar15 = local_40;
LAB_0002aaf6:
                if (uVar15 == 0) {
                  uVar6 = 0;
                  goto LAB_0002aa8c;
                }
              }
              else {
                if (0x3f < conf._16_4_ - 0x41) {
                  printf("%s: conf.core = %d, but it is error\n","receive_func");
                  uVar3 = *(uint *)(last_nonce + iVar10);
                  uVar15 = uVar14;
                  goto LAB_0002aaf6;
                }
                local_40 = local_2c & 0x7f;
                uVar15 = local_40;
                if ((local_40 < 0x39) || (uVar15 = uVar14, 0x3f < local_40 - 0x40))
                goto LAB_0002aaf6;
                uVar15 = local_40 - 7 & 0xff;
              }
              uVar6 = 0;
              uVar8 = 0;
              uVar14 = conf._120_4_;
              uVar7 = conf._116_4_;
              uVar11 = conf._112_4_;
              uVar16 = conf._108_4_;
              do {
                while (uVar8 < 0x20) {
                  if ((uVar16 & 1) == 0) {
                    uVar16 = uVar16 >> 1;
                  }
                  else {
                    uVar16 = uVar16 >> 1;
                    uVar6 = uVar6 + 1 & 0xff;
                  }
LAB_0002ab32:
                  uVar8 = uVar8 + 1;
                  if (uVar8 == uVar15) goto LAB_0002aa8c;
                }
                if (0x1f < uVar8 - 0x20) {
                  if (uVar8 - 0x40 < 0x20) {
                    if ((uVar7 & 1) != 0) {
                      uVar6 = uVar6 + 1 & 0xff;
                    }
                    uVar7 = uVar7 >> 1;
                  }
                  else {
                    if ((uVar14 & 1) != 0) {
                      uVar6 = uVar6 + 1 & 0xff;
                    }
                    uVar14 = uVar14 >> 1;
                  }
                  goto LAB_0002ab32;
                }
                uVar8 = uVar8 + 1;
                if ((uVar11 & 1) != 0) {
                  uVar6 = uVar6 + 1 & 0xff;
                }
                uVar11 = uVar11 >> 1;
              } while (uVar8 != uVar15);
            }
            else {
              uVar6 = local_2c / 0x3000000;
              uVar15 = uVar6;
              if (0x53 < uVar6) goto LAB_0002aa24;
            }
LAB_0002aa8c:
            uVar7 = *(uint *)(work_id + iVar10);
            *(uint *)(llast_nonce + iVar10) = uVar3;
            *(uint *)(last_nonce + iVar10) = local_2c;
            uVar14 = uVar15;
            if (uVar7 < 5000) {
              uVar3 = *(uint *)(uVar7 * 0x34 + *(int *)(iVar1 + uVar6 * 4 + -0x26fd64) + 4);
              *(uint *)(m_nonce + iVar10) = uVar3;
              if (uVar3 == local_2c) {
                iVar13 = uVar12 * 0x100;
                iVar17 = (iVar13 + uVar15) * 4;
                if (uVar7 == *(uint *)(repeated_nonce_id + iVar17)) {
                  *(int *)(repeated_nonce_num + iVar10) = *(int *)(repeated_nonce_num + iVar10) + 1;
                }
                else {
                  *(uint *)(repeated_nonce_id + iVar17) = uVar7;
                  iVar4 = *DAT_0002ac80;
                  iVar9 = *(int *)(valid_nonce_num + iVar10);
                  *(int *)(asic_nonce_num + iVar17) = *(int *)(asic_nonce_num + iVar17) + 1;
                  *(int *)(valid_nonce_num + iVar10) = iVar9 + 1;
                  total_valid_nonce_num = total_valid_nonce_num + 1;
                  if (iVar4 != 1) {
                    if ((int)conf._16_4_ < 0x41) {
                      local_40 = local_2c & 0x3f;
                    }
                    else if (conf._16_4_ - 0x41 < 0x40) {
                      local_40 = local_2c & 0x7f;
                      if (local_40 - 0x40 < 0x40) {
                        local_40 = local_40 - 7 & 0xff;
                      }
                    }
                    else {
                      printf("%s: conf.core = %d, but it is error\n","receive_func");
                    }
                    iVar10 = (local_40 + (iVar13 + uVar15) * 0x100) * 4;
                    *(int *)(asic_core_nonce_num + iVar10) =
                         *(int *)(asic_core_nonce_num + iVar10) + 1;
                  }
                }
              }
              else {
                *(int *)(err_nonce_num + iVar10) = *(int *)(err_nonce_num + iVar10) + 1;
              }
            }
          }
        }
      }
      else {
        insert_reg_data(&local_30);
      }
LAB_0002aa24:
      uVar5 = uVar5 + 1;
    } while ((uVar2 & 0x1ff) != uVar5);
  } while( true );
}

