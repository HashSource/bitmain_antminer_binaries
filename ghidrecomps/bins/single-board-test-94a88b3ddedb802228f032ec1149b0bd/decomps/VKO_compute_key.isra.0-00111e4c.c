
undefined4
VKO_compute_key_isra_0(undefined4 param_1,EC_POINT *param_2,EC_KEY *param_3,undefined *param_4)

{
  BIGNUM *a;
  EC_GROUP *pEVar1;
  EC_POINT *r;
  BN_CTX *ctx;
  BIGNUM *b;
  BIGNUM *r_00;
  BIGNUM *order;
  BIGNUM *x;
  BIGNUM *y;
  undefined *puVar2;
  undefined *puVar3;
  undefined local_120;
  undefined local_11f;
  undefined local_11e;
  undefined local_11d;
  undefined local_11c;
  undefined local_11b;
  undefined local_11a;
  undefined local_119;
  undefined local_118 [64];
  undefined auStack_d8 [63];
  undefined local_99 [117];
  
  a = EC_KEY_get0_private_key(param_3);
  pEVar1 = EC_KEY_get0_group(param_3);
  r = EC_POINT_new(pEVar1);
  ctx = BN_CTX_new();
  local_120 = param_4[7];
  local_11a = param_4[1];
  local_11c = param_4[3];
  local_119 = *param_4;
  local_11b = param_4[2];
  local_11e = param_4[5];
  local_11d = param_4[4];
  local_11f = param_4[6];
  BN_CTX_start(ctx);
  b = (BIGNUM *)getbnfrombuf(&local_120,8);
  r_00 = BN_CTX_get(ctx);
  order = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_GROUP_get_order(pEVar1,order,ctx);
  BN_mod_mul(r_00,a,b,order,ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_POINT_mul(pEVar1,r,(BIGNUM *)0x0,param_2,r_00,ctx);
  pEVar1 = EC_KEY_get0_group(param_3);
  EC_POINT_get_affine_coordinates_GFp(pEVar1,r,x,y,ctx);
  store_bignum(y,local_118,0x20);
  store_bignum(x,local_118 + 0x20,0x20);
  puVar2 = local_99 + 1;
  puVar3 = &local_119;
  do {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + -1;
    *puVar2 = *puVar3;
  } while (puVar3 != local_118 + 0x3f);
  init_gost_hash_ctx(local_99 + 1,DAT_00111f94);
  start_hash(local_99 + 1);
  hash_block(local_99 + 1,auStack_d8,0x40);
  finish_hash(local_99 + 1,param_1);
  done_gost_hash_ctx(local_99 + 1);
  BN_free(b);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  EC_POINT_free(r);
  return 0x20;
}

