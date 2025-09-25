
int X509_supported_extension(X509_EXTENSION *ex)

{
  ASN1_OBJECT *o;
  void *local_c;
  
  o = X509_EXTENSION_get_object(ex);
  local_c = (void *)OBJ_obj2nid(o);
  if (local_c != (void *)0x0) {
    local_c = OBJ_bsearch_(&local_c,&supported_nids_23211,0xe,4,(cmp *)0x173985);
    if (local_c != (void *)0x0) {
      local_c = (void *)0x1;
    }
  }
  return (int)local_c;
}

