
int pop3_done(int *param_1,int param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(*param_1 + 0x14c);
  if (puVar2 != (undefined4 *)0x0) {
    if (param_2 != 0) {
      *(undefined1 *)((int)param_1 + 0x1ed) = 1;
    }
    (*Curl_cfree)(puVar2[1]);
    pcVar1 = Curl_cfree;
    puVar2[1] = 0;
    (*pcVar1)(puVar2[2]);
    puVar2[2] = 0;
    *puVar2 = 0;
    return param_2;
  }
  return 0;
}

