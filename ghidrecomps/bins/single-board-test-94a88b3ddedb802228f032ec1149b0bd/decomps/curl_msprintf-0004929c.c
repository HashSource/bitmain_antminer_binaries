
void curl_msprintf(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *local_24 [2];
  undefined4 *local_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_1c = &uStack_8;
  local_24[0] = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  dprintf_formatf(local_24,0x4854d,param_2,local_1c);
  *local_24[0] = 0;
  return;
}

