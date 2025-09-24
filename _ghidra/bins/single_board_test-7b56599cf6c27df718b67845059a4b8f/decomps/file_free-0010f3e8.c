
undefined4 file_free(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    if ((*(int *)(param_1 + 0x10) != 0) && (*(FILE **)(param_1 + 0x24) != (FILE *)0x0)) {
      fclose(*(FILE **)(param_1 + 0x24));
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
    return 1;
  }
  return 1;
}

