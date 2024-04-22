
void Curl_fileinfo_dtor(undefined4 param_1,int param_2)

{
  code **ppcVar1;
  code *pcVar2;
  
  ppcVar1 = DAT_0005e938;
  if (param_2 != 0) {
    (**DAT_0005e938)(*(undefined4 *)(param_2 + 0x3c));
    pcVar2 = *ppcVar1;
    *(undefined4 *)(param_2 + 0x3c) = 0;
    (*pcVar2)(param_2);
  }
  return;
}

