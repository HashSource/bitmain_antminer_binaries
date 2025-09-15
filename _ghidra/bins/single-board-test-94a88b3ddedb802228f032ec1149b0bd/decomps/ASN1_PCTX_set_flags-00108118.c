
void ASN1_PCTX_set_flags(ASN1_PCTX *p,ulong flags)

{
  *(ulong *)p = flags;
  return;
}

