
ASN1_STRING * dh_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ASN1_STRING *a;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  int iVar1;
  DH *a_01;
  uchar *local_1c;
  
  local_1c = (uchar *)0x0;
  a_01 = *(DH **)(param_2 + 0x14);
  a = ASN1_STRING_new();
  iVar1 = 0xa4;
  if (a != (ASN1_STRING *)0x0) {
    if (*(int *)(param_2 + 0xc) == DAT_000a53d8) {
      iVar1 = i2d_DHxparams();
    }
    else {
      iVar1 = i2d_DHparams(a_01,&a->data);
    }
    a->length = iVar1;
    if (iVar1 < 1) {
      iVar1 = 0xa9;
    }
    else {
      a_00 = BN_to_ASN1_INTEGER(a_01->pub_key,(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_000a53a2;
      iVar1 = i2d_ASN1_INTEGER(a_00,&local_1c);
      ASN1_INTEGER_free(a_00);
      if (0 < iVar1) {
        aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,0x10,a,local_1c,iVar1);
        if (iVar1 != 0) {
          return (ASN1_STRING *)0x1;
        }
        goto LAB_000a53a2;
      }
      iVar1 = 0xb7;
    }
  }
  ERR_put_error(5,0x6d,0x41,DAT_000a53dc,iVar1);
LAB_000a53a2:
  if (local_1c != (uchar *)0x0) {
    CRYPTO_free(local_1c);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
    a = (ASN1_STRING *)0x0;
  }
  return a;
}

