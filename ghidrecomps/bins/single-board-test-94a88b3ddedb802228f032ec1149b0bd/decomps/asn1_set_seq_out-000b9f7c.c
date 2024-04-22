
undefined4
asn1_set_seq_out(_STACK *param_1,void **param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  void **ppvVar1;
  int iVar2;
  int iVar3;
  void **ptr;
  void *ptr_00;
  void *pvVar4;
  size_t __nmemb;
  void **ppvVar5;
  void *local_30;
  void *local_2c [2];
  
  local_2c[0] = (void *)0x0;
  if ((param_5 == 0) || (iVar3 = sk_num(param_1), iVar3 < 2)) {
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num(param_1);
      if (iVar2 <= iVar3) break;
      local_30 = sk_value(param_1,iVar3);
      ASN1_item_ex_i2d_constprop_1(&local_30,param_2,param_4,param_6);
      iVar3 = iVar3 + 1;
    }
  }
  else {
    iVar3 = sk_num(param_1);
    ptr = (void **)CRYPTO_malloc(iVar3 * 0xc,DAT_000ba0e0,0x1b2);
    if (ptr == (void **)0x0) {
      return 0;
    }
    ptr_00 = CRYPTO_malloc(param_3,DAT_000ba0e0,0x1b5);
    if (ptr_00 == (void *)0x0) {
      CRYPTO_free(ptr);
      return 0;
    }
    ppvVar5 = ptr;
    iVar3 = 0;
    local_2c[0] = ptr_00;
    while( true ) {
      iVar2 = sk_num(param_1);
      HintPreloadData(ppvVar5 + 0xd);
      if (iVar2 <= iVar3) break;
      local_30 = sk_value(param_1,iVar3);
      *ppvVar5 = local_2c[0];
      pvVar4 = (void *)ASN1_item_ex_i2d_constprop_1(&local_30,local_2c,param_4,param_6);
      ppvVar5[2] = local_30;
      ppvVar5[1] = pvVar4;
      ppvVar5 = ppvVar5 + 3;
      iVar3 = iVar3 + 1;
    }
    __nmemb = sk_num(param_1);
    qsort(ptr,__nmemb,0xc,DAT_000ba0e4);
    local_2c[0] = *param_2;
    ppvVar5 = ptr;
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num(param_1);
      HintPreloadData(ppvVar5 + 0x13);
      if (iVar2 <= iVar3) break;
      memcpy(local_2c[0],*ppvVar5,(size_t)ppvVar5[1]);
      local_2c[0] = (void *)((int)local_2c[0] + (int)ppvVar5[1]);
      ppvVar5 = ppvVar5 + 3;
      iVar3 = iVar3 + 1;
    }
    *param_2 = local_2c[0];
    if (param_5 == 2) {
      iVar3 = 0;
      ppvVar5 = ptr;
      while( true ) {
        HintPreloadData(ppvVar5 + 0x17);
        iVar2 = sk_num(param_1);
        if (iVar2 <= iVar3) break;
        ppvVar1 = ppvVar5 + 2;
        ppvVar5 = ppvVar5 + 3;
        sk_set(param_1,iVar3,*ppvVar1);
        iVar3 = iVar3 + 1;
      }
    }
    CRYPTO_free(ptr);
    CRYPTO_free(ptr_00);
  }
  return 1;
}

