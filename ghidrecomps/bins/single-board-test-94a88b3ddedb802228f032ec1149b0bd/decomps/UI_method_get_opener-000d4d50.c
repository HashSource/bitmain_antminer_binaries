
int UI_method_get_opener(UI *param_1)

{
  if (param_1 != (UI *)0x0) {
    param_1 = *(UI **)(param_1 + 4);
  }
  return (int)param_1;
}

