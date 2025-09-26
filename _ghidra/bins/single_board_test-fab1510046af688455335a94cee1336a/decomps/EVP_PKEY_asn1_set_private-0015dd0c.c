
void EVP_PKEY_asn1_set_private
               (EVP_PKEY_ASN1_METHOD *ameth,priv_decode *priv_decode,priv_encode *priv_encode,
               priv_print *priv_print)

{
  *(priv_decode **)(ameth + 0x24) = priv_decode;
  *(priv_encode **)(ameth + 0x28) = priv_encode;
  *(priv_print **)(ameth + 0x2c) = priv_print;
  return;
}

