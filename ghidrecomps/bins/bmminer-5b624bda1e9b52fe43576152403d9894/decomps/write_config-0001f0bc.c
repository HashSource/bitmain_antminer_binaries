
/* WARNING: Unknown calling convention */

void write_config(FILE *fcfg)

{
  undefined4 *puVar1;
  int *piVar2;
  char **ppcVar3;
  pool *ppVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *name;
  char *p;
  char *pcVar9;
  char *carg;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  pool *pool;
  void **__ptr;
  JE *jeptr;
  int iVar14;
  void **ppvVar15;
  int iVar16;
  char *local_2c;
  
  piVar2 = DAT_0001f408;
  fwrite(DAT_0001f380,1,0xd,(FILE *)fcfg);
  if (0 < *piVar2) {
    iVar14 = 0;
    do {
      ppVar4 = priority_pool(iVar14);
      iVar16 = ppVar4->quota;
      if (iVar16 == 1) {
        pcVar8 = DAT_0001f390;
        if (iVar14 == 0) {
          pcVar8 = DAT_0001f38c;
        }
        pcVar9 = DAT_0001f4c4;
        pcVar5 = DAT_0001f38c;
        if (ppVar4->rpc_proxy == (char *)0x0) {
LAB_0001f458:
          pcVar6 = DAT_0001f4c4;
        }
        else {
          pcVar9 = proxytype(ppVar4->rpc_proxytype);
          pcVar5 = json_escape(pcVar9);
          pcVar9 = DAT_0001f4c4;
          if ((ppVar4->rpc_proxy == (char *)0x0) ||
             (pcVar9 = json_escape(ppVar4->rpc_proxy), pcVar6 = DAT_0001f394,
             ppVar4->rpc_proxy == (char *)0x0)) goto LAB_0001f458;
        }
        pcVar7 = json_escape(ppVar4->rpc_url);
        fprintf((FILE *)fcfg,DAT_0001f3a0,pcVar8,pcVar5,pcVar9,pcVar6,pcVar7);
      }
      else {
        pcVar8 = DAT_0001f38c;
        if (iVar14 != 0) {
          pcVar8 = DAT_0001f390;
        }
        pcVar9 = DAT_0001f38c;
        pcVar5 = DAT_0001f38c;
        if (ppVar4->rpc_proxy == (char *)0x0) {
LAB_0001f1f8:
          local_2c = DAT_0001f38c;
        }
        else {
          pcVar9 = proxytype(ppVar4->rpc_proxytype);
          pcVar9 = json_escape(pcVar9);
          if (ppVar4->rpc_proxy == (char *)0x0) {
            iVar16 = ppVar4->quota;
            pcVar5 = DAT_0001f38c;
            goto LAB_0001f1f8;
          }
          pcVar5 = json_escape(ppVar4->rpc_proxy);
          iVar16 = ppVar4->quota;
          if (ppVar4->rpc_proxy == (char *)0x0) goto LAB_0001f1f8;
          local_2c = DAT_0001f394;
        }
        pcVar6 = json_escape(ppVar4->rpc_url);
        fprintf((FILE *)fcfg,DAT_0001f398,pcVar8,pcVar9,pcVar5,local_2c,iVar16,pcVar6);
      }
      if (ppVar4->extranonce_subscribe != false) {
        fwrite(DAT_0001f39c,1,0x21,(FILE *)fcfg);
      }
      iVar14 = iVar14 + 1;
      pcVar8 = json_escape(ppVar4->rpc_user);
      fprintf((FILE *)fcfg,DAT_0001f384,pcVar8);
      pcVar8 = json_escape(ppVar4->rpc_pass);
      fprintf((FILE *)fcfg,DAT_0001f388,pcVar8);
    } while (iVar14 < *piVar2);
  }
  puVar1 = DAT_0001f3a4;
  fwrite(DAT_0001f3a8,1,3,(FILE *)fcfg);
  iVar16 = DAT_0001f410;
  ppcVar3 = DAT_0001f40c;
  iVar14 = DAT_0001f3ac;
  iVar12 = puVar1[1];
  ppvVar15 = DAT_0001f400;
  do {
    DAT_0001f400 = ppvVar15;
    if (iVar12 == 0x10) {
      pvVar10 = ppvVar15[0x107];
      if (pvVar10 == (void *)0x4) {
        fwrite(DAT_0001f4bc,1,0x12,(FILE *)fcfg);
        pvVar10 = ppvVar15[0x107];
      }
      if (pvVar10 == (void *)0x3) {
        fwrite(DAT_0001f4c0,1,0x17,(FILE *)fcfg);
        pvVar10 = ppvVar15[0x107];
      }
      if (pvVar10 == (void *)0x1) {
        fwrite(DAT_0001f4b8,1,0x16,(FILE *)fcfg);
        pvVar10 = ppvVar15[0x107];
      }
      if (pvVar10 == (void *)0x2) {
        fprintf((FILE *)fcfg,DAT_0001f4b4,*DAT_0001f4b0);
      }
      fwrite(DAT_0001f404,1,3,(FILE *)fcfg);
      __ptr = (void **)*ppvVar15;
      *ppvVar15 = (void *)0x0;
      while (__ptr != (void **)0x0) {
        ppvVar15 = (void **)__ptr[1];
        free(*__ptr);
        free(__ptr);
        __ptr = ppvVar15;
      }
      return;
    }
    pcVar8 = (char *)__strdup(*puVar1);
    name = strtok(pcVar8,DAT_0001f394);
    iVar12 = DAT_0001f414;
    while (name != (char *)0x0) {
      if ((name[1] == '-') && (puVar1[6] != iVar14)) {
        uVar11 = puVar1[1];
        if (((int)(uVar11 << 0x1f) < 0) &&
           (((iVar13 = puVar1[2], iVar13 == DAT_0001f3b0 || (iVar13 == DAT_0001f3b4)) &&
            ((bool)*(char *)puVar1[5] == (iVar13 == DAT_0001f3b0))))) {
          fprintf((FILE *)fcfg,DAT_0001f4a8,name + 2);
        }
        else if ((int)(uVar11 << 0x1e) < 0) {
          iVar13 = puVar1[3];
          if (((((iVar13 == iVar16) || (iVar13 == iVar12)) ||
               ((iVar13 == DAT_0001f3b8 || ((iVar13 == DAT_0001f3bc || (iVar13 == DAT_0001f3c0))))))
              || (iVar13 == DAT_0001f3c4)) ||
             ((((((iVar13 == DAT_0001f3c8 || (iVar13 == DAT_0001f3cc)) || (iVar13 == DAT_0001f3d0))
                || ((iVar13 == DAT_0001f3d4 || (iVar13 == DAT_0001f3d8)))) ||
               ((iVar13 == DAT_0001f3dc || ((iVar13 == DAT_0001f3e0 || (iVar13 == DAT_0001f3e4))))))
              || ((iVar13 == DAT_0001f3e8 || (iVar13 == DAT_0001f3ec)))))) {
            fprintf((FILE *)fcfg,DAT_0001f3fc,name + 2,*(undefined4 *)puVar1[5]);
          }
          else {
            if ((iVar13 != DAT_0001f3f0) && (iVar13 != DAT_0001f3f4)) goto LAB_0001f2e8;
            fprintf((FILE *)fcfg,DAT_0001f4ac,name + 2,(float *)puVar1[5],
                    (double)*(float *)puVar1[5]);
          }
        }
        else {
LAB_0001f2e8:
          if (((uVar11 & 6) != 0) &&
             (((char **)puVar1[5] != ppcVar3 &&
              (pcVar9 = *(char **)puVar1[5], pcVar9 != (char *)0x0)))) {
            pcVar9 = json_escape(pcVar9);
            fprintf((FILE *)fcfg,DAT_0001f3f8,name + 2,pcVar9);
          }
        }
      }
      name = strtok((char *)0x0,DAT_0001f394);
    }
    free(pcVar8);
    iVar12 = puVar1[8];
    puVar1 = puVar1 + 7;
    ppvVar15 = DAT_0001f400;
  } while( true );
}

