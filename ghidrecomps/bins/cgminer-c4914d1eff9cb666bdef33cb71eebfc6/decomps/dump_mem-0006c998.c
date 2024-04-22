
void dump_mem(char *desc,void *addr,int len)

{
  FILE *pFVar1;
  uint uVar2;
  int len_local;
  void *addr_local;
  char *desc_local;
  uchar buff [17];
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_4;
  FILE *pFile_5;
  FILE *pFile;
  uchar *pc;
  int i;
  
  if ((desc != (char *)0x0) && (3 < log_level)) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:\n",desc);
    }
    fclose(pFVar1);
  }
  pc = (uchar *)addr;
  for (i = 0; i < len; i = i + 1) {
    if ((i & 0xfU) == 0) {
      if ((i != 0) && (3 < log_level)) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"  %s\n",buff);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"  %04x ",i);
        }
        fclose(pFVar1);
      }
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1," %02x",(uint)pc[i]);
      }
      fclose(pFVar1);
    }
    if ((pc[i] < 0x20) || (0x7e < pc[i])) {
      uVar2 = i & 0xf;
      if (i < 1) {
        uVar2 = -(-i & 0xfU);
      }
      buff[uVar2] = '.';
    }
    else {
      uVar2 = i & 0xf;
      if (i < 1) {
        uVar2 = -(-i & 0xfU);
      }
      buff[uVar2] = pc[i];
    }
    uVar2 = i & 0xf;
    if (i < 1) {
      uVar2 = -(-i & 0xfU);
    }
    buff[uVar2 + 1] = '\0';
  }
  for (; (i & 0xfU) != 0; i = i + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fwrite(&DAT_000947b8,1,3,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"  %s\n",buff);
    }
    fclose(pFVar1);
  }
  return;
}

