
int EVP_DigestFinalXOF(EVP_MD_CTX *param_1,uchar *param_2,int param_3)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  if ((((int)(param_1->digest->flags << 0x1e) < 0) && (-1 < param_3)) &&
     (iVar1 = (*(code *)param_1->digest->required_pkey_type[0])(param_1,3,param_3,0), iVar1 != 0)) {
    iVar1 = (*param_1->digest->final)(param_1,param_2);
    pEVar2 = param_1->digest;
    if (pEVar2->cleanup != (_func_1224 *)0x0) {
      (*pEVar2->cleanup)(param_1);
      EVP_MD_CTX_set_flags(param_1,2);
      pEVar2 = param_1->digest;
    }
    OPENSSL_cleanse(param_1->md_data,(size_t)pEVar2->verify);
    return iVar1;
  }
  ERR_put_error(6,0xae,0xb2,"crypto/evp/digest.c",0xd2);
  return 0;
}

