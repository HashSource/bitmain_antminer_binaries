
void X509_get_signature_nid(int param_1)

{
  OBJ_obj2nid(**(ASN1_OBJECT ***)(param_1 + 4));
  return;
}

