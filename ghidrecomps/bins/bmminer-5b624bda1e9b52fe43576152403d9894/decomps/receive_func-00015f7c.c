
/* WARNING: Unknown calling convention */

void * receive_func(void *arg)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int chainIndex;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint local_44;
  uint buf [2];
  
  uVar16 = 0;
  buf[0] = 0;
  buf[1] = 0;
  local_44 = 0;
  memset(DAT_00016200,0xff,0x4000);
  memset(DAT_00016204,0,0x40);
  memset(DAT_00016208,0,0x40);
  piVar4 = DAT_0001621c;
  iVar3 = DAT_00016214;
  memset(DAT_0001620c,0,0x40);
  pvVar2 = DAT_00016210;
  memset(DAT_00016210,0,0x40);
  do {
    while( true ) {
      cVar1 = *(char *)(iVar3 + 0x304);
      while( true ) {
        if (cVar1 != '\0') {
          *(undefined *)(DAT_00016214 + 0x305) = 1;
          return (void *)0x0;
        }
        uVar11 = (uint)*(byte *)((int)pvVar2 + 0x40);
        if (uVar11 != 0) break;
        buf[0] = uVar11;
        buf[1] = uVar11;
        memset(DAT_00016200,0xff,0x4000);
        memset(DAT_00016204,0,0x40);
        memset(DAT_00016208,0,0x40);
        memset(DAT_0001620c,0,0x40);
        memset(DAT_00016210,0,0x40);
        usleep(100000);
        cVar1 = *(char *)(iVar3 + 0x304);
        uVar16 = 0;
        local_44 = 0;
      }
      uVar6 = get_nonce_number_in_fifo();
      uVar11 = 0;
      if ((uVar6 & 0x1ff) != 0) break;
      usleep(1000);
    }
    do {
      get_return_nonce(buf);
      if ((int)buf[0] < 0) {
        if ((*(char *)((int)pvVar2 + 0x41) != '\0') && ((int)(buf[0] << 0x18) < 0)) {
          uVar7 = buf[0] & 0xf;
          if (*piVar4 == 0) {
            iVar15 = (int)pvVar2 + uVar7 * 4 + -0xca8;
            uVar8 = *(uint *)(iVar15 + 0xbe8);
            *(uint *)((int)pvVar2 + uVar7 * 4 + -0x40) = (buf[0] << 1) >> 0x11;
          }
          else {
            iVar15 = (int)pvVar2 + uVar7 * 4 + -0xca8;
            uVar8 = *(uint *)(iVar15 + 0xbe8);
            *(uint *)((int)pvVar2 + uVar7 * 4 + -0x40) = (buf[0] << 1) >> 0x11;
          }
          if ((buf[1] == uVar8) || (iVar10 = uVar7 * 4, buf[1] == *(uint *)(iVar15 + 0xc28))) {
            *(int *)((int)pvVar2 + uVar7 * 4 + 0x44) = *(int *)((int)pvVar2 + uVar7 * 4 + 0x44) + 1;
          }
          else {
            if (*DAT_00016218 == 1) {
              if (*(int *)((int)pvVar2 + 0x94) < 0x41) {
                local_44 = buf[1] & 0x3f;
                uVar17 = local_44;
              }
              else if (*(int *)((int)pvVar2 + 0x94) - 0x41U < 0x40) {
                local_44 = buf[1] & 0x7f;
                uVar17 = local_44;
                if ((0x38 < local_44) && (uVar17 = uVar16, local_44 - 0x40 < 0x40)) {
                  uVar17 = local_44 - 7 & 0xff;
                }
              }
              else {
                printf(DAT_00016314,DAT_00016310);
                uVar8 = *(uint *)(iVar15 + 0xbe8);
                uVar17 = uVar16;
              }
              uVar16 = *(uint *)((int)pvVar2 + 0xf8);
              uVar9 = *(uint *)((int)pvVar2 + 0xf0);
              uVar18 = *(uint *)((int)pvVar2 + 0xf4);
              uVar13 = *(uint *)((int)pvVar2 + 0xfc);
              if (uVar17 == 0) {
                uVar12 = 0;
              }
              else {
                uVar12 = 0;
                uVar14 = 0;
                do {
                  while (uVar14 < 0x20) {
                    if ((int)(uVar9 << 0x1f) < 0) {
                      uVar9 = uVar9 >> 1;
                      uVar12 = uVar12 + 1 & 0xff;
                    }
                    else {
                      uVar9 = uVar9 >> 1;
                    }
LAB_00016182:
                    uVar14 = uVar14 + 1;
                    if (uVar17 <= uVar14) goto LAB_000160ba;
                  }
                  if (0x1f < uVar14 - 0x20) {
                    if (uVar14 - 0x40 < 0x20) {
                      if ((int)(uVar16 << 0x1f) < 0) {
                        uVar12 = uVar12 + 1 & 0xff;
                      }
                      uVar16 = uVar16 >> 1;
                    }
                    else {
                      if ((int)(uVar13 << 0x1f) < 0) {
                        uVar12 = uVar12 + 1 & 0xff;
                      }
                      uVar13 = uVar13 >> 1;
                    }
                    goto LAB_00016182;
                  }
                  uVar14 = uVar14 + 1;
                  if ((uVar18 & 1) != 0) {
                    uVar12 = uVar12 + 1 & 0xff;
                  }
                  uVar18 = uVar18 >> 1;
                } while (uVar14 < uVar17);
              }
            }
            else {
              uVar12 = buf[1] >> 0x1a;
              uVar17 = uVar12;
              if (0x11 < uVar12) goto LAB_00016056;
            }
LAB_000160ba:
            uVar9 = *(uint *)((int)pvVar2 + iVar10 + -0x40);
            *(uint *)((int)pvVar2 + iVar10 + -0x80) = uVar8;
            *(uint *)((int)pvVar2 + iVar10 + -0xc0) = buf[1];
            uVar16 = uVar17;
            if (uVar9 < 5000) {
              uVar8 = cgpu.works[uVar12][uVar9].nonce;
              *(uint *)((int)pvVar2 + iVar10) = uVar8;
              if (buf[1] == uVar8) {
                iVar15 = uVar7 * 0x400 + uVar17 * 4;
                if (uVar9 == repeated_nonce_id[uVar7][uVar17]) {
                  *(int *)(iVar10 + iVar3 + 0x284) = *(int *)(iVar10 + iVar3 + 0x284) + 1;
                }
                else {
                  repeated_nonce_id[uVar7][uVar17] = uVar9;
                  piVar5 = DAT_0001630c;
                  iVar10 = valid_nonce_num[uVar7];
                  *(int *)((int)pvVar2 + iVar15 + 0x148) =
                       *(int *)((int)pvVar2 + iVar15 + 0x148) + 1;
                  iVar15 = *piVar5;
                  valid_nonce_num[uVar7] = iVar10 + 1;
                  total_valid_nonce_num = total_valid_nonce_num + 1;
                  if (iVar15 != 1) {
                    if (*(int *)((int)pvVar2 + 0x94) < 0x41) {
                      local_44 = buf[1] & 0x3f;
                    }
                    else if (*(int *)((int)pvVar2 + 0x94) - 0x41U < 0x40) {
                      local_44 = buf[1] & 0x7f;
                      if ((0x38 < local_44) && (local_44 - 0x40 < 0x40)) {
                        local_44 = local_44 - 7 & 0xff;
                      }
                    }
                    else {
                      printf(DAT_00016314,DAT_00016310);
                    }
                    asic_core_nonce_num[uVar7][uVar17][local_44] =
                         asic_core_nonce_num[uVar7][uVar17][local_44] + 1;
                  }
                }
              }
              else {
                *(int *)(iVar10 + iVar3 + 0x2c4) = *(int *)(iVar10 + iVar3 + 0x2c4) + 1;
              }
            }
          }
        }
      }
      else {
        insert_reg_data(buf);
      }
LAB_00016056:
      uVar11 = uVar11 + 1;
    } while ((uVar6 & 0x1ff) != uVar11);
  } while( true );
}

