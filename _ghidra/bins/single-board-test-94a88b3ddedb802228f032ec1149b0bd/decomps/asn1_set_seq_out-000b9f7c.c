
undefined4
asn1_set_seq_out(_STACK *param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *ptr;
  void *ptr_00;
  undefined4 uVar4;
  size_t __nmemb;
  undefined4 *puVar5;
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
    ptr = (undefined4 *)CRYPTO_malloc(iVar3 * 0xc,"tasn_enc.c",0x1b2);
    if (ptr == (undefined4 *)0x0) {
      return 0;
    }
    ptr_00 = CRYPTO_malloc(param_3,"tasn_enc.c",0x1b5);
    if (ptr_00 == (void *)0x0) {
      CRYPTO_free(ptr);
      return 0;
    }
    puVar5 = ptr;
    iVar3 = 0;
    local_2c[0] = ptr_00;
    while( true ) {
      iVar2 = sk_num(param_1);
      HintPreloadData(puVar5 + 0xd);
      if (iVar2 <= iVar3) break;
      local_30 = sk_value(param_1,iVar3);
      *puVar5 = local_2c[0];
      uVar4 = ASN1_item_ex_i2d_constprop_1(&local_30,local_2c,param_4,param_6);
      puVar5[2] = local_30;
      puVar5[1] = uVar4;
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + 1;
    }
    __nmemb = sk_num(param_1);
    qsort(ptr,__nmemb,0xc,(__compar_fn_t)0xb97f1);
    local_2c[0] = (void *)*param_2;
    puVar5 = ptr;
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num(param_1);
      HintPreloadData(puVar5 + 0x13);
      if (iVar2 <= iVar3) break;
      memcpy(local_2c[0],(void *)*puVar5,puVar5[1]);
      local_2c[0] = (void *)((int)local_2c[0] + puVar5[1]);
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + 1;
    }
    *param_2 = (int)local_2c[0];
    if (param_5 == 2) {
      iVar3 = 0;
      puVar5 = ptr;
      while( true ) {
        HintPreloadData(puVar5 + 0x17);
        iVar2 = sk_num(param_1);
        if (iVar2 <= iVar3) break;
        puVar1 = puVar5 + 2;
        puVar5 = puVar5 + 3;
        sk_set(param_1,iVar3,(void *)*puVar1);
        iVar3 = iVar3 + 1;
      }
    }
    CRYPTO_free(ptr);
    CRYPTO_free(ptr_00);
  }
  return 1;
}

