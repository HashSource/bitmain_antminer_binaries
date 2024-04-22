
void __suspend_stratum(int param_1)

{
  if (*(undefined **)(param_1 + 0x250) != (undefined *)0x0) {
    **(undefined **)(param_1 + 0x250) = 0;
  }
  *(undefined *)(param_1 + 0x283) = 0;
  *(undefined *)(param_1 + 0x281) = 0;
  if (*(int *)(param_1 + 0x24c) != 0) {
    close(*(int *)(param_1 + 0x24c));
  }
  *(undefined4 *)(param_1 + 0x24c) = 0;
  return;
}

