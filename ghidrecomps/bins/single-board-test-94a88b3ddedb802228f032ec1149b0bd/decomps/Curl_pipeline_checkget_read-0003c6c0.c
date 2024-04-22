
int * Curl_pipeline_checkget_read(int param_1,int param_2)

{
  int *piVar1;
  
  if (*(char *)(param_2 + 0x205) != '\0') {
    return (int *)0x1;
  }
  piVar1 = (int *)0x0;
  if (((*(char *)(param_2 + 0x254) == '\0') &&
      (piVar1 = *(int **)(param_2 + 0x25c), piVar1 != (int *)0x0)) &&
     (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0)) {
    if (param_1 == *piVar1) {
      *(undefined *)(param_2 + 0x254) = 1;
      return (int *)0x1;
    }
    return (int *)0x0;
  }
  return piVar1;
}

