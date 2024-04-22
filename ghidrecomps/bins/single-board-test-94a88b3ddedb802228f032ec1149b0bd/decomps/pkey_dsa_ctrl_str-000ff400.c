
int pkey_dsa_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  EVP_MD *p2;
  long lVar2;
  
  iVar1 = strcmp(param_2,DAT_000ff490);
  if (iVar1 == 0) {
    lVar2 = strtol(param_3,(char **)0x0,10);
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x74,2,0x1001,lVar2,(void *)0x0);
  }
  else {
    iVar1 = strcmp(param_2,DAT_000ff494);
    if (iVar1 == 0) {
      lVar2 = strtol(param_3,(char **)0x0,10);
      iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x74,2,0x1002,lVar2,(void *)0x0);
    }
    else {
      iVar1 = strcmp(param_2,DAT_000ff498);
      if (iVar1 == 0) {
        p2 = EVP_get_digestbyname(param_3);
        iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x74,2,0x1003,0,p2);
      }
      else {
        iVar1 = -2;
      }
    }
  }
  return iVar1;
}

