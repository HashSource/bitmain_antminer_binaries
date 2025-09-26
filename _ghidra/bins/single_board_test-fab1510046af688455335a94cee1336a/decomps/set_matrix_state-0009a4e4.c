
void set_matrix_state(uint8_t **state)

{
  uint8_t **state_local;
  int i;
  
  for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
    if ((g_rt.asic_stats.bad_asic_list[i] != false) && ((*state)[i] != '\0')) {
      (*state)[i] = '\0';
    }
  }
  dump_matrix_state(*state);
  return;
}

