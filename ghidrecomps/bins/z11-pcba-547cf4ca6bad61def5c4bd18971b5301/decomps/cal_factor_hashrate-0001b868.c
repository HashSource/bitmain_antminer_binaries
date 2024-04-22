
float cal_factor_hashrate(uint param_1,uint param_2)

{
  undefined4 unaff_r7;
  undefined4 in_lr;
  double dVar1;
  
  dVar1 = pow((double)CONCAT44(param_1,param_2),(double)CONCAT44(in_lr,unaff_r7));
  return (float)((dVar1 * (double)(ulonglong)param_2) / (double)(ulonglong)param_1);
}

