
/* WARNING: Unknown calling convention */

int single_BM1397_check_nonce(uchar which_chain,uint *buf)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint OpenCoreNum2;
  uint OpenCoreNum1;
  uint uVar5;
  uint OpenCoreNum8;
  int iVar6;
  work *pwVar7;
  uint OpenCoreNum3;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  pthread_mutex_t *__mutex;
  uint OpenCoreNum7;
  uint OpenCoreNum6;
  uint OpenCoreNum5;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar3 = (uint)which_chain;
  uVar10 = buf[1];
  uVar13 = *buf;
  uVar12 = (uVar13 << 1) >> 0x11;
  iVar4 = __udivsi3((uVar10 << 10) >> 0x18,gChain_Asic_Interval);
  uVar11 = uVar10 >> 0x1f | ((uVar10 << 1) >> 0x17) << 1;
  if (iVar4 != 0) {
    printf("%s: received ASIC%02d nonce. error!!! data[0] = 0x%08x, received nonce = 0x%08x\n",
           DAT_00028dc8,iVar4,uVar13,uVar10);
    return -1;
  }
  if (0x29f < uVar11) {
    printf("%s: received core%02d nonce. error!!! data[0] = 0x%08x, received nonce = 0x%08x\n",
           DAT_00028dc8,uVar11,uVar13,uVar10);
    return -1;
  }
  if (Conf.pattern_number <= uVar12) {
    printf("%s: received work_id = %02d nonce. error!!! data[0] = 0x%08x, received nonce = 0x%08x\n"
           ,DAT_00028dc8,uVar12,uVar13,uVar10);
    return -1;
  }
  if (uVar11 < 0x20) {
    iVar4 = 0;
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum1;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (iVar6 != uVar11 + 1);
  }
  else if (uVar11 - 0x20 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum1;
    do {
      uVar5 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar5 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum2;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (uVar11 - 0x1f != iVar6);
  }
  else if (uVar11 - 0x40 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    do {
      uVar8 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar8 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar8 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar8 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum3;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (uVar11 - 0x3f != iVar6);
  }
  else if (uVar11 - 0x60 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    uVar8 = Conf.OpenCoreNum3;
    do {
      uVar9 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar9 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar9 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar9 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar9 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      if (uVar9 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum4;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (iVar6 != uVar11 - 0x5f);
  }
  else if (uVar11 - 0x80 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    uVar8 = Conf.OpenCoreNum4;
    uVar9 = Conf.OpenCoreNum3;
    do {
      uVar14 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar14 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar14 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar14 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar14 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      if (uVar14 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar14 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      if (uVar14 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum5;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (iVar6 != uVar11 - 0x7f);
  }
  else if (uVar11 - 0xa0 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    uVar8 = Conf.OpenCoreNum4;
    uVar9 = Conf.OpenCoreNum3;
    uVar14 = Conf.OpenCoreNum5;
    do {
      uVar15 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar15 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar15 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar15 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar15 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      if (uVar15 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar15 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      if (uVar15 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar15 = uVar14 & 1;
      uVar14 = uVar14 >> 1;
      if (uVar15 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum6;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (uVar11 - 0x9f != iVar6);
  }
  else if (uVar11 - 0xc0 < 0x20) {
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    uVar8 = Conf.OpenCoreNum4;
    uVar9 = Conf.OpenCoreNum3;
    uVar14 = Conf.OpenCoreNum6;
    uVar15 = Conf.OpenCoreNum5;
    do {
      uVar16 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar16 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar16 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar16 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar16 = uVar15 & 1;
      uVar15 = uVar15 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar16 = uVar14 & 1;
      uVar14 = uVar14 >> 1;
      if (uVar16 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum7;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (iVar6 != uVar11 - 0xbf);
  }
  else {
    if (0x1f < uVar11 - 0xe0) {
      printf("%s: which_core = %d, error!!!\n",DAT_00028dc8,uVar11);
      iVar4 = -1;
      goto LAB_000289be;
    }
    iVar6 = 0x20;
    iVar4 = 0;
    uVar13 = Conf.OpenCoreNum2;
    uVar5 = Conf.OpenCoreNum1;
    uVar8 = Conf.OpenCoreNum4;
    uVar9 = Conf.OpenCoreNum3;
    uVar14 = Conf.OpenCoreNum7;
    uVar15 = Conf.OpenCoreNum6;
    uVar16 = Conf.OpenCoreNum5;
    do {
      uVar1 = uVar5 & 1;
      uVar5 = uVar5 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar13 & 1;
      uVar13 = uVar13 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar9 & 1;
      uVar9 = uVar9 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar8 & 1;
      uVar8 = uVar8 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar16 & 1;
      uVar16 = uVar16 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar15 & 1;
      uVar15 = uVar15 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar1 = uVar14 & 1;
      uVar14 = uVar14 >> 1;
      if (uVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar6 = 0;
    uVar13 = Conf.OpenCoreNum8;
    do {
      iVar6 = iVar6 + 1;
      if ((uVar13 & 1) != 0) {
        iVar4 = iVar4 + 1;
      }
      uVar13 = uVar13 >> 1;
    } while (iVar6 != uVar11 - 0xdf);
  }
  iVar4 = iVar4 + -1;
LAB_000289be:
  pwVar7 = cgpu.works[iVar4];
  if (uVar10 == pwVar7[uVar12].nonce) {
    uVar10 = pwVar7[uVar12].is_nonce_return_back[uVar3][0];
    if (uVar10 == 0) {
      uVar13 = gValid_Nonce_Num[uVar3];
      pwVar7[uVar12].is_nonce_return_back[uVar3][0] = 1;
      uVar10 = gAsic_Core_Nonce_Num[uVar3][0][uVar11];
      gValid_Nonce_Num[uVar3] = uVar13 + 1;
      gAsic_Core_Nonce_Num[uVar3][0][uVar11] = uVar10 + 1;
      return 0;
    }
    pwVar7[uVar12].is_nonce_return_back[uVar3][0] = uVar10 + 1;
    gRepeated_Nonce_Id[uVar3] = gRepeated_Nonce_Id[uVar3] + 1;
  }
  else {
    __mutex = (pthread_mutex_t *)(HW_check_mutex + uVar3);
    pthread_mutex_lock(__mutex);
    if (gWork_Num_For_Hw_Check == '\0') {
      pthread_mutex_unlock(__mutex);
    }
    else {
      uVar12 = 0;
      pwVar7 = gWorks_For_Hw_Check[uVar3];
      do {
        uVar12 = uVar12 + 1;
        iVar4 = check_hw(pwVar7,uVar10,false);
        if (iVar4 == 0) {
          pthread_mutex_unlock(__mutex);
          return 0;
        }
        pwVar7 = pwVar7 + 1;
      } while (uVar12 < gWork_Num_For_Hw_Check);
      pthread_mutex_unlock(__mutex);
      uVar2 = DAT_00028dc8;
      if (iVar4 == 1) {
        gHw_Nonce_Num[uVar3] = gHw_Nonce_Num[uVar3] + 1;
        printf("%s: Find a HW. Chain%d ASIC%d Core%d : nonce = 0x%08x.\n",uVar2,uVar3,0,uVar11,
               uVar10);
      }
    }
  }
  return 0;
}

