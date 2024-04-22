
ulong lh_strhash(char *c)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (c != (char *)0x0) {
    uVar3 = (uint)(byte)*c;
    if (uVar3 == 0) {
      c = (char *)0x0;
    }
    else {
      uVar5 = 0;
      uVar2 = 0x100;
      do {
        uVar4 = uVar2 | uVar3;
        c = (char *)((byte *)c + 1);
        uVar3 = (uint)(byte)*c;
        uVar2 = uVar2 + 0x100;
        uVar1 = 0x20 - ((uVar4 ^ uVar4 >> 2) & 0xf) & 0x1f;
        uVar5 = (uVar5 >> uVar1 | uVar5 << 0x20 - uVar1) ^ uVar4 * uVar4;
      } while (uVar3 != 0);
      c = (char *)(uVar5 ^ uVar5 >> 0x10);
    }
  }
  return (ulong)c;
}

