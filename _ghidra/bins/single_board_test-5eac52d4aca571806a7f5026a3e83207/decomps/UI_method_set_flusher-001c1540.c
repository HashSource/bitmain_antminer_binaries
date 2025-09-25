
int UI_method_set_flusher(UI_METHOD *method,flusher *flusher)

{
  if (method != (UI_METHOD *)0x0) {
    *(flusher **)(method + 0xc) = flusher;
    return 0;
  }
  return -1;
}

