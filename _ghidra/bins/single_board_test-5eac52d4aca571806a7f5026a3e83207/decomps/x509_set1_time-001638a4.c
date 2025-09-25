
ASN1_STRING * x509_set1_time(undefined4 *param_1,ASN1_STRING *param_2)

{
  if (((ASN1_STRING *)*param_1 != param_2) &&
     (param_2 = ASN1_STRING_dup(param_2), param_2 != (ASN1_STRING *)0x0)) {
    ASN1_TIME_free((ASN1_TIME *)*param_1);
    *param_1 = param_2;
  }
  if (param_2 != (ASN1_STRING *)0x0) {
    param_2 = (ASN1_STRING *)0x1;
  }
  return param_2;
}

