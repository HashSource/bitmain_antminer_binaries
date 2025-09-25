
undefined4
rsa_item_verify(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
               undefined4 param_5,EVP_PKEY *param_6)

{
  int iVar1;
  RSA_PSS_PARAMS *a;
  int iVar2;
  RSA_PSS_PARAMS *a_00;
  X509_ALGOR *pXVar3;
  EVP_PKEY_CTX *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  EVP_MD *local_20;
  EVP_MD *local_1c;
  
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_4);
  if (iVar1 != 0x390) {
    ERR_put_error(4,0x94,0x9b,"crypto/rsa/rsa_ameth.c",0x314);
    return 0xffffffff;
  }
  local_2c = (EVP_PKEY_CTX *)0x0;
  local_24 = 0;
  local_20 = (EVP_MD *)0x0;
  iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*param_4);
  if (iVar1 != 0x390) {
    ERR_put_error(4,0x9b,0x9b,"crypto/rsa/rsa_ameth.c",0x2a4);
    return 0xffffffff;
  }
  a = (RSA_PSS_PARAMS *)ASN1_TYPE_unpack_sequence(RSA_PSS_PARAMS_it,param_4[1]);
  a_00 = a;
  if ((a != (RSA_PSS_PARAMS *)0x0) && (pXVar3 = a->maskGenAlgorithm, pXVar3 != (X509_ALGOR *)0x0)) {
    iVar1 = OBJ_obj2nid(pXVar3->algorithm);
    if (iVar1 == 0x38f) {
      pXVar3 = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,pXVar3->parameter);
      a[1].hashAlgorithm = pXVar3;
      if (pXVar3 != (X509_ALGOR *)0x0) goto LAB_0014b28e;
    }
    else {
      a[1].hashAlgorithm = (X509_ALGOR *)0x0;
    }
    a_00 = (RSA_PSS_PARAMS *)0x0;
    RSA_PSS_PARAMS_free(a);
  }
LAB_0014b28e:
  iVar1 = rsa_pss_get_param(a_00,&local_20,&local_24,&local_28);
  if (iVar1 == 0) {
    ERR_put_error(4,0x9b,0x95,"crypto/rsa/rsa_ameth.c",0x2ab);
    goto LAB_0014b34e;
  }
  if (param_6 == (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_CTX_ctrl(local_2c,-1,0xf8,0xd,0,&local_1c);
    if (iVar1 < 1) goto LAB_0014b34e;
    iVar1 = EVP_MD_type(local_20);
    iVar2 = EVP_MD_type(local_1c);
    if (iVar1 != iVar2) {
      ERR_put_error(4,0x9b,0x9e,"crypto/rsa/rsa_ameth.c",0x2b8);
      goto LAB_0014b34e;
    }
  }
  else {
    iVar1 = EVP_DigestVerifyInit(param_1,&local_2c,local_20,(ENGINE *)0x0,param_6);
    if (iVar1 == 0) goto LAB_0014b34e;
  }
  iVar1 = RSA_pkey_ctx_ctrl(local_2c,0xffffffff,0x1001,6,0);
  if (((0 < iVar1) && (iVar1 = RSA_pkey_ctx_ctrl(local_2c,0x18,0x1002,local_28,0), 0 < iVar1)) &&
     (iVar1 = RSA_pkey_ctx_ctrl(local_2c,0x3f8,0x1005,0,local_24), 0 < iVar1)) {
    RSA_PSS_PARAMS_free(a_00);
    return 2;
  }
LAB_0014b34e:
  RSA_PSS_PARAMS_free(a_00);
  return 0xffffffff;
}

