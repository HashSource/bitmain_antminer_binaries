
void ms_to_timespec(undefined4 *param_1)

{
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  int local_18;
  
  lldiv((lldiv_t *)&stack0xffffffe0,1000,CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
  *param_1 = in_stack_ffffffe0;
  param_1[1] = local_18 * 1000000;
  return;
}

