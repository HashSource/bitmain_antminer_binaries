
float cal_avg_hashrate(int param_1,uint param_2)

{
  time_t tVar1;
  uint uVar2;
  double dVar3;
  
  tVar1 = time((time_t *)0x0);
  uVar2 = tVar1 - param_1;
  dVar3 = pow((double)CONCAT44(param_1,param_2),(double)CONCAT44(tVar1,uVar2));
  return (float)((dVar3 * (double)(ulonglong)param_2) / (double)(ulonglong)uVar2);
}

