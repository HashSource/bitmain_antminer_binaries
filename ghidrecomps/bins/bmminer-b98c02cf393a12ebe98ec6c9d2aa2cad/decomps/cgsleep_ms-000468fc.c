
void cgsleep_ms(undefined4 param_1)

{
  timespec tStack_10;
  
  clock_gettime(1,&tStack_10);
  cgsleep_ms_r(&tStack_10,param_1);
  return;
}

