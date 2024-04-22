
ulong ASN1_tag2bit(int tag)

{
  ulong uVar1;
  
  if ((uint)tag < 0x1f) {
    uVar1 = *(ulong *)(DAT_000ba9f0 + tag * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

