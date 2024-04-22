
float cal_rt_hashrate(int param_1,int param_2)

{
  uint uVar1;
  double dVar2;
  float fVar3;
  undefined4 in_stack_fffffff0;
  
  this_time_8855 = time((time_t *)0x0);
  fVar3 = DAT_0001b864;
  if ((param_2 <= this_time_8855 - last_time_8854) &&
     (uVar1 = param_1 - last_time_nonces_8856, last_time_8854 = this_time_8855,
     last_time_nonces_8856 = param_1, this_time_8855 != 0)) {
    dVar2 = pow((double)CONCAT44(param_1,param_2),(double)CONCAT44(uVar1,in_stack_fffffff0));
    dVar2 = pow((double)CONCAT44(param_1,param_2),(double)CONCAT44(uVar1,(int)(longlong)dVar2));
    fVar3 = (float)((dVar2 * (double)(ulonglong)uVar1) / (double)(longlong)param_2);
  }
  return fVar3;
}

