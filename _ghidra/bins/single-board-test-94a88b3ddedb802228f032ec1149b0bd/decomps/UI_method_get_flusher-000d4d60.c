
int UI_method_get_flusher(UI *param_1)

{
  if (param_1 != (UI *)0x0) {
    param_1 = *(UI **)(param_1 + 0xc);
  }
  return (int)param_1;
}

