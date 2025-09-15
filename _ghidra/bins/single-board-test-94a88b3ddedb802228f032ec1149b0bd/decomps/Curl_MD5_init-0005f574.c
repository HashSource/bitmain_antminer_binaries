
int * Curl_MD5_init(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*Curl_cmalloc)(8);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*Curl_cmalloc)(param_1[3]);
    piVar1[1] = iVar2;
    if (iVar2 == 0) {
      (*Curl_cfree)(piVar1);
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = (int)param_1;
      (*(code *)*param_1)();
    }
  }
  return piVar1;
}

