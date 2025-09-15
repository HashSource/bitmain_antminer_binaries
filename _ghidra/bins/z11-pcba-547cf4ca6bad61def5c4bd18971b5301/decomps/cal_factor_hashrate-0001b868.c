
float cal_factor_hashrate(uint param_1,uint param_2)

{
  double dVar1;
  
  dVar1 = pow(2.0,(double)g_ticket_mask);
  return (float)((dVar1 * (double)param_2) / (double)param_1);
}

