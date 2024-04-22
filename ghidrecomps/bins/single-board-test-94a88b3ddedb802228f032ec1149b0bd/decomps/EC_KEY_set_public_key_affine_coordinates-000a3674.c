
int EC_KEY_set_public_key_affine_coordinates(EC_KEY *key,BIGNUM *x,BIGNUM *y)

{
  BN_CTX *c;
  EC_POINT *p;
  EC_METHOD *meth;
  int iVar1;
  BIGNUM *x_00;
  BIGNUM *y_00;
  EC_POINT *pEVar2;
  
  if (((key == (EC_KEY *)0x0) || (*(int *)(key + 4) == 0)) ||
     (x == (BIGNUM *)0x0 || y == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xe5,0x43,DAT_000a37a0,0x175);
    return 0;
  }
  c = BN_CTX_new();
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  p = EC_POINT_new(*(EC_GROUP **)(key + 4));
  if (p == (EC_POINT *)0x0) {
    BN_CTX_free(c);
    return 0;
  }
  meth = EC_GROUP_method_of(*(EC_GROUP **)(key + 4));
  iVar1 = EC_METHOD_get_field_type(meth);
  if (iVar1 == 0x197) {
    x_00 = BN_CTX_get(c);
    y_00 = BN_CTX_get(c);
    pEVar2 = (EC_POINT *)EC_POINT_set_affine_coordinates_GF2m(*(undefined4 *)(key + 4),p,x,y,c);
    if (pEVar2 == (EC_POINT *)0x0) goto LAB_000a36f2;
    pEVar2 = (EC_POINT *)
             EC_POINT_get_affine_coordinates_GF2m(*(undefined4 *)(key + 4),p,x_00,y_00,c);
joined_r0x000a3778:
    if (pEVar2 == (EC_POINT *)0x0) goto LAB_000a36f2;
    iVar1 = BN_cmp(x,x_00);
    if ((iVar1 == 0) && (iVar1 = BN_cmp(y,y_00), iVar1 == 0)) {
      if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
        EC_POINT_free(*(EC_POINT **)(key + 8));
      }
      pEVar2 = EC_POINT_dup(p,*(EC_GROUP **)(key + 4));
      *(EC_POINT **)(key + 8) = pEVar2;
      if ((pEVar2 != (EC_POINT *)0x0) &&
         (pEVar2 = (EC_POINT *)EC_KEY_check_key(key), pEVar2 != (EC_POINT *)0x0)) {
        pEVar2 = (EC_POINT *)0x1;
      }
      goto LAB_000a36f2;
    }
    ERR_put_error(0x10,0xe5,0x92,DAT_000a37a0,0x1a0);
  }
  else {
    x_00 = BN_CTX_get(c);
    y_00 = BN_CTX_get(c);
    iVar1 = EC_POINT_set_affine_coordinates_GFp(*(EC_GROUP **)(key + 4),p,x,y,c);
    if (iVar1 != 0) {
      pEVar2 = (EC_POINT *)
               EC_POINT_get_affine_coordinates_GFp(*(EC_GROUP **)(key + 4),p,x_00,y_00,c);
      goto joined_r0x000a3778;
    }
  }
  pEVar2 = (EC_POINT *)0x0;
LAB_000a36f2:
  BN_CTX_free(c);
  EC_POINT_free(p);
  return (int)pEVar2;
}

