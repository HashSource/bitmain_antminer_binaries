
/* WARNING: Unknown calling convention */

uint32_t generate_seed(void)

{
  uint32_t seed;
  int done;
  
  done = 0;
  seed_from_timestamp_and_pid(&seed);
  if (seed == 0) {
    seed = 1;
  }
  return seed;
}

