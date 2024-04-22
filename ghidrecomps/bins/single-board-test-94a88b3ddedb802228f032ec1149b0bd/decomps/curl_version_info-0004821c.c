
int curl_version_info(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_0004824c;
  iVar1 = DAT_00048248;
  if (*(char *)(DAT_00048248 + 0xc9) == '\0') {
    iVar4 = DAT_00048248 + 0xcc;
    Curl_ssl_version(iVar4,0x50);
    *(int *)(iVar2 + 0x14) = iVar4;
    uVar3 = zlibVersion();
    *(undefined4 *)(iVar2 + 0x1c) = uVar3;
    *(undefined *)(iVar1 + 0xc9) = 1;
  }
  return DAT_0004824c;
}

