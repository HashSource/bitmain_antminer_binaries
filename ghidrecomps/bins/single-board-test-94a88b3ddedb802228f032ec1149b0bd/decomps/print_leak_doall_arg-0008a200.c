
void print_leak_doall_arg(int *param_1,int *param_2)

{
  ulong uVar1;
  size_t sVar2;
  size_t sVar3;
  tm *ptVar4;
  size_t sVar5;
  CRYPTO_THREADID *src;
  int iVar6;
  char *pcVar7;
  char *__s;
  int iVar8;
  CRYPTO_THREADID CStack_428;
  char acStack_420 [1024];
  undefined1 auStack_20 [4];
  
  if (*param_1 != *param_2) {
    if (options << 0x1f < 0) {
      ptVar4 = localtime(param_1 + 7);
      BIO_snprintf(acStack_420,0x400,"[%02d:%02d:%02d] ",ptVar4->tm_hour,ptVar4->tm_min,
                   ptVar4->tm_sec);
      sVar5 = strlen(acStack_420);
      pcVar7 = acStack_420 + sVar5;
      sVar5 = 0x400 - sVar5;
    }
    else {
      pcVar7 = acStack_420;
      sVar5 = 0x400;
    }
    iVar8 = param_1[3];
    iVar6 = param_1[2];
    BIO_snprintf(pcVar7,sVar5,"%5lu file=%s, line=%d, ",param_1[6],iVar6,iVar8);
    sVar5 = strlen(pcVar7);
    pcVar7 = pcVar7 + sVar5;
    if (options << 0x1e < 0) {
      uVar1 = CRYPTO_THREADID_hash((CRYPTO_THREADID *)(param_1 + 4));
      BIO_snprintf(pcVar7,(size_t)(auStack_20 + -(int)pcVar7),"thread=%lu, ",uVar1,iVar6,iVar8);
      sVar5 = strlen(pcVar7);
      pcVar7 = pcVar7 + sVar5;
    }
    BIO_snprintf(pcVar7,(size_t)(auStack_20 + -(int)pcVar7),"number=%d, address=%08lX\n",param_1[1],
                 *param_1,iVar8);
    BIO_puts((BIO *)*param_2,acStack_420);
    iVar6 = param_1[1];
    src = (CRYPTO_THREADID *)param_1[8];
    param_2[1] = param_2[1] + 1;
    param_2[2] = param_2[2] + iVar6;
    if (src != (CRYPTO_THREADID *)0x0) {
      sVar5 = 0;
      CRYPTO_THREADID_cpy(&CStack_428,src);
      do {
        sVar5 = sVar5 + 1;
        memset(acStack_420,0x3e,sVar5);
        uVar1 = CRYPTO_THREADID_hash(src);
        BIO_snprintf(acStack_420 + sVar5,0x400 - sVar5," thread=%lu, file=%s, line=%d, info=\"",
                     uVar1,src[1].ptr,src[1].val);
        sVar2 = strlen(acStack_420);
        __s = (char *)src[2].ptr;
        sVar3 = strlen(__s);
        pcVar7 = acStack_420 + sVar2;
        if ((int)(0x7d - sVar2) < (int)sVar3) {
          memcpy(pcVar7,__s,0x7d - sVar2);
          sVar3 = 899;
          sVar2 = 0x7d;
        }
        else {
          BUF_strlcpy(pcVar7,__s,0x400 - sVar2);
          sVar2 = strlen(acStack_420);
          sVar3 = 0x400 - sVar2;
        }
        BIO_snprintf(acStack_420 + sVar2,sVar3,"\"\n");
        BIO_puts((BIO *)*param_2,acStack_420);
        src = (CRYPTO_THREADID *)src[2].val;
      } while ((src != (CRYPTO_THREADID *)0x0) &&
              (iVar6 = CRYPTO_THREADID_cmp(src,&CStack_428), iVar6 == 0));
    }
  }
  return;
}

