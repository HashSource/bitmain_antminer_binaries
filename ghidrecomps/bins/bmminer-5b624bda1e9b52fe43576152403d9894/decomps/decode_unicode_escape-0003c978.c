
/* WARNING: Unknown calling convention */

int32_t decode_unicode_escape(char *str)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int i;
  
  if (*str != 'u') {
                    /* WARNING: Subroutine does not return */
    __assert_fail(DAT_0003c9d8,DAT_0003c9dc,0x120,DAT_0003c9e0);
  }
  iVar1 = 0;
  iVar4 = 1;
  do {
    uVar3 = (uint)(byte)str[iVar4];
    uVar2 = uVar3 - 0x30;
    if (9 < (uVar2 & 0xff)) {
      if (uVar3 - 0x61 < 0x1a) {
        uVar2 = uVar3 - 0x57;
      }
      else {
        if (0x19 < uVar3 - 0x41) {
                    /* WARNING: Subroutine does not return */
          __assert_fail(DAT_0003c9e4,DAT_0003c9dc,300,DAT_0003c9e0);
        }
        uVar2 = uVar3 - 0x37;
      }
    }
    iVar1 = uVar2 + iVar1 * 0x10;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 5);
  return iVar1;
}

