
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  ASN1_STRING **ppAVar1;
  int iVar2;
  ASN1_INTEGER **val;
  int iVar3;
  SXNET *val_00;
  
  if ((psx == (SXNET **)0x0 || izone == (ASN1_INTEGER *)0x0) || (user == (char *)0x0)) {
    ERR_put_error(0x22,0x7e,0x6b,DAT_000c9b78,0xbe);
    return 0;
  }
  if (userlen == -1) {
    userlen = strlen(user);
    if (0x40 < userlen) goto LAB_000c9b38;
  }
  else if (0x40 < userlen) {
LAB_000c9b38:
    ERR_put_error(0x22,0x7e,0x84,DAT_000c9b78,0xc4);
    return 0;
  }
  val_00 = *psx;
  if (val_00 == (SXNET *)0x0) {
    val_00 = (SXNET *)ASN1_item_new(DAT_000c9b7c);
    if (val_00 == (SXNET *)0x0) {
      val = (ASN1_INTEGER **)0x0;
      goto LAB_000c9ab6;
    }
    iVar3 = ASN1_INTEGER_set(val_00->version,0);
    if (iVar3 == 0) {
      val = (ASN1_INTEGER **)0x0;
      goto LAB_000c9ab6;
    }
    *psx = val_00;
  }
  iVar3 = 0;
  do {
    iVar2 = sk_num(&val_00->ids->stack);
    if (iVar2 <= iVar3) goto LAB_000c9a98;
    ppAVar1 = (ASN1_STRING **)sk_value(&val_00->ids->stack,iVar3);
    iVar2 = ASN1_STRING_cmp(*ppAVar1,izone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  if (ppAVar1[1] != (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x7e,0x85,DAT_000c9b78,0xd0);
    return 0;
  }
LAB_000c9a98:
  val = (ASN1_INTEGER **)ASN1_item_new(DAT_000c9b74);
  if (val != (ASN1_INTEGER **)0x0) {
    if (userlen == 0xffffffff) {
      userlen = strlen(user);
    }
    iVar3 = ASN1_STRING_set(val[1],user,userlen);
    if ((iVar3 != 0) && (iVar3 = sk_push(&val_00->ids->stack,val), iVar3 != 0)) {
      *val = izone;
      return 1;
    }
  }
LAB_000c9ab6:
  ERR_put_error(0x22,0x7e,0x41,DAT_000c9b78,0xe1);
  ASN1_item_free((ASN1_VALUE *)val,DAT_000c9b74);
  ASN1_item_free((ASN1_VALUE *)val_00,DAT_000c9b7c);
  *psx = (SXNET *)0x0;
  return 0;
}

