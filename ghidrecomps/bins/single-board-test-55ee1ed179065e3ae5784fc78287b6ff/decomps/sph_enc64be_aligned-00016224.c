
void sph_enc64be_aligned(undefined8 *param_1,undefined4 param_2,undefined4 param_3,
                        undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = sph_bswap64(param_3,param_4);
  *param_1 = uVar1;
  return;
}

