
undefined4 * curl_version(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int iVar8;
  
  puVar1 = DAT_00048210;
  if (*(char *)(DAT_00048210 + 0x32) != '\0') {
    return DAT_00048210;
  }
  iVar8 = 0xba;
  uVar4 = DAT_00048214[1];
  uVar5 = DAT_00048214[2];
  uVar6 = DAT_00048214[3];
  *DAT_00048210 = *DAT_00048214;
  puVar1[1] = uVar4;
  puVar1[2] = uVar5;
  *(short *)(puVar1 + 3) = (short)uVar6;
  puVar7 = (undefined *)((int)puVar1 + 0xe);
  *puVar7 = (char)((uint)uVar6 >> 0x10);
  iVar2 = Curl_ssl_version((int)puVar1 + 0xf,0xb9);
  if (iVar2 != 0) {
    iVar8 = 0xb9 - iVar2;
    puVar7 = puVar7 + iVar2 + 1;
    *(undefined *)((int)puVar1 + 0xe) = 0x20;
  }
  uVar4 = zlibVersion();
  curl_msnprintf(puVar7,iVar8,DAT_00048218,uVar4);
  puVar3 = DAT_00048210;
  *(undefined *)(puVar1 + 0x32) = 1;
  return puVar3;
}

