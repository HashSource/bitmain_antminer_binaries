
void get_temp_info_from_default_by_chain(uint32_t chain)

{
  FILE *pFVar1;
  uint32_t chain_local;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_6;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile;
  int i;
  
  temp_info[chain].type = TMP451;
  temp_info[chain].num = 4;
  temp_info[chain].pos[0] = '\f';
  temp_info[chain].pos[1] = '\t';
  temp_info[chain].pos[2] = '%';
  temp_info[chain].pos[3] = '(';
  temp_info[chain].offset[0] = '\0';
  temp_info[chain].offset[1] = '\0';
  temp_info[chain].offset[2] = '\0';
  temp_info[chain].offset[3] = '\0';
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"sensor type = %d,sensor num = %d\n",temp_info[chain].type,temp_info[chain].num
             );
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("sensor pos:",1,0xb,pFVar1);
    }
    fclose(pFVar1);
  }
  for (i = 0; i < 8; i = i + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1," %d ",(uint)(byte)temp_info[chain].pos[i]);
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("sensor offset:",1,0xe,pFVar1);
    }
    fclose(pFVar1);
  }
  for (i = 0; i < 8; i = i + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1," %d ",(uint)(byte)temp_info[chain].offset[i]);
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}

