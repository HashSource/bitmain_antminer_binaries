
undefined4 dh_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  a = ASN1_STRING_new();
  if (a == (ASN1_STRING *)0x0) {
    iVar1 = 0xd4;
  }
  else {
    if (*(undefined1 **)(param_2 + 0xc) == &dhx_asn1_meth) {
      iVar1 = i2d_DHxparams();
    }
    else {
      iVar1 = i2d_DHparams(*(DH **)(param_2 + 0x18),&a->data);
    }
    a->length = iVar1;
    if (0 < iVar1) {
      a->type = 0x10;
      a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x18),(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(5,0x6f,0x6a,"crypto/dh/dh_ameth.c",0xe3);
      }
      else {
        iVar1 = i2d_ASN1_INTEGER(a_00,local_24);
        ASN1_STRING_clear_free(a_00);
        aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
        iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,local_24[0],iVar1);
        if (iVar1 != 0) {
          return 1;
        }
      }
      goto LAB_00111aa4;
    }
    iVar1 = 0xda;
  }
  ERR_put_error(5,0x6f,0x41,"crypto/dh/dh_ameth.c",iVar1);
LAB_00111aa4:
  CRYPTO_free(local_24[0]);
  ASN1_STRING_free(a);
  ASN1_STRING_clear_free(0);
  return 0;
}

