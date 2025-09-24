
undefined4 def_crl_lookup(int param_1,undefined4 *param_2,ASN1_INTEGER *param_3,X509_NAME *param_4)

{
  int iVar1;
  int iVar2;
  ASN1_INTEGER *x;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  X509_NAME *pXVar8;
  int local_4c;
  int iStack_48;
  uchar *puStack_44;
  long lStack_40;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar1 = OPENSSL_sk_is_sorted(*(int *)(param_1 + 0x18));
    if (iVar1 == 0) {
      CRYPTO_THREAD_write_lock(*(undefined4 *)(param_1 + 0x84));
      OPENSSL_sk_sort(*(undefined4 *)(param_1 + 0x18));
      CRYPTO_THREAD_unlock(*(undefined4 *)(param_1 + 0x84));
    }
    local_4c = param_3->length;
    iStack_48 = param_3->type;
    puStack_44 = param_3->data;
    lStack_40 = param_3->flags;
    iVar1 = OPENSSL_sk_find(*(undefined4 *)(param_1 + 0x18),&local_4c);
    if ((-1 < iVar1) && (iVar2 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x18)), iVar1 < iVar2)) {
      do {
        x = (ASN1_INTEGER *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x18),iVar1);
        iVar3 = ASN1_INTEGER_cmp(x,param_3);
        if (iVar3 != 0) {
          return 0;
        }
        puVar4 = x[1].data;
        if (puVar4 == (uchar *)0x0) {
          if (param_4 == (X509_NAME *)0x0) {
LAB_0016d106:
            if (param_2 != (undefined4 *)0x0) {
              *param_2 = x;
            }
            if (x[1].flags == 8) {
              uVar7 = 2;
            }
            else {
              uVar7 = 1;
            }
            return uVar7;
          }
          pXVar8 = (X509_NAME *)X509_CRL_get_issuer(param_1);
          iVar3 = X509_NAME_cmp(param_4,pXVar8);
          if (iVar3 == 0) goto LAB_0016d106;
        }
        else {
          pXVar8 = param_4;
          if (param_4 == (X509_NAME *)0x0) {
            pXVar8 = (X509_NAME *)X509_CRL_get_issuer(param_1);
            puVar4 = x[1].data;
          }
          iVar3 = 0;
          while( true ) {
            iVar5 = OPENSSL_sk_num(puVar4);
            if (iVar5 <= iVar3) break;
            piVar6 = (int *)OPENSSL_sk_value(x[1].data,iVar3);
            if ((*piVar6 == 4) && (iVar5 = X509_NAME_cmp(pXVar8,(X509_NAME *)piVar6[1]), iVar5 == 0)
               ) goto LAB_0016d106;
            puVar4 = x[1].data;
            iVar3 = iVar3 + 1;
          }
        }
        iVar1 = iVar1 + 1;
      } while (iVar2 != iVar1);
    }
  }
  return 0;
}

