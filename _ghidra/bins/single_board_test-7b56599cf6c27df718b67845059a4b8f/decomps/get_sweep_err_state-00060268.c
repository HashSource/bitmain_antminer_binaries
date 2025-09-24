
void get_sweep_err_state(sweep_err_state *state)

{
  sweep_err_state *state_local;
  
  if (state != (sweep_err_state *)0x0) {
    memcpy(state,&sweep_err,8);
  }
  return;
}

