
int file_ctrl(BIO *param_1,int param_2,uint param_3,FILE **param_4)

{
  FILE *pFVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  char *src;
  char acStack_1c [8];
  
  pFVar1 = (FILE *)param_1->ptr;
  if (param_2 == 0xb) {
    fflush(pFVar1);
    return 1;
  }
  if (param_2 < 0xc) {
    if (param_2 == 3) {
LAB_000a99d8:
      lVar2 = ftell(pFVar1);
      return lVar2;
    }
    if (param_2 < 4) {
      if (param_2 == 1) goto LAB_000a99e6;
      if (param_2 == 2) {
        iVar3 = feof(pFVar1);
        return iVar3;
      }
    }
    else {
      if (param_2 == 8) {
        return param_1->shutdown;
      }
      if (param_2 == 9) {
        param_1->shutdown = param_3;
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x6b) {
      if (param_4 == (FILE **)0x0) {
        return 1;
      }
      *param_4 = pFVar1;
      return 1;
    }
    if (param_2 < 0x6c) {
      if (param_2 == 0xc) {
        return 1;
      }
      if (param_2 == 0x6a) {
        if (((param_1->shutdown != 0) && (param_1->init != 0)) && (pFVar1 != (FILE *)0x0)) {
          fclose(pFVar1);
          param_1->flags = 0;
        }
        param_1->shutdown = param_3 & 1;
        param_1->ptr = param_4;
        param_1->init = 1;
        return 1;
      }
    }
    else {
      if (param_2 == 0x80) {
LAB_000a99e6:
        iVar3 = fseek(pFVar1,param_3,0);
        return iVar3;
      }
      if (param_2 == 0x85) goto LAB_000a99d8;
      if (param_2 == 0x6c) {
        if (param_1->shutdown != 0) {
          if ((param_1->init != 0) && (pFVar1 != (FILE *)0x0)) {
            fclose(pFVar1);
            param_1->ptr = (void *)0x0;
            param_1->flags = 0;
          }
          param_1->init = 0;
        }
        param_1->shutdown = param_3 & 1;
        if ((int)(param_3 << 0x1c) < 0) {
          src = DAT_000a9ab0;
          if (-1 < (int)(param_3 << 0x1e)) {
            src = DAT_000a9ab4;
          }
          BUF_strlcpy(acStack_1c,src,4);
        }
        else if ((param_3 & 6) == 6) {
          BUF_strlcpy(acStack_1c,DAT_000a9acc,4);
        }
        else if ((int)(param_3 << 0x1d) < 0) {
          BUF_strlcpy(acStack_1c,DAT_000a9ac8,4);
        }
        else {
          if ((param_3 & 2) == 0) {
            ERR_put_error(0x20,0x74,0x65,DAT_000a9ab8,0x175);
            return 0;
          }
          BUF_strlcpy(acStack_1c,DAT_000a9aac,4);
        }
        pFVar1 = fopen64((char *)param_4,acStack_1c);
        if (pFVar1 == (FILE *)0x0) {
          piVar4 = __errno_location();
          ERR_put_error(2,1,*piVar4,DAT_000a9ab8,0x187);
          ERR_add_error_data(5,DAT_000a9ac0,param_4,DAT_000a9ac4,acStack_1c,DAT_000a9abc);
          ERR_put_error(0x20,0x74,2,DAT_000a9ab8,0x189);
          return 0;
        }
        param_1->ptr = pFVar1;
        param_1->init = 1;
        BIO_clear_flags(param_1,0);
        return 1;
      }
    }
  }
  return 0;
}

