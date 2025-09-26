
int SSL_export_keying_material
              (SSL *s,uchar *out,size_t olen,char *label,size_t llen,uchar *p,size_t plen,
              int use_context)

{
  int iVar1;
  
  if ((s[2].tlsext_ticket_expected != 0) && (s->version == 0x100 || 0x300 < s->version)) {
                    /* WARNING: Could not recover jumptable at 0x000eb8d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(s->type + 100) + 0x2c))();
    return iVar1;
  }
  return -1;
}

