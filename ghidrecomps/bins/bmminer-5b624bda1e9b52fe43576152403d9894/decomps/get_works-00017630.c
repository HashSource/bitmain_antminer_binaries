
/* WARNING: Unknown calling convention */

int get_works(void)

{
  FILE *__stream;
  void *__ptr;
  size_t sVar1;
  void *__ptr_00;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  testpatten_work *local_88c;
  testpatten_cgpu_info *local_884;
  int local_880;
  int local_87c;
  uint local_86c;
  char strFilePath [64];
  char tmp42 [2048];
  
  memset(strFilePath,0,0x40);
  iVar3 = conf.asicNum;
  if (conf.asicNum < 1) {
    iVar10 = 0;
    cgpu.min_work_subid = cgpu.subid[0];
    iVar12 = cgpu.subid[0];
  }
  else {
    local_880 = 0;
    local_87c = 0;
    local_884 = &cgpu;
    do {
      local_87c = local_87c + 1;
      sprintf(strFilePath,"%s%02i.bin",0x62d24,local_87c);
      __stream = fopen(strFilePath,"rb");
      *(FILE **)((int)cgpu.fps + local_880) = __stream;
      if (__stream == (FILE *)0x0) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
        goto LAB_0001787a;
        snprintf(tmp42,0x800,"Open test file %s error\n",strFilePath);
        goto LAB_0001791e;
      }
      local_86c = 240000;
      __ptr = malloc(240000);
      fseek(__stream,0,2);
      sVar1 = ftell(*(FILE **)((int)cgpu.fps + local_880));
      fseek(*(FILE **)((int)cgpu.fps + local_880),0,0);
      __ptr_00 = malloc(sVar1);
      sVar1 = fread(__ptr_00,1,sVar1,*(FILE **)((int)cgpu.fps + local_880));
      uncompress(__ptr,&local_86c,__ptr_00,sVar1);
      free(__ptr_00);
      local_88c = (testpatten_work *)malloc(260000);
      local_884->works[0] = local_88c;
      if (local_88c == (testpatten_work *)0x0) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          builtin_strncpy(tmp42,"malloc struct testpatten_work er",0x20);
          tmp42[0x20] = 'r';
          tmp42[0x21] = '\n';
          tmp42[0x22] = '\0';
          _applog(3,tmp42,false);
        }
      }
      else {
        uVar15 = local_86c;
        if (local_86c != 0) {
          uVar15 = 0;
          uVar8 = 0x30;
          uVar16 = 0;
          iVar10 = 0;
          while( true ) {
            uVar14 = uVar8;
            puVar11 = (undefined4 *)((int)__ptr + uVar16);
            *(undefined4 *)(local_88c->data + iVar10 + -4) =
                 *(undefined4 *)((int)__ptr + uVar16 + 0x2c);
            puVar13 = (undefined4 *)(uVar16 + 0x20 + (int)__ptr);
            uVar8 = *(uint *)(local_88c->data + iVar10 + -4);
            *(uint *)(local_88c->data + iVar10 + -4) =
                 uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
                 uVar8 >> 0x18;
            uVar4 = puVar11[1];
            uVar6 = puVar11[2];
            uVar9 = puVar11[3];
            *(undefined4 *)(local_88c->midstate + iVar10) = *puVar11;
            *(undefined4 *)(local_88c->midstate + iVar10 + 4) = uVar4;
            *(undefined4 *)(local_88c->midstate + iVar10 + 8) = uVar6;
            *(undefined4 *)(local_88c->midstate + iVar10 + 0xc) = uVar9;
            uVar4 = puVar11[4];
            uVar6 = puVar11[5];
            uVar9 = puVar11[6];
            *(undefined4 *)(local_88c->midstate + iVar10 + 0x1c) = puVar11[7];
            *(undefined4 *)(local_88c->midstate + iVar10 + 0x10) = uVar4;
            *(undefined4 *)(local_88c->midstate + iVar10 + 0x14) = uVar6;
            *(undefined4 *)(local_88c->midstate + iVar10 + 0x18) = uVar9;
            uVar4 = *puVar13;
            uVar6 = puVar13[1];
            uVar9 = puVar13[2];
            *(uint *)(local_88c->data + iVar10 + -8) = uVar15;
            uVar15 = uVar15 + 1;
            *(undefined4 *)(local_88c->data + iVar10) = uVar4;
            *(undefined4 *)(local_88c->data + iVar10 + 4) = uVar6;
            *(undefined4 *)(local_88c->data + iVar10 + 8) = uVar9;
            if ((local_86c <= uVar14) || (uVar15 == 5000)) break;
            local_88c = local_884->works[0];
            uVar8 = uVar14 + 0x30;
            uVar16 = uVar14;
            iVar10 = iVar10 + 0x34;
          }
        }
        free(__ptr);
      }
      *(uint *)((int)cgpu.subid + local_880) = uVar15;
      local_884 = (testpatten_cgpu_info *)(local_884->fps + 1);
      puVar11 = (undefined4 *)((int)cgpu.fps + local_880);
      local_880 = local_880 + 4;
      fclose((FILE *)*puVar11);
    } while (local_87c != iVar3);
    iVar10 = 0;
    iVar7 = 0;
    piVar2 = cgpu.subid;
    iVar5 = cgpu.subid[0];
    iVar12 = cgpu.subid[0];
    cgpu.min_work_subid = cgpu.subid[0];
    while( true ) {
      if (iVar5 < iVar12) {
        iVar10 = iVar7;
        cgpu.min_work_subid = iVar5;
      }
      iVar7 = iVar7 + 1;
      if (iVar5 < iVar12) {
        iVar12 = cgpu.min_work_subid;
      }
      if (iVar7 == iVar3) break;
      piVar2 = piVar2 + 1;
      iVar5 = *piVar2;
    }
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"min work minertest[%d]:%d\n\n\n",iVar10,iVar12);
    _applog(7,tmp42,false);
    iVar12 = cgpu.min_work_subid;
  }
  if (iVar12 < conf.dataCount) {
    if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
      snprintf(tmp42,0x800,"$$$$dataCount=%d, but min work subid=%d\n",conf.dataCount,iVar12);
LAB_0001791e:
      _applog(3,tmp42,false);
    }
LAB_0001787a:
    iVar3 = -1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

