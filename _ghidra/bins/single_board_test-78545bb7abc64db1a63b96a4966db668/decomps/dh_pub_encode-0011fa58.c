
undefined4 dh_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  DH *a_01;
  uchar *local_1c;
  
  a_01 = *(DH **)(param_2 + 0x18);
  local_1c = (uchar *)0x0;
  a = ASN1_STRING_new();
  if (a == (ASN1_STRING *)0x0) {
    iVar1 = 0x6e;
  }
  else {
    if (*(undefined1 **)(param_2 + 0xc) == &dhx_asn1_meth) {
      iVar1 = i2d_DHxparams();
    }
    else {
      iVar1 = i2d_DHparams(a_01,&a->data);
    }
    a->length = iVar1;
    if (iVar1 < 1) {
      iVar1 = 0x73;
    }
    else {
      a_00 = BN_to_ASN1_INTEGER(a_01->pub_key,(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_0011faca;
      iVar1 = i2d_ASN1_INTEGER(a_00,&local_1c);
      ASN1_INTEGER_free(a_00);
      if (0 < iVar1) {
        aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,0x10,a,local_1c,iVar1);
        if (iVar1 != 0) {
          return 1;
        }
        goto LAB_0011faca;
      }
      iVar1 = 0x81;
    }
  }
  ERR_put_error(5,0x6d,0x41,"crypto/dh/dh_ameth.c",iVar1);
LAB_0011faca:
  CRYPTO_free(local_1c);
  ASN1_STRING_free(a);
  return 0;
}

