
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  char acStack_e8 [64];
  char acStack_a8 [64];
  uint local_68 [17];
  
  iVar1 = DAT_000ad428;
  iVar5 = *(int *)(DAT_000ad428 + 0x2f4);
  uVar4 = (e << 8) >> 0x14;
  if (iVar5 == 0) {
    CRYPTO_lock(9,1,DAT_000ad43c,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad440;
    }
    CRYPTO_lock(10,1,DAT_000ad43c,0x12a);
    iVar5 = *(int *)(iVar1 + 0x2f4);
  }
  local_68[0] = e & 0xff000000;
  iVar2 = (**(code **)(iVar5 + 8))(local_68);
  iVar5 = DAT_000ad428;
  if (iVar2 == 0) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = *(char **)(iVar2 + 4);
  }
  iVar2 = *(int *)(iVar1 + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad43c,0x127);
    if (*(int *)(iVar5 + 0x2f4) == 0) {
      *(undefined4 *)(iVar5 + 0x2f4) = DAT_000ad440;
    }
    CRYPTO_lock(10,1,DAT_000ad43c,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  local_68[0] = e & 0xff000000 | uVar4 << 0xc;
  iVar2 = (**(code **)(iVar2 + 8))(local_68);
  iVar5 = DAT_000ad428;
  if (iVar2 == 0) {
    pcVar8 = (char *)0x0;
  }
  else {
    pcVar8 = *(char **)(iVar2 + 4);
  }
  iVar2 = *(int *)(iVar1 + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad43c,0x127);
    if (*(int *)(iVar5 + 0x2f4) == 0) {
      *(undefined4 *)(iVar5 + 0x2f4) = DAT_000ad440;
    }
    CRYPTO_lock(10,1,DAT_000ad43c,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  iVar1 = DAT_000ad428;
  local_68[0] = e & 0xff000fff;
  iVar5 = (**(code **)(iVar2 + 8))(local_68);
  if ((iVar5 == 0) &&
     (local_68[0] = e & 0xfff, iVar5 = (**(code **)(*(int *)(iVar1 + 0x2f4) + 8))(local_68),
     iVar5 == 0)) {
    puVar6 = (uint *)0x0;
    if (pcVar7 == (char *)0x0) {
      puVar6 = (uint *)0x0;
LAB_000ad31c:
      BIO_snprintf(acStack_e8,0x40,DAT_000ad430,e >> 0x18);
    }
  }
  else {
    puVar6 = *(uint **)(iVar5 + 4);
    if (pcVar7 == (char *)0x0) goto LAB_000ad31c;
  }
  if (pcVar8 == (char *)0x0) {
    BIO_snprintf(acStack_a8,0x40,DAT_000ad434,uVar4);
  }
  if (puVar6 == (uint *)0x0) {
    BIO_snprintf((char *)local_68,0x40,DAT_000ad438,e & 0xfff);
  }
  if (pcVar7 == (char *)0x0) {
    pcVar7 = acStack_e8;
  }
  if (pcVar8 == (char *)0x0) {
    pcVar8 = acStack_a8;
  }
  if (puVar6 == (uint *)0x0) {
    puVar6 = local_68;
  }
  BIO_snprintf(buf,len,DAT_000ad42c,e,pcVar7,pcVar8,puVar6);
  sVar3 = strlen(buf);
  if (sVar3 != len - 1) {
    return;
  }
  if (len < 5) {
    return;
  }
  pcVar7 = strchr(buf,0x3a);
  if (pcVar7 == (char *)0x0) {
    pcVar8 = buf + (len - 5);
LAB_000ad2b4:
    pcVar7 = pcVar8;
    *pcVar7 = ':';
  }
  else {
    pcVar8 = buf + (len - 5);
    if (buf + (len - 5) < pcVar7) goto LAB_000ad2b4;
  }
  pcVar7 = strchr(pcVar7 + 1,0x3a);
  if (pcVar7 == (char *)0x0) {
    pcVar8 = buf + (len - 4);
LAB_000ad2d0:
    pcVar7 = pcVar8;
    *pcVar7 = ':';
  }
  else {
    pcVar8 = buf + (len - 4);
    if (buf + (len - 4) < pcVar7) goto LAB_000ad2d0;
  }
  pcVar7 = strchr(pcVar7 + 1,0x3a);
  if (pcVar7 == (char *)0x0) {
    pcVar8 = buf + (len - 3);
  }
  else {
    pcVar8 = buf + (len - 3);
    if (pcVar7 <= buf + (len - 3)) goto LAB_000ad2f2;
  }
  pcVar7 = pcVar8;
  *pcVar7 = ':';
LAB_000ad2f2:
  pcVar7 = strchr(pcVar7 + 1,0x3a);
  if ((pcVar7 == (char *)0x0) || (buf + (len - 2) < pcVar7)) {
    buf[len - 2] = ':';
  }
  return;
}

