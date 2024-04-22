
void lex_close(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 0x100) {
    jsonp_free(*(undefined4 *)(param_1 + 0x38));
  }
  strbuffer_close(param_1 + 0x28);
  return;
}

