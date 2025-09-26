
void dump_matrix_state(uint8_t *state)

{
  uint8_t *state_local;
  uint8_t state_pcba [216];
  int j;
  int i;
  
  puts("============matrix state==============");
  memset(state_pcba,0,0xd8);
  i = 0;
  while( true ) {
    if ((g_rt.config)->domains <= i) break;
    printf("%4d ",i);
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      if ((i & 1U) == 0) {
        state_pcba[j * (g_rt.config)->domains + i] =
             state[((i + 1) * (g_rt.config)->asics_in_domain + -1) - j];
      }
      else {
        state_pcba[j * (g_rt.config)->domains + i] = state[j + i * (g_rt.config)->asics_in_domain];
      }
    }
    i = i + 1;
  }
  putchar(10);
  for (i = 0; i < (g_rt.config)->asics_in_domain; i = i + 1) {
    for (j = 0; j < (g_rt.config)->domains; j = j + 1) {
      printf("%4d ",(uint)state_pcba[j + i * (g_rt.config)->domains]);
    }
    putchar(10);
  }
  puts("============matrix state==============");
  return;
}

