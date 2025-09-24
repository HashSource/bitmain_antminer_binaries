
ulong ASN1_tag2bit(int tag)

{
  if ((uint)tag < 0x1f) {
    return *(ulong *)(&tag2bit + tag * 4);
  }
  return 0;
}

