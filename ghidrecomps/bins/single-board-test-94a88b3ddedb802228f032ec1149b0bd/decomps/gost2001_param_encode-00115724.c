
void gost2001_param_encode(EVP_PKEY *param_1,uchar **param_2)

{
  EC_KEY *key;
  EC_GROUP *group;
  int n;
  ASN1_OBJECT *a;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  group = EC_KEY_get0_group(key);
  n = EC_GROUP_get_curve_name(group);
  a = OBJ_nid2obj(n);
  i2d_ASN1_OBJECT(a,param_2);
  return;
}

