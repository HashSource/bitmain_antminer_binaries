
_Bool is_tempsensor_data_correct(temp_info_t temp_info)

{
  int in_r0;
  FILE *pFVar1;
  uint in_r1;
  _Bool _Var2;
  int iVar3;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  uint32_t i;
  char acStack_8 [6];
  char acStack_2 [2];
  
  if (in_r0 == 1) {
    if ((in_r1 == 0) || (6 < in_r1)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Bad,temp_info.num = %d\n","temperature.c",0x209,
                  "is_tempsensor_data_correct",in_r1);
        }
        fclose(pFVar1);
      }
      _Var2 = false;
    }
    else {
      for (i = 0; i < in_r1; i = i + 1) {
        if ((acStack_8[i] < '\x01') || ('<' < acStack_8[i])) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: Bad,temp_info.pos[%d] = %d\n","temperature.c",0x211,
                      "is_tempsensor_data_correct",i,(int)acStack_8[i]);
            }
            fclose(pFVar1);
          }
          return false;
        }
        iVar3 = (int)acStack_2[i];
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (9 < iVar3) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: Bad,temp_info.pos[%d] = %d\n","temperature.c",0x217,
                      "is_tempsensor_data_correct",i,(int)acStack_2[i]);
            }
            fclose(pFVar1);
          }
          return false;
        }
      }
      _Var2 = true;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Bad,temp_info.type = %d\n","temperature.c",0x203,
                "is_tempsensor_data_correct",in_r0);
      }
      fclose(pFVar1);
    }
    _Var2 = false;
  }
  return _Var2;
}

