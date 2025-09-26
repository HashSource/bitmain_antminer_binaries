
int X509_STORE_CTX_get1_crls(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  X509_CRL *a;
  int iVar5;
  int local_24;
  
  iVar1 = OPENSSL_sk_new_null();
  iVar2 = X509_OBJECT_new();
  iVar5 = *param_1;
  if ((iVar5 == 0 || (iVar2 == 0 || iVar1 == 0)) ||
     (iVar3 = X509_STORE_CTX_get_by_subject(param_1,2,param_2,iVar2), iVar3 == 0)) {
    X509_OBJECT_free(iVar2);
    OPENSSL_sk_free(iVar1);
    return 0;
  }
  X509_OBJECT_free(iVar2);
  X509_STORE_lock(iVar5);
  iVar2 = x509_object_idx_cnt(*(undefined4 *)(iVar5 + 4),2,param_2,&local_24);
  if (iVar2 < 0) {
    X509_STORE_unlock(iVar5);
    OPENSSL_sk_free(iVar1);
    return 0;
  }
  iVar3 = 0;
  if (0 < local_24) {
    do {
      iVar4 = OPENSSL_sk_value(*(undefined4 *)(iVar5 + 4),iVar3 + iVar2);
      a = *(X509_CRL **)(iVar4 + 4);
      iVar3 = iVar3 + 1;
      iVar4 = X509_CRL_up_ref(a);
      if (iVar4 == 0) {
        X509_STORE_unlock(iVar5);
LAB_00170fd2:
        OPENSSL_sk_pop_free(iVar1,(undefined *)0x176e4d);
        return 0;
      }
      iVar4 = OPENSSL_sk_push(iVar1,a);
      if (iVar4 == 0) {
        X509_STORE_unlock(iVar5);
        X509_CRL_free(a);
        goto LAB_00170fd2;
      }
    } while (iVar3 < local_24);
  }
  X509_STORE_unlock(iVar5);
  return iVar1;
}

