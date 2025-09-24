
void set_sweep_err_state(int val,_Bool consumed)

{
  _Bool consumed_local;
  int val_local;
  
  sweep_err.err_val = val;
  sweep_err.consumed = consumed;
  return;
}

