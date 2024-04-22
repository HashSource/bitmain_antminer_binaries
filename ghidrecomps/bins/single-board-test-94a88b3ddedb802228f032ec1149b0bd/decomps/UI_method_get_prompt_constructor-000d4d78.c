
char * UI_method_get_prompt_constructor(UI *param_1,char *param_2,char *param_3)

{
  if (param_1 != (UI *)0x0) {
    param_1 = *(UI **)(param_1 + 0x18);
  }
  return (char *)param_1;
}

