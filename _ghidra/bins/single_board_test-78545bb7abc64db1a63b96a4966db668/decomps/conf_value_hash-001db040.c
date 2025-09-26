
uint conf_value_hash(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = OPENSSL_LH_strhash(*param_1);
  uVar2 = OPENSSL_LH_strhash(param_1[1]);
  return uVar2 ^ iVar1 << 2;
}

