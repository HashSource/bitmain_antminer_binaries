
int GENERAL_NAME_set0_othername(GENERAL_NAME *gen,ASN1_OBJECT *oid,ASN1_TYPE *value)

{
  OTHERNAME *value_00;
  
  value_00 = OTHERNAME_new();
  if (value_00 != (OTHERNAME *)0x0) {
    ASN1_TYPE_free(value_00->value);
    value_00->type_id = oid;
    value_00->value = value;
    GENERAL_NAME_set0_value(gen,0,value_00);
    return 1;
  }
  return 0;
}

