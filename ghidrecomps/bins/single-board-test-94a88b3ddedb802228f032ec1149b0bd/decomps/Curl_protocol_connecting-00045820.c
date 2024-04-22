
undefined4 Curl_protocol_connecting(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  
  if ((param_1 != 0) &&
     (pcVar2 = *(code **)(*(int *)(param_1 + 0x218) + 0x18), pcVar2 != (code *)0x0)) {
    *param_2 = 0;
    uVar1 = (*pcVar2)();
    return uVar1;
  }
  *param_2 = 1;
  return 0;
}

