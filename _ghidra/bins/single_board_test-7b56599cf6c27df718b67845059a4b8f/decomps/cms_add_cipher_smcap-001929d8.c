
int cms_add_cipher_smcap(stack_st_X509_ALGOR **param_1,int param_2,int param_3)

{
  char *name;
  EVP_CIPHER *pEVar1;
  int iVar2;
  
  name = OBJ_nid2sn(param_2);
  pEVar1 = EVP_get_cipherbyname(name);
  if (pEVar1 != (EVP_CIPHER *)0x0) {
    iVar2 = CMS_add_simple_smimecap(param_1,param_2,param_3);
    return iVar2;
  }
  return 1;
}

