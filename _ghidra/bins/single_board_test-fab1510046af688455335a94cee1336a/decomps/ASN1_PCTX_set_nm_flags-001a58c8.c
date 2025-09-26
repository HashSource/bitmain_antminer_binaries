
void ASN1_PCTX_set_nm_flags(ASN1_PCTX *p,ulong flags)

{
  *(ulong *)(p + 4) = flags;
  return;
}

