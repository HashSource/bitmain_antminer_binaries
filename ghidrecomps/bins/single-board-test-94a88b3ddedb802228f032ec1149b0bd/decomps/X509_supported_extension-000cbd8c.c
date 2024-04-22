
int X509_supported_extension(X509_EXTENSION *ex)

{
  ASN1_OBJECT *o;
  void *local_c;
  
  o = X509_EXTENSION_get_object(ex);
  local_c = (void *)OBJ_obj2nid(o);
  if (local_c != (void *)0x0) {
    local_c = OBJ_bsearch_(&local_c,DAT_000cbdbc,0xb,4,DAT_000cbdb8);
    if (local_c != (void *)0x0) {
      local_c = (void *)0x1;
    }
  }
  return (int)local_c;
}

