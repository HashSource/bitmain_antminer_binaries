
undefined4 pkey_siphash_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  void *pvVar4;
  
  if (param_3 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"digestsize");
  if (iVar1 != 0) {
    if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0'))
    {
      uVar2 = EVP_PKEY_CTX_str2ctrl(param_1,6,param_3);
      return uVar2;
    }
    iVar1 = strcmp(param_2,"hexkey");
    if (iVar1 == 0) {
      uVar2 = EVP_PKEY_CTX_hex2ctrl(param_1,6,param_3);
      return uVar2;
    }
    return 0xfffffffe;
  }
  lVar3 = strtol(param_3,(char **)0x0,10);
  pvVar4 = EVP_PKEY_CTX_get_data(param_1);
  uVar2 = SipHash_set_hash_size((int)pvVar4 + 0x10,lVar3);
  return uVar2;
}

