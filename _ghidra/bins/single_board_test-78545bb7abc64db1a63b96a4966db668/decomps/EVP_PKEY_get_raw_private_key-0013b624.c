
undefined4 EVP_PKEY_get_raw_private_key(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0xc) + 0x88);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(6,0xca,0x96,"crypto/evp/p_lib.c",0x125);
    return 0;
  }
  iVar1 = (*pcVar2)();
  if (iVar1 != 0) {
    return 1;
  }
  ERR_put_error(6,0xca,0xb6,"crypto/evp/p_lib.c",0x12a);
  return 0;
}

