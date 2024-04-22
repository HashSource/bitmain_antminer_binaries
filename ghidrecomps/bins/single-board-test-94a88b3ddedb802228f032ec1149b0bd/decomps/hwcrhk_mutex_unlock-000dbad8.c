
void hwcrhk_mutex_unlock(int *param_1)

{
  CRYPTO_lock(10,*param_1,"e_chil.c",0x48c);
  return;
}

