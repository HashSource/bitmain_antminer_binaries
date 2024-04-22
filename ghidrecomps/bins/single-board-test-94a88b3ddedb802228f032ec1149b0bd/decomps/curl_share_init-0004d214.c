
uint * curl_share_init(void)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  puVar1 = (uint *)(**DAT_0004d244)(1,0x3c);
  puVar3 = puVar1;
  if (puVar1 != (uint *)0x0) {
    *puVar1 = *puVar1 | 2;
    iVar2 = Curl_mk_dnscache(puVar1 + 5);
    if (iVar2 != 0) {
      puVar3 = (uint *)0x0;
      (**DAT_0004d248)(puVar1);
    }
  }
  return puVar3;
}

