
int decode_unicode_escape(byte *param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  if (*param_1 != 0x75) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[0] == \'u\'","compat/jansson-2.9/src/load.c",0x138,"decode_unicode_escape");
  }
  iVar1 = 0;
  pbVar3 = param_1 + 4;
  do {
    param_1 = param_1 + 1;
    uVar2 = (uint)*param_1;
    iVar1 = iVar1 * 0x10;
    if ((uVar2 - 0x30 & 0xff) < 10) {
      iVar1 = iVar1 + (uVar2 - 0x30);
    }
    else if (uVar2 - 0x61 < 0x1a) {
      iVar1 = iVar1 + (uVar2 - 0x57);
    }
    else {
      if (0x19 < uVar2 - 0x41) {
        return -1;
      }
      iVar1 = iVar1 + (uVar2 - 0x37);
    }
  } while (param_1 != pbVar3);
  return iVar1;
}

