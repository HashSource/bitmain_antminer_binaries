
void us_to_timeval(undefined4 *param_1)

{
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  undefined4 local_18;
  
  lldiv((lldiv_t *)&stack0xffffffe0,1000000,CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
  *param_1 = in_stack_ffffffe0;
  param_1[1] = local_18;
  return;
}

