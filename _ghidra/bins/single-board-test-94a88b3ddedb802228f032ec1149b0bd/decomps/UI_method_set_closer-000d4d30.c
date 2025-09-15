
int UI_method_set_closer(UI_METHOD *method,closer *closer)

{
  if (method != (UI_METHOD *)0x0) {
    *(closer **)(method + 0x14) = closer;
    return 0;
  }
  return -1;
}

