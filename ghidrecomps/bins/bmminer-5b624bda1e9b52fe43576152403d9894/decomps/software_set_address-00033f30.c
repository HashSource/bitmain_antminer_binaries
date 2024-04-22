
/* WARNING: Unknown calling convention */

void software_set_address(void)

{
  int *piVar1;
  uchar chain;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint i;
  uchar address;
  uint uVar7;
  char tmp42 [2048];
  
  piVar1 = DAT_00034040;
  iVar5 = *DAT_00034040;
  cVar3 = *DAT_00034044;
  iVar4 = iVar5 + 0x2f80;
  *(undefined *)(iVar5 + 0x2fba) = 0;
  if ((cVar3 != '\0') &&
     (((*DAT_00034048 != '\0' || (*DAT_0003404c != '\0')) || (cVar3 = '\0', 6 < *DAT_00034058)))) {
    snprintf(tmp42,0x800,DAT_00034054,DAT_00034050);
    _applog(7,tmp42,false);
    iVar5 = *piVar1;
    iVar4 = iVar5 + 0x2f80;
    cVar3 = *(char *)(iVar5 + 0x2fba);
  }
  iVar6 = 0;
  *(char *)(iVar4 + 0x3a) = cVar3 + '\x02';
  *(undefined *)(iVar5 + 0x2fe8) = 4;
  while( true ) {
    if ((*(int *)(iVar5 + (iVar6 + 2) * 4) == 1) && (*(char *)(iVar5 + iVar6 + 0x2faa) != '\0')) {
      chain = (uchar)iVar6;
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      chain_inactive(chain);
      cgsleep_ms(0x1e);
      iVar4 = __aeabi_idiv(0x100,*(undefined *)(*piVar1 + 0x2fe8));
      if (iVar4 != 0) {
        address = '\0';
        uVar7 = 0;
        do {
          uVar7 = uVar7 + 1;
          set_address(chain,'\0',address);
          address = address + *(char *)(*piVar1 + 0x2fe8);
          cgsleep_ms(0x1e);
          uVar2 = __aeabi_idiv(0x100,*(undefined *)(*piVar1 + 0x2fe8));
        } while (uVar7 < uVar2);
      }
    }
    if (iVar6 == 0xf) break;
    iVar6 = iVar6 + 1;
    iVar5 = *piVar1;
  }
  return;
}

