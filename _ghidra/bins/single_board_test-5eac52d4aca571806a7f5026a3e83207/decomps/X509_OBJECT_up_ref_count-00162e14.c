
void X509_OBJECT_up_ref_count(X509_OBJECT *a)

{
  if (a->type == 1) {
    X509_up_ref((a->data).ptr);
    return;
  }
  if (a->type == 2) {
    X509_CRL_up_ref((a->data).ptr);
    return;
  }
  return;
}

