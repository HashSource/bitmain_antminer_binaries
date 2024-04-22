
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 get_works(void)

{
  bool bVar1;
  FILE *pFVar2;
  void *__ptr;
  size_t sVar3;
  void *__ptr_00;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  FILE **ppFVar13;
  undefined4 uVar14;
  int iVar15;
  int local_888;
  int *local_884;
  uint local_86c;
  char acStack_868 [64];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined2 uStack_808;
  undefined local_806;
  
  local_884 = DAT_0002c318;
  memset(acStack_868,0,0x40);
  local_888 = 0;
  ppFVar13 = (FILE **)&cgpu;
  do {
    local_888 = local_888 + 1;
    sprintf(acStack_868,"%s%02i.bin",DAT_0002c31c);
    pFVar2 = fopen(acStack_868,"rb");
    *ppFVar13 = pFVar2;
    if (pFVar2 == (FILE *)0x0) {
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        return 0xffffffff;
      }
      snprintf((char *)&local_828,0x800,"Open test file %s error\n",acStack_868);
      goto LAB_0002c2fc;
    }
    local_86c = 240000;
    __ptr = malloc(240000);
    fseek(pFVar2,0,2);
    sVar3 = ftell(*ppFVar13);
    fseek(*ppFVar13,0,0);
    __ptr_00 = malloc(sVar3);
    sVar3 = fread(__ptr_00,1,sVar3,*ppFVar13);
    uncompress(__ptr,&local_86c,__ptr_00,sVar3);
    free(__ptr_00);
    pFVar2 = (FILE *)malloc(260000);
    ppFVar13[0xa7] = pFVar2;
    if (pFVar2 == (FILE *)0x0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (iVar11 = 0, 2 < opt_log_level)) {
        iVar11 = 0;
        local_828._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[0];
        local_828._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[1];
        local_828._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[2];
        local_828._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[3];
        uStack_824._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[4];
        uStack_824._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[5];
        uStack_824._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[6];
        uStack_824._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[7];
        uStack_820._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[8];
        uStack_820._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[9];
        uStack_820._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[10];
        uStack_820._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[11];
        uStack_81c._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[12];
        uStack_81c._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[13];
        uStack_81c._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[14];
        uStack_81c._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[15];
        local_818._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[16];
        local_818._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[17];
        local_818._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[18];
        local_818._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[19];
        uStack_814._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[20];
        uStack_814._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[21];
        uStack_814._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[22];
        uStack_814._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[23];
        uStack_810._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[24];
        uStack_810._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[25];
        uStack_810._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[26];
        uStack_810._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[27];
        uStack_80c._0_1_ = s_malloc_struct_testpatten_work_er_00060c68[28];
        uStack_80c._1_1_ = s_malloc_struct_testpatten_work_er_00060c68[29];
        uStack_80c._2_1_ = s_malloc_struct_testpatten_work_er_00060c68[30];
        uStack_80c._3_1_ = s_malloc_struct_testpatten_work_er_00060c68[31];
        uStack_808 = (undefined2)ram0x00060c88;
        local_806 = (undefined)((uint)ram0x00060c88 >> 0x10);
        _applog(3,&local_828,0);
      }
    }
    else {
      if (local_86c == 0) {
        iVar11 = 0;
      }
      else {
        iVar15 = 0;
        iVar11 = 0;
        puVar7 = (undefined4 *)((int)__ptr + 0x2c);
        while( true ) {
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x43) = *puVar7;
          uVar8 = *(uint *)(pFVar2->_shortbuf + iVar15 + -0x43);
          *(uint *)(pFVar2->_shortbuf + iVar15 + -0x43) =
               uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
               uVar8 >> 0x18;
          uVar14 = puVar7[-10];
          uVar12 = puVar7[-9];
          uVar9 = puVar7[-8];
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x33) = puVar7[-0xb];
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x2f) = uVar14;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x2b) = uVar12;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x27) = uVar9;
          uVar9 = puVar7[-4];
          uVar12 = puVar7[-7];
          uVar14 = puVar7[-6];
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x1b) = puVar7[-5];
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x23) = uVar12;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x1f) = uVar14;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x17) = uVar9;
          uVar12 = puVar7[-2];
          uVar9 = puVar7[-1];
          uVar8 = (4 - (int)__ptr) + (int)puVar7;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x3f) = puVar7[-3];
          puVar7 = puVar7 + 0xc;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x3b) = uVar12;
          *(undefined4 *)(pFVar2->_shortbuf + iVar15 + -0x37) = uVar9;
          *(int *)(pFVar2->_shortbuf + iVar15 + -0x47) = iVar11;
          iVar11 = iVar11 + 1;
          iVar15 = iVar15 + 0x34;
          if ((local_86c <= uVar8) || (iVar11 == 5000)) break;
          pFVar2 = ppFVar13[0xa7];
        }
      }
      free(__ptr);
    }
    pFVar2 = *ppFVar13;
    local_884 = local_884 + 1;
    *local_884 = iVar11;
    fclose(pFVar2);
    ppFVar13 = ppFVar13 + 1;
  } while (local_888 != 0x54);
  bVar1 = false;
  iVar6 = 0;
  DAT_002f44ac = DAT_002f42ac;
  piVar4 = DAT_0002c320;
  iVar11 = 0;
  iVar15 = DAT_002f42ac;
  iVar10 = DAT_002f42ac;
  while (iVar6 = iVar6 + 1, iVar6 != 0x54) {
    piVar4 = piVar4 + 1;
    iVar5 = *piVar4;
    if (iVar5 < iVar15) {
      bVar1 = true;
      iVar11 = iVar6;
      iVar15 = iVar5;
      iVar10 = iVar5;
    }
  }
  if (bVar1) {
    DAT_002f44ac = iVar10;
  }
  if (opt_debug == '\0') {
LAB_0002c224:
    if ((int)conf._0_4_ <= iVar15) {
      return 0;
    }
    if ((use_syslog != '\0') || (opt_log_output != '\0')) goto LAB_0002c25a;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
      snprintf((char *)&local_828,0x800,"min work minertest[%d]:%d\n\n\n",iVar11,iVar15);
      _applog(7,&local_828,0);
      iVar15 = DAT_002f44ac;
      goto LAB_0002c224;
    }
    if ((int)conf._0_4_ <= iVar15) {
      return 0;
    }
  }
  if (opt_log_level < 3) {
    return 0xffffffff;
  }
LAB_0002c25a:
  snprintf((char *)&local_828,0x800,"$$$$dataCount=%d, but min work subid=%d\n",conf._0_4_,iVar15);
LAB_0002c2fc:
  _applog(3,&local_828,0);
  return 0xffffffff;
}

