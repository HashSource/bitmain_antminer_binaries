
void sigpipe_restore(int param_1)

{
  if (*(char *)(param_1 + 0x8c) == '\0') {
    (*(code *)PTR_sigaction_001942d8)(0xd,param_1);
    return;
  }
  return;
}

