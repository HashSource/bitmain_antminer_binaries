
float cal_avg_hashrate(int param_1,uint param_2)

{
  time_t tVar1;
  double dVar2;
  
  tVar1 = time((time_t *)0x0);
  dVar2 = pow(2.0,(double)g_ticket_mask);
  return (float)((dVar2 * (double)param_2) / (double)(uint)(tVar1 - param_1));
}

