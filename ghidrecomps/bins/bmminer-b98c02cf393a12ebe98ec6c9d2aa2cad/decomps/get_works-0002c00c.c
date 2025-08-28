
undefined4 get_works(void)

{
  bool bVar1;
  FILE *pFVar2;
  void *__ptr;
  size_t sVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  int iVar16;
  int local_888;
  int *local_884;
  uint local_86c;
  char acStack_868 [64];
  char local_828 [32];
  undefined2 uStack_808;
  undefined1 local_806;
  
  local_884 = (int *)&DAT_002f42a8;
  memset(acStack_868,0,0x40);
  local_888 = 0;
  puVar14 = &cgpu;
  do {
    local_888 = local_888 + 1;
    sprintf(acStack_868,"%s%02i.bin",&DAT_00082e6c);
    pFVar2 = fopen(acStack_868,"rb");
    *puVar14 = pFVar2;
    if (pFVar2 == (FILE *)0x0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return 0xffffffff;
      }
      snprintf(local_828,0x800,"Open test file %s error\n",acStack_868);
      goto LAB_0002c2fc;
    }
    local_86c = 240000;
    __ptr = malloc(240000);
    fseek(pFVar2,0,2);
    sVar3 = ftell((FILE *)*puVar14);
    fseek((FILE *)*puVar14,0,0);
    pvVar4 = malloc(sVar3);
    sVar3 = fread(pvVar4,1,sVar3,(FILE *)*puVar14);
    uncompress(__ptr,&local_86c,pvVar4,sVar3);
    free(pvVar4);
    pvVar4 = malloc(260000);
    puVar14[0xa7] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (iVar12 = 0, 2 < opt_log_level)) {
        iVar12 = 0;
        builtin_strncpy(local_828,"malloc struct testpatten_work er",0x20);
        uStack_808 = 0xa72;
        local_806 = 0;
        _applog(3,local_828,0);
      }
    }
    else {
      if (local_86c == 0) {
        iVar12 = 0;
      }
      else {
        iVar16 = 0;
        iVar12 = 0;
        puVar8 = (undefined4 *)((int)__ptr + 0x2c);
        while( true ) {
          *(undefined4 *)((int)pvVar4 + iVar16 + 4) = *puVar8;
          uVar9 = *(uint *)((int)pvVar4 + iVar16 + 4);
          *(uint *)((int)pvVar4 + iVar16 + 4) =
               uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
               uVar9 >> 0x18;
          uVar15 = puVar8[-10];
          uVar13 = puVar8[-9];
          uVar10 = puVar8[-8];
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x14) = puVar8[-0xb];
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x18) = uVar15;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x1c) = uVar13;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x20) = uVar10;
          uVar10 = puVar8[-4];
          uVar13 = puVar8[-7];
          uVar15 = puVar8[-6];
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x2c) = puVar8[-5];
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x24) = uVar13;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x28) = uVar15;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x30) = uVar10;
          uVar13 = puVar8[-2];
          uVar10 = puVar8[-1];
          uVar9 = (4 - (int)__ptr) + (int)puVar8;
          *(undefined4 *)((int)pvVar4 + iVar16 + 8) = puVar8[-3];
          puVar8 = puVar8 + 0xc;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0xc) = uVar13;
          *(undefined4 *)((int)pvVar4 + iVar16 + 0x10) = uVar10;
          *(int *)((int)pvVar4 + iVar16) = iVar12;
          iVar12 = iVar12 + 1;
          iVar16 = iVar16 + 0x34;
          if ((local_86c <= uVar9) || (iVar12 == 5000)) break;
          pvVar4 = (void *)puVar14[0xa7];
        }
      }
      free(__ptr);
    }
    pFVar2 = (FILE *)*puVar14;
    local_884 = local_884 + 1;
    *local_884 = iVar12;
    fclose(pFVar2);
    puVar14 = puVar14 + 1;
  } while (local_888 != 0x54);
  bVar1 = false;
  iVar7 = 0;
  piVar5 = &DAT_002f42ac;
  DAT_002f44ac = DAT_002f42ac;
  iVar12 = 0;
  iVar16 = DAT_002f42ac;
  iVar11 = DAT_002f42ac;
  while (iVar7 = iVar7 + 1, iVar7 != 0x54) {
    piVar5 = piVar5 + 1;
    iVar6 = *piVar5;
    if (iVar6 < iVar16) {
      bVar1 = true;
      iVar12 = iVar7;
      iVar16 = iVar6;
      iVar11 = iVar6;
    }
  }
  if (bVar1) {
    DAT_002f44ac = iVar11;
  }
  if (opt_debug == '\0') {
LAB_0002c224:
    if ((int)conf._0_4_ <= iVar16) {
      return 0;
    }
    if ((use_syslog != '\0') || (opt_log_output != '\0')) goto LAB_0002c25a;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
      snprintf(local_828,0x800,"min work minertest[%d]:%d\n\n\n",iVar12,iVar16);
      _applog(7,local_828,0);
      iVar16 = DAT_002f44ac;
      goto LAB_0002c224;
    }
    if ((int)conf._0_4_ <= iVar16) {
      return 0;
    }
  }
  if (opt_log_level < 3) {
    return 0xffffffff;
  }
LAB_0002c25a:
  snprintf(local_828,0x800,"$$$$dataCount=%d, but min work subid=%d\n",conf._0_4_,iVar16);
LAB_0002c2fc:
  _applog(3,local_828,0);
  return 0xffffffff;
}

