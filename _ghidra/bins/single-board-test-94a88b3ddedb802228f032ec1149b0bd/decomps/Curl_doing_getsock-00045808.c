
code * Curl_doing_getsock(code *param_1)

{
  code *pcVar1;
  
  if ((param_1 != (code *)0x0) &&
     (param_1 = *(code **)(*(int *)(param_1 + 0x218) + 0x24), param_1 != (code *)0x0)) {
    pcVar1 = (code *)(*param_1)();
    return pcVar1;
  }
  return param_1;
}

