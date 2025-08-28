
void Curl_fileinfo_dtor(undefined4 param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 != 0) {
    (*Curl_cfree)(*(undefined4 *)(param_2 + 0x3c));
    pcVar1 = Curl_cfree;
    *(undefined4 *)(param_2 + 0x3c) = 0;
    (*pcVar1)(param_2);
  }
  return;
}

