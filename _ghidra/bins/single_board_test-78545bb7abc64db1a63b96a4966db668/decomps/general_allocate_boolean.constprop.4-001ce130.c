
int general_allocate_boolean_constprop_4
              (int param_1,int param_2,int param_3,byte *param_4,char *param_5,int param_6,
              int param_7,int param_8)

{
  byte bVar1;
  char *pcVar2;
  int *ptr;
  int iVar3;
  uint __c;
  byte *pbVar4;
  
  if (param_4 == (byte *)0x0) {
    iVar3 = 0xa0;
  }
  else {
    if (param_5 != (char *)0x0) {
      bVar1 = *param_4;
      pbVar4 = param_4;
      while (__c = (uint)bVar1, __c != 0) {
        while (pcVar2 = strchr(param_5,__c), pcVar2 == (char *)0x0) {
          pbVar4 = pbVar4 + 1;
          __c = (uint)*pbVar4;
          if (__c == 0) goto LAB_001ce180;
        }
        ERR_put_error(0x28,0x6c,0x68,"crypto/ui/ui_lib.c",0xa7);
        pbVar4 = pbVar4 + 1;
        bVar1 = *pbVar4;
      }
LAB_001ce180:
      if (param_2 == 0) {
        ERR_put_error(0x28,0x6d,0x43,"crypto/ui/ui_lib.c",0x69);
        return -1;
      }
      if (param_8 == 0) {
        ERR_put_error(0x28,0x6d,0x69,"crypto/ui/ui_lib.c",0x6c);
        return -1;
      }
      ptr = (int *)CRYPTO_malloc(0x24,"crypto/ui/ui_lib.c",0x6d);
      if (ptr == (int *)0x0) {
        return -1;
      }
      ptr[1] = param_2;
      ptr[3] = param_8;
      iVar3 = *(int *)(param_1 + 4);
      if (param_6 != 0) {
        param_6 = 1;
      }
      ptr[8] = param_6;
      *ptr = 3;
      ptr[2] = param_7;
      if (iVar3 == 0) {
        iVar3 = OPENSSL_sk_new_null();
        *(int *)(param_1 + 4) = iVar3;
        if (iVar3 == 0) {
          if ((ptr[8] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
            CRYPTO_free((void *)ptr[7]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[7] = (int)param_5;
      ptr[5] = param_3;
      ptr[6] = (int)param_4;
      iVar3 = OPENSSL_sk_push(iVar3,ptr);
      if (0 < iVar3) {
        return iVar3;
      }
      if ((ptr[8] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
        CRYPTO_free((void *)ptr[5]);
        CRYPTO_free((void *)ptr[6]);
        CRYPTO_free((void *)ptr[7]);
      }
      CRYPTO_free(ptr);
      return iVar3 + -1;
    }
    iVar3 = 0xa2;
  }
  ERR_put_error(0x28,0x6c,0x43,"crypto/ui/ui_lib.c",iVar3);
  return -1;
}

