
int EVP_PKEY_CTX_md(EVP_PKEY_CTX *param_1,int param_2,int param_3,char *param_4)

{
  EVP_MD *p2;
  int iVar1;
  
  if ((param_4 != (char *)0x0) && (p2 = EVP_get_digestbyname(param_4), p2 != (EVP_MD *)0x0)) {
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,-1,param_2,param_3,0,p2);
    return iVar1;
  }
  ERR_put_error(6,0xa8,0x98,"crypto/evp/pmeth_lib.c",0x1c5);
  return 0;
}

