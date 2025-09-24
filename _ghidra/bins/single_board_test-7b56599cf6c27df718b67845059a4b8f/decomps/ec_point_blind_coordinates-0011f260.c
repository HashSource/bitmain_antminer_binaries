
undefined4 ec_point_blind_coordinates(int *param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(*param_1 + 0xcc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011f268. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0xcc))();
    return uVar1;
  }
  return 1;
}

