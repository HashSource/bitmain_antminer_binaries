
void sph_enc32be_aligned(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = sph_bswap32(param_2);
  *param_1 = uVar1;
  return;
}

