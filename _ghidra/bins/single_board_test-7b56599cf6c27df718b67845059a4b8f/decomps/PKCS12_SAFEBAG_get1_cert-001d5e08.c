
void * PKCS12_SAFEBAG_get1_cert(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = PKCS12_SAFEBAG_get_nid();
  if ((iVar1 == 0x98) &&
     (iVar1 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(param_1 + 4)), iVar1 == 0x9e)) {
    pvVar2 = ASN1_item_unpack(*(ASN1_STRING **)(*(int *)(param_1 + 4) + 4),(ASN1_ITEM *)&X509_it);
    return pvVar2;
  }
  return (void *)0x0;
}

