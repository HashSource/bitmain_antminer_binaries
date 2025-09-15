
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  char acStack_e8 [64];
  char acStack_a8 [64];
  uint local_68 [17];
  
  uVar4 = (e << 8) >> 0x14;
  uVar3 = e & 0xfff;
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  uVar8 = (e >> 0x18) << 0x18;
  local_68[0] = uVar8;
  iVar1 = (*(code *)err_fns[2])(local_68);
  if (iVar1 == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6 = *(char **)(iVar1 + 4);
  }
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_68[0] = uVar8 | uVar4 << 0xc;
  iVar1 = (*(code *)err_fns[2])(local_68);
  if (iVar1 == 0) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = *(char **)(iVar1 + 4);
  }
  if (err_fns == (undefined **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined **)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_68[0] = uVar8 | uVar3;
  iVar1 = (*(code *)err_fns[2])(local_68);
  if ((iVar1 == 0) && (local_68[0] = uVar3, iVar1 = (*(code *)err_fns[2])(local_68), iVar1 == 0)) {
    puVar5 = (uint *)0x0;
    if (pcVar6 == (char *)0x0) {
      puVar5 = (uint *)0x0;
LAB_000ad31c:
      BIO_snprintf(acStack_e8,0x40,"lib(%lu)",e >> 0x18);
    }
  }
  else {
    puVar5 = *(uint **)(iVar1 + 4);
    if (pcVar6 == (char *)0x0) goto LAB_000ad31c;
  }
  if (pcVar7 == (char *)0x0) {
    BIO_snprintf(acStack_a8,0x40,"func(%lu)",uVar4);
  }
  if (puVar5 == (uint *)0x0) {
    BIO_snprintf((char *)local_68,0x40,"reason(%lu)",uVar3);
  }
  if (pcVar6 == (char *)0x0) {
    pcVar6 = acStack_e8;
  }
  if (pcVar7 == (char *)0x0) {
    pcVar7 = acStack_a8;
  }
  if (puVar5 == (uint *)0x0) {
    puVar5 = local_68;
  }
  BIO_snprintf(buf,len,"error:%08lX:%s:%s:%s",e,pcVar6,pcVar7,puVar5);
  sVar2 = strlen(buf);
  if (sVar2 != len - 1) {
    return;
  }
  if (len < 5) {
    return;
  }
  pcVar6 = strchr(buf,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar7 = buf + (len - 5);
LAB_000ad2b4:
    pcVar6 = pcVar7;
    *pcVar6 = ':';
  }
  else {
    pcVar7 = buf + (len - 5);
    if (buf + (len - 5) < pcVar6) goto LAB_000ad2b4;
  }
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar7 = buf + (len - 4);
LAB_000ad2d0:
    pcVar6 = pcVar7;
    *pcVar6 = ':';
  }
  else {
    pcVar7 = buf + (len - 4);
    if (buf + (len - 4) < pcVar6) goto LAB_000ad2d0;
  }
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar7 = buf + (len - 3);
  }
  else {
    pcVar7 = buf + (len - 3);
    if (pcVar6 <= buf + (len - 3)) goto LAB_000ad2f2;
  }
  pcVar6 = pcVar7;
  *pcVar6 = ':';
LAB_000ad2f2:
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if ((pcVar6 == (char *)0x0) || (buf + (len - 2) < pcVar6)) {
    buf[len - 2] = ':';
  }
  return;
}

