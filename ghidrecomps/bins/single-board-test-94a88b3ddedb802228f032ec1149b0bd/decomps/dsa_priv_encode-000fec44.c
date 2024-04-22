
ASN1_INTEGER * dsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(*(int *)(param_2 + 0x14) + 0x1c) == 0)) {
    a_00 = (ASN1_INTEGER *)0x0;
    ERR_put_error(10,0x74,0x65,DAT_000fed3c,0x124);
    a = (ASN1_STRING *)0x0;
  }
  else {
    a = ASN1_STRING_new();
    if (a == (ASN1_STRING *)0x0) {
      ERR_put_error(10,0x74,0x41,DAT_000fed3c,299);
      a_00 = (ASN1_INTEGER *)0x0;
    }
    else {
      iVar1 = i2d_DSAparams(*(DSA **)(param_2 + 0x14),&a->data);
      a->length = iVar1;
      if (iVar1 < 1) {
        a_00 = (ASN1_INTEGER *)0x0;
        ERR_put_error(10,0x74,0x41,DAT_000fed3c,0x131);
      }
      else {
        a->type = 0x10;
        a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x1c),(ASN1_INTEGER *)0x0)
        ;
        if (a_00 == (ASN1_INTEGER *)0x0) {
          ERR_put_error(10,0x74,0x6d,DAT_000fed3c,0x13a);
        }
        else {
          iVar1 = i2d_ASN1_INTEGER(a_00,local_24);
          ASN1_STRING_clear_free(a_00);
          aobj = OBJ_nid2obj(0x74);
          iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,local_24[0],iVar1);
          if (iVar1 != 0) {
            return (ASN1_INTEGER *)0x1;
          }
        }
      }
    }
  }
  if (local_24[0] != (uchar *)0x0) {
    CRYPTO_free(local_24[0]);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
  }
  if (a_00 != (ASN1_INTEGER *)0x0) {
    ASN1_STRING_clear_free(a_00);
    a_00 = (ASN1_INTEGER *)0x0;
  }
  return a_00;
}

