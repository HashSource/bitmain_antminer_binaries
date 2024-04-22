
void print_leak_doall_arg(BIO **param_1,BIO **param_2)

{
  int *piVar1;
  int iVar2;
  ulong uVar3;
  size_t sVar4;
  size_t sVar5;
  tm *ptVar6;
  size_t sVar7;
  BIO *pBVar8;
  char *pcVar9;
  char *__s;
  BIO *pBVar10;
  CRYPTO_THREADID CStack_428;
  char acStack_420 [1024];
  undefined auStack_20 [4];
  
  piVar1 = DAT_0008a37c;
  if (*param_1 != *param_2) {
    if (*DAT_0008a37c << 0x1f < 0) {
      ptVar6 = localtime((time_t *)(param_1 + 7));
      BIO_snprintf(acStack_420,0x400,DAT_0008a390,ptVar6->tm_hour,ptVar6->tm_min,ptVar6->tm_sec);
      sVar7 = strlen(acStack_420);
      pcVar9 = acStack_420 + sVar7;
      sVar7 = 0x400 - sVar7;
    }
    else {
      pcVar9 = acStack_420;
      sVar7 = 0x400;
    }
    pBVar10 = param_1[3];
    pBVar8 = param_1[2];
    BIO_snprintf(pcVar9,sVar7,DAT_0008a380,param_1[6],pBVar8,pBVar10);
    sVar7 = strlen(pcVar9);
    pcVar9 = pcVar9 + sVar7;
    if (*piVar1 << 0x1e < 0) {
      uVar3 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)(param_1 + 4));
      BIO_snprintf(pcVar9,(size_t)(auStack_20 + -(int)pcVar9),DAT_0008a394,uVar3,pBVar8,pBVar10);
      sVar7 = strlen(pcVar9);
      pcVar9 = pcVar9 + sVar7;
    }
    BIO_snprintf(pcVar9,(size_t)(auStack_20 + -(int)pcVar9),DAT_0008a384,param_1[1],*param_1,pBVar10
                );
    BIO_puts(*param_2,acStack_420);
    pBVar8 = param_1[1];
    pBVar10 = param_1[8];
    param_2[1] = (BIO *)((int)&param_2[1]->method + 1);
    param_2[2] = (BIO *)((int)&pBVar8->method + (int)&param_2[2]->method);
    if (pBVar10 != (BIO *)0x0) {
      sVar7 = 0;
      CRYPTO_THREADID_cpy(&CStack_428,(CRYPTO_THREADID *)pBVar10);
      do {
        sVar7 = sVar7 + 1;
        memset(acStack_420,0x3e,sVar7);
        uVar3 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)pBVar10);
        BIO_snprintf(acStack_420 + sVar7,0x400 - sVar7,DAT_0008a38c,uVar3,pBVar10->cb_arg,
                     pBVar10->init);
        sVar4 = strlen(acStack_420);
        __s = (char *)pBVar10->shutdown;
        sVar5 = strlen(__s);
        pcVar9 = acStack_420 + sVar4;
        if ((int)(0x7d - sVar4) < (int)sVar5) {
          memcpy(pcVar9,__s,0x7d - sVar4);
          sVar5 = 899;
          sVar4 = 0x7d;
        }
        else {
          BUF_strlcpy(pcVar9,__s,0x400 - sVar4);
          sVar4 = strlen(acStack_420);
          sVar5 = 0x400 - sVar4;
        }
        BIO_snprintf(acStack_420 + sVar4,sVar5,DAT_0008a388);
        BIO_puts(*param_2,acStack_420);
        pBVar10 = (BIO *)pBVar10->flags;
      } while ((pBVar10 != (BIO *)0x0) &&
              (iVar2 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)pBVar10,&CStack_428), iVar2 == 0));
    }
  }
  return;
}

