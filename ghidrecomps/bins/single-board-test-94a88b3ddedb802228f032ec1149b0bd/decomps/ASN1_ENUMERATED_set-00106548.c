
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a,long v)

{
  uchar *puVar1;
  int extraout_r1;
  int iVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  uchar local_18 [8];
  
  puVar3 = (uchar *)a->length;
  a->type = 10;
  iVar2 = v;
  if ((int)puVar3 < 5) {
    if (a->data != (uchar *)0x0) {
      CRYPTO_free(a->data);
    }
    puVar1 = (uchar *)CRYPTO_malloc(5,DAT_00106604,0x51);
    a->data = puVar1;
    if (puVar1 == (uchar *)0x0) goto LAB_001065e4;
    *puVar1 = '\0';
    puVar1[1] = '\0';
    puVar1[2] = '\0';
    puVar3 = puVar1 + 4;
    puVar1[3] = '\0';
    *puVar3 = '\0';
    iVar2 = extraout_r1;
  }
  puVar1 = a->data;
  if (puVar1 == (uchar *)0x0) {
LAB_001065e4:
    ERR_put_error(0xd,0x70,0x41,DAT_00106604,0x55);
    return 0;
  }
  if (v < 0) {
    puVar3 = (uchar *)0x10a;
    iVar2 = -v;
  }
  if (v < 0) {
    a->type = (int)puVar3;
    v = iVar2;
  }
  else if (v == 0) goto LAB_001065dc;
  local_18[0] = (uchar)v;
  if (v >> 8 == 0) {
    uVar5 = 1;
LAB_001065fa:
    uVar5 = uVar5 - 1;
  }
  else {
    local_18[1] = (char)((uint)v >> 8);
    if (v >> 0x10 == 0) {
      uVar5 = 2;
      goto LAB_001065fa;
    }
    local_18[2] = (char)((uint)v >> 0x10);
    uVar5 = 3;
    if (v >> 0x18 == 0) goto LAB_001065fa;
    local_18[3] = (char)((uint)v >> 0x18);
  }
  iVar2 = 0;
  uVar4 = uVar5;
  while( true ) {
    puVar3 = local_18 + uVar4;
    uVar4 = uVar4 - 1;
    puVar1[iVar2] = *puVar3;
    iVar2 = iVar2 + 1;
    if ((int)uVar4 < 0) break;
    puVar1 = a->data;
  }
  v = (uVar5 & ~((int)uVar5 >> 0x1f)) + 1;
LAB_001065dc:
  a->length = v;
  return 1;
}

