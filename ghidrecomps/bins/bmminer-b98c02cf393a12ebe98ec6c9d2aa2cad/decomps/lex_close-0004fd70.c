
void lex_close(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0x100) {
    strbuffer_close(param_1 + 0x28);
    return;
  }
  jsonp_free(*(undefined4 *)(param_1 + 0x40));
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  strbuffer_close(param_1 + 0x28);
  return;
}

