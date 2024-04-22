
/* WARNING: Unknown calling convention */

void cg_logwork(work *work,uchar *nonce_bin,_Bool ok)

{
  uchar uVar1;
  FILE **ppFVar2;
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *__ptr_02;
  char *__ptr_03;
  char *__ptr_04;
  undefined4 uVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  size_t i_1;
  size_t i_2;
  uint uVar8;
  int iVar9;
  size_t i;
  uchar *puVar10;
  int diffnum;
  ulonglong uVar11;
  uint64_t uVar12;
  uchar midstate_tmp [32];
  uchar data_tmp [32];
  uchar hash_tmp [32];
  char szmsg [1024];
  char tmp42 [2048];
  
  if (opt_logwork_path != (char *)0x0) {
    memset(szmsg,0,0x400);
    data_tmp[12] = '\0';
    data_tmp[13] = '\0';
    data_tmp[14] = '\0';
    data_tmp[15] = '\0';
    midstate_tmp._0_4_ = *(undefined4 *)work->midstate;
    midstate_tmp._4_4_ = *(undefined4 *)(work->midstate + 4);
    midstate_tmp._8_4_ = *(undefined4 *)(work->midstate + 8);
    midstate_tmp._12_4_ = *(undefined4 *)(work->midstate + 0xc);
    midstate_tmp._16_4_ = *(undefined4 *)(work->midstate + 0x10);
    midstate_tmp._20_4_ = *(undefined4 *)(work->midstate + 0x14);
    midstate_tmp._24_4_ = *(undefined4 *)(work->midstate + 0x18);
    midstate_tmp._28_4_ = *(undefined4 *)(work->midstate + 0x1c);
    data_tmp[16] = '\0';
    data_tmp[17] = '\0';
    data_tmp[18] = '\0';
    data_tmp[19] = '\0';
    data_tmp[20] = '\0';
    data_tmp[21] = '\0';
    data_tmp[22] = '\0';
    data_tmp[23] = '\0';
    iVar9 = 0;
    data_tmp[24] = '\0';
    data_tmp[25] = '\0';
    data_tmp[26] = '\0';
    data_tmp[27] = '\0';
    data_tmp._8_4_ = *(undefined4 *)(work->data + 0x48);
    data_tmp[28] = '\0';
    data_tmp[29] = '\0';
    data_tmp[30] = '\0';
    data_tmp[31] = '\0';
    data_tmp._0_4_ = *(undefined4 *)(work->data + 0x40);
    data_tmp._4_4_ = *(undefined4 *)(work->data + 0x44);
    hash_tmp._0_4_ = *(undefined4 *)work->hash;
    hash_tmp._4_4_ = *(undefined4 *)(work->hash + 4);
    hash_tmp._8_4_ = *(undefined4 *)(work->hash + 8);
    hash_tmp._12_4_ = *(undefined4 *)(work->hash + 0xc);
    hash_tmp._16_4_ = *(undefined4 *)(work->hash + 0x10);
    hash_tmp._20_4_ = *(undefined4 *)(work->hash + 0x14);
    hash_tmp._24_4_ = *(undefined4 *)(work->hash + 0x18);
    hash_tmp._28_4_ = *(undefined4 *)(work->hash + 0x1c);
    puVar10 = midstate_tmp;
    do {
      uVar1 = midstate_tmp[iVar9];
      midstate_tmp[iVar9] = puVar10[0x1f];
      iVar9 = iVar9 + 1;
      puVar10[0x1f] = uVar1;
      puVar10 = puVar10 + -1;
    } while (iVar9 != 0x10);
    iVar9 = 0;
    puVar10 = data_tmp;
    do {
      uVar1 = data_tmp[iVar9];
      data_tmp[iVar9] = puVar10[0xb];
      iVar9 = iVar9 + 1;
      puVar10[0xb] = uVar1;
      puVar10 = puVar10 + -1;
    } while (iVar9 != 6);
    iVar9 = 0;
    puVar10 = hash_tmp;
    do {
      uVar1 = hash_tmp[iVar9];
      hash_tmp[iVar9] = puVar10[0x1f];
      iVar9 = iVar9 + 1;
      puVar10[0x1f] = uVar1;
      puVar10 = puVar10 + -1;
    } while (iVar9 != 0x10);
    __ptr = bin2hex(work->data,0x80);
    __ptr_00 = bin2hex(midstate_tmp,0x20);
    __ptr_01 = bin2hex(data_tmp,0xc);
    __ptr_02 = bin2hex(nonce_bin,4);
    __ptr_03 = bin2hex(nonce_bin,5);
    __ptr_04 = bin2hex(hash_tmp,0x20);
    uVar11 = share_ndiff(work);
    uVar5 = (undefined4)(uVar11 >> 0x20);
    uVar3 = (undefined4)uVar11;
    uVar6 = DAT_00015774;
    if (!ok) {
      uVar6 = DAT_000157a4;
    }
    uVar12 = uVar11;
    sprintf(szmsg,DAT_00015778,uVar6,work->id,__ptr_00,__ptr_01,__ptr_03,__ptr_04,uVar3,uVar5);
    iVar9 = strcmp(opt_logwork_path,DAT_0001577c);
    if (iVar9 == 0) {
      if (((*DAT_00015780 != '\0') || (*DAT_00015784 != '\0')) || (2 < *DAT_00015798)) {
        snprintf(tmp42,0x800,szmsg);
        _applog(3,tmp42,false);
      }
    }
    else {
      if (((use_syslog != false) || (*DAT_00015784 != '\0')) || (2 < *DAT_00015798)) {
        snprintf(tmp42,0x800,szmsg);
        _applog(3,tmp42,false);
      }
      ppFVar2 = DAT_000157a8;
      uVar6 = (undefined4)(uVar12 >> 0x20);
      if (*DAT_000157a8 != (FILE *)0x0) {
        if (ok) {
          sprintf(szmsg,DAT_00015788,DAT_00015774,work->id,__ptr,__ptr_00,__ptr_01,__ptr_03,__ptr_04
                  ,uVar6,uVar3,uVar5);
          sVar4 = strlen(szmsg);
          fwrite(szmsg,sVar4,1,*ppFVar2);
          fwrite(DAT_0001578c,1,1,*ppFVar2);
          fflush(*ppFVar2);
          if (g_logwork_asicnum == 1) {
            sprintf(szmsg,DAT_00015854,__ptr_00,__ptr_01,__ptr_02,__ptr_04);
            ppFVar2 = DAT_0001585c;
            sVar4 = strlen(szmsg);
            fwrite(szmsg,sVar4,1,*ppFVar2);
            fwrite(DAT_00015858,1,1,*ppFVar2);
            fflush(*ppFVar2);
          }
          else if (g_logwork_asicnum == 0x20 || g_logwork_asicnum == 0x40) {
            sprintf(szmsg,DAT_00015854,__ptr_00,__ptr_01,__ptr_02,__ptr_04);
            ppFVar2 = DAT_0001585c;
            iVar9 = check_asicnum(g_logwork_asicnum,*nonce_bin);
            sVar4 = strlen(szmsg);
            fwrite(szmsg,sVar4,1,ppFVar2[iVar9]);
            fwrite(DAT_00015858,1,1,ppFVar2[iVar9]);
            fflush(ppFVar2[iVar9]);
          }
          if (*DAT_00015790 != '\0') {
            diffnum = 0;
            do {
              uVar8 = (uint)(uVar11 >> 0x21);
              uVar7 = (uint)((uVar11 & 0x100000000) != 0) << 0x1f | (uint)uVar11 >> 1;
              uVar11 = CONCAT44(uVar8,uVar7);
              if ((uVar7 | uVar8) == 0) break;
              diffnum = diffnum + 1;
            } while (diffnum != 0x40);
            if ((*DAT_00015794 != '\0') &&
               (((use_syslog != false || (*DAT_00015784 != '\0')) || (6 < *DAT_00015798)))) {
              snprintf(tmp42,0x800,DAT_0001579c,uVar3,uVar3,uVar5,diffnum);
              _applog(7,tmp42,false);
            }
            iVar9 = DAT_000157ac;
            sprintf(szmsg,DAT_000157a0,__ptr_00,__ptr_01,__ptr_02,__ptr_04);
            sVar4 = strlen(szmsg);
            fwrite(szmsg,sVar4,1,*(FILE **)(iVar9 + diffnum * 4));
            fwrite(DAT_0001578c,1,1,*(FILE **)(iVar9 + diffnum * 4));
            fflush(*(FILE **)(iVar9 + diffnum * 4));
          }
        }
        else {
          sprintf(szmsg,DAT_00015788,DAT_000157a4,work->id,__ptr,__ptr_00,__ptr_01,__ptr_03,__ptr_04
                  ,uVar6,uVar3,uVar5);
          sVar4 = strlen(szmsg);
          fwrite(szmsg,sVar4,1,*ppFVar2);
          fwrite(DAT_0001578c,1,1,*ppFVar2);
          fflush(*ppFVar2);
        }
      }
    }
    if (__ptr != (char *)0x0) {
      free(__ptr);
    }
    if (__ptr_00 != (char *)0x0) {
      free(__ptr_00);
    }
    if (__ptr_01 != (char *)0x0) {
      free(__ptr_01);
    }
    if (__ptr_02 != (char *)0x0) {
      free(__ptr_02);
    }
    if (__ptr_03 != (char *)0x0) {
      free(__ptr_03);
    }
    if (__ptr_04 != (char *)0x0) {
      free(__ptr_04);
    }
  }
  return;
}

