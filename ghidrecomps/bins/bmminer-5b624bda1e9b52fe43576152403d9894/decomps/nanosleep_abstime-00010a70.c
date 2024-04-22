
/* WARNING: Unknown calling convention */
/* Local variable ret:int[r0:4] conflicts with parameter, skipped. */

void nanosleep_abstime(timespec *ts_end)

{
  int iVar1;
  
  do {
    iVar1 = clock_nanosleep(1,1,(timespec *)ts_end,(timespec *)0x0);
  } while (iVar1 == 4);
  return;
}

