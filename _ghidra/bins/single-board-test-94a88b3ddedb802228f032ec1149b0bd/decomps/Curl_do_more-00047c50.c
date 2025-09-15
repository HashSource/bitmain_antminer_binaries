
code * Curl_do_more(int param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 + 0x218);
  *param_2 = 0;
  pcVar2 = *(code **)(iVar1 + 0x10);
  if (((pcVar2 != (code *)0x0) && (pcVar2 = (code *)(*pcVar2)(), pcVar2 == (code *)0x0)) &&
     (*param_2 == 1)) {
    do_complete(param_1);
    return (code *)0x0;
  }
  return pcVar2;
}

