
undefined4 dsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ulong *puVar1;
  ASN1_INTEGER *a;
  int penclen;
  ASN1_OBJECT *aobj;
  BIGNUM *a_00;
  DSA *a_01;
  int iVar2;
  uchar *local_1c;
  
  a_00 = *(BIGNUM **)(param_2 + 0x1c);
  a_01 = *(DSA **)(param_2 + 0x18);
  local_1c = (uchar *)0x0;
  if ((((a_00 == (BIGNUM *)0x0) || (a_00 = (BIGNUM *)a_01->write_params, a_00 == (BIGNUM *)0x0)) ||
      (a_00 = a_01->p, a_00 == (BIGNUM *)0x0)) || (a_00 = a_01->q, a_00 == (BIGNUM *)0x0)) {
    iVar2 = -1;
LAB_00118226:
    a = BN_to_ASN1_INTEGER(a_01->g,(ASN1_INTEGER *)0x0);
    if (a == (ASN1_INTEGER *)0x0) {
      iVar2 = 0x6a;
    }
    else {
      penclen = i2d_ASN1_INTEGER(a,&local_1c);
      ASN1_INTEGER_free(a);
      if (0 < penclen) {
        aobj = OBJ_nid2obj(0x74);
        if ((aobj != (ASN1_OBJECT *)0x0) &&
           (iVar2 = X509_PUBKEY_set0_param(param_1,aobj,iVar2,a_00,local_1c,penclen), iVar2 != 0)) {
          return 1;
        }
        goto LAB_00118260;
      }
      iVar2 = 0x72;
    }
  }
  else {
    a_00 = (BIGNUM *)ASN1_STRING_new();
    if (a_00 == (BIGNUM *)0x0) {
      iVar2 = 0x5b;
    }
    else {
      puVar1 = (ulong *)i2d_DSAparams(a_01,(uchar **)&a_00->dmax);
      a_00->d = puVar1;
      if (0 < (int)puVar1) {
        iVar2 = 0x10;
        goto LAB_00118226;
      }
      iVar2 = 0x60;
    }
  }
  ERR_put_error(10,0x76,0x41,"crypto/dsa/dsa_ameth.c",iVar2);
LAB_00118260:
  CRYPTO_free(local_1c);
  ASN1_STRING_free((ASN1_STRING *)a_00);
  return 0;
}

