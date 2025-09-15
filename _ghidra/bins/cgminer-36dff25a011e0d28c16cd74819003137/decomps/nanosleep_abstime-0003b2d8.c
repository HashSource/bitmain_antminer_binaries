
void nanosleep_abstime(timespec *ts_end)

{
  int iVar1;
  timespec *ts_end_local;
  int ret;
  
  do {
    iVar1 = clock_nanosleep(1,1,(timespec *)ts_end,(timespec *)0x0);
  } while (iVar1 == 4);
  return;
}

