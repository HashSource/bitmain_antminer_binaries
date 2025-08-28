
DH * d2i_DHxparams(undefined4 *param_1,uchar **param_2,long param_3)

{
  DH *dh;
  ASN1_VALUE *ptr;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  uchar *puVar3;
  undefined4 *puVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ASN1_BIT_STRING *a;
  
  dh = DH_new();
  if (dh != (DH *)0x0) {
    ptr = ASN1_item_d2i((ASN1_VALUE **)0x0,param_2,param_3,(ASN1_ITEM *)DHxparams_it);
    if (ptr == (ASN1_VALUE *)0x0) {
      DH_free(dh);
      dh = (DH *)0x0;
    }
    else {
      if (param_1 != (undefined4 *)0x0) {
        if ((DH *)*param_1 != (DH *)0x0) {
          DH_free((DH *)*param_1);
        }
        *param_1 = dh;
      }
      pBVar1 = *(BIGNUM **)(ptr + 4);
      pBVar2 = *(BIGNUM **)(ptr + 8);
      pBVar6 = *(BIGNUM **)(ptr + 0xc);
      puVar4 = *(undefined4 **)(ptr + 0x10);
      dh->p = *(BIGNUM **)ptr;
      dh->q = pBVar1;
      dh->g = pBVar2;
      dh->j = pBVar6;
      if (puVar4 != (undefined4 *)0x0) {
        a = (ASN1_BIT_STRING *)*puVar4;
        puVar3 = a->data;
        iVar5 = a->length;
        dh->counter = (BIGNUM *)puVar4[1];
        dh->seed = puVar3;
        dh->seedlen = iVar5;
        a->data = (uchar *)0x0;
        ASN1_BIT_STRING_free(a);
        CRYPTO_free(*(void **)(ptr + 0x10));
        *(undefined4 *)(ptr + 0x10) = 0;
      }
      CRYPTO_free(ptr);
    }
  }
  return dh;
}

