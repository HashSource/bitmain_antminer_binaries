
int x509_name_ex_d2i(undefined4 *param_1,undefined4 *param_2,long param_3,undefined4 param_4,
                    int param_5,int param_6,char param_7,ASN1_TLC *param_8)

{
  int iVar1;
  X509_NAME *a;
  stack_st_X509_NAME_ENTRY *psVar2;
  BUF_MEM *str;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *ptr;
  uchar *__src;
  uchar *local_28;
  ASN1_VALUE *local_24;
  
  if (0xfffff < param_3) {
    param_3 = 0x100000;
  }
  __src = (uchar *)*param_2;
  local_24 = (ASN1_VALUE *)0x0;
  local_28 = __src;
  iVar1 = ASN1_item_ex_d2i(&local_24,&local_28,param_3,(ASN1_ITEM *)X509_NAME_INTERNAL_it,param_5,
                           param_6,param_7,param_8);
  if (iVar1 < 1) {
    return iVar1;
  }
  ptr = (undefined4 *)*param_1;
  if (ptr != (undefined4 *)0x0) {
    BUF_MEM_free((BUF_MEM *)ptr[2]);
    OPENSSL_sk_pop_free(*ptr,0x177061);
    CRYPTO_free((void *)ptr[3]);
    CRYPTO_free(ptr);
    *param_1 = 0;
  }
  a = (X509_NAME *)CRYPTO_zalloc(0x14,"crypto/x509/x_name.c",0x5c);
  if (a == (X509_NAME *)0x0) {
    ERR_put_error(0xd,0xab,0x41,"crypto/x509/x_name.c",0x69);
  }
  else {
    psVar2 = (stack_st_X509_NAME_ENTRY *)OPENSSL_sk_new_null();
    a->entries = psVar2;
    if (psVar2 != (stack_st_X509_NAME_ENTRY *)0x0) {
      str = BUF_MEM_new();
      a->bytes = str;
      if (str != (BUF_MEM *)0x0) {
        a->modified = 1;
        iVar1 = BUF_MEM_grow(str,(int)local_28 - (int)__src);
        if (iVar1 != 0) {
          memcpy(a->bytes->data,__src,(int)local_28 - (int)__src);
          for (iVar1 = 0; iVar3 = OPENSSL_sk_num(local_24), iVar1 < iVar3; iVar1 = iVar1 + 1) {
            uVar4 = OPENSSL_sk_value(local_24,iVar1);
            for (iVar3 = 0; iVar5 = OPENSSL_sk_num(uVar4), iVar3 < iVar5; iVar3 = iVar3 + 1) {
              iVar5 = OPENSSL_sk_value(uVar4);
              psVar2 = a->entries;
              *(int *)(iVar5 + 8) = iVar1;
              iVar5 = OPENSSL_sk_push(psVar2);
              if (iVar5 == 0) goto LAB_0017772c;
              OPENSSL_sk_set(uVar4,iVar3,0);
            }
          }
          CRYPTO_free(a->canon_enc);
          a->canon_enc = (uchar *)0x0;
          iVar1 = OPENSSL_sk_num(a->entries);
          if (iVar1 == 0) {
            iVar1 = 1;
            a->canon_enclen = 0;
LAB_0017780c:
            OPENSSL_sk_pop_free(local_24,0x17708d);
            a->modified = 0;
            *param_1 = a;
            *param_2 = local_28;
            return iVar1;
          }
          iVar1 = x509_name_canon_part_0(a);
          if (iVar1 != 0) goto LAB_0017780c;
        }
LAB_0017772c:
        X509_NAME_free(a);
        goto LAB_00177732;
      }
    }
    ERR_put_error(0xd,0xab,0x41,"crypto/x509/x_name.c",0x69);
    OPENSSL_sk_free(a->entries);
    CRYPTO_free(a);
  }
LAB_00177732:
  OPENSSL_sk_pop_free(local_24,0x177091);
  ERR_put_error(0xd,0x9e,0x3a,"crypto/x509/x_name.c",0xce);
  return 0;
}

