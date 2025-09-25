
int PKCS12_SAFEBAG_get_bag_nid(int param_1)

{
  int iVar1;
  
  iVar1 = PKCS12_SAFEBAG_get_nid();
  if (iVar1 - 0x98U < 3) {
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(param_1 + 4));
    return iVar1;
  }
  return -1;
}

