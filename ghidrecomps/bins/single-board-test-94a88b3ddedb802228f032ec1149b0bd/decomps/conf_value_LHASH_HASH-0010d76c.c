
uint conf_value_LHASH_HASH(char **param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = lh_strhash(*param_1);
  uVar2 = lh_strhash(param_1[1]);
  return uVar2 ^ uVar1 << 2;
}

