
void ERR_load_strings(int lib,ERR_STRING_DATA *str)

{
  ERR_STRING_DATA *pEVar1;
  int extraout_r0;
  uint uVar2;
  ulong uVar3;
  
  ERR_load_ERR_strings();
  if (extraout_r0 == 0) {
    return;
  }
  uVar2 = str->error;
  pEVar1 = str + 1;
  while (uVar2 != 0) {
    pEVar1[-1].error = uVar2 | lib << 0x18;
    uVar2 = pEVar1->error;
    pEVar1 = pEVar1 + 1;
  }
  CRYPTO_THREAD_write_lock(err_string_lock);
  uVar3 = str->error;
  while (uVar3 != 0) {
    OPENSSL_LH_insert(int_error_hash,str);
    str = str + 1;
    uVar3 = str->error;
  }
  CRYPTO_THREAD_unlock(err_string_lock);
  return;
}

