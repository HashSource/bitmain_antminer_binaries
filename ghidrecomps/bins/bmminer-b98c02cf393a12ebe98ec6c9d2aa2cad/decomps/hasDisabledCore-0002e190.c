
undefined4 hasDisabledCore(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0002e1d0;
  do {
    if ((*(char *)(iVar2 + -0xe) == ',') && (*(char *)(iVar2 + -0xd) == 'e')) {
      iVar1 = iVar2 + -0xe;
      do {
        if ((*(byte *)(iVar1 + 2) < 0x54) && (*(byte *)(iVar1 + 3) < 0x72)) {
          return 1;
        }
        iVar1 = iVar1 + 2;
      } while (iVar2 != iVar1);
    }
    iVar2 = iVar2 + 0x10;
    if (iVar2 == DAT_0002e1d0 + 0x100) {
      return 0;
    }
  } while( true );
}

