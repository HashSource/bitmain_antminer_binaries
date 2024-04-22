
int * Curl_removeHandleFromPipeline(int param_1,int **param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (param_2 == (int **)0x0) {
    return (int *)0x0;
  }
  piVar1 = *param_2;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    do {
      if (*piVar1 == param_1) {
        Curl_llist_remove(param_2,piVar1,0,piVar1,param_4);
        return (int *)0x1;
      }
      piVar1 = (int *)piVar1[2];
    } while (piVar1 != (int *)0x0);
  }
  return piVar1;
}

