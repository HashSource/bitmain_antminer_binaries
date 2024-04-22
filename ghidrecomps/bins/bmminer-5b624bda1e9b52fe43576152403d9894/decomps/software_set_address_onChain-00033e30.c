
/* WARNING: Unknown calling convention */

void software_set_address_onChain(int chainIndex)

{
  int *piVar1;
  uchar chain;
  uint i;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uchar address;
  uint uVar6;
  char tmp42 [2048];
  
  piVar1 = DAT_00033f14;
  iVar4 = *DAT_00033f14;
  cVar3 = *DAT_00033f18;
  iVar5 = iVar4 + 0x2f80;
  *(undefined *)(iVar4 + 0x2fba) = 0;
  if ((cVar3 != '\0') &&
     (((*DAT_00033f1c != '\0' || (*DAT_00033f20 != '\0')) || (cVar3 = '\0', 6 < *DAT_00033f2c)))) {
    snprintf(tmp42,0x800,DAT_00033f28,DAT_00033f24);
    _applog(7,tmp42,false);
    iVar4 = *piVar1;
    iVar5 = iVar4 + 0x2f80;
    cVar3 = *(char *)(iVar4 + 0x2fba);
  }
  *(char *)(iVar5 + 0x3a) = cVar3 + '\x02';
  *(undefined *)(iVar4 + 0x2fe8) = 4;
  chain = (uchar)chainIndex;
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  chain_inactive(chain);
  cgsleep_ms(0x1e);
  iVar4 = __aeabi_idiv(0x100,*(undefined *)(*piVar1 + 0x2fe8));
  if (iVar4 != 0) {
    address = '\0';
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      set_address(chain,'\0',address);
      address = address + *(char *)(*piVar1 + 0x2fe8);
      cgsleep_ms(0x1e);
      uVar2 = __aeabi_idiv(0x100,*(undefined *)(*piVar1 + 0x2fe8));
    } while (uVar6 < uVar2);
  }
  return;
}

