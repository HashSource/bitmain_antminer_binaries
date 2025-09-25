
size_t x509_name_ex_i2d(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  ASN1_VALUE *local_28;
  uchar *local_24 [2];
  
  param_1 = (undefined4 *)*param_1;
  if (param_1[1] == 0) {
LAB_00169696:
    sVar3 = *(size_t *)param_1[2];
    if (param_2 != (int *)0x0) {
      memcpy((void *)*param_2,(void *)((size_t *)param_1[2])[1],sVar3);
      *param_2 = sVar3 + *param_2;
    }
    return sVar3;
  }
  local_28 = (ASN1_VALUE *)0x0;
  local_28 = (ASN1_VALUE *)OPENSSL_sk_new_null();
  if (local_28 != (ASN1_VALUE *)0x0) {
    iVar5 = -1;
    iVar4 = 0;
    iVar2 = 0;
    do {
      iVar1 = OPENSSL_sk_num(*param_1);
      if (iVar1 <= iVar2) {
        sVar3 = ASN1_item_ex_i2d(&local_28,(uchar **)0x0,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
        iVar2 = BUF_MEM_grow((BUF_MEM *)param_1[2],sVar3);
        if (iVar2 != 0) {
          local_24[0] = *(uchar **)(param_1[2] + 4);
          ASN1_item_ex_i2d(&local_28,local_24,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
          OPENSSL_sk_pop_free(local_28,0x169265);
          param_1[1] = 0;
          if ((int)sVar3 < 0) {
            return sVar3;
          }
          CRYPTO_free((void *)param_1[3]);
          param_1[3] = 0;
          iVar2 = OPENSSL_sk_num(*param_1);
          if (iVar2 == 0) {
            param_1[4] = 0;
          }
          else {
            iVar2 = x509_name_canon_part_0(param_1);
            if (iVar2 == 0) {
              return 0xffffffff;
            }
          }
          goto LAB_00169696;
        }
        break;
      }
      iVar1 = OPENSSL_sk_value(*param_1,iVar2);
      if (*(int *)(iVar1 + 8) != iVar5) {
        iVar4 = OPENSSL_sk_new_null();
        if (iVar4 == 0) break;
        iVar5 = OPENSSL_sk_push(local_28,iVar4);
        if (iVar5 == 0) {
          OPENSSL_sk_free(iVar4);
          break;
        }
        iVar5 = *(int *)(iVar1 + 8);
      }
      iVar1 = OPENSSL_sk_push(iVar4,iVar1);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
  }
  OPENSSL_sk_pop_free(local_28,0x169265);
  ERR_put_error(0xd,0xcb,0x41,"crypto/x509/x_name.c",0x114);
  return 0xffffffff;
}

