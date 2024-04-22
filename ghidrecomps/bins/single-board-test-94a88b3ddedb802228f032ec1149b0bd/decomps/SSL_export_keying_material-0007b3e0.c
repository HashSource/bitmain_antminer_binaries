
int SSL_export_keying_material
              (SSL *s,uchar *out,size_t olen,char *label,size_t llen,uchar *p,size_t plen,
              int use_context)

{
  int iVar1;
  
  if (s->version < 0x301) {
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(s->method->ssl3_enc + 0x34))();
  }
  return iVar1;
}

