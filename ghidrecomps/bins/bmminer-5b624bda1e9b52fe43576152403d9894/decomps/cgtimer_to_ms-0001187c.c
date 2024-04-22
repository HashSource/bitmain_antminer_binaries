
/* WARNING: Unknown calling convention */

int cgtimer_to_ms(cgtimer_t *cgt)

{
  return cgt->tv_sec * 1000 + cgt->tv_nsec / 1000000;
}

