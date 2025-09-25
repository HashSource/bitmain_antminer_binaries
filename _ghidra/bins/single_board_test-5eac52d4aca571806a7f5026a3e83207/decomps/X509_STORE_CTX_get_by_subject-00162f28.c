
undefined4 X509_STORE_CTX_get_by_subject(int *param_1,int param_2,X509_NAME *param_3,int *param_4)

{
  X509_OBJECT *a;
  X509_LOOKUP *ctx;
  int iVar1;
  int extraout_r0;
  int extraout_r0_00;
  int iVar2;
  int iVar3;
  X509_OBJECT local_28;
  
  iVar3 = *param_1;
  if (iVar3 != 0) {
    iVar2 = 0;
    local_28.type = 0;
    local_28.data.ptr = (char *)0x0;
    X509_STORE_lock(iVar3);
    a = X509_OBJECT_retrieve_by_subject(*(stack_st_X509_OBJECT **)(iVar3 + 4),param_2,param_3);
    X509_STORE_unlock(iVar3);
    if (param_2 == 2 || a == (X509_OBJECT *)0x0) {
      do {
        iVar1 = OPENSSL_sk_num(*(undefined4 *)(iVar3 + 8));
        if (iVar1 <= iVar2) {
          if (a == (X509_OBJECT *)0x0) {
            return 0;
          }
          goto LAB_00162f8e;
        }
        ctx = (X509_LOOKUP *)OPENSSL_sk_value(*(undefined4 *)(iVar3 + 8),iVar2);
        iVar1 = X509_LOOKUP_by_subject(ctx,param_2,param_3,&local_28);
        iVar2 = iVar2 + 1;
      } while (iVar1 == 0);
      X509_OBJECT_up_ref_count(&local_28);
      a = &local_28;
      iVar3 = extraout_r0_00;
    }
    else {
LAB_00162f8e:
      X509_OBJECT_up_ref_count(a);
      iVar3 = extraout_r0;
    }
    if (iVar3 != 0) {
      *param_4 = a->type;
      *(_union_387 *)(param_4 + 1) = a->data;
      return 1;
    }
  }
  return 0;
}

