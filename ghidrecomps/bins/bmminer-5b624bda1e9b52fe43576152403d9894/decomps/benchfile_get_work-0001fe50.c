
/* WARNING: Unknown calling convention */

_Bool benchfile_get_work(work *work)

{
  _Bool _Var1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  long nonce_time;
  char **ppcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *commas [5];
  char buf [1024];
  char item [1024];
  
  if (benchfile_in == (FILE *)0x0) {
    if (opt_benchfile == (char *)0x0) {
      builtin_strncpy(item,"BENCHFILE Invalid benchfile NULL",0x20);
      item[0x20] = '\0';
      _applog(3,item,true);
      _quit(1);
    }
    else {
      benchfile_in = (FILE *)fopen(opt_benchfile,"r");
    }
    if (benchfile_in == (FILE *)0x0) {
      snprintf(item,0x800,"BENCHFILE Failed to open benchfile \'%s\'",opt_benchfile);
      _applog(3,item,true);
      _quit(1);
    }
    benchfile_line = 0;
    pcVar2 = fgets(buf,0x400,(FILE *)benchfile_in);
    if (pcVar2 == (char *)0x0) {
      snprintf(item,0x800,"BENCHFILE Failed to read benchfile \'%s\'",opt_benchfile);
      _applog(3,item,true);
      _quit(1);
    }
    benchfile_work = 0;
  }
  else {
    pcVar2 = fgets(buf,0x400,(FILE *)benchfile_in);
    if (pcVar2 == (char *)0x0) goto joined_r0x0001feac;
  }
  do {
    pcVar2 = buf;
    benchfile_line = benchfile_line + 1;
    if ((buf[0] != '#' && buf[0] != '\0') && (buf[0] != '/')) {
      ppcVar7 = commas;
      iVar8 = 0;
      iVar9 = 1;
      commas[0] = pcVar2;
      do {
        pcVar3 = strchr(pcVar2,0x2c);
        ppcVar7[1] = pcVar3;
        if (pcVar3 == (char *)0x0) {
          snprintf(item,0x800,
                   "BENCHFILE Invalid input file line %d - field count is %d but should be %d",
                   benchfile_line,iVar9,5);
          _applog(3,item,true);
          _quit(1);
        }
        iVar10 = *(int *)((int)&benchfile_data[0].length + iVar8);
        if ((iVar10 != 0) && ((int)pcVar3 - (int)*ppcVar7 != iVar10)) {
          snprintf(item,0x800,
                   "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d"
                   ,benchfile_line,iVar9,*(undefined4 *)((int)&benchfile_data[0].name + iVar8),
                   (int)pcVar3 - (int)*ppcVar7,iVar10);
          _applog(3,item,true);
          _quit(1);
        }
        iVar9 = iVar9 + 1;
        pcVar2 = pcVar3 + 1;
        *pcVar3 = '\0';
        iVar8 = iVar8 + 8;
        ppcVar7[1] = pcVar2;
        ppcVar7 = ppcVar7 + 1;
      } while (iVar9 != 5);
      sVar4 = strlen(commas[4]);
      if ((int)sVar4 < 10) {
        snprintf(item,0x800,
                 "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d"
                 ,benchfile_line,5,"NonceTime",sVar4,10);
        _applog(3,item,true);
        _quit(1);
      }
      sprintf(item,"0000000%c",(uint)(byte)*commas[0]);
      sVar5 = strlen(item);
      pcVar2 = commas[2] + 0x38;
      sVar4 = sVar5;
      do {
        pcVar3 = item + sVar4;
        sVar4 = sVar4 + 8;
        sprintf(pcVar3,"%.8s",pcVar2);
        pcVar2 = pcVar2 + -8;
      } while (sVar4 != sVar5 + 0x40);
      pcVar2 = commas[1] + 0x38;
      do {
        pcVar3 = item + sVar4;
        sVar4 = sVar4 + 8;
        sprintf(pcVar3,"%.8s",pcVar2);
        pcVar2 = pcVar2 + -8;
      } while (sVar4 != sVar5 + 0x80);
      lVar6 = strtol(commas[4],(char **)0x0,10);
      sprintf(item + sVar4,"%08lx",lVar6);
      strcpy(item + sVar5 + 0x88,commas[3]);
      memset(work,0,0x1c0);
      hex2bin(work->data,item,(int)(sVar5 + 0x90) >> 1);
      calc_midstate(work);
      benchfile_work = benchfile_work + 1;
      return true;
    }
    pcVar2 = fgets(pcVar2,0x400,(FILE *)benchfile_in);
  } while (pcVar2 != (char *)0x0);
joined_r0x0001feac:
  if (benchfile_work == 0) {
    snprintf(item,0x800,"BENCHFILE No work in benchfile \'%s\'",opt_benchfile);
    _applog(3,item,true);
    _quit(1);
  }
  fclose((FILE *)benchfile_in);
  benchfile_in = (FILE *)0x0;
  _Var1 = benchfile_get_work(work);
  return _Var1;
}

