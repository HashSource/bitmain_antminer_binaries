
void cg_logwork(int param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  void *__ptr;
  void *__ptr_00;
  void *__ptr_01;
  void *__ptr_02;
  void *__ptr_03;
  void *__ptr_04;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined4 local_c88;
  undefined4 uStack_c84;
  undefined4 uStack_c80;
  undefined4 uStack_c7c;
  undefined4 local_c78;
  undefined4 uStack_c74;
  undefined4 uStack_c70;
  undefined4 uStack_c6c;
  undefined4 local_c68;
  undefined auStack_c64 [4];
  undefined4 uStack_c60;
  undefined4 local_c48;
  undefined4 uStack_c44;
  undefined4 uStack_c40;
  undefined4 uStack_c3c;
  undefined4 local_c38;
  undefined4 uStack_c34;
  undefined4 uStack_c30;
  undefined4 uStack_c2c;
  char acStack_c28 [1024];
  char acStack_828 [2052];
  
  if (opt_logwork_path != (char *)0x0) {
    memset(acStack_c28,0,0x400);
    memset(&local_c68,0,0x20);
    local_c88 = *(undefined4 *)(param_1 + 0x80);
    uStack_c84 = *(undefined4 *)(param_1 + 0x84);
    uStack_c80 = *(undefined4 *)(param_1 + 0x88);
    uStack_c7c = *(undefined4 *)(param_1 + 0x8c);
    local_c78 = *(undefined4 *)(param_1 + 0x90);
    uStack_c74 = *(undefined4 *)(param_1 + 0x94);
    uStack_c70 = *(undefined4 *)(param_1 + 0x98);
    uStack_c6c = *(undefined4 *)(param_1 + 0x9c);
    uStack_c60 = *(undefined4 *)(param_1 + 0x48);
    local_c68 = *(undefined4 *)(param_1 + 0x40);
    auStack_c64 = (undefined  [4])*(undefined4 *)(param_1 + 0x44);
    local_c48 = *(undefined4 *)(param_1 + 0xc0);
    uStack_c44 = *(undefined4 *)(param_1 + 0xc4);
    uStack_c40 = *(undefined4 *)(param_1 + 200);
    uStack_c3c = *(undefined4 *)(param_1 + 0xcc);
    local_c38 = *(undefined4 *)(param_1 + 0xd0);
    uStack_c34 = *(undefined4 *)(param_1 + 0xd4);
    uStack_c30 = *(undefined4 *)(param_1 + 0xd8);
    uStack_c2c = *(undefined4 *)(param_1 + 0xdc);
    puVar8 = &local_c88;
    puVar6 = (undefined *)((int)&uStack_c6c + 3);
    do {
      uVar1 = *(undefined *)puVar8;
      puVar10 = (undefined4 *)((int)puVar8 + 1);
      *(undefined *)puVar8 = *puVar6;
      *puVar6 = uVar1;
      puVar8 = puVar10;
      puVar6 = puVar6 + -1;
    } while (&local_c78 != puVar10);
    puVar6 = (undefined *)((int)&uStack_c60 + 3);
    puVar8 = &local_c68;
    do {
      uVar1 = *(undefined *)puVar8;
      puVar10 = (undefined4 *)((int)puVar8 + 1);
      *(undefined *)puVar8 = *puVar6;
      *puVar6 = uVar1;
      puVar6 = puVar6 + -1;
      puVar8 = puVar10;
    } while ((undefined4 *)(auStack_c64 + 2) != puVar10);
    puVar6 = (undefined *)((int)&uStack_c2c + 3);
    puVar8 = &local_c48;
    do {
      uVar1 = *(undefined *)puVar8;
      puVar10 = (undefined4 *)((int)puVar8 + 1);
      *(undefined *)puVar8 = *puVar6;
      *puVar6 = uVar1;
      puVar6 = puVar6 + -1;
      puVar8 = puVar10;
    } while (&local_c38 != puVar10);
    __ptr = (void *)bin2hex(param_1,0x80);
    __ptr_00 = (void *)bin2hex(&local_c88,0x20);
    __ptr_01 = (void *)bin2hex(&local_c68,0xc);
    __ptr_02 = (void *)bin2hex(param_2,4);
    __ptr_03 = (void *)bin2hex(param_2,5);
    __ptr_04 = (void *)bin2hex(&local_c48,0x20);
    uVar11 = share_ndiff(param_1);
    uVar5 = (undefined4)(uVar11 >> 0x20);
    uVar2 = (undefined4)uVar11;
    puVar6 = &DAT_000659cc;
    if (param_3 != 0) {
      puVar6 = &DAT_0006829c;
    }
    uVar12 = uVar5;
    sprintf(acStack_c28,"%s %08x midstate %s data %s nonce %s hash %s diff %I64d",puVar6,
            *(undefined4 *)(param_1 + 0x154),__ptr_00,__ptr_01,__ptr_03,__ptr_04,uVar2,uVar5);
    iVar3 = strcmp(opt_logwork_path,"screen");
    if (iVar3 == 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_828,0x800,acStack_c28);
        _applog(3,acStack_828,0);
      }
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_828,0x800,acStack_c28);
        _applog(3,acStack_828,0);
      }
      if (g_logwork_file != (FILE *)0x0) {
        if (param_3 == 0) {
          sprintf(acStack_c28,"%s %08x work %s midstate %s data %s nonce %s hash %s diff %I64d",
                  &DAT_000659cc,*(undefined4 *)(param_1 + 0x154),__ptr,__ptr_00,__ptr_01,__ptr_03,
                  __ptr_04,uVar12,uVar2,uVar5);
          sVar4 = strlen(acStack_c28);
          fwrite(acStack_c28,sVar4,1,g_logwork_file);
          fwrite(&DAT_00065a34,1,1,g_logwork_file);
          fflush(g_logwork_file);
        }
        else {
          sprintf(acStack_c28,"%s %08x work %s midstate %s data %s nonce %s hash %s diff %I64d",
                  &DAT_0006829c,*(undefined4 *)(param_1 + 0x154),__ptr,__ptr_00,__ptr_01,__ptr_03,
                  __ptr_04,uVar12,uVar2,uVar5);
          sVar4 = strlen(acStack_c28);
          fwrite(acStack_c28,sVar4,1,g_logwork_file);
          fwrite(&DAT_00065a34,1,1,g_logwork_file);
          fflush(g_logwork_file);
          if (g_logwork_asicnum == 1) {
            sprintf(acStack_c28,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,
                    __ptr_04);
            sVar4 = strlen(acStack_c28);
            fwrite(acStack_c28,sVar4,1,(FILE *)g_logwork_files._0_4_);
            fwrite(&DAT_00065a34,1,1,(FILE *)g_logwork_files._0_4_);
            fflush((FILE *)g_logwork_files._0_4_);
          }
          else if ((g_logwork_asicnum - 0x20U & 0xffffffdf) == 0) {
            sprintf(acStack_c28,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,
                    __ptr_04);
            iVar3 = check_asicnum(g_logwork_asicnum,*param_2);
            sVar4 = strlen(acStack_c28);
            fwrite(acStack_c28,sVar4,1,*(FILE **)(g_logwork_files + iVar3 * 4));
            fwrite(&DAT_00065a34,1,1,*(FILE **)(g_logwork_files + iVar3 * 4));
            fflush(*(FILE **)(g_logwork_files + iVar3 * 4));
          }
          if (opt_logwork_diff != '\0') {
            iVar3 = 0;
            do {
              uVar9 = (uint)(uVar11 >> 0x21);
              uVar7 = (uint)((uVar11 & 0x100000000) != 0) << 0x1f | (uint)uVar11 >> 1;
              uVar11 = CONCAT44(uVar9,uVar7);
              if ((uVar7 | uVar9) == 0) break;
              iVar3 = iVar3 + 1;
            } while (iVar3 != 0x40);
            if ((opt_debug != '\0') &&
               (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
              snprintf(acStack_828,0x800,"work diff %I64d diffnum %d",uVar5,uVar2,uVar5,iVar3);
              _applog(7,acStack_828,0);
            }
            sprintf(acStack_c28,"midstate %s data %s nonce %s hash %s",__ptr_00,__ptr_01,__ptr_02,
                    __ptr_04);
            sVar4 = strlen(acStack_c28);
            fwrite(acStack_c28,sVar4,1,*(FILE **)(g_logwork_diffs + iVar3 * 4));
            fwrite(&DAT_00065a34,1,1,*(FILE **)(g_logwork_diffs + iVar3 * 4));
            fflush(*(FILE **)(g_logwork_diffs + iVar3 * 4));
          }
        }
      }
    }
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
    if (__ptr_00 != (void *)0x0) {
      free(__ptr_00);
    }
    if (__ptr_01 != (void *)0x0) {
      free(__ptr_01);
    }
    if (__ptr_02 != (void *)0x0) {
      free(__ptr_02);
    }
    if (__ptr_03 != (void *)0x0) {
      free(__ptr_03);
    }
    if (__ptr_04 != (void *)0x0) {
      free(__ptr_04);
    }
  }
  return;
}

