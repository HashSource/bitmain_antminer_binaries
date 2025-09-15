
/* WARNING: Unknown calling convention */

void * receive_func(void *arg)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_44;
  uint buf [2];
  
  uVar10 = 0;
  buf[0] = 0;
  buf[1] = 0;
  local_44 = 0;
  memset(repeated_nonce_id,0xff,0x4000);
  memset(last_nonce,0,0x40);
  memset(llast_nonce,0,0x40);
  memset(work_id,0,0x40);
  memset(m_nonce,0,0x40);
  do {
    while( true ) {
      while( true ) {
        if (ExitFlag != false) {
          receiveExit = true;
          return (void *)0x0;
        }
        uVar6 = (uint)start_receive;
        if (uVar6 != 0) break;
        buf[0] = uVar6;
        buf[1] = uVar6;
        memset(repeated_nonce_id,0xff,0x4000);
        memset(last_nonce,0,0x40);
        memset(llast_nonce,0,0x40);
        memset(work_id,0,0x40);
        memset(m_nonce,0,0x40);
        usleep(100000);
        uVar10 = 0;
        local_44 = 0;
      }
      uVar1 = get_nonce_number_in_fifo();
      uVar6 = 0;
      if ((uVar1 & 0x1ff) != 0) break;
      usleep(1000);
    }
    do {
      get_return_nonce(buf);
      if ((int)buf[0] < 0) {
        if ((gBegin_get_nonce != false) && ((int)(buf[0] << 0x18) < 0)) {
          uVar2 = buf[0] & 0xf;
          if (cgpu.CommandMode == 0) {
            uVar3 = last_nonce[uVar2];
            work_id[uVar2] = (buf[0] << 1) >> 0x11;
          }
          else {
            uVar3 = last_nonce[uVar2];
            work_id[uVar2] = (buf[0] << 1) >> 0x11;
          }
          if ((buf[1] == uVar3) || (buf[1] == llast_nonce[uVar2])) {
            last_nonce_num[uVar2] = last_nonce_num[uVar2] + 1;
          }
          else {
            if (cgpu.real_asic_num == 1) {
              if (conf.core < 0x41) {
                local_44 = buf[1] & 0x3f;
                uVar11 = local_44;
              }
              else if (conf.core - 0x41U < 0x40) {
                local_44 = buf[1] & 0x7f;
                uVar11 = local_44;
                if ((0x38 < local_44) && (uVar11 = uVar10, local_44 - 0x40 < 0x40)) {
                  uVar11 = local_44 - 7 & 0xff;
                }
              }
              else {
                printf("%s: conf.core = %d, but it is error\n","receive_func");
                uVar3 = last_nonce[uVar2];
                uVar11 = uVar10;
              }
              if (uVar11 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = 0;
                uVar8 = 0;
                uVar10 = conf.OpenCoreNum3;
                uVar4 = conf.OpenCoreNum1;
                uVar9 = conf.OpenCoreNum4;
                uVar12 = conf.OpenCoreNum2;
                do {
                  while (uVar8 < 0x20) {
                    if ((int)(uVar4 << 0x1f) < 0) {
                      uVar4 = uVar4 >> 1;
                      uVar7 = uVar7 + 1 & 0xff;
                    }
                    else {
                      uVar4 = uVar4 >> 1;
                    }
LAB_00016182:
                    uVar8 = uVar8 + 1;
                    if (uVar11 <= uVar8) goto LAB_000160ba;
                  }
                  if (0x1f < uVar8 - 0x20) {
                    if (uVar8 - 0x40 < 0x20) {
                      if ((int)(uVar10 << 0x1f) < 0) {
                        uVar7 = uVar7 + 1 & 0xff;
                      }
                      uVar10 = uVar10 >> 1;
                    }
                    else {
                      if ((int)(uVar9 << 0x1f) < 0) {
                        uVar7 = uVar7 + 1 & 0xff;
                      }
                      uVar9 = uVar9 >> 1;
                    }
                    goto LAB_00016182;
                  }
                  uVar8 = uVar8 + 1;
                  if ((uVar12 & 1) != 0) {
                    uVar7 = uVar7 + 1 & 0xff;
                  }
                  uVar12 = uVar12 >> 1;
                } while (uVar8 < uVar11);
              }
            }
            else {
              uVar7 = buf[1] >> 0x1a;
              uVar11 = uVar7;
              if (0x11 < uVar7) goto LAB_00016056;
            }
LAB_000160ba:
            uVar4 = work_id[uVar2];
            llast_nonce[uVar2] = uVar3;
            last_nonce[uVar2] = buf[1];
            uVar10 = uVar11;
            if (uVar4 < 5000) {
              uVar3 = cgpu.works[uVar7][uVar4].nonce;
              m_nonce[uVar2] = uVar3;
              if (buf[1] == uVar3) {
                if (uVar4 == repeated_nonce_id[uVar2][uVar11]) {
                  repeated_nonce_num[uVar2] = repeated_nonce_num[uVar2] + 1;
                }
                else {
                  repeated_nonce_id[uVar2][uVar11] = uVar4;
                  iVar5 = valid_nonce_num[uVar2];
                  asic_nonce_num[uVar2][uVar11] = asic_nonce_num[uVar2][uVar11] + 1;
                  uVar3 = cgpu.real_asic_num;
                  valid_nonce_num[uVar2] = iVar5 + 1;
                  total_valid_nonce_num = total_valid_nonce_num + 1;
                  if (uVar3 != 1) {
                    if (conf.core < 0x41) {
                      local_44 = buf[1] & 0x3f;
                    }
                    else if (conf.core - 0x41U < 0x40) {
                      local_44 = buf[1] & 0x7f;
                      if ((0x38 < local_44) && (local_44 - 0x40 < 0x40)) {
                        local_44 = local_44 - 7 & 0xff;
                      }
                    }
                    else {
                      printf("%s: conf.core = %d, but it is error\n","receive_func");
                    }
                    asic_core_nonce_num[uVar2][uVar11][local_44] =
                         asic_core_nonce_num[uVar2][uVar11][local_44] + 1;
                  }
                }
              }
              else {
                err_nonce_num[uVar2] = err_nonce_num[uVar2] + 1;
              }
            }
          }
        }
      }
      else {
        insert_reg_data(buf);
      }
LAB_00016056:
      uVar6 = uVar6 + 1;
    } while ((uVar1 & 0x1ff) != uVar6);
  } while( true );
}

