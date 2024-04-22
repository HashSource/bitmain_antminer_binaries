
/* WARNING: Unknown calling convention */

double tsince_update(void)

{
  double dVar1;
  timeval now;
  
  cgtime(&now);
  dVar1 = tdiff(&now,DAT_0001ee58);
  return dVar1;
}

