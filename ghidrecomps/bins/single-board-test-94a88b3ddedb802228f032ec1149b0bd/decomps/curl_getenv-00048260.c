
byte * curl_getenv(char *param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)getenv(param_1);
  if ((pbVar1 != (byte *)0x0) && (pbVar1 = (byte *)(uint)*pbVar1, pbVar1 != (byte *)0x0)) {
    pbVar1 = (byte *)(**DAT_0004827c)();
    return pbVar1;
  }
  return pbVar1;
}

