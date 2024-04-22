
void ASN1_PCTX_set_oid_flags(ASN1_PCTX *p,ulong flags)

{
  *(ulong *)(p + 0xc) = flags;
  return;
}

