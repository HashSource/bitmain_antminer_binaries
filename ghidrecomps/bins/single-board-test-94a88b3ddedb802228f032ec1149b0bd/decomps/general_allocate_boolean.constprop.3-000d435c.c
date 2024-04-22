
int general_allocate_boolean_constprop_3
              (int param_1,int param_2,int param_3,byte *param_4,char *param_5,int param_6,
              int param_7,int param_8)

{
  byte bVar1;
  char *pcVar2;
  int *ptr;
  _STACK *p_Var3;
  uint __c;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = 0xc4;
  if (param_4 != (byte *)0x0) {
    if (param_5 != (char *)0x0) {
      bVar1 = *param_4;
      pbVar5 = param_4;
      while (__c = (uint)bVar1, __c != 0) {
        while (pcVar2 = strchr(param_5,__c), pcVar2 == (char *)0x0) {
          pbVar5 = pbVar5 + 1;
          __c = (uint)*pbVar5;
          if (__c == 0) goto LAB_000d43aa;
        }
        ERR_put_error(0x28,0x6c,0x68,DAT_000d4480,0xcb);
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar5;
      }
LAB_000d43aa:
      if (param_2 == 0) {
        ERR_put_error(0x28,0x6d,0x43,DAT_000d4480,0x8f);
        return -1;
      }
      if (param_8 == 0) {
        ERR_put_error(0x28,0x6d,0x69,DAT_000d4480,0x92);
        return -1;
      }
      ptr = (int *)CRYPTO_malloc(0x20,DAT_000d4480,0x93);
      if (ptr == (int *)0x0) {
        return -1;
      }
      iVar4 = *(int *)(param_1 + 4);
      ptr[1] = param_2;
      if (param_6 != 0) {
        param_6 = 1;
      }
      ptr[3] = param_8;
      ptr[7] = param_6;
      ptr[2] = param_7;
      *ptr = 3;
      if (iVar4 == 0) {
        p_Var3 = sk_new_null();
        *(_STACK **)(param_1 + 4) = p_Var3;
        if (p_Var3 == (_STACK *)0x0) {
          if ((ptr[7] << 0x1f < 0) && (CRYPTO_free((void *)ptr[1]), *ptr == 3)) {
            CRYPTO_free((void *)ptr[4]);
            CRYPTO_free((void *)ptr[5]);
            CRYPTO_free((void *)ptr[6]);
          }
          CRYPTO_free(ptr);
          return -1;
        }
      }
      ptr[4] = param_3;
      ptr[5] = (int)param_4;
      ptr[6] = (int)param_5;
      iVar4 = sk_push(*(_STACK **)(param_1 + 4),ptr);
      if (iVar4 < 1) {
        return iVar4 + -1;
      }
      return iVar4;
    }
    iVar4 = 0xc6;
  }
  ERR_put_error(0x28,0x6c,0x43,DAT_000d4480,iVar4);
  return -1;
}

