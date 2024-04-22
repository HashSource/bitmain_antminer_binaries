
int pkey_cmac_ctrl_str(int param_1,char *param_2,char *param_3)

{
  size_t keylen;
  int iVar1;
  uchar *key;
  EVP_CIPHER *cipher;
  size_t local_1c [2];
  
  if (param_3 != (char *)0x0) {
    if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0'))
    {
      keylen = strlen(param_3);
      if (-1 < (int)keylen) {
        iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),param_3,keylen,(EVP_CIPHER *)0x0,
                          (ENGINE *)0x0);
        if (iVar1 == 0) {
          return 0;
        }
        return 1;
      }
    }
    else {
      iVar1 = strcmp(param_2,DAT_000d85b8);
      if (iVar1 == 0) {
        cipher = EVP_get_cipherbyname(param_3);
        if (cipher != (EVP_CIPHER *)0x0) {
          iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),(void *)0x0,0,cipher,
                            *(ENGINE **)(param_1 + 4));
          if (iVar1 == 0) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar1 = strcmp(param_2,DAT_000d85bc);
        if (iVar1 != 0) {
          return -2;
        }
        key = string_to_hex(param_3,(long *)local_1c);
        if (key != (uchar *)0x0) {
          iVar1 = 0;
          if ((-1 < (int)local_1c[0]) &&
             (iVar1 = CMAC_Init(*(CMAC_CTX **)(param_1 + 0x14),key,local_1c[0],(EVP_CIPHER *)0x0,
                                (ENGINE *)0x0), iVar1 != 0)) {
            iVar1 = 1;
          }
          CRYPTO_free(key);
          return iVar1;
        }
      }
    }
  }
  return 0;
}

