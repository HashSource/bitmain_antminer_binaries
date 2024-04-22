
int seed_from_timestamp_and_pid(uint32_t *seed)

{
  uint32_t uVar1;
  uint32_t *seed_local;
  
  uVar1 = time((time_t *)0x0);
  *seed = uVar1;
  return 0;
}

