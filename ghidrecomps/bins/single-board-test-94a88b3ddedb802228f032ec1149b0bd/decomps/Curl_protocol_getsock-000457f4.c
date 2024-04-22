
undefined4 Curl_protocol_getsock(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0x218) + 0x20);
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)();
    return uVar1;
  }
  return 0;
}

