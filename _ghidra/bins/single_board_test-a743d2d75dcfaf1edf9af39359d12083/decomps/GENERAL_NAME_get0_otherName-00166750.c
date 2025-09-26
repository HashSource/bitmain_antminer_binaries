
int GENERAL_NAME_get0_otherName(GENERAL_NAME *gen,ASN1_OBJECT **poid,ASN1_TYPE **pvalue)

{
  if (gen->type != 0) {
    return 0;
  }
  if (poid != (ASN1_OBJECT **)0x0) {
    *poid = ((gen->d).otherName)->type_id;
  }
  if (pvalue != (ASN1_TYPE **)0x0) {
    *pvalue = ((gen->d).otherName)->value;
    return 1;
  }
  return 1;
}

