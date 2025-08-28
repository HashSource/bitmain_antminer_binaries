
undefined4 * curl_version(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (initialized_22785 != '\0') {
    return &version_22786;
  }
  iVar4 = 0xba;
  version_22786 = 0x6362696c;
  DAT_003b0fd8 = 0x2f6c7275;
  DAT_003b0fdc = 0x38342e37;
  DAT_003b0fe0 = 0x302e;
  puVar3 = &DAT_003b0fe2;
  DAT_003b0fe2 = 0;
  iVar1 = Curl_ssl_version(&DAT_003b0fe3,0xb9);
  if (iVar1 != 0) {
    iVar4 = 0xb9 - iVar1;
    puVar3 = &DAT_003b0fe3 + iVar1;
    DAT_003b0fe2 = 0x20;
  }
  uVar2 = zlibVersion();
  curl_msnprintf(puVar3,iVar4," zlib/%s",uVar2);
  initialized_22785 = 1;
  return &version_22786;
}

