
void EVP_PKEY_asn1_set_ctrl(EVP_PKEY_ASN1_METHOD *ameth,pkey_ctrl *pkey_ctrl)

{
  *(pkey_ctrl **)(ameth + 0x58) = pkey_ctrl;
  return;
}

