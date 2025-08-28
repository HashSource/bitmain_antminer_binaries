
void sasl_digest_md5_to_ascii(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined1 *)(param_1 + iVar2);
    iVar2 = iVar2 + 1;
    curl_msnprintf(param_2,3,&DAT_001397a8,*puVar1);
    param_2 = param_2 + 2;
  } while (iVar2 != 0x10);
  return;
}

