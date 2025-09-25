
int pkey_cmac_ctrl_str(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  EVP_CIPHER *cipher;
  
  if (param_3 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"cipher");
  if (iVar1 == 0) {
    cipher = EVP_get_cipherbyname(param_3);
    iVar1 = 0;
    if (cipher != (EVP_CIPHER *)0x0) {
      iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),(void *)0x0,0,cipher,
                        *(ENGINE **)(param_1 + 4));
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
  }
  else {
    if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0'))
    {
      iVar1 = EVP_PKEY_CTX_str2ctrl(param_1,6,param_3);
      return iVar1;
    }
    iVar1 = strcmp(param_2,"hexkey");
    if (iVar1 == 0) {
      iVar1 = EVP_PKEY_CTX_hex2ctrl(param_1,6,param_3);
      return iVar1;
    }
    iVar1 = -2;
  }
  return iVar1;
}

