
/* WARNING: Unknown calling convention */

void cg_logwork(work *work,uchar *nonce_bin,_Bool ok)

{
  uchar uVar1;
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *__ptr_02;
  char *__ptr_03;
  char *__ptr_04;
  undefined4 uVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uchar *puVar9;
  ulonglong uVar10;
  uint64_t uVar11;
  undefined4 uVar12;
  uchar midstate_tmp [32];
  uchar data_tmp [32];
  uchar hash_tmp [32];
  char szmsg [1024];
  char tmp42 [2048];
  
  if (opt_logwork_path != (char *)0x0) {
    memset(szmsg,0,0x400);
    data_tmp[0xc] = '\0';
    data_tmp[0xd] = '\0';
    data_tmp[0xe] = '\0';
    data_tmp[0xf] = '\0';
    midstate_tmp._0_4_ = *(undefined4 *)work->midstate;
    midstate_tmp._4_4_ = *(undefined4 *)(work->midstate + 4);
    midstate_tmp._8_4_ = *(undefined4 *)(work->midstate + 8);
    midstate_tmp._12_4_ = *(undefined4 *)(work->midstate + 0xc);
    midstate_tmp._16_4_ = *(undefined4 *)(work->midstate + 0x10);
    midstate_tmp._20_4_ = *(undefined4 *)(work->midstate + 0x14);
    midstate_tmp._24_4_ = *(undefined4 *)(work->midstate + 0x18);
    midstate_tmp._28_4_ = *(undefined4 *)(work->midstate + 0x1c);
    data_tmp[0x10] = '\0';
    data_tmp[0x11] = '\0';
    data_tmp[0x12] = '\0';
    data_tmp[0x13] = '\0';
    data_tmp[0x14] = '\0';
    data_tmp[0x15] = '\0';
    data_tmp[0x16] = '\0';
    data_tmp[0x17] = '\0';
    iVar8 = 0;
    data_tmp[0x18] = '\0';
    data_tmp[0x19] = '\0';
    data_tmp[0x1a] = '\0';
    data_tmp[0x1b] = '\0';
    data_tmp._8_4_ = *(undefined4 *)(work->data + 0x48);
    data_tmp[0x1c] = '\0';
    data_tmp[0x1d] = '\0';
    data_tmp[0x1e] = '\0';
    data_tmp[0x1f] = '\0';
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
    puVar9 = midstate_tmp;
    do {
      uVar1 = midstate_tmp[iVar8];
      midstate_tmp[iVar8] = puVar9[0x1f];
      iVar8 = iVar8 + 1;
      puVar9[0x1f] = uVar1;
      puVar9 = puVar9 + -1;
    } while (iVar8 != 0x10);
    iVar8 = 0;
    puVar9 = data_tmp;
    do {
      uVar1 = data_tmp[iVar8];
      data_tmp[iVar8] = puVar9[0xb];
      iVar8 = iVar8 + 1;
      puVar9[0xb] = uVar1;
      puVar9 = puVar9 + -1;
    } while (iVar8 != 6);
    iVar8 = 0;
    puVar9 = hash_tmp;
    do {
      uVar1 = hash_tmp[iVar8];
      hash_tmp[iVar8] = puVar9[0x1f];
      iVar8 = iVar8 + 1;
      puVar9[0x1f] = uVar1;
      puVar9 = puVar9 + -1;
    } while (iVar8 != 0x10);
    __ptr = bin2hex(work->data,0x80);
    __ptr_00 = bin2hex(midstate_tmp,0x20);
    __ptr_01 = bin2hex(data_tmp,0xc);
    __ptr_02 = bin2hex(nonce_bin,4);
    __ptr_03 = bin2hex(nonce_bin,5);
    __ptr_04 = bin2hex(hash_tmp,0x20);
    uVar10 = share_ndiff(work);
    uVar4 = (undefined4)(uVar10 >> 0x20);
    uVar2 = (undefined4)uVar10;
    pcVar5 = "o";
    if (!ok) {
      pcVar5 = "x";
    }
    uVar11 = uVar10;
    sprintf(szmsg,"%s %08x midstate %s data %s nonce %s hash %s diff %I64d",pcVar5,work->id,__ptr_00
            ,__ptr_01,__ptr_03,__ptr_04,uVar2,uVar4);
    iVar8 = strcmp(opt_logwork_path,"screen");
    if (iVar8 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,szmsg);
        _applog(3,tmp42,false);
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        snprintf(tmp42,0x800,szmsg);
        _applog(3,tmp42,false);
      }
      uVar12 = (undefined4)(uVar11 >> 0x20);
      if (g_logwork_file != (FILE *)0x0) {
        if (ok) {
          sprintf(szmsg,"%s %08x work %s midstate %s data %s nonce %s hash %s diff %I64d",
                  &DAT_00046508,work->id,__ptr,__ptr_00,__ptr_01,__ptr_03,__ptr_04,uVar12,uVar2,
                  uVar4);
          sVar3 = strlen(szmsg);
          fwrite(szmsg,sVar3,1,(FILE *)g_logwork_file);
          fwrite("\n",1,1,(FILE *)g_logwork_file);
          fflush((FILE *)g_logwork_file);
          if (g_logwork_asicnum == 1) {
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            sVar3 = strlen(szmsg);
            fwrite(szmsg,sVar3,1,(FILE *)g_logwork_files[0]);
            fwrite("\n",1,1,(FILE *)g_logwork_files[0]);
            fflush((FILE *)g_logwork_files[0]);
          }
          else if (g_logwork_asicnum == 0x20 || g_logwork_asicnum == 0x40) {
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            iVar8 = check_asicnum(g_logwork_asicnum,*nonce_bin);
            sVar3 = strlen(szmsg);
            fwrite(szmsg,sVar3,1,(FILE *)g_logwork_files[iVar8]);
            fwrite("\n",1,1,(FILE *)g_logwork_files[iVar8]);
            fflush((FILE *)g_logwork_files[iVar8]);
          }
          if (opt_logwork_diff != false) {
            iVar8 = 0;
            do {
              uVar7 = (uint)(uVar10 >> 0x21);
              uVar6 = (uint)((uVar10 & 0x100000000) != 0) << 0x1f | (uint)uVar10 >> 1;
              uVar10 = CONCAT44(uVar7,uVar6);
              if (uVar6 == 0 && uVar7 == 0) break;
              iVar8 = iVar8 + 1;
            } while (iVar8 != 0x40);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"work diff %I64d diffnum %d",uVar2,uVar2,uVar4,iVar8);
              _applog(7,tmp42,false);
            }
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            sVar3 = strlen(szmsg);
            fwrite(szmsg,sVar3,1,(FILE *)g_logwork_diffs[iVar8]);
            fwrite("\n",1,1,(FILE *)g_logwork_diffs[iVar8]);
            fflush((FILE *)g_logwork_diffs[iVar8]);
          }
        }
        else {
          sprintf(szmsg,"%s %08x work %s midstate %s data %s nonce %s hash %s diff %I64d","x",
                  work->id,__ptr,__ptr_00,__ptr_01,__ptr_03,__ptr_04,uVar12,uVar2,uVar4);
          sVar3 = strlen(szmsg);
          fwrite(szmsg,sVar3,1,(FILE *)g_logwork_file);
          fwrite("\n",1,1,(FILE *)g_logwork_file);
          fflush((FILE *)g_logwork_file);
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

