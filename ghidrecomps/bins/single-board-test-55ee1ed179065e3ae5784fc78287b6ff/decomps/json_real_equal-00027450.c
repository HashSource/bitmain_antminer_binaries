
bool json_real_equal(undefined4 param_1,undefined4 param_2)

{
  double dVar1;
  double dVar2;
  
  dVar1 = (double)json_real_value(param_1);
  dVar2 = (double)json_real_value(param_2);
  return dVar1 == dVar2;
}

