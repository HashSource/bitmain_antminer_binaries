
/* WARNING: Unknown calling convention */

void regen_hash(work *work)

{
  uint *data32;
  int iVar1;
  uint uVar2;
  uchar hash1 [32];
  uchar swap [80];
  
  iVar1 = 0;
  do {
    uVar2 = *(uint *)(work->data + iVar1);
    *(uint *)(swap + iVar1) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
    iVar1 = iVar1 + 4;
  } while (iVar1 != 0x50);
  sha256(swap,0x50,hash1);
  sha256(hash1,0x20,work->hash);
  return;
}

