
undefined4 pkey_poly1305_ctrl_str(undefined4 param_1,char *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0')) {
    uVar1 = EVP_PKEY_CTX_str2ctrl(param_1,6,param_3,param_4);
    return uVar1;
  }
  iVar2 = strcmp(param_2,"hexkey");
  if (iVar2 == 0) {
    uVar1 = EVP_PKEY_CTX_hex2ctrl(param_1,6,param_3,param_4);
    return uVar1;
  }
  return 0xfffffffe;
}

