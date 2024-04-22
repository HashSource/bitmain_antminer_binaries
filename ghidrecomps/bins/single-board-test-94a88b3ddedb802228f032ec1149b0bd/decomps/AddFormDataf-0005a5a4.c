
void AddFormDataf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_1020 [4100];
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  curl_mvsnprintf(auStack_1020,0x1000,param_3,&uStack_4);
  AddFormData(param_1,0,auStack_1020);
  return;
}

