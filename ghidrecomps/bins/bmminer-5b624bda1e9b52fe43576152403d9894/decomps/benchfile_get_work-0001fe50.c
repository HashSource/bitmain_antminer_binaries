
/* WARNING: Unknown calling convention */

_Bool benchfile_get_work(work *work)

{
  int iVar1;
  int iVar2;
  _Bool _Var3;
  char *pcVar4;
  char *pcVar5;
  size_t sVar6;
  size_t sVar7;
  int j;
  long lVar8;
  FILE *pFVar9;
  long nonce_time;
  undefined4 uVar10;
  char **ppcVar11;
  int iVar12;
  int iVar13;
  int i;
  int iVar14;
  char *commas [5];
  char buf [1024];
  char item [1024];
  
  iVar1 = DAT_00020150;
  if (*(FILE **)(DAT_00020150 + 0x444) == (FILE *)0x0) {
    if (*(char **)(DAT_00020150 + 0x448) == (char *)0x0) {
      item._0_4_ = *DAT_0002017c;
      item._4_4_ = DAT_0002017c[1];
      item._8_4_ = DAT_0002017c[2];
      item._12_4_ = DAT_0002017c[3];
      item._16_4_ = DAT_0002017c[4];
      item._20_4_ = DAT_0002017c[5];
      item._24_4_ = DAT_0002017c[6];
      item._28_4_ = DAT_0002017c[7];
      item[32] = (char)DAT_0002017c[8];
      _applog(3,item,true);
      _quit(1);
      pFVar9 = *(FILE **)(iVar1 + 0x444);
    }
    else {
      pFVar9 = fopen(*(char **)(DAT_00020150 + 0x448),DAT_0002016c);
      *(FILE **)(iVar1 + 0x444) = pFVar9;
    }
    if (pFVar9 == (FILE *)0x0) {
      snprintf(item,0x800,DAT_00020184,*(undefined4 *)(iVar1 + 0x448));
      _applog(3,item,true);
      _quit(1);
    }
    *(undefined4 *)(iVar1 + 0x44c) = 0;
    iVar12 = DAT_00020150;
    pcVar4 = fgets(buf,0x400,*(FILE **)(iVar1 + 0x444));
    if (pcVar4 == (char *)0x0) {
      snprintf(item,0x800,DAT_00020180,*(undefined4 *)(iVar12 + 0x448));
      _applog(3,item,true);
      _quit(1);
    }
    *(undefined4 *)(iVar1 + 0x450) = 0;
LAB_0001fe78:
    do {
      iVar12 = DAT_00020150;
      pcVar4 = buf;
      *(int *)(iVar1 + 0x44c) = *(int *)(iVar1 + 0x44c) + 1;
      iVar2 = DAT_00020154;
      if ((buf[0] != '#' && buf[0] != '\0') && (buf[0] != '/')) {
        ppcVar11 = commas;
        iVar12 = 0;
        iVar13 = 1;
        commas[0] = pcVar4;
        do {
          pcVar5 = strchr(pcVar4,0x2c);
          ppcVar11[1] = pcVar5;
          if (pcVar5 == (char *)0x0) {
            snprintf(item,0x800,DAT_00020178,*(undefined4 *)(iVar1 + 0x44c),iVar13,5);
            _applog(3,item,true);
            _quit(1);
          }
          iVar14 = *(int *)(iVar2 + iVar12);
          if (iVar14 != 0) {
            if ((int)pcVar5 - (int)*ppcVar11 != iVar14) {
              snprintf(item,0x800,DAT_00020158,*(undefined4 *)(iVar1 + 0x44c),iVar13,
                       *(undefined4 *)(DAT_00020154 + iVar12 + 4),(int)pcVar5 - (int)*ppcVar11,
                       iVar14);
              _applog(3,item,true);
              _quit(1);
            }
          }
          iVar13 = iVar13 + 1;
          pcVar4 = pcVar5 + 1;
          *pcVar5 = '\0';
          iVar12 = iVar12 + 8;
          ppcVar11[1] = pcVar4;
          ppcVar11 = ppcVar11 + 1;
        } while (iVar13 != 5);
        sVar6 = strlen(commas[4]);
        if ((int)sVar6 < 10) {
          snprintf(item,0x800,DAT_00020174,*(undefined4 *)(iVar1 + 0x44c),5,DAT_00020170,sVar6,10);
          _applog(3,item,true);
          _quit(1);
        }
        sprintf(item,DAT_0002015c,(uint)(byte)*commas[0]);
        sVar7 = strlen(item);
        pcVar4 = commas[2] + 0x38;
        sVar6 = sVar7;
        do {
          pcVar5 = item + sVar6;
          sVar6 = sVar6 + 8;
          sprintf(pcVar5,DAT_00020160,pcVar4);
          pcVar4 = pcVar4 + -8;
        } while (sVar6 != sVar7 + 0x40);
        pcVar4 = commas[1] + 0x38;
        do {
          pcVar5 = item + sVar6;
          sVar6 = sVar6 + 8;
          sprintf(pcVar5,DAT_00020160,pcVar4);
          pcVar4 = pcVar4 + -8;
        } while (sVar6 != sVar7 + 0x80);
        lVar8 = strtol(commas[4],(char **)0x0,10);
        sprintf(item + sVar6,DAT_00020164,lVar8);
        strcpy(item + sVar7 + 0x88,commas[3]);
        memset(work,0,0x1c0);
        hex2bin(work->data,item,(int)(sVar7 + 0x90) >> 1);
        calc_midstate(work);
        *(int *)(iVar1 + 0x450) = *(int *)(iVar1 + 0x450) + 1;
        return true;
      }
      pcVar4 = fgets(pcVar4,0x400,*(FILE **)(iVar1 + 0x444));
    } while (pcVar4 != (char *)0x0);
    if (*(int *)(iVar12 + 0x450) != 0) goto LAB_0001feb0;
    uVar10 = *(undefined4 *)(iVar12 + 0x448);
  }
  else {
    pcVar4 = fgets(buf,0x400,*(FILE **)(DAT_00020150 + 0x444));
    if (pcVar4 != (char *)0x0) goto LAB_0001fe78;
    if (*(int *)(iVar1 + 0x450) != 0) goto LAB_0001feb0;
    uVar10 = *(undefined4 *)(iVar1 + 0x448);
  }
  snprintf(item,0x800,DAT_00020168,uVar10);
  _applog(3,item,true);
  _quit(1);
LAB_0001feb0:
  fclose(*(FILE **)(iVar1 + 0x444));
  *(undefined4 *)(iVar1 + 0x444) = 0;
  _Var3 = benchfile_get_work(work);
  return _Var3;
}

