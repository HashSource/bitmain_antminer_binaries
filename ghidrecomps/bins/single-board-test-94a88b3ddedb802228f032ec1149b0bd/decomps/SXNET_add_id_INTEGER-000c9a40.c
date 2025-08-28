
int SXNET_add_id_INTEGER(SXNET **psx,ASN1_INTEGER *izone,char *user,int userlen)

{
  undefined4 *puVar1;
  int iVar2;
  ASN1_VALUE *val;
  int iVar3;
  SXNET *val_00;
  
  if ((psx == (SXNET **)0x0 || izone == (ASN1_INTEGER *)0x0) || (user == (char *)0x0)) {
    ERR_put_error(0x22,0x7e,0x6b,"v3_sxnet.c",0xbe);
    return 0;
  }
  if (userlen == -1) {
    userlen = strlen(user);
    if (0x40 < userlen) goto LAB_000c9b38;
  }
  else if (0x40 < userlen) {
LAB_000c9b38:
    ERR_put_error(0x22,0x7e,0x84,"v3_sxnet.c",0xc4);
    return 0;
  }
  val_00 = *psx;
  if (val_00 == (SXNET *)0x0) {
    val_00 = (SXNET *)ASN1_item_new((ASN1_ITEM *)SXNET_it);
    if (val_00 == (SXNET *)0x0) {
      val = (ASN1_VALUE *)0x0;
      goto LAB_000c9ab6;
    }
    iVar3 = ASN1_INTEGER_set(val_00->version,0);
    if (iVar3 == 0) {
      val = (ASN1_VALUE *)0x0;
      goto LAB_000c9ab6;
    }
    *psx = val_00;
  }
  iVar3 = 0;
  do {
    iVar2 = sk_num(&val_00->ids->stack);
    if (iVar2 <= iVar3) goto LAB_000c9a98;
    puVar1 = (undefined4 *)sk_value(&val_00->ids->stack,iVar3);
    iVar2 = ASN1_STRING_cmp((ASN1_STRING *)*puVar1,izone);
    iVar3 = iVar3 + 1;
  } while (iVar2 != 0);
  if (puVar1[1] != 0) {
    ERR_put_error(0x22,0x7e,0x85,"v3_sxnet.c",0xd0);
    return 0;
  }
LAB_000c9a98:
  val = ASN1_item_new((ASN1_ITEM *)&SXNETID_it);
  if (val != (ASN1_VALUE *)0x0) {
    if (userlen == 0xffffffff) {
      userlen = strlen(user);
    }
    iVar3 = ASN1_STRING_set(*(ASN1_STRING **)(val + 4),user,userlen);
    if ((iVar3 != 0) && (iVar3 = sk_push(&val_00->ids->stack,val), iVar3 != 0)) {
      *(ASN1_INTEGER **)val = izone;
      return 1;
    }
  }
LAB_000c9ab6:
  ERR_put_error(0x22,0x7e,0x41,"v3_sxnet.c",0xe1);
  ASN1_item_free(val,(ASN1_ITEM *)&SXNETID_it);
  ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)SXNET_it);
  *psx = (SXNET *)0x0;
  return 0;
}

