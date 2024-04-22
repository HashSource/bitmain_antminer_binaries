
bool Curl_sendpipe_head(int param_1,int param_2)

{
  int *piVar1;
  
  if (*(int ***)(param_2 + 600) == (int **)0x0) {
    return false;
  }
  piVar1 = **(int ***)(param_2 + 600);
  if (piVar1 != (int *)0x0) {
    return param_1 == *piVar1;
  }
  return false;
}

