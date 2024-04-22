
/* WARNING: Unknown calling convention */

double tsince_update(void)

{
  double dVar1;
  timeval now;
  
  cgtime(&now);
  dVar1 = tdiff(&now,&update_tv_start);
  return dVar1;
}

