
DH * d2i_DHxparams(DH **param_1,uchar **param_2,long param_3)

{
  DH *dh;
  BIGNUM **ptr;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  uchar *puVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ASN1_BIT_STRING *a;
  
  dh = DH_new();
  if (dh != (DH *)0x0) {
    ptr = (BIGNUM **)ASN1_item_d2i((ASN1_VALUE **)0x0,param_2,param_3,DAT_0010043c);
    if (ptr == (BIGNUM **)0x0) {
      DH_free(dh);
      dh = (DH *)0x0;
    }
    else {
      if (param_1 != (DH **)0x0) {
        if (*param_1 != (DH *)0x0) {
          DH_free(*param_1);
        }
        *param_1 = dh;
      }
      pBVar1 = ptr[1];
      pBVar2 = ptr[2];
      pBVar6 = ptr[3];
      pBVar4 = ptr[4];
      dh->p = *ptr;
      dh->q = pBVar1;
      dh->g = pBVar2;
      dh->j = pBVar6;
      if (pBVar4 != (BIGNUM *)0x0) {
        a = (ASN1_BIT_STRING *)pBVar4->d;
        puVar3 = a->data;
        iVar5 = a->length;
        dh->counter = (BIGNUM *)pBVar4->top;
        dh->seed = puVar3;
        dh->seedlen = iVar5;
        a->data = (uchar *)0x0;
        ASN1_BIT_STRING_free(a);
        CRYPTO_free(ptr[4]);
        ptr[4] = (BIGNUM *)0x0;
      }
      CRYPTO_free(ptr);
    }
  }
  return dh;
}

