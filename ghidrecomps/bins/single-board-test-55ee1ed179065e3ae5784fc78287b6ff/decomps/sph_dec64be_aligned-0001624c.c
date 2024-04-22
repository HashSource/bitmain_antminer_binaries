
undefined4 sph_dec64be_aligned(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = sph_bswap64(*param_1,param_1[1]);
  return uVar1;
}

