
int ENGINE_set_pkey_asn1_meths(ENGINE *e,ENGINE_PKEY_ASN1_METHS_PTR f)

{
  *(ENGINE_PKEY_ASN1_METHS_PTR *)(e + 0x28) = f;
  return 1;
}

