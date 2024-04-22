
stack_st_PKCS12_SAFEBAG * PKCS12_unpack_p7data(PKCS7 *p7)

{
  int iVar1;
  stack_st_PKCS12_SAFEBAG *psVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x15) {
    psVar2 = (stack_st_PKCS12_SAFEBAG *)ASN1_item_unpack((p7->d).data,DAT_0010ec20);
    return psVar2;
  }
  ERR_put_error(0x23,0x83,0x79,DAT_0010ec24,0xa2);
  return (stack_st_PKCS12_SAFEBAG *)0x0;
}

