
undefined4 get_asic_num_per_vol_domain(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  uVar1 = get_asic_num_per_chain();
  uVar2 = get_domain_num();
  uVar1 = __aeabi_idiv(uVar1,uVar2,extraout_r2,uVar2,in_r3);
  return uVar1;
}

