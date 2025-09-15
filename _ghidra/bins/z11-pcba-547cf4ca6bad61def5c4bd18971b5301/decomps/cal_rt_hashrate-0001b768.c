
float cal_rt_hashrate(int param_1,int param_2)

{
  uint uVar1;
  double dVar2;
  float fVar3;
  
  this_time_8855 = time((time_t *)0x0);
  if (this_time_8855 - last_time_8854 < param_2) {
    fVar3 = 0.0;
  }
  else {
    uVar1 = param_1 - last_time_nonces_8856;
    last_time_8854 = this_time_8855;
    last_time_nonces_8856 = param_1;
    if (this_time_8855 == 0) {
      fVar3 = 0.0;
    }
    else {
      pow(2.0,(double)g_ticket_mask);
      dVar2 = pow(2.0,(double)g_ticket_mask);
      fVar3 = (float)((dVar2 * (double)uVar1) / (double)(longlong)param_2);
    }
  }
  return fVar3;
}

