
int ssl_add_cert_chain(int param_1,X509 *param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  X509 *pXVar6;
  X509_STORE *store;
  BUF_MEM *str;
  _STACK *p_Var7;
  uchar *local_ac;
  X509_STORE_CTX XStack_a8;
  
  str = *(BUF_MEM **)(param_1 + 0x3c);
  pXVar6 = param_2;
  if (param_2 != (X509 *)0x0) {
    pXVar6 = (X509 *)param_2->cert_info;
  }
  store = *(X509_STORE **)(*(int *)(param_1 + 0x98) + 0x14c);
  if (store == (X509_STORE *)0x0) {
    store = *(X509_STORE **)(*(int *)(param_1 + 0xe4) + 0xc);
  }
  if ((((param_2 == (X509 *)0x0) || (p_Var7 = (_STACK *)param_2->valid, p_Var7 == (_STACK *)0x0)) &&
      (p_Var7 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x94),
      -1 < *(int *)(param_1 + 0x104) << 0x1c)) && (p_Var7 == (_STACK *)0x0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iVar2 = BUF_MEM_grow_clean(str,10);
  if (iVar2 == 0) {
    ERR_put_error(0x14,0x13e,7,DAT_0007e448,0x454);
    return 0;
  }
  if (pXVar6 != (X509 *)0x0) {
    if (bVar1) {
      iVar2 = i2d_X509(pXVar6,(uchar **)0x0);
      iVar3 = BUF_MEM_grow_clean(str,*param_3 + 3 + iVar2);
      if (iVar3 == 0) goto LAB_0007e3ac;
      pcVar5 = str->data;
      iVar3 = *param_3;
      pcVar5[iVar3] = (char)((uint)iVar2 >> 0x10);
      pcVar5[iVar3 + 1] = (char)((uint)iVar2 >> 8);
      pcVar5[iVar3 + 2] = (char)iVar2;
      local_ac = (uchar *)(pcVar5 + iVar3 + 3);
      i2d_X509(pXVar6,&local_ac);
      *param_3 = *param_3 + 3 + iVar2;
    }
    else {
      iVar2 = X509_STORE_CTX_init(&XStack_a8,store,pXVar6,(stack_st_X509 *)0x0);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0x13e,0xb,DAT_0007e448,0x45f);
        return 0;
      }
      X509_verify_cert(&XStack_a8);
      ERR_clear_error();
      iVar2 = 0;
      while( true ) {
        iVar3 = sk_num(&(XStack_a8.chain)->stack);
        if (iVar3 <= iVar2) break;
        pXVar6 = (X509 *)sk_value(&(XStack_a8.chain)->stack,iVar2);
        iVar3 = i2d_X509(pXVar6,(uchar **)0x0);
        iVar4 = BUF_MEM_grow_clean(str,*param_3 + 3 + iVar3);
        if (iVar4 == 0) {
          ERR_put_error(0x14,0x13f,7,DAT_0007e448,0x425);
          X509_STORE_CTX_cleanup(&XStack_a8);
          return 0;
        }
        pcVar5 = str->data;
        iVar4 = *param_3;
        pcVar5[iVar4] = (char)((uint)iVar3 >> 0x10);
        pcVar5[iVar4 + 1] = (char)((uint)iVar3 >> 8);
        pcVar5[iVar4 + 2] = (char)iVar3;
        local_ac = (uchar *)(pcVar5 + iVar4 + 3);
        i2d_X509(pXVar6,&local_ac);
        *param_3 = *param_3 + 3 + iVar3;
        iVar2 = iVar2 + 1;
      }
      X509_STORE_CTX_cleanup(&XStack_a8);
    }
  }
  iVar2 = 0;
  while( true ) {
    iVar3 = sk_num(p_Var7);
    if (iVar3 <= iVar2) {
      return 1;
    }
    pXVar6 = (X509 *)sk_value(p_Var7,iVar2);
    iVar4 = i2d_X509(pXVar6,(uchar **)0x0);
    iVar3 = BUF_MEM_grow_clean(str,*param_3 + 3 + iVar4);
    if (iVar3 == 0) break;
    pcVar5 = str->data;
    iVar3 = *param_3;
    pcVar5[iVar3] = (char)((uint)iVar4 >> 0x10);
    pcVar5[iVar3 + 1] = (char)((uint)iVar4 >> 8);
    pcVar5[iVar3 + 2] = (char)iVar4;
    local_ac = (uchar *)(pcVar5 + iVar3 + 3);
    i2d_X509(pXVar6,&local_ac);
    *param_3 = *param_3 + 3 + iVar4;
    iVar2 = iVar2 + 1;
  }
LAB_0007e3ac:
  ERR_put_error(0x14,0x13f,7,DAT_0007e448,0x425);
  return iVar3;
}

