
undefined4 rsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  RSA *r;
  RSA_PSS_PARAMS *a;
  X509_ALGOR *pXVar2;
  uchar *puStack_30;
  long local_2c;
  X509_ALGOR *local_28;
  ASN1_OBJECT *local_24;
  void *pvStack_20;
  int local_1c;
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&puStack_30,&local_2c,&local_28,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  r = d2i_RSAPrivateKey((RSA **)0x0,&puStack_30,local_2c);
  if (r == (RSA *)0x0) {
    ERR_put_error(4,0x96,4,"crypto/rsa/rsa_ameth.c",0xc0);
    return 0;
  }
  X509_ALGOR_get0(&local_24,&local_1c,&pvStack_20,local_28);
  iVar1 = OBJ_obj2nid(local_24);
  if ((iVar1 != 0x390) || (local_1c == -1)) goto LAB_0014e91e;
  if (local_1c != 0x10) {
    ERR_put_error(4,0xa4,0x95,"crypto/rsa/rsa_ameth.c",0x42);
    goto LAB_0014e94e;
  }
  a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,local_28->parameter);
  if (a != (RSA_PSS_PARAMS *)0x0) {
    pXVar2 = a->maskGenAlgorithm;
    if (pXVar2 == (X509_ALGOR *)0x0) {
LAB_0014e994:
      (r->ex_data).dummy = (int)a;
LAB_0014e91e:
      EVP_PKEY_assign(param_1,*(int *)param_1->ameth,r);
      return 1;
    }
    iVar1 = OBJ_obj2nid(pXVar2->algorithm);
    if (iVar1 == 0x38f) {
      pXVar2 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar2->parameter);
      a[1].hashAlgorithm = pXVar2;
      if (pXVar2 != (X509_ALGOR *)0x0) goto LAB_0014e994;
    }
    else {
      a[1].hashAlgorithm = (X509_ALGOR *)0x0;
    }
    RSA_PSS_PARAMS_free(a);
  }
  (r->ex_data).dummy = 0;
LAB_0014e94e:
  RSA_free(r);
  return 0;
}

