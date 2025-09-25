
uint HMAC_size(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = EVP_MD_size((EVP_MD *)*param_1);
  return uVar1 & ~((int)uVar1 >> 0x1f);
}

