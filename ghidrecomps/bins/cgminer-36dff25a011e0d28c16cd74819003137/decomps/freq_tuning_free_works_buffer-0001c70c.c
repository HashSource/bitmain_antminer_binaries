
/* WARNING: Unknown calling convention */

void freq_tuning_free_works_buffer(void)

{
  int asic;
  
  for (asic = 0; asic < 0x30; asic = asic + 1) {
    if (g_works[asic] != (freq_tuning_work *)0x0) {
      free(g_works[asic]);
      g_works[asic] = (freq_tuning_work *)0x0;
    }
  }
  return;
}

