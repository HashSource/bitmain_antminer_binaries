
void cgsleep_us_r(int *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  timespec local_10;
  
  us_to_timespec(&local_10);
  iVar2 = param_1[1] + local_10.tv_nsec;
  iVar1 = *param_1 + local_10.tv_sec;
  local_10.tv_nsec = iVar2;
  local_10.tv_sec = iVar1;
  if (iVar2 < 1000000000) {
    for (; local_10.tv_nsec < 0; local_10.tv_nsec = local_10.tv_nsec + 1000000000) {
      local_10.tv_sec = local_10.tv_sec + -1;
    }
  }
  else {
    local_10.tv_sec = iVar1 + 1;
    local_10.tv_nsec = iVar2 + -1000000000;
    bVar4 = SBORROW4(local_10.tv_nsec,999999999);
    bVar3 = local_10.tv_nsec != 999999999;
    if (999999999 < local_10.tv_nsec) {
      local_10.tv_sec = iVar1 + 2;
      local_10.tv_nsec = -2000000000;
    }
    if (bVar3 && iVar2 + -1999999999 < 0 == bVar4) {
      local_10.tv_nsec = local_10.tv_nsec + iVar2;
    }
  }
  do {
    iVar1 = clock_nanosleep(1,1,&local_10,(timespec *)0x0);
  } while (iVar1 == 4);
  return;
}

