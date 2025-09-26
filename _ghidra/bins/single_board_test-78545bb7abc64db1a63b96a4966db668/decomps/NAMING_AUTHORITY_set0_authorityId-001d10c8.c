
void NAMING_AUTHORITY_set0_authorityId(undefined4 *param_1,undefined4 param_2)

{
  ASN1_OBJECT_free((ASN1_OBJECT *)*param_1);
  *param_1 = param_2;
  return;
}

