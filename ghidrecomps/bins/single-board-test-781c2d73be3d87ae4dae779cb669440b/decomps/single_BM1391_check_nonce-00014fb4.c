
/* WARNING: Unknown calling convention */

int single_BM1391_check_nonce(uchar which_chain,uint *buf)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint OpenCoreNum3;
  uint uVar5;
  uint OpenCoreNum2;
  uint uVar6;
  uint OpenCoreNum4;
  uint OpenCoreNum8;
  int iVar7;
  uint uVar8;
  uint OpenCoreNum1;
  uint uVar9;
  work *work;
  int iVar10;
  uint nonce;
  uint uVar11;
  uint OpenCoreNum6;
  pthread_mutex_t *__mutex;
  uint OpenCoreNum7;
  uint uVar12;
  uint OpenCoreNum5;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  
  uVar9 = Conf.OpenCoreNum1;
  uVar3 = (uint)which_chain;
  nonce = buf[1];
  uVar11 = *buf;
  iVar4 = __udivsi3(nonce >> 0x18,gChain_Asic_Interval);
  uVar15 = (uVar11 << 1) >> 0x11;
  if (iVar4 == 0) {
    if (uVar15 < Conf.pattern_number) {
      uVar11 = nonce & 0xff;
      if (uVar11 < 0x20) {
        iVar4 = 0;
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (uVar11 + 1 != iVar7);
      }
      else if (uVar11 - 0x20 < 0x20) {
        iVar7 = 0x20;
        iVar4 = 0;
        do {
          uVar5 = uVar9 & 1;
          uVar9 = uVar9 >> 1;
          if (uVar5 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 0;
        uVar9 = Conf.OpenCoreNum2;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (iVar7 != uVar11 - 0x1f);
      }
      else if (uVar11 - 0x40 < 0x20) {
        iVar7 = 0x20;
        iVar4 = 0;
        uVar5 = Conf.OpenCoreNum2;
        do {
          uVar6 = uVar9 & 1;
          uVar9 = uVar9 >> 1;
          if (uVar6 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar6 = uVar5 & 1;
          uVar5 = uVar5 >> 1;
          if (uVar6 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 0;
        uVar9 = Conf.OpenCoreNum3;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (iVar7 != uVar11 - 0x3f);
      }
      else if (uVar11 - 0x60 < 0x20) {
        iVar7 = 0x20;
        iVar4 = 0;
        uVar5 = Conf.OpenCoreNum3;
        uVar6 = Conf.OpenCoreNum2;
        do {
          uVar8 = uVar9 & 1;
          uVar9 = uVar9 >> 1;
          if (uVar8 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar8 = uVar6 & 1;
          uVar6 = uVar6 >> 1;
          if (uVar8 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar8 = uVar5 & 1;
          uVar5 = uVar5 >> 1;
          if (uVar8 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 0;
        uVar9 = Conf.OpenCoreNum4;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (uVar11 - 0x5f != iVar7);
      }
      else if (uVar11 - 0x80 < 0x20) {
        iVar7 = 0x20;
        iVar4 = 0;
        uVar5 = Conf.OpenCoreNum3;
        uVar6 = Conf.OpenCoreNum2;
        uVar8 = Conf.OpenCoreNum4;
        do {
          uVar13 = uVar9 & 1;
          uVar9 = uVar9 >> 1;
          if (uVar13 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar13 = uVar6 & 1;
          uVar6 = uVar6 >> 1;
          if (uVar13 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar13 = uVar5 & 1;
          uVar5 = uVar5 >> 1;
          if (uVar13 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar13 = uVar8 & 1;
          uVar8 = uVar8 >> 1;
          if (uVar13 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 0;
        uVar9 = Conf.OpenCoreNum5;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (uVar11 - 0x7f != iVar7);
      }
      else if (uVar11 - 0xa0 < 0x20) {
        iVar7 = 0x20;
        iVar4 = 0;
        uVar5 = Conf.OpenCoreNum3;
        uVar6 = Conf.OpenCoreNum2;
        uVar8 = Conf.OpenCoreNum4;
        uVar13 = Conf.OpenCoreNum5;
        do {
          uVar12 = uVar9 & 1;
          uVar9 = uVar9 >> 1;
          if (uVar12 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar12 = uVar6 & 1;
          uVar6 = uVar6 >> 1;
          if (uVar12 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar12 = uVar5 & 1;
          uVar5 = uVar5 >> 1;
          if (uVar12 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar12 = uVar8 & 1;
          uVar8 = uVar8 >> 1;
          if (uVar12 != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar12 = uVar13 & 1;
          uVar13 = uVar13 >> 1;
          if (uVar12 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = 0;
        uVar9 = Conf.OpenCoreNum6;
        do {
          iVar7 = iVar7 + 1;
          if ((uVar9 & 1) != 0) {
            iVar4 = iVar4 + 1;
          }
          uVar9 = uVar9 >> 1;
        } while (iVar7 != uVar11 - 0x9f);
      }
      else {
        iVar10 = 0x20;
        iVar4 = 0;
        uVar5 = Conf.OpenCoreNum3;
        uVar6 = Conf.OpenCoreNum2;
        iVar7 = 0;
        uVar8 = Conf.OpenCoreNum4;
        uVar13 = Conf.OpenCoreNum6;
        uVar12 = Conf.OpenCoreNum7;
        uVar14 = Conf.OpenCoreNum5;
        if (uVar11 - 0xc0 < 0x20) {
          do {
            uVar12 = uVar9 & 1;
            uVar9 = uVar9 >> 1;
            iVar4 = iVar7;
            if (uVar12 != 0) {
              iVar4 = iVar7 + 1;
            }
            uVar12 = uVar6 & 1;
            uVar6 = uVar6 >> 1;
            if (uVar12 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar12 = uVar5 & 1;
            uVar5 = uVar5 >> 1;
            if (uVar12 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar12 = uVar8 & 1;
            uVar8 = uVar8 >> 1;
            if (uVar12 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar12 = uVar14 & 1;
            uVar14 = uVar14 >> 1;
            if (uVar12 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar12 = uVar13 & 1;
            uVar13 = uVar13 >> 1;
            if (uVar12 != 0) {
              iVar4 = iVar4 + 1;
            }
            iVar10 = iVar10 + -1;
            iVar7 = iVar4;
          } while (iVar10 != 0);
          iVar7 = 0;
          uVar9 = Conf.OpenCoreNum7;
          do {
            iVar7 = iVar7 + 1;
            if ((uVar9 & 1) != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar9 = uVar9 >> 1;
          } while (uVar11 - 0xbf != iVar7);
        }
        else {
          do {
            uVar1 = uVar9 & 1;
            uVar9 = uVar9 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar6 & 1;
            uVar6 = uVar6 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar5 & 1;
            uVar5 = uVar5 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar8 & 1;
            uVar8 = uVar8 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar14 & 1;
            uVar14 = uVar14 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar13 & 1;
            uVar13 = uVar13 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar1 = uVar12 & 1;
            uVar12 = uVar12 >> 1;
            if (uVar1 != 0) {
              iVar4 = iVar4 + 1;
            }
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          iVar7 = 0;
          uVar9 = Conf.OpenCoreNum8;
          do {
            iVar7 = iVar7 + 1;
            if ((uVar9 & 1) != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar9 = uVar9 >> 1;
          } while (iVar7 != uVar11 - 0xdf);
        }
      }
      iVar4 = *(int *)(cgpu.workdataFilePrefix + iVar4 * 4 + 0x3c) + uVar15 * 0x44;
      if (nonce == *(uint *)(iVar4 + 4)) {
        iVar4 = iVar4 + uVar3 * 4;
        if (*(int *)(iVar4 + 0x34) == 0) {
          *(undefined4 *)(iVar4 + 0x34) = 1;
          uVar9 = gValid_Nonce_Num[uVar3];
          gAsic_Core_Nonce_Num[uVar3][0][uVar11] = gAsic_Core_Nonce_Num[uVar3][0][uVar11] + 1;
          gValid_Nonce_Num[uVar3] = uVar9 + 1;
          return 0;
        }
        *(int *)(iVar4 + 0x34) = *(int *)(iVar4 + 0x34) + 1;
        iVar4 = 0;
        gRepeated_Nonce_Id[uVar3] = gRepeated_Nonce_Id[uVar3] + 1;
      }
      else {
        __mutex = (pthread_mutex_t *)(HW_check_mutex + uVar3);
        pthread_mutex_lock(__mutex);
        if (gWork_Num_For_Hw_Check == '\0') {
          pthread_mutex_unlock(__mutex);
          iVar4 = 0;
        }
        else {
          uVar9 = 0;
          work = gWorks_For_Hw_Check[uVar3];
          do {
            uVar9 = uVar9 + 1;
            iVar4 = check_hw(work,nonce,false);
            if (iVar4 == 0) {
              pthread_mutex_unlock(__mutex);
              return 0;
            }
            work = work + 1;
          } while (uVar9 < gWork_Num_For_Hw_Check);
          pthread_mutex_unlock(__mutex);
          uVar2 = DAT_00015404;
          if (iVar4 == 1) {
            gHw_Nonce_Num[uVar3] = gHw_Nonce_Num[uVar3] + 1;
            printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar2,uVar3,0,uVar11,
                   nonce);
            iVar4 = 0;
          }
          else {
            iVar4 = 0;
          }
        }
      }
    }
    else {
      printf("%s: received work_id = %02d nonce. error!!! data[0] = 0x%08x, received nonce = 0x%08x\n"
             ,DAT_00015404,uVar15,uVar11,nonce);
      iVar4 = -1;
    }
  }
  else {
    printf("%s: received ASIC%02d nonce. error!!! data[0] = 0x%08x, received nonce = 0x%08x\n",
           DAT_00015404,iVar4,uVar11,nonce);
    iVar4 = -1;
  }
  return iVar4;
}

