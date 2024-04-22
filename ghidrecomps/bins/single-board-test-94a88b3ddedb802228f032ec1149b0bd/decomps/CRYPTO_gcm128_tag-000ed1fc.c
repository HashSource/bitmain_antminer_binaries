
void CRYPTO_gcm128_tag(int param_1,undefined4 param_2)

{
  CRYPTO_gcm128_finish(param_1,0,0);
  (*(code *)PTR_memcpy_00194250)(param_2,param_1 + 0x40);
  return;
}

