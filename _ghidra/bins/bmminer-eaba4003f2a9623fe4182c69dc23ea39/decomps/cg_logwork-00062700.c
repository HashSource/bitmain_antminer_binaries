
void cg_logwork(work *work,uchar *nonce_bin,_Bool ok)

{
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *__ptr_02;
  char *__ptr_03;
  char *__ptr_04;
  int iVar1;
  size_t sVar2;
  undefined *puVar3;
  uint64_t uVar4;
  uint uVar5;
  _Bool ok_local;
  uchar *nonce_bin_local;
  work *work_local;
  uchar midstate_tmp [32];
  uchar data_tmp [32];
  uchar hash_tmp [32];
  char szmsg [1024];
  char tmp42 [2048];
  uint64_t worksharediff;
  int asicnum;
  char *szhash;
  char *sznonce5;
  char *sznonce4;
  char *szdata;
  char *szmidstate;
  char *szworkdata;
  uint64_t difftmp;
  int diffnum;
  
  if (opt_logwork_path != (char *)0x0) {
    memset(szmsg,0,0x400);
    data_tmp[0] = '\0';
    data_tmp[1] = '\0';
    data_tmp[2] = '\0';
    data_tmp[3] = '\0';
    data_tmp[4] = '\0';
    data_tmp[5] = '\0';
    data_tmp[6] = '\0';
    data_tmp[7] = '\0';
    data_tmp[8] = '\0';
    data_tmp[9] = '\0';
    data_tmp[10] = '\0';
    data_tmp[0xb] = '\0';
    data_tmp[0xc] = '\0';
    data_tmp[0xd] = '\0';
    data_tmp[0xe] = '\0';
    data_tmp[0xf] = '\0';
    data_tmp[0x10] = '\0';
    data_tmp[0x11] = '\0';
    data_tmp[0x12] = '\0';
    data_tmp[0x13] = '\0';
    data_tmp[0x14] = '\0';
    data_tmp[0x15] = '\0';
    data_tmp[0x16] = '\0';
    data_tmp[0x17] = '\0';
    data_tmp[0x18] = '\0';
    data_tmp[0x19] = '\0';
    data_tmp[0x1a] = '\0';
    data_tmp[0x1b] = '\0';
    data_tmp[0x1c] = '\0';
    data_tmp[0x1d] = '\0';
    data_tmp[0x1e] = '\0';
    data_tmp[0x1f] = '\0';
    hash_tmp[0] = '\0';
    hash_tmp[1] = '\0';
    hash_tmp[2] = '\0';
    hash_tmp[3] = '\0';
    hash_tmp[4] = '\0';
    hash_tmp[5] = '\0';
    hash_tmp[6] = '\0';
    hash_tmp[7] = '\0';
    hash_tmp[8] = '\0';
    hash_tmp[9] = '\0';
    hash_tmp[10] = '\0';
    hash_tmp[0xb] = '\0';
    hash_tmp[0xc] = '\0';
    hash_tmp[0xd] = '\0';
    hash_tmp[0xe] = '\0';
    hash_tmp[0xf] = '\0';
    hash_tmp[0x10] = '\0';
    hash_tmp[0x11] = '\0';
    hash_tmp[0x12] = '\0';
    hash_tmp[0x13] = '\0';
    hash_tmp[0x14] = '\0';
    hash_tmp[0x15] = '\0';
    hash_tmp[0x16] = '\0';
    hash_tmp[0x17] = '\0';
    hash_tmp[0x18] = '\0';
    hash_tmp[0x19] = '\0';
    hash_tmp[0x1a] = '\0';
    hash_tmp[0x1b] = '\0';
    hash_tmp[0x1c] = '\0';
    hash_tmp[0x1d] = '\0';
    hash_tmp[0x1e] = '\0';
    hash_tmp[0x1f] = '\0';
    midstate_tmp._0_4_ = *(undefined4 *)work->midstate;
    midstate_tmp._4_4_ = *(undefined4 *)(work->midstate + 4);
    midstate_tmp._8_4_ = *(undefined4 *)(work->midstate + 8);
    midstate_tmp._12_4_ = *(undefined4 *)(work->midstate + 0xc);
    midstate_tmp._16_4_ = *(undefined4 *)(work->midstate + 0x10);
    midstate_tmp._20_4_ = *(undefined4 *)(work->midstate + 0x14);
    midstate_tmp._24_4_ = *(undefined4 *)(work->midstate + 0x18);
    midstate_tmp._28_4_ = *(undefined4 *)(work->midstate + 0x1c);
    memcpy(data_tmp,work->data + 0x40,0xc);
    hash_tmp._0_4_ = *(undefined4 *)work->hash;
    hash_tmp._4_4_ = *(undefined4 *)(work->hash + 4);
    hash_tmp._8_4_ = *(undefined4 *)(work->hash + 8);
    hash_tmp._12_4_ = *(undefined4 *)(work->hash + 0xc);
    hash_tmp._16_4_ = *(undefined4 *)(work->hash + 0x10);
    hash_tmp._20_4_ = *(undefined4 *)(work->hash + 0x14);
    hash_tmp._24_4_ = *(undefined4 *)(work->hash + 0x18);
    hash_tmp._28_4_ = *(undefined4 *)(work->hash + 0x1c);
    rev(midstate_tmp,0x20);
    rev(data_tmp,0xc);
    rev(hash_tmp,0x20);
    __ptr = bin2hex(work->data,0x80);
    __ptr_00 = bin2hex(midstate_tmp,0x20);
    __ptr_01 = bin2hex(data_tmp,0xc);
    __ptr_02 = bin2hex(nonce_bin,4);
    __ptr_03 = bin2hex(nonce_bin,5);
    __ptr_04 = bin2hex(hash_tmp,0x20);
    uVar4 = share_ndiff(work);
    if (ok) {
      puVar3 = &DAT_0007c27c;
    }
    else {
      puVar3 = &UNK_0007c280;
    }
    worksharediff._0_4_ = (uint)uVar4;
    worksharediff._4_4_ = (uint)(uVar4 >> 0x20);
    uVar5 = worksharediff._4_4_;
    sprintf(szmsg,"%s %08x midstate %s data %s nonce %s hash %s diff %I64d",puVar3,work->id,__ptr_00
            ,__ptr_01,__ptr_03,__ptr_04,(uint)worksharediff,worksharediff._4_4_);
    iVar1 = strcmp(opt_logwork_path,"screen");
    if (iVar1 == 0) {
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
      if (g_logwork_file != (FILE *)0x0) {
        if (ok) {
          puVar3 = &DAT_0007c27c;
        }
        else {
          puVar3 = &UNK_0007c280;
        }
        sprintf(szmsg,"%s %08x work %s midstate %s data %s nonce %s hash %s diff %I64d",puVar3,
                work->id,__ptr,__ptr_00,__ptr_01,__ptr_03,__ptr_04,uVar5,(uint)worksharediff,
                worksharediff._4_4_);
        sVar2 = strlen(szmsg);
        fwrite(szmsg,sVar2,1,(FILE *)g_logwork_file);
        fwrite(&DAT_0007b128,1,1,(FILE *)g_logwork_file);
        fflush((FILE *)g_logwork_file);
        if (ok) {
          if (g_logwork_asicnum == 1) {
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            sVar2 = strlen(szmsg);
            fwrite(szmsg,sVar2,1,(FILE *)g_logwork_files[0]);
            fwrite(&DAT_0007b128,1,1,(FILE *)g_logwork_files[0]);
            fflush((FILE *)g_logwork_files[0]);
          }
          else if ((g_logwork_asicnum == 0x20) || (g_logwork_asicnum == 0x40)) {
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            iVar1 = check_asicnum(g_logwork_asicnum,*nonce_bin);
            sVar2 = strlen(szmsg);
            fwrite(szmsg,sVar2,1,(FILE *)g_logwork_files[iVar1]);
            fwrite(&DAT_0007b128,1,1,(FILE *)g_logwork_files[iVar1]);
            fflush((FILE *)g_logwork_files[iVar1]);
          }
          if (opt_logwork_diff != false) {
            diffnum = 0;
            difftmp._0_4_ = (uint)worksharediff;
            difftmp._4_4_ = worksharediff._4_4_;
            do {
              uVar5 = difftmp._4_4_ & 1;
              difftmp._4_4_ = difftmp._4_4_ >> 1;
              difftmp._0_4_ = (uint)(uVar5 != 0) << 0x1f | (uint)difftmp >> 1;
              if ((uint)difftmp == 0 && difftmp._4_4_ == 0) break;
              diffnum = diffnum + 1;
            } while (diffnum < 0x40);
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"work diff %I64d diffnum %d",diffnum,(uint)worksharediff,
                       worksharediff._4_4_,diffnum);
              _applog(7,tmp42,false);
            }
            sprintf(szmsg,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,__ptr_04
                   );
            sVar2 = strlen(szmsg);
            fwrite(szmsg,sVar2,1,(FILE *)g_logwork_diffs[diffnum]);
            fwrite(&DAT_0007b128,1,1,(FILE *)g_logwork_diffs[diffnum]);
            fflush((FILE *)g_logwork_diffs[diffnum]);
          }
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

