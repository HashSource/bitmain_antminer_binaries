
/* WARNING: Unknown calling convention */

double tsince_restart(void)

{
  double dVar1;
  timeval now;
  
  cgtime(&now);
  dVar1 = tdiff(&now,DAT_0001ee3c);
  return dVar1;
}

