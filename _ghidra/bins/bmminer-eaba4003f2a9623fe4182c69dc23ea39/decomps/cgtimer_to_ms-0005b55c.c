
int cgtimer_to_ms(cgtimer_t *cgt)

{
  int iVar1;
  cgtimer_t *cgt_local;
  
  iVar1 = timespec_to_ms(cgt);
  return iVar1;
}

