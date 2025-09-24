
long file_ctrl(BIO *param_1,int param_2,uint param_3,bio_st *param_4)

{
  FILE *pFVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  char acStack_1c [8];
  
  pFVar1 = (FILE *)param_1->next_bio;
  if (param_2 == 0xb) {
    iVar2 = fflush(pFVar1);
    if (iVar2 != -1) {
      return 1;
    }
    piVar4 = __errno_location();
    ERR_put_error(2,0x12,*piVar4,"crypto/bio/bss_file.c",0x13c);
    ERR_add_error_data(1,"fflush()");
    ERR_put_error(0x20,0x74,2,"crypto/bio/bss_file.c",0x13e);
    return 0;
  }
  if (param_2 < 0xc) {
    if (param_2 != 3) {
      if (3 < param_2) {
        if (param_2 == 8) {
          return param_1->flags;
        }
        if (param_2 == 9) {
          param_1->flags = param_3;
          return 1;
        }
        return 0;
      }
      if (param_2 != 1) {
        if (param_2 == 2) {
          iVar2 = feof(pFVar1);
          return iVar2;
        }
        return 0;
      }
      goto LAB_0010f4e2;
    }
  }
  else {
    if (param_2 == 0x6b) {
      if (param_4 != (bio_st *)0x0) {
        param_4->method = (BIO_METHOD *)pFVar1;
        return 1;
      }
      return 1;
    }
    if (param_2 < 0x6c) {
      if (param_2 == 0xc) {
        return 1;
      }
      if (param_2 == 0x6a) {
        if ((param_1->flags != 0) && (param_1->shutdown != 0 && pFVar1 != (FILE *)0x0)) {
          fclose(pFVar1);
          param_1->retry_reason = 0;
        }
        param_1->flags = param_3 & 1;
        param_1->next_bio = param_4;
        param_1->shutdown = 1;
        return 1;
      }
      return 0;
    }
    if (param_2 == 0x80) {
LAB_0010f4e2:
      iVar2 = fseek(pFVar1,param_3,0);
      return iVar2;
    }
    if (param_2 != 0x85) {
      if (param_2 != 0x6c) {
        return 0;
      }
      if (param_1->flags != 0) {
        if (param_1->shutdown != 0 && pFVar1 != (FILE *)0x0) {
          fclose(pFVar1);
          param_1->next_bio = (bio_st *)0x0;
          param_1->retry_reason = 0;
        }
        param_1->shutdown = 0;
      }
      param_1->flags = param_3 & 1;
      if ((int)(param_3 << 0x1c) < 0) {
        if ((param_3 & 2) == 0) {
          OPENSSL_strlcpy(acStack_1c,"a",4);
        }
        else {
          OPENSSL_strlcpy(acStack_1c,&DAT_002091c0,4);
        }
      }
      else if ((param_3 & 6) == 6) {
        OPENSSL_strlcpy(acStack_1c,&DAT_002091c4,4);
      }
      else if ((int)(param_3 << 0x1d) < 0) {
        OPENSSL_strlcpy(acStack_1c,"w",4);
      }
      else {
        if ((param_3 & 2) == 0) {
          ERR_put_error(0x20,0x74,0x65,"crypto/bio/bss_file.c",0x111);
          return 0;
        }
        OPENSSL_strlcpy(acStack_1c,"r",4);
      }
      pFVar1 = openssl_fopen((char *)param_4,acStack_1c);
      if (pFVar1 != (FILE *)0x0) {
        param_1->next_bio = (bio_st *)pFVar1;
        param_1->shutdown = 1;
        BIO_clear_flags(param_1,0);
        return 1;
      }
      piVar4 = __errno_location();
      ERR_put_error(2,1,*piVar4,"crypto/bio/bss_file.c",0x120);
      ERR_add_error_data(5,"fopen(\'",param_4,&DAT_002091c8,acStack_1c,&DAT_00202e30);
      ERR_put_error(0x20,0x74,2,"crypto/bio/bss_file.c",0x122);
      return 0;
    }
  }
  lVar3 = ftell(pFVar1);
  return lVar3;
}

