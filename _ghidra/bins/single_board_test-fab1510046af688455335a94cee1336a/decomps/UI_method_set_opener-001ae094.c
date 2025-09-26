
int UI_method_set_opener(UI_METHOD *method,opener *opener)

{
  if (method != (UI_METHOD *)0x0) {
    *(opener **)(method + 4) = opener;
    return 0;
  }
  return -1;
}

