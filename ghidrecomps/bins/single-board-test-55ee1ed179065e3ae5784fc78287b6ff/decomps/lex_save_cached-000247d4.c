
void lex_save_cached(int param_1)

{
  while (*(char *)(param_1 + *(int *)(param_1 + 0x10) + 8) != '\0') {
    lex_save(param_1,*(undefined *)(param_1 + *(int *)(param_1 + 0x10) + 8));
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  return;
}

