
bool json_real_equal(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  
  uVar1 = json_real_value(param_1);
  uVar2 = json_real_value(param_2);
  return (double)CONCAT44(extraout_s1,uVar1) == (double)CONCAT44(extraout_s1_00,uVar2);
}

