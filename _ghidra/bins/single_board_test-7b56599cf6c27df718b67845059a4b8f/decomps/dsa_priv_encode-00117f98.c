
undefined4 dsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  if ((*(int *)(param_2 + 0x18) == 0) || (*(int *)(*(int *)(param_2 + 0x18) + 0x18) == 0)) {
    a = (ASN1_STRING *)0x0;
    ERR_put_error(10,0x74,0x65,"crypto/dsa/dsa_ameth.c",0xd3);
  }
  else {
    a = ASN1_STRING_new();
    if (a == (ASN1_STRING *)0x0) {
      iVar1 = 0xda;
    }
    else {
      iVar1 = i2d_DSAparams(*(DSA **)(param_2 + 0x18),&a->data);
      a->length = iVar1;
      if (0 < iVar1) {
        a->type = 0x10;
        a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x18),(ASN1_INTEGER *)0x0)
        ;
        if (a_00 == (ASN1_INTEGER *)0x0) {
          ERR_put_error(10,0x74,0x6d,"crypto/dsa/dsa_ameth.c",0xe9);
        }
        else {
          iVar1 = i2d_ASN1_INTEGER(a_00,local_24);
          ASN1_STRING_clear_free(a_00);
          aobj = OBJ_nid2obj(0x74);
          iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,local_24[0],iVar1);
          if (iVar1 != 0) {
            return 1;
          }
        }
        goto LAB_00118010;
      }
      iVar1 = 0xe0;
    }
    ERR_put_error(10,0x74,0x41,"crypto/dsa/dsa_ameth.c",iVar1);
  }
LAB_00118010:
  CRYPTO_free(local_24[0]);
  ASN1_STRING_free(a);
  ASN1_STRING_clear_free(0);
  return 0;
}

