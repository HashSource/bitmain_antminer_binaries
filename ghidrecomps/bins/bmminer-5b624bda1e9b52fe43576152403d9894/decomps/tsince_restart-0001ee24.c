
/* WARNING: Unknown calling convention */

double tsince_restart(void)

{
  double dVar1;
  timeval now;
  
  cgtime(&now);
  dVar1 = tdiff(&now,&restart_tv_start);
  return dVar1;
}

