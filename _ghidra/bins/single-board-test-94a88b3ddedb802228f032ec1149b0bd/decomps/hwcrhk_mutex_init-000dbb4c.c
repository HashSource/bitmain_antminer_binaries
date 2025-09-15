
int hwcrhk_mutex_init(uint *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = CRYPTO_get_new_dynlockid();
  *param_1 = uVar1;
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

