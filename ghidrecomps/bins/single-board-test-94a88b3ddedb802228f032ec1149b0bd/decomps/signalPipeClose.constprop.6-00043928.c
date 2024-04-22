
void signalPipeClose_constprop_6(int **param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != (int **)0x0) {
    piVar1 = *param_1;
    while (piVar1 != (int *)0x0) {
      piVar2 = (int *)piVar1[2];
      *(undefined *)(*piVar1 + 0x867d) = 1;
      Curl_multi_handlePipeBreak();
      Curl_llist_remove(param_1,piVar1,0);
      piVar1 = piVar2;
    }
  }
  return;
}

