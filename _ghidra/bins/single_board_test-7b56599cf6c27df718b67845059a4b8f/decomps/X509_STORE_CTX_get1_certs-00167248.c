
undefined4 X509_STORE_CTX_get1_certs(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  X509 *a;
  int iVar5;
  int local_24;
  
  iVar5 = *param_1;
  if (iVar5 != 0) {
    X509_STORE_lock(iVar5);
    iVar1 = x509_object_idx_cnt(*(undefined4 *)(iVar5 + 4),1,param_2,&local_24);
    if (-1 < iVar1) {
LAB_00167278:
      uVar2 = OPENSSL_sk_new_null();
      if (0 < local_24) {
        iVar4 = 0;
        do {
          iVar3 = OPENSSL_sk_value(*(undefined4 *)(iVar5 + 4),iVar1 + iVar4);
          a = *(X509 **)(iVar3 + 4);
          iVar4 = iVar4 + 1;
          iVar3 = X509_up_ref(a);
          if (iVar3 == 0) {
            X509_STORE_unlock(iVar5);
LAB_001672bc:
            OPENSSL_sk_pop_free(uVar2,(undefined *)0x16e591);
            return 0;
          }
          iVar3 = OPENSSL_sk_push(uVar2,a);
          if (iVar3 == 0) {
            X509_STORE_unlock(iVar5);
            X509_free(a);
            goto LAB_001672bc;
          }
        } while (iVar4 < local_24);
      }
      X509_STORE_unlock(iVar5);
      return uVar2;
    }
    iVar1 = X509_OBJECT_new();
    X509_STORE_unlock(iVar5);
    if (iVar1 != 0) {
      iVar4 = X509_STORE_CTX_get_by_subject(param_1,1,param_2,iVar1);
      if (iVar4 == 0) {
        X509_OBJECT_free(iVar1);
      }
      else {
        X509_OBJECT_free(iVar1);
        X509_STORE_lock(iVar5);
        iVar1 = x509_object_idx_cnt(*(undefined4 *)(iVar5 + 4),1,param_2,&local_24);
        if (-1 < iVar1) goto LAB_00167278;
        X509_STORE_unlock(iVar5);
      }
    }
  }
  return 0;
}

