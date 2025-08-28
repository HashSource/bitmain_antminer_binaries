
undefined4 receive_func(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint local_40;
  uint local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = 0;
  uVar13 = 0;
  memset(repeated_nonce_id,0xff,0x4000);
  memset(last_nonce,0,0x40);
  memset(llast_nonce,0,0x40);
  memset(work_id,0,0x40);
  local_40 = 0;
  memset(m_nonce,0,0x40);
  do {
    while( true ) {
      while( true ) {
        if (ExitFlag != '\0') {
          return 0;
        }
        uVar4 = (uint)start_receive;
        if (uVar4 != 0) break;
        local_30 = uVar4;
        local_2c = uVar4;
        memset(repeated_nonce_id,0xff,0x4000);
        memset(last_nonce,0,0x40);
        memset(llast_nonce,0,0x40);
        memset(work_id,0,0x40);
        memset(m_nonce,0,0x40);
        usleep(100000);
        uVar13 = 0;
        local_40 = 0;
      }
      uVar2 = get_nonce_number_in_fifo();
      uVar4 = 0;
      if ((uVar2 & 0x1ff) != 0) break;
      usleep(1000);
    }
    do {
      get_return_nonce(&local_30);
      if ((int)local_30 < 0) {
        if ((gBegin_get_nonce != '\0') && ((int)(local_30 << 0x18) < 0)) {
          uVar11 = local_30 & 0xf;
          iVar9 = uVar11 * 4;
          uVar3 = *(uint *)(last_nonce + iVar9);
          *(uint *)(work_id + iVar9) = (local_30 << 1) >> 0x11;
          if ((local_2c == uVar3) || (local_2c == *(uint *)(llast_nonce + iVar9))) {
            *(int *)(last_nonce_num + iVar9) = *(int *)(last_nonce_num + iVar9) + 1;
          }
          else {
            if (DAT_002f44d0 == 1) {
              if ((int)conf._16_4_ < 0x41) {
                local_40 = local_2c & 0x3f;
                uVar14 = local_40;
LAB_0002aaf6:
                if (uVar14 == 0) {
                  uVar5 = 0;
                  goto LAB_0002aa8c;
                }
              }
              else {
                if (0x3f < conf._16_4_ - 0x41) {
                  printf("%s: conf.core = %d, but it is error\n","receive_func");
                  uVar3 = *(uint *)(last_nonce + iVar9);
                  uVar14 = uVar13;
                  goto LAB_0002aaf6;
                }
                local_40 = local_2c & 0x7f;
                uVar14 = local_40;
                if ((local_40 < 0x39) || (uVar14 = uVar13, 0x3f < local_40 - 0x40))
                goto LAB_0002aaf6;
                uVar14 = local_40 - 7 & 0xff;
              }
              uVar5 = 0;
              uVar7 = 0;
              uVar13 = conf._120_4_;
              uVar6 = conf._116_4_;
              uVar10 = conf._112_4_;
              uVar15 = conf._108_4_;
              do {
                while (uVar7 < 0x20) {
                  if ((uVar15 & 1) == 0) {
                    uVar15 = uVar15 >> 1;
                  }
                  else {
                    uVar15 = uVar15 >> 1;
                    uVar5 = uVar5 + 1 & 0xff;
                  }
LAB_0002ab32:
                  uVar7 = uVar7 + 1;
                  if (uVar7 == uVar14) goto LAB_0002aa8c;
                }
                if (0x1f < uVar7 - 0x20) {
                  if (uVar7 - 0x40 < 0x20) {
                    if ((uVar6 & 1) != 0) {
                      uVar5 = uVar5 + 1 & 0xff;
                    }
                    uVar6 = uVar6 >> 1;
                  }
                  else {
                    if ((uVar13 & 1) != 0) {
                      uVar5 = uVar5 + 1 & 0xff;
                    }
                    uVar13 = uVar13 >> 1;
                  }
                  goto LAB_0002ab32;
                }
                uVar7 = uVar7 + 1;
                if ((uVar10 & 1) != 0) {
                  uVar5 = uVar5 + 1 & 0xff;
                }
                uVar10 = uVar10 >> 1;
              } while (uVar7 != uVar14);
            }
            else {
              uVar5 = local_2c / 0x3000000;
              uVar14 = uVar5;
              if (0x53 < uVar5) goto LAB_0002aa24;
            }
LAB_0002aa8c:
            uVar6 = *(uint *)(work_id + iVar9);
            *(uint *)(llast_nonce + iVar9) = uVar3;
            *(uint *)(last_nonce + iVar9) = local_2c;
            uVar13 = uVar14;
            if (uVar6 < 5000) {
              uVar3 = *(uint *)(uVar6 * 0x34 + (&DAT_00082eac)[uVar5] + 4);
              *(uint *)(m_nonce + iVar9) = uVar3;
              if (uVar3 == local_2c) {
                iVar12 = uVar11 * 0x100;
                iVar16 = (iVar12 + uVar14) * 4;
                if (uVar6 == *(uint *)(repeated_nonce_id + iVar16)) {
                  *(int *)(repeated_nonce_num + iVar9) = *(int *)(repeated_nonce_num + iVar9) + 1;
                }
                else {
                  *(uint *)(repeated_nonce_id + iVar16) = uVar6;
                  iVar1 = DAT_002f44d0;
                  iVar8 = *(int *)(valid_nonce_num + iVar9);
                  *(int *)(asic_nonce_num + iVar16) = *(int *)(asic_nonce_num + iVar16) + 1;
                  *(int *)(valid_nonce_num + iVar9) = iVar8 + 1;
                  total_valid_nonce_num = total_valid_nonce_num + 1;
                  if (iVar1 != 1) {
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
                    iVar9 = (local_40 + (iVar12 + uVar14) * 0x100) * 4;
                    *(int *)(asic_core_nonce_num + iVar9) =
                         *(int *)(asic_core_nonce_num + iVar9) + 1;
                  }
                }
              }
              else {
                *(int *)(err_nonce_num + iVar9) = *(int *)(err_nonce_num + iVar9) + 1;
              }
            }
          }
        }
      }
      else {
        insert_reg_data(&local_30);
      }
LAB_0002aa24:
      uVar4 = uVar4 + 1;
    } while ((uVar2 & 0x1ff) != uVar4);
  } while( true );
}

