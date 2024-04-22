
undefined4
get_asic_num_per_vol_domain
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = get_asic_num_per_chain();
  uVar2 = get_domain_num();
  uVar1 = __aeabi_idiv(uVar1,uVar2,param_3,uVar2,param_4);
  return uVar1;
}

