
void dump_mem(int param_1,byte *param_2,uint param_3)

{
  bool bVar1;
  FILE *pFVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte abStack_3c [24];
  
  if (param_1 == 0) {
LAB_00040c26:
    uVar5 = log_level;
    if ((int)param_3 < 1) goto LAB_00040c2c;
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:\n",param_1);
      }
      fclose(pFVar2);
      goto LAB_00040c26;
    }
    if ((int)param_3 < 1) {
      return;
    }
  }
  uVar5 = 0;
  do {
    uVar6 = uVar5 & 0xf;
    if (uVar6 == 0) {
      if (uVar5 == 0) {
LAB_00040bda:
        if (3 < log_level) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"  %04x ",uVar5);
          }
          fclose(pFVar2);
          goto LAB_00040b88;
        }
      }
      else if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"  %s\n",abStack_3c);
        }
        fclose(pFVar2);
        goto LAB_00040bda;
      }
LAB_00040b4a:
      bVar3 = *param_2;
    }
    else {
LAB_00040b88:
      if (log_level < 4) goto LAB_00040b4a;
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2," %02x",(uint)*param_2);
      }
      fclose(pFVar2);
      bVar3 = *param_2;
    }
    if (0x5e < bVar3 - 0x20) {
      bVar3 = 0x2e;
    }
    bVar1 = (int)uVar5 < 1;
    uVar4 = -uVar5;
    uVar5 = uVar5 + 1;
    if (bVar1) {
      uVar6 = -(uVar4 & 0xf);
    }
    abStack_3c[uVar6] = bVar3;
    abStack_3c[uVar6 + 1] = 0;
    param_2 = param_2 + 1;
  } while (param_3 != uVar5);
  uVar6 = param_3 & 0xf;
  uVar5 = log_level;
  while (uVar6 != 0) {
    param_3 = param_3 + 1;
    if (3 < uVar5) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fwrite(&DAT_000659d0,1,3,pFVar2);
      }
      fclose(pFVar2);
      uVar5 = log_level;
    }
    uVar6 = param_3 & 0xf;
  }
LAB_00040c2c:
  if (3 < uVar5) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"  %s\n",abStack_3c);
    }
    fclose(pFVar2);
  }
  return;
}

