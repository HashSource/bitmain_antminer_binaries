
void get_lastn_nonce_num(char *dest,int n)

{
  uint uVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  FILE *pFVar5;
  int n_local;
  char *dest_local;
  char xtime [2048];
  char tmp [20];
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int len;
  FILE *pFile_8;
  FILE *pFile_9;
  int j;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      xtime[0] = '{';
      xtime[1] = '\0';
      xtime[2] = '\0';
      xtime[3] = '\0';
      memset(xtime + 4,0,0x7fc);
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      tmp[4] = '\0';
      tmp[5] = '\0';
      tmp[6] = '\0';
      tmp[7] = '\0';
      tmp[8] = '\0';
      tmp[9] = '\0';
      tmp[10] = '\0';
      tmp[11] = '\0';
      tmp[12] = '\0';
      tmp[13] = '\0';
      tmp[14] = '\0';
      tmp[15] = '\0';
      tmp[16] = '\0';
      tmp[17] = '\0';
      tmp[18] = '\0';
      tmp[19] = '\0';
      uVar1 = snprintf(tmp,0x14,"Chain%d:{",i + 1);
      if ((0x14 < uVar1) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xcdc,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      sVar4 = strlen(xtime);
      if ((0x7ff - sVar4 < 0x14) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xce1,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      strncat(xtime,tmp,0x7ff - sVar4);
      iVar2 = get_asic_nonce_num(i,0,n);
      uVar1 = snprintf(tmp,0x14,"N%d=%d",0,iVar2);
      if ((0x14 < uVar1) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xce7,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      sVar4 = strlen(xtime);
      if ((0x7ff - sVar4 < 0x14) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xcec,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      strncat(xtime,tmp,0x7ff - sVar4);
      for (j = 1; j < (int)(uint)dev->max_asic_num_in_one_chain; j = j + 1) {
        iVar2 = get_asic_nonce_num(i,j,n);
        uVar1 = snprintf(tmp,0x14,",N%d=%d",j,iVar2);
        if ((0x14 < uVar1) && (3 < log_level)) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xcf5,
                    "get_lastn_nonce_num");
          }
          fclose(pFVar5);
        }
        sVar4 = strlen(xtime);
        if ((0x7ff - sVar4 < 0x14) && (3 < log_level)) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xcfa,
                    "get_lastn_nonce_num");
          }
          fclose(pFVar5);
        }
        strncat(xtime,tmp,0x7ff - sVar4);
      }
      sVar4 = strlen(xtime);
      if (((int)(0x7ff - sVar4) < 2) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xd01,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      strncat(xtime,"},",0x7ff - sVar4);
      sVar4 = strlen(dest);
      sVar3 = strlen(xtime);
      sVar4 = (-sVar3 - sVar4) + 0xfff;
      if (((int)sVar4 < 1) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar5 = fopen(log_file,"a+");
        if (pFVar5 != (FILE *)0x0) {
          fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xd07,
                  "get_lastn_nonce_num");
        }
        fclose(pFVar5);
      }
      strncat(dest,xtime,sVar4);
    }
  }
  sVar4 = strlen(dest);
  if (sVar4 < 0x1000) {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        sVar4 = strlen(dest);
        fprintf(pFVar5,"%s:%d:%s: len=%u\n","driver-btm-soc.c",0xd12,"get_lastn_nonce_num",sVar4);
      }
      fclose(pFVar5);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar5 = fopen(log_file,"a+");
    if (pFVar5 != (FILE *)0x0) {
      fprintf(pFVar5,"%s:%d:%s: string too long\n","driver-btm-soc.c",0xd0e,"get_lastn_nonce_num");
    }
    fclose(pFVar5);
  }
  sVar4 = strlen(dest);
  dest[sVar4 - 1] = '\0';
  return;
}

