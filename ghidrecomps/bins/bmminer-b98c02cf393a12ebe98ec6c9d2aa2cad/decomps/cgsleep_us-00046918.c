
void cgsleep_us(void)

{
  timespec tStack_18;
  
  clock_gettime(1,&tStack_18);
  cgsleep_us_r(&tStack_18);
  return;
}

