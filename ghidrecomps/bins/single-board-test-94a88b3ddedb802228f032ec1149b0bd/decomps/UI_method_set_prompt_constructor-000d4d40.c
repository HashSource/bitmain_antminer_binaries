
int UI_method_set_prompt_constructor(UI_METHOD *method,prompt_constructor *prompt_constructor)

{
  if (method != (UI_METHOD *)0x0) {
    *(prompt_constructor **)(method + 0x18) = prompt_constructor;
    return 0;
  }
  return -1;
}

