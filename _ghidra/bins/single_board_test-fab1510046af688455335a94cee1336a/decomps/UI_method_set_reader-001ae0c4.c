
int UI_method_set_reader(UI_METHOD *method,reader *reader)

{
  if (method != (UI_METHOD *)0x0) {
    *(reader **)(method + 0x10) = reader;
    return 0;
  }
  return -1;
}

