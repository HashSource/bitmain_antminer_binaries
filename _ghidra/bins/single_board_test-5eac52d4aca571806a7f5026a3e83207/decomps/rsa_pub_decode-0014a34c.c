
undefined4 rsa_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

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
  
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&puStack_30,&local_2c,&local_28,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  r = d2i_RSAPublicKey((RSA **)0x0,&puStack_30,local_2c);
  if (r == (RSA *)0x0) {
    ERR_put_error(4,0x8b,4,"crypto/rsa/rsa_ameth.c",0x69);
    return 0;
  }
  X509_ALGOR_get0(&local_24,&local_1c,&pvStack_20,local_28);
  iVar1 = OBJ_obj2nid(local_24);
  if ((iVar1 != 0x390) || (local_1c == -1)) goto LAB_0014a39e;
  if (local_1c != 0x10) {
    ERR_put_error(4,0xa4,0x95,"crypto/rsa/rsa_ameth.c",0x42);
    goto LAB_0014a3dc;
  }
  a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,local_28->parameter);
  if (a != (RSA_PSS_PARAMS *)0x0) {
    pXVar2 = a->maskGenAlgorithm;
    if (pXVar2 == (X509_ALGOR *)0x0) {
LAB_0014a424:
      (r->ex_data).dummy = (int)a;
LAB_0014a39e:
      iVar1 = EVP_PKEY_assign(param_1,*(int *)param_1->ameth,r);
      if (iVar1 == 0) {
        RSA_free(r);
        return 0;
      }
      return 1;
    }
    iVar1 = OBJ_obj2nid(pXVar2->algorithm);
    if (iVar1 == 0x38f) {
      pXVar2 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar2->parameter);
      a[1].hashAlgorithm = pXVar2;
      if (pXVar2 != (X509_ALGOR *)0x0) goto LAB_0014a424;
    }
    else {
      a[1].hashAlgorithm = (X509_ALGOR *)0x0;
    }
    RSA_PSS_PARAMS_free(a);
  }
  (r->ex_data).dummy = 0;
LAB_0014a3dc:
  RSA_free(r);
  return 0;
}

