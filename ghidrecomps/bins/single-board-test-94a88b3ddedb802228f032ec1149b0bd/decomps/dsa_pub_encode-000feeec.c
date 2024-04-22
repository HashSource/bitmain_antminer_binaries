
BIGNUM * dsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ulong *puVar1;
  int penclen;
  ASN1_OBJECT *aobj;
  int iVar2;
  DSA *a;
  BIGNUM *a_00;
  uchar *local_1c [2];
  
  a_00 = *(BIGNUM **)(param_2 + 0x18);
  a = *(DSA **)(param_2 + 0x14);
  local_1c[0] = (uchar *)0x0;
  if ((((a_00 == (BIGNUM *)0x0) || (a_00 = a->p, a_00 == (BIGNUM *)0x0)) ||
      (a_00 = a->q, a_00 == (BIGNUM *)0x0)) || (a_00 = a->g, a_00 == (BIGNUM *)0x0)) {
    iVar2 = -1;
LAB_000fef56:
    a->write_params = 0;
    penclen = i2d_DSAPublicKey(a,local_1c);
    if (0 < penclen) {
      aobj = OBJ_nid2obj(0x74);
      iVar2 = X509_PUBKEY_set0_param(param_1,aobj,iVar2,a_00,local_1c[0],penclen);
      if (iVar2 != 0) {
        return (BIGNUM *)0x1;
      }
      goto LAB_000fef3c;
    }
    iVar2 = 0x9e;
  }
  else {
    a_00 = (BIGNUM *)ASN1_STRING_new();
    iVar2 = 0x8d;
    if (a_00 != (BIGNUM *)0x0) {
      puVar1 = (ulong *)i2d_DSAparams(a,(uchar **)&a_00->dmax);
      a_00->d = puVar1;
      if (0 < (int)puVar1) {
        iVar2 = 0x10;
        goto LAB_000fef56;
      }
      iVar2 = 0x92;
    }
  }
  ERR_put_error(10,0x76,0x41,DAT_000fef8c,iVar2);
LAB_000fef3c:
  if (local_1c[0] != (uchar *)0x0) {
    CRYPTO_free(local_1c[0]);
  }
  if (a_00 != (BIGNUM *)0x0) {
    ASN1_STRING_free((ASN1_STRING *)a_00);
    a_00 = (BIGNUM *)0x0;
  }
  return a_00;
}

