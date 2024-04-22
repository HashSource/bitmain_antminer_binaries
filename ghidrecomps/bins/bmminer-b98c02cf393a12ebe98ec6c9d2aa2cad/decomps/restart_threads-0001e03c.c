
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint restart_threads(void)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  size_t sVar6;
  long lVar7;
  void *__s;
  int iVar8;
  FILE *pFVar9;
  uint unaff_r6;
  byte *pbVar10;
  byte **ppbVar11;
  byte *apbStack_c4c [2];
  int iStack_c44;
  char *pcStack_c40;
  char *pcStack_c3c;
  byte abStack_c38 [1024];
  undefined4 uStack_838;
  undefined4 uStack_834;
  undefined4 uStack_830;
  undefined4 uStack_82c;
  undefined4 uStack_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined uStack_818;
  char acStack_7f8 [64];
  char acStack_7b8 [8];
  char acStack_7b0 [1916];
  uint uStack_34;
  pthread_t apStack_c [3];
  
  cgtime(DAT_0001e064);
  iVar1 = pthread_create(apStack_c,(pthread_attr_t *)0x0,restart_thread + 1,(void *)0x0);
  if (iVar1 == 0) {
    return 0;
  }
  restart_threads_part_59();
  pFVar9 = benchfile_in;
  uStack_34 = unaff_r6 >> 0x1d;
  if (benchfile_in == (FILE *)0x0) {
    if (opt_benchfile == (char *)0x0) {
      uStack_838._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[0];
      uStack_838._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[1];
      uStack_838._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[2];
      uStack_838._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[3];
      uStack_834._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[4];
      uStack_834._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[5];
      uStack_834._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[6];
      uStack_834._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[7];
      uStack_830._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[8];
      uStack_830._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[9];
      uStack_830._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[10];
      uStack_830._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[11];
      uStack_82c._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[12];
      uStack_82c._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[13];
      uStack_82c._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[14];
      uStack_82c._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[15];
      uStack_828._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[16];
      uStack_828._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[17];
      uStack_828._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[18];
      uStack_828._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[19];
      uStack_824._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[20];
      uStack_824._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[21];
      uStack_824._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[22];
      uStack_824._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[23];
      uStack_820._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[24];
      uStack_820._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[25];
      uStack_820._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[26];
      uStack_820._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[27];
      uStack_81c._0_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[28];
      uStack_81c._1_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[29];
      uStack_81c._2_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[30];
      uStack_81c._3_1_ = s_BENCHFILE_Invalid_benchfile_NULL_0005c940[31];
      uStack_818 = (undefined)ram0x0005c960;
      _applog(3,&uStack_838,1);
                    /* WARNING: Subroutine does not return */
      __quit(1);
    }
    benchfile_in = fopen(opt_benchfile,"r");
    if (benchfile_in == (FILE *)0x0) {
      pcVar2 = "BENCHFILE Failed to open benchfile \'%s\'";
    }
    else {
      benchfile_line = pFVar9;
      pcVar2 = fgets((char *)abStack_c38,0x400,benchfile_in);
      if (pcVar2 != (char *)0x0) goto LAB_0001e0aa;
      pcVar2 = "BENCHFILE Failed to read benchfile \'%s\'";
    }
  }
  else {
    pcVar2 = fgets((char *)abStack_c38,0x400,benchfile_in);
    while (pFVar9 = benchfile_work, pcVar2 != (char *)0x0) {
LAB_0001e0aa:
      benchfile_work = pFVar9;
      pbVar10 = abStack_c38;
      uVar5 = (uint)(abStack_c38[0] != 0 && abStack_c38[0] != 0x23);
      if (abStack_c38[0] == 0x2f) {
        uVar5 = 0;
      }
      pFVar9 = (FILE *)((int)&benchfile_line->_flags + 1);
      benchfile_line = pFVar9;
      if (uVar5 != 0) {
        ppbVar11 = apbStack_c4c;
        iVar1 = 0;
        apbStack_c4c[0] = pbVar10;
        goto LAB_0001e0ea;
      }
      pcVar2 = fgets((char *)pbVar10,0x400,benchfile_in);
    }
    if (benchfile_work != (FILE *)0x0) {
      fclose(benchfile_in);
      benchfile_in = (FILE *)0;
      uVar5 = benchfile_get_work(__s);
      return uVar5;
    }
    pcVar2 = "BENCHFILE No work in benchfile \'%s\'";
  }
  snprintf((char *)&uStack_838,0x800,pcVar2,opt_benchfile);
  goto LAB_0001e14a;
  while( true ) {
    pbVar10 = pbVar3 + 1;
    *pbVar3 = 0;
    *ppbVar11 = pbVar10;
    iVar1 = iVar8;
    if (iVar8 == 4) break;
LAB_0001e0ea:
    pbVar3 = (byte *)strchr((char *)pbVar10,0x2c);
    ppbVar11[1] = pbVar3;
    iVar8 = iVar1 + 1;
    if (pbVar3 == (byte *)0x0) {
      snprintf((char *)&uStack_838,0x800,
               "BENCHFILE Invalid input file line %d - field count is %d but should be %d",pFVar9,
               iVar8,5);
      goto LAB_0001e14a;
    }
    pbVar10 = *ppbVar11;
    ppbVar11 = ppbVar11 + 1;
    iVar4 = *(int *)(benchfile_data + iVar1 * 8);
    if ((int)pbVar3 - (int)pbVar10 != iVar4 && iVar4 != 0) {
      snprintf((char *)&uStack_838,0x800,
               "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d",
               pFVar9,iVar8,*(undefined4 *)(benchfile_data + iVar1 * 8 + 4),
               (int)pbVar3 - (int)pbVar10,iVar4);
      goto LAB_0001e14a;
    }
  }
  sVar6 = strlen(pcStack_c3c);
  if (9 < (int)sVar6) {
    sprintf((char *)&uStack_838,"0000000%c",(uint)*apbStack_c4c[0]);
    sVar6 = strlen((char *)&uStack_838);
    pcVar2 = (char *)((int)&uStack_838 + sVar6);
    iVar1 = iStack_c44 + 0x38;
    do {
      iVar8 = iVar1 + -8;
      sprintf(pcVar2,"%.8s",iVar1);
      pcVar2 = pcVar2 + 8;
      iVar1 = iVar8;
    } while (iStack_c44 + -8 != iVar8);
    pcVar2 = acStack_7f8 + sVar6;
    iVar1 = (int)apbStack_c4c[1] + 0x38;
    do {
      iVar8 = iVar1 + -8;
      sprintf(pcVar2,"%.8s",iVar1);
      pcVar2 = pcVar2 + 8;
      iVar1 = iVar8;
    } while ((int)apbStack_c4c[1] + -8 != iVar8);
    lVar7 = strtol(pcStack_c3c,(char **)0x0,10);
    sprintf(acStack_7b8 + sVar6,"%08lx",lVar7);
    strcpy(acStack_7b0 + sVar6,pcStack_c40);
    memset(__s,0,0x1c0);
    hex2bin(__s,&uStack_838,(int)(sVar6 + 0x90) >> 1);
    calc_midstate(__s);
    benchfile_work = (FILE *)((int)&benchfile_work->_flags + 1);
    return uVar5;
  }
  snprintf((char *)&uStack_838,0x800,
           "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d",
           pFVar9,5,"NonceTime",sVar6,10);
LAB_0001e14a:
  _applog(3,&uStack_838,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

