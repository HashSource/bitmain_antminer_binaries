
void sasl_digest_md5_to_ascii(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    curl_msnprintf(param_2,3,DAT_0005526c,*puVar1);
    param_2 = param_2 + 2;
  } while (iVar2 != 0x10);
  return;
}

