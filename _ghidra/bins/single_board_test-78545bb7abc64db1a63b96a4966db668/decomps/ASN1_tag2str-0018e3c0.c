
char * ASN1_tag2str(int tag)

{
  if ((tag & 0xfffffff7U) == 0x102) {
    tag = tag & 0xfffffeff;
  }
  if ((uint)tag < 0x1f) {
    return (&tag2str_10906)[tag];
  }
  return "(unknown)";
}

