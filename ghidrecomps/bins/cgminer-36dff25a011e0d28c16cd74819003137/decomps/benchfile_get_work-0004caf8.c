
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool benchfile_get_work(work *work)

{
  bool bVar1;
  _Bool _Var2;
  char *pcVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  work *work_local;
  char tmp42 [2048];
  char *commas [5];
  char item [1024];
  char buf [1024];
  long nonce_time;
  int len;
  int j;
  int i;
  _Bool got;
  
  bVar1 = false;
  if (benchfile_in == (FILE *)0x0) {
    if (opt_benchfile == (char *)0x0) {
      tmp42._0_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._0_4_;
      tmp42._4_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._4_4_;
      tmp42._8_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._8_4_;
      tmp42._12_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._12_4_;
      tmp42._16_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._16_4_;
      tmp42._20_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._20_4_;
      tmp42._24_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._24_4_;
      tmp42._28_4_ = s_BENCHFILE_Invalid_benchfile_NULL_000a3834._28_4_;
      tmp42[32] = (char)ram0x000a3854;
      _applog(3,tmp42,true);
      _quit(1);
    }
    else {
      benchfile_in = (FILE *)fopen(opt_benchfile,"r");
    }
    if (benchfile_in == (FILE *)0x0) {
      snprintf(tmp42,0x800,"BENCHFILE Failed to open benchfile \'%s\'",opt_benchfile);
      _applog(3,tmp42,true);
      _quit(1);
    }
    benchfile_line = 0;
    pcVar3 = fgets(buf,0x400,(FILE *)benchfile_in);
    if (pcVar3 == (char *)0x0) {
      snprintf(tmp42,0x800,"BENCHFILE Failed to read benchfile \'%s\'",opt_benchfile);
      _applog(3,tmp42,true);
      _quit(1);
    }
    bVar1 = true;
    benchfile_work = 0;
  }
  if ((bVar1) || (pcVar3 = fgets(buf,0x400,(FILE *)benchfile_in), pcVar3 != (char *)0x0)) {
    do {
      benchfile_line = benchfile_line + 1;
      if ((buf[0] != '\0') && ((buf[0] != '#' && (buf[0] != '/')))) {
        commas[0] = buf;
        for (i = 1; i < 5; i = i + 1) {
          pcVar3 = strchr(commas[i + -1],0x2c);
          commas[i] = pcVar3;
          if (commas[i] == (char *)0x0) {
            snprintf(tmp42,0x800,
                     "BENCHFILE Invalid input file line %d - field count is %d but should be %d",
                     benchfile_line,i,5);
            _applog(3,tmp42,true);
            _quit(1);
          }
          if ((benchfile_data[i + -1].length != 0) &&
             ((int)commas[i] - (int)commas[i + -1] != benchfile_data[i + -1].length)) {
            snprintf(tmp42,0x800,
                     "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d"
                     ,benchfile_line,i,benchfile_data[i + -1].name,
                     (int)commas[i] - (int)commas[i + -1],benchfile_data[i + -1].length);
            _applog(3,tmp42,true);
            _quit(1);
          }
          pcVar3 = commas[i];
          commas[i] = pcVar3 + 1;
          *pcVar3 = '\0';
        }
        sVar4 = strlen(commas[4]);
        if ((int)sVar4 < benchfile_data[4].length) {
          snprintf(tmp42,0x800,
                   "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d"
                   ,benchfile_line,5,benchfile_data[4].name,sVar4,benchfile_data[4].length);
          _applog(3,tmp42,true);
          _quit(1);
        }
        sprintf(item,"0000000%c",(uint)(byte)*commas[0]);
        j = strlen(item);
        i = benchfile_data[2].length;
        while (i = i + -8, iVar6 = benchfile_data[1].length, -1 < i) {
          sprintf(item + j,"%.8s",commas[2] + i);
          j = j + 8;
        }
        while (i = iVar6 + -8, -1 < i) {
          sprintf(item + j,"%.8s",commas[1] + i);
          j = j + 8;
          iVar6 = i;
        }
        lVar5 = atol(commas[4]);
        sprintf(item + j,"%08lx",lVar5);
        strcpy(item + j + 8,commas[3]);
        iVar6 = j + 8 + benchfile_data[3].length;
        memset(work,0,0x1c0);
        hex2bin(work->data,item,iVar6 >> 1);
        calc_midstate(work);
        benchfile_work = benchfile_work + 1;
        return true;
      }
      pcVar3 = fgets(buf,0x400,(FILE *)benchfile_in);
    } while (pcVar3 != (char *)0x0);
    if (benchfile_work == 0) {
      snprintf(tmp42,0x800,"BENCHFILE No work in benchfile \'%s\'",opt_benchfile);
      _applog(3,tmp42,true);
      _quit(1);
    }
    fclose((FILE *)benchfile_in);
    benchfile_in = (FILE *)0x0;
    _Var2 = benchfile_get_work(work);
  }
  else {
    if (benchfile_work == 0) {
      snprintf(tmp42,0x800,"BENCHFILE No work in benchfile \'%s\'",opt_benchfile);
      _applog(3,tmp42,true);
      _quit(1);
    }
    fclose((FILE *)benchfile_in);
    benchfile_in = (FILE *)0x0;
    _Var2 = benchfile_get_work(work);
  }
  return _Var2;
}

