
undefined4 pkey_tls1_prf_ctrl_str(int param_1,char *param_2,char *param_3)

{
  EVP_MD *pEVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(0x34,100,0x66,"crypto/kdf/tls1_prf.c",0x61);
    uVar2 = 0;
  }
  else {
    if (((*param_2 != 'm') || (param_2[1] != 'd')) || (param_2[2] != '\0')) {
      iVar3 = strcmp(param_2,"secret");
      if (iVar3 == 0) {
        uVar2 = 0x1001;
      }
      else {
        iVar3 = strcmp(param_2,"hexsecret");
        if (iVar3 == 0) {
          uVar2 = EVP_PKEY_CTX_hex2ctrl(param_1,0x1001,param_3);
          return uVar2;
        }
        iVar3 = strcmp(param_2,"seed");
        if (iVar3 != 0) {
          iVar3 = strcmp(param_2,"hexseed");
          if (iVar3 != 0) {
            ERR_put_error(0x34,100,0x67,"crypto/kdf/tls1_prf.c",0x78);
            return 0xfffffffe;
          }
          uVar2 = EVP_PKEY_CTX_hex2ctrl(param_1,0x1002,param_3);
          return uVar2;
        }
        uVar2 = 0x1002;
      }
      uVar2 = EVP_PKEY_CTX_str2ctrl(param_1,uVar2,param_3);
      return uVar2;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x14);
    pEVar1 = EVP_get_digestbyname(param_3);
    if (pEVar1 == (EVP_MD *)0x0) {
      ERR_put_error(0x34,100,100,"crypto/kdf/tls1_prf.c",0x69);
      uVar2 = 0;
    }
    else {
      *puVar4 = pEVar1;
      uVar2 = 1;
    }
  }
  return uVar2;
}

