
/* WARNING: Unknown calling convention */

int32_t decode_unicode_escape(char *str)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*str != 'u') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[0] == \'u\'","load.c",0x116,"decode_unicode_escape");
  }
  iVar1 = 0;
  iVar3 = 1;
  do {
    uVar2 = (uint)(byte)str[iVar3];
    iVar1 = iVar1 * 0x10;
    if ((uVar2 - 0x30 & 0xff) < 10) {
      iVar1 = (uVar2 - 0x30) + iVar1;
    }
    else if (uVar2 - 0x61 < 0x1a) {
      iVar1 = (uVar2 - 0x57) + iVar1;
    }
    else {
      if (0x19 < uVar2 - 0x41) {
        return -1;
      }
      iVar1 = (uVar2 - 0x37) + iVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 5);
  return iVar1;
}

