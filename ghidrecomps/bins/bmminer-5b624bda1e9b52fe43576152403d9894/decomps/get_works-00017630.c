
/* WARNING: Unknown calling convention */

int get_works(void)

{
  FILE **ppFVar1;
  int iVar2;
  FILE *__stream;
  void *__ptr;
  uchar *workData;
  size_t sVar3;
  ulong zipLen;
  void *__ptr_00;
  uchar *zipData;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  testpatten_work *new_work;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uVar17;
  ulong uVar18;
  uint uVar19;
  void *local_88c;
  int local_884;
  int local_880;
  int local_87c;
  int local_878;
  ulong DataLen;
  char strFilePath [64];
  char tmp42 [2048];
  
  memset(strFilePath,0,0x40);
  iVar2 = conf.asicNum;
  iVar5 = DAT_000178d0;
  if (conf.asicNum < 1) {
    local_878 = DAT_0001796c;
    iVar11 = 0;
    iVar13 = *(int *)((int)cgpu.results[0x6b] + DAT_0001796c + 0x3fd8);
    *(int *)((int)cgpu.results[0x6b] + DAT_0001796c + 0x41d8) = iVar13;
  }
  else {
    local_880 = 0;
    local_87c = 0;
    local_878 = DAT_000178d0;
    local_884 = DAT_000178d0;
    do {
      local_87c = local_87c + 1;
      sprintf(strFilePath,DAT_000178d4,DAT_000178d8,local_87c);
      __stream = fopen(strFilePath,DAT_000178dc);
      *(FILE **)(iVar5 + local_880) = __stream;
      if (__stream == (FILE *)0x0) {
        if (((*DAT_00017958 == '\0') && (*DAT_0001795c == '\0')) && (*DAT_00017960 < 3))
        goto LAB_0001787a;
        snprintf(tmp42,0x800,DAT_00017964,strFilePath);
        goto LAB_0001791e;
      }
      DataLen = 240000;
      __ptr = malloc(240000);
      fseek(__stream,0,2);
      sVar3 = ftell(*(FILE **)((int)cgpu.fps + local_880));
      fseek(*(FILE **)((int)cgpu.fps + local_880),0,0);
      __ptr_00 = malloc(sVar3);
      sVar3 = fread(__ptr_00,1,sVar3,*(FILE **)((int)cgpu.fps + local_880));
      uncompress(__ptr,&DataLen,__ptr_00,sVar3);
      free(__ptr_00);
      local_88c = malloc(260000);
      *(void **)(local_884 + 0x29c) = local_88c;
      if (local_88c == (void *)0x0) {
        if (((use_syslog == false) && (*DAT_000178ec == '\0')) && (*DAT_000178f0 < 3)) {
          uVar18 = 0;
        }
        else {
          uVar18 = 0;
          tmp42._0_4_ = *DAT_000178f8;
          tmp42._4_4_ = DAT_000178f8[1];
          tmp42._8_4_ = DAT_000178f8[2];
          tmp42._12_4_ = DAT_000178f8[3];
          tmp42._16_4_ = DAT_000178f8[4];
          tmp42._20_4_ = DAT_000178f8[5];
          tmp42._24_4_ = DAT_000178f8[6];
          tmp42._28_4_ = DAT_000178f8[7];
          tmp42._32_2_ = (undefined2)DAT_000178f8[8];
          tmp42[34] = (char)((uint)DAT_000178f8[8] >> 0x10);
          _applog(3,tmp42,false);
        }
      }
      else {
        uVar18 = DataLen;
        if (DataLen != 0) {
          uVar18 = 0;
          uVar9 = 0x30;
          uVar19 = 0;
          iVar11 = 0;
          while( true ) {
            uVar17 = uVar9;
            puVar12 = (undefined4 *)((int)__ptr + uVar19);
            *(undefined4 *)((int)local_88c + iVar11 + 4) =
                 *(undefined4 *)((int)__ptr + uVar19 + 0x2c);
            puVar16 = (undefined4 *)(uVar19 + 0x20 + (int)__ptr);
            uVar9 = *(uint *)((int)local_88c + iVar11 + 4);
            *(uint *)((int)local_88c + iVar11 + 4) =
                 uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                 uVar9 >> 0x18;
            uVar6 = puVar12[1];
            uVar7 = puVar12[2];
            uVar10 = puVar12[3];
            *(undefined4 *)((int)local_88c + iVar11 + 0x14) = *puVar12;
            *(undefined4 *)((int)local_88c + iVar11 + 0x18) = uVar6;
            *(undefined4 *)((int)local_88c + iVar11 + 0x1c) = uVar7;
            *(undefined4 *)((int)local_88c + iVar11 + 0x20) = uVar10;
            uVar6 = puVar12[4];
            uVar7 = puVar12[5];
            uVar10 = puVar12[6];
            *(undefined4 *)((int)local_88c + iVar11 + 0x30) = puVar12[7];
            *(undefined4 *)((int)local_88c + iVar11 + 0x24) = uVar6;
            *(undefined4 *)((int)local_88c + iVar11 + 0x28) = uVar7;
            *(undefined4 *)((int)local_88c + iVar11 + 0x2c) = uVar10;
            uVar6 = *puVar16;
            uVar7 = puVar16[1];
            uVar10 = puVar16[2];
            *(ulong *)((int)local_88c + iVar11) = uVar18;
            uVar18 = uVar18 + 1;
            *(undefined4 *)((int)local_88c + iVar11 + 8) = uVar6;
            *(undefined4 *)((int)local_88c + iVar11 + 0xc) = uVar7;
            *(undefined4 *)((int)local_88c + iVar11 + 0x10) = uVar10;
            if ((DataLen <= uVar17) || (uVar18 == 5000)) break;
            local_88c = *(void **)(local_884 + 0x29c);
            uVar9 = uVar17 + 0x30;
            uVar19 = uVar17;
            iVar11 = iVar11 + 0x34;
          }
        }
        free(__ptr);
      }
      *(ulong *)((int)cgpu.results[0x6b] + iVar5 + local_880 + 0x3fd8) = uVar18;
      local_884 = local_884 + 4;
      ppFVar1 = (FILE **)(iVar5 + local_880);
      local_880 = local_880 + 4;
      fclose(*ppFVar1);
      piVar4 = DAT_000178e0;
    } while (local_87c != iVar2);
    iVar14 = *(int *)((int)cgpu.results[0x6b] + DAT_000178d0 + 0x3fd8);
    iVar11 = 0;
    iVar8 = 0;
    *(int *)((int)cgpu.results[0x6b] + DAT_000178d0 + 0x41d8) = iVar14;
    iVar13 = iVar14;
    iVar15 = iVar14;
    while( true ) {
      if (iVar14 < iVar13) {
        iVar11 = iVar8;
        iVar15 = iVar14;
      }
      iVar8 = iVar8 + 1;
      if (iVar14 < iVar13) {
        iVar13 = iVar15;
      }
      if (iVar8 == iVar2) break;
      piVar4 = piVar4 + 1;
      iVar14 = *piVar4;
    }
    *(int *)((int)cgpu.results[0x6b] + iVar5 + 0x41d8) = iVar15;
  }
  if ((*DAT_000178e4 != '\0') &&
     (((*DAT_000178e8 != '\0' || (*DAT_000178ec != '\0')) || (6 < *DAT_000178f0)))) {
    snprintf(tmp42,0x800,DAT_000178f4,iVar11,iVar13);
    _applog(7,tmp42,false);
    iVar13 = *(int *)((int)cgpu.results[0x6b] + local_878 + 0x41d8);
  }
  if (iVar13 < conf.dataCount) {
    if (((*DAT_000178e8 != '\0') || (*DAT_000178ec != '\0')) || (2 < *DAT_000178f0)) {
      snprintf(tmp42,0x800,DAT_00017968,conf.dataCount,iVar13);
LAB_0001791e:
      _applog(3,tmp42,false);
    }
LAB_0001787a:
    iVar5 = -1;
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}

