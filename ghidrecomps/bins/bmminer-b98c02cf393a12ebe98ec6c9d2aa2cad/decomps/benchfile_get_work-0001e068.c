
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint benchfile_get_work(void *param_1)

{
  char *pcVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  long lVar6;
  int iVar7;
  FILE *pFVar8;
  int iVar9;
  byte *pbVar10;
  byte **ppbVar11;
  byte *local_c3c [2];
  int local_c34;
  char *local_c30;
  char *local_c2c;
  byte local_c28 [1024];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined local_808;
  char acStack_7e8 [64];
  char acStack_7a8 [8];
  char acStack_7a0 [1916];
  
  pFVar8 = benchfile_in;
  if (benchfile_in == (FILE *)0x0) {
    if (opt_benchfile == (char *)0x0) {
      local_828 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._0_4_;
      uStack_824 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._4_4_;
      uStack_820 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._8_4_;
      uStack_81c = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._12_4_;
      local_818 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._16_4_;
      uStack_814 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._20_4_;
      uStack_810 = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._24_4_;
      uStack_80c = s_BENCHFILE_Invalid_benchfile_NULL_0005c940._28_4_;
      local_808 = (undefined)ram0x0005c960;
      _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
      __quit(1);
    }
    benchfile_in = fopen(opt_benchfile,"r");
    if (benchfile_in == (FILE *)0x0) {
      pcVar1 = "BENCHFILE Failed to open benchfile \'%s\'";
    }
    else {
      benchfile_line = pFVar8;
      pcVar1 = fgets((char *)local_c28,0x400,benchfile_in);
      if (pcVar1 != (char *)0x0) goto LAB_0001e0aa;
      pcVar1 = "BENCHFILE Failed to read benchfile \'%s\'";
    }
  }
  else {
    pcVar1 = fgets((char *)local_c28,0x400,benchfile_in);
    while (pFVar8 = benchfile_work, pcVar1 != (char *)0x0) {
LAB_0001e0aa:
      benchfile_work = pFVar8;
      pbVar10 = local_c28;
      uVar4 = (uint)(local_c28[0] != 0 && local_c28[0] != 0x23);
      if (local_c28[0] == 0x2f) {
        uVar4 = 0;
      }
      pFVar8 = (FILE *)((int)&benchfile_line->_flags + 1);
      benchfile_line = pFVar8;
      if (uVar4 != 0) {
        ppbVar11 = local_c3c;
        iVar9 = 0;
        local_c3c[0] = pbVar10;
        goto LAB_0001e0ea;
      }
      pcVar1 = fgets((char *)pbVar10,0x400,benchfile_in);
    }
    if (benchfile_work != (FILE *)0x0) {
      fclose(benchfile_in);
      benchfile_in = (FILE *)0;
      uVar4 = benchfile_get_work(param_1);
      return uVar4;
    }
    pcVar1 = "BENCHFILE No work in benchfile \'%s\'";
  }
  snprintf((char *)&local_828,0x800,pcVar1,opt_benchfile);
  goto LAB_0001e14a;
  while( true ) {
    pbVar10 = pbVar2 + 1;
    *pbVar2 = 0;
    *ppbVar11 = pbVar10;
    iVar9 = iVar7;
    if (iVar7 == 4) break;
LAB_0001e0ea:
    pbVar2 = (byte *)strchr((char *)pbVar10,0x2c);
    ppbVar11[1] = pbVar2;
    iVar7 = iVar9 + 1;
    if (pbVar2 == (byte *)0x0) {
      snprintf((char *)&local_828,0x800,
               "BENCHFILE Invalid input file line %d - field count is %d but should be %d",pFVar8,
               iVar7,5);
      goto LAB_0001e14a;
    }
    pbVar10 = *ppbVar11;
    ppbVar11 = ppbVar11 + 1;
    iVar3 = *(int *)(benchfile_data + iVar9 * 8);
    if ((int)pbVar2 - (int)pbVar10 != iVar3 && iVar3 != 0) {
      snprintf((char *)&local_828,0x800,
               "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d",
               pFVar8,iVar7,*(undefined4 *)(benchfile_data + iVar9 * 8 + 4),
               (int)pbVar2 - (int)pbVar10,iVar3);
      goto LAB_0001e14a;
    }
  }
  sVar5 = strlen(local_c2c);
  if (9 < (int)sVar5) {
    sprintf((char *)&local_828,"0000000%c",(uint)*local_c3c[0]);
    sVar5 = strlen((char *)&local_828);
    pcVar1 = (char *)((int)&local_828 + sVar5);
    iVar9 = local_c34 + 0x38;
    do {
      iVar7 = iVar9 + -8;
      sprintf(pcVar1,"%.8s",iVar9);
      pcVar1 = pcVar1 + 8;
      iVar9 = iVar7;
    } while (local_c34 + -8 != iVar7);
    pcVar1 = acStack_7e8 + sVar5;
    iVar9 = (int)local_c3c[1] + 0x38;
    do {
      iVar7 = iVar9 + -8;
      sprintf(pcVar1,"%.8s",iVar9);
      pcVar1 = pcVar1 + 8;
      iVar9 = iVar7;
    } while ((int)local_c3c[1] + -8 != iVar7);
    lVar6 = strtol(local_c2c,(char **)0x0,10);
    sprintf(acStack_7a8 + sVar5,"%08lx",lVar6);
    strcpy(acStack_7a0 + sVar5,local_c30);
    memset(param_1,0,0x1c0);
    hex2bin(param_1,&local_828,(int)(sVar5 + 0x90) >> 1);
    calc_midstate(param_1);
    benchfile_work = (FILE *)((int)&benchfile_work->_flags + 1);
    return uVar4;
  }
  snprintf((char *)&local_828,0x800,
           "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d",
           pFVar8,5,"NonceTime",sVar5,10);
LAB_0001e14a:
  _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

