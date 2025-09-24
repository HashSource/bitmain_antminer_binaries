
undefined4 EVP_PKEY_get_raw_public_key(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0xc) + 0x8c);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(6,0xcb,0x96,"crypto/evp/p_lib.c",0x136);
    return 0;
  }
  iVar1 = (*pcVar2)();
  if (iVar1 != 0) {
    return 1;
  }
  ERR_put_error(6,0xcb,0xb6,"crypto/evp/p_lib.c",0x13b);
  return 0;
}

