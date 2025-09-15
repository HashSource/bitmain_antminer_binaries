
void Curl_strntoupper(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      if (bVar1 - 0x61 < 0x1a) {
        bVar1 = bVar1 - 0x20;
      }
      *param_1 = bVar1;
    } while ((*param_2 != 0) &&
            (param_3 = param_3 + -1, param_1 = param_1 + 1, param_2 = param_2 + 1, param_3 != 0));
  }
  return;
}

